#include <stdio.h>
#include <stdlib.h>
#include<dir.h>
#include <dirent.h>

int IfFile(const char* dir,const char* name){

    char file[100]; strcpy(file,dir);strcat(file,"/");strcat(file,name);// добавление дириктории
    int j = strlen(dir),otvet,a;

    freopen(file,"r",stdin);

    if (dir[j-1] == 'd' && dir[j-2] == 'd' && dir[j-3] == 'a'){
        otvet = 0;
        while(scanf("%d",&a)!=EOF){
            otvet+=a;
        }
    }
    else{
        otvet = 1;
        while(scanf("%d",&a)!=EOF){
            otvet*=a;
        }
    }
    close(stdin);
    return otvet;
}

int list_dir(const char *startdir)
{
  char current_path[100];
  strcpy(current_path,startdir);
  int j = strlen(current_path),answer = 0,Bool;
  DIR *dir = opendir(current_path);
  struct  dirent *de = readdir(dir);

   if ((current_path[j-1] == 'd' && current_path[j-2] == 'd' && current_path[j-3] == 'a')|| (strstr(current_path,".txt") >0)){
      Bool= 0;
   }
   else{
    Bool = 1;
    answer = 1;
   }

  if(dir)
    while(de)
    {
     if(0!=strcmp(".",de->d_name) && 0!=strcmp("..",de->d_name))
     {

      if (strstr(de->d_name,".txt")){
            (Bool == 0)?(answer+=IfFile(current_path,de->d_name)):(answer*=IfFile(current_path,de->d_name));
            }else if(strstr(de->d_name,"add")>0 ||strstr(de->d_name,"mul")>0){

                                                                        int path_len = strlen(current_path);
                                                                        strcat(current_path,"/");
                                                                        strcat(current_path,de->d_name);

                                                                        if ((strstr(current_path,".txt") ==0)){
                                                                                                    (Bool ==0)?(answer +=list_dir(current_path)):(answer *=list_dir(current_path));
                                                                                                        }
                                        current_path[path_len] = '\0';
            }
     }
     de = readdir(dir);
    }

  closedir(dir);
  return answer;
}

int main()
{
    printf("%d",list_dir("add"));
    return 0;
}
