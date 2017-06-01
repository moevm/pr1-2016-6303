#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct MyStruct {
	int num;
	char c[100];
} MyStruct;

typedef struct MyStructList {
	MyStruct str[100];
	int size;
} MyStructList;

MyStruct* getIndex(MyStructList* list, int i) {
	for(int x = 0; x < list->size; x++) {
		if(list->str[x].num == i) {
			return &(list->str[x]);
		}
	}
	return 0;
}


void printFile_(const char *path, MyStructList* list)
{
	char arr[100];
	int number = 0;

	FILE *f = fopen(path, "r");
	if(f)
	{
		while(fgets(arr, 100, f))
		{
			strcpy(list->str[list->size].c, arr);
			char* arrPtr = strtok(arr, " ");
			if(isdigit(*arrPtr)) {
			number = atoi(arrPtr);
			list->str[list->size].num=number;
			}
			list->size++;
		}
		fclose(f);
	}
}

void dirTraveler(const char *startDir, const int lvl, MyStructList* list)
{
    char path[1000];
    strcpy(path, startDir);
	  DIR *dir=opendir(path);

    if(dir)
    {
	struct dirent *de = readdir(dir);
        while(de)
        {
			if(de->d_type == DT_REG && strstr(de->d_name,".txt"))
			{
				int path_len = strlen(path);
                strcat(path, "/");
                strcat(path, de->d_name);
								printFile_(path, list);
                path[path_len] = '\0';
			}
            if(de->d_type == DT_DIR && 0!=strcmp(".", de->d_name) && 0!=strcmp("..", de->d_name))
            {
                int path_len = strlen(path);
                strcat(path, "/");
                strcat(path, de->d_name);
                dirTraveler(path, lvl+1, list);
                path[path_len] = '\0';
            }
           de = readdir(dir);
        }
    }
    closedir(dir);
}

int main()
{
	MyStructList* list = (MyStructList*) malloc(sizeof(MyStructList));
	list->size = 0;

	dirTraveler(".", 0, list);

	MyStruct* temp = 0;
	for(int i = 1; i < 100; i++) {
		if((temp = getIndex(list, i)) != 0)
			printf("%s\n", temp->c);
	}

	return 0;
}
