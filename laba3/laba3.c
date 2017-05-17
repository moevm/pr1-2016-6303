#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

// 0 - начальная папка
// 1 - add
// 2 - mul
int ReadDir(const char* path,int modificator);

int main()    // текущая папка
{
	printf("%d\n",ReadDir(".",0));
	return 0;
}

int ReadDir(const char* path,int modificator)
{
	int result;
	char current_path[200];
	strcpy(current_path,path);
	if (modificator == 1)
		result = 0;
	else if (modificator == 2)
		result = 1;
	char in_file[200];
	DIR* dir = opendir(current_path);
	struct dirent* de =readdir(dir);
	if (dir)
		while(de)
		{
			if ((strstr(de->d_name,".txt"))&&(modificator!=0))
			{
				int path_len=strlen(current_path);
				strcat(current_path,"/");
				strcat(current_path,de->d_name);
				FILE* fo = fopen(current_path,"r");
				current_path[path_len] = '\0';
				fgets(in_file,199,fo);
				if(in_file[0]!='\n')
				{
					int a; 
					char* digit_in_file = strtok(in_file," \n");
					while (digit_in_file)
					{
						sscanf(digit_in_file,"%d",&a);
						if (modificator==1)
							result+=a;
						else if (modificator == 2)
							result*=a;
						digit_in_file = strtok(NULL," \n");
					} 
				}
				fclose(fo);
			}
			else
			{
				if(strcmp(".",de->d_name)!=0 && strcmp("..",de->d_name)!=0 && de->d_type ==DT_DIR)
				{
				int path_len = strlen(current_path);
				strcat(current_path,"/");
				strcat(current_path,de->d_name);
				if (strcmp(de->d_name,"mul")==0)
				{
					if (modificator == 1)
						result+=ReadDir(current_path,2);
					else if(modificator == 2)
						result*=ReadDir(current_path,2);
					else result = ReadDir(current_path,2);
				}
				else if(strcmp(de->d_name,"add")==0)
				{
					if (modificator == 1)
						result+=ReadDir(current_path,1);
					else if(modificator == 2)
						result*=ReadDir(current_path,1);
					else result = ReadDir(current_path,1);
				}
				current_path[path_len] = '\0';
				}
			}
			de = readdir(dir);
		}
	closedir(dir);
		return result;
}