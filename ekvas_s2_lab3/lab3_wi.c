#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILES 200

int file_read(const char* filename, const char* buff, char** files);

void index_files(const char *startdir, char** files, int* files_num){
  char current_path[10000];
  strcpy(current_path,startdir);
  DIR *dir = opendir(current_path);
  struct  dirent *de = readdir(dir);
  if(dir)
  while(de){
    if(de->d_type==8){
      int path_len = strlen(current_path);
      strcat(current_path,"/");
      strcat(current_path,de->d_name);
      strcpy(files[*files_num], current_path);
      (*files_num)++;
      current_path[path_len] = '\0';
    }
    if(de->d_type == DT_DIR && 0!=strcmp(".",de->d_name) && 0!=strcmp("..",de->d_name)){
      int path_len = strlen(current_path);
      strcat(current_path,"/");
      strcat(current_path,de->d_name);
      index_files(current_path, files, files_num);
      current_path[path_len] = '\0';
    }
    de = readdir(dir);
  }
  closedir(dir);
}

void find_file(char **files, const char *file_to_find, const char* buff){
  char buffer[10000];
  for(int i=0;i<MAX_FILES;i++){
    if(strstr(files[i], file_to_find)!=NULL){
      strcpy(buffer, buff);
      strcat(buffer, files[i]);
      strcat(buffer, "\n");
      if(file_read(files[i], buffer, files)){
        char sep[]="\n";
	      char *ptext;
        char *temp;
        char *pdir;
        char dir[1001];
        getcwd(dir, 1000);
        pdir=strtok(dir, "/");
        while(pdir!=NULL){
            temp=pdir;
		        pdir=strtok(NULL, "/");
	      }
	      ptext=strtok(buffer, sep);
	      while(ptext!=NULL){
            printf("/%s/%s\n", temp, ptext+2);
		        ptext=strtok(NULL, sep);
	      }
      }
    }
    }
}

int file_read(const char* filename, const char* buff, char** files){
  FILE *file = fopen (filename, "r");
  if (file != NULL){
     char line [ 128 ];
     while ( fgets(line,sizeof line,file)!= NULL){
       if(strstr(line, "Minotaur")){
         return 1;
       }
        char sep[]=" \n\r";
	      char *ptext;
	      ptext=strtok(line, sep);
	      while(ptext!=NULL){
            if(strstr(ptext, ".txt\0")){
              find_file(files, ptext, buff);
            }
		        ptext=strtok(NULL, sep);
	      }
     }
     fclose(file);
  }else{
     perror(filename);
  }
  return 0;
}

int main(int c, char **v, char **env ){
  char** files;
  int files_num=0;
  files=(char**)malloc(200*sizeof(char*));
  for(int i=0;i<200;i++){
    files[i]=(char*)malloc(1000*sizeof(char));
  }
  index_files(".", files, &files_num);
  find_file(files, "file.txt", "");
  return 0;
}
