    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>

 int takeAdd(const char *path) {

    char* s=malloc(100*sizeof(char));
    FILE *f = fopen(path, "r");
    int count;
    char* part;
    count=0;
    if(f) {
    	fgets(s,sizeof(s)/sizeof(char),f) ;
    	part=strtok(s, " ");
    	while (part!=NULL){
    		count=count+atoi(part);
    		part = strtok(NULL, " ");
    	}

    	fclose(f);
    }
    free(s);
    return count;
  }

  int takeMul(const char *path) {

    char* s=malloc(100*sizeof(char));
    FILE *f = fopen(path, "r");
    int count;
    char* part;
    count=1;
    
    if(f) {
    	fgets(s,sizeof(s)/sizeof(char),f);
   	part=strtok(s, " ");
    	while (part!=NULL){
    		count=count*atoi(part);
    		part = strtok(NULL, " ");
    	}

    	fclose(f);
    }
    free(s);
    return count;
  }

  
  
  void remake( char *path, char * new) {

    strcat(path, "/");
    strcat(path, new);
  }



  int dirTraveler(const char *startDir, int flag) {

    char* path=malloc(1000*sizeof(char));
    strcpy(path, startDir);
    int path_len, path_len1;
    int result;
    
    if (flag==0){
    	result=0;
    	remake(path, "add");
    }
    if (flag==1){
    	result=1;
    	remake(path, "mul");
    }

    DIR *dir=opendir(path);
    struct dirent *de;

    while(de = readdir(dir)) {
    	  if(de->d_type == DT_REG && strstr(de->d_name,".txt")) {
    		path_len=strlen(path);
    		remake(path, de->d_name);
    		if (flag==0){
    			result=result+takeAdd(path);
    			printf("add %d\n", result);
    			printf("direcrory %s\n", path);
    			
    		}
    		if (flag==1){
    			result=result*takeMul(path);
    			printf("mull %d\n", result);
    			printf("direcrory %s\n", path);

    		}
    		path[path_len]='\0';
    	  }

    	  if(de->d_type == DT_DIR && strcmp("add", de->d_name)==0 ) {
	
    		if (flag==0) {
			result=result+dirTraveler(path, 0);
		}
		else {
    			result=result*dirTraveler(path, 0);
    		}
    		 
    	  }
    	  if(de->d_type == DT_DIR && strcmp("mul", de->d_name)==0 ) {
		
    		if (flag==0) {
			result=result+dirTraveler(path, 1);
		}
		else {
    			result=result*dirTraveler(path, 1);
    		}
    	   }	
     }
     closedir(dir);
     free(path);
     return result;
  }

   int main() {
    
    char* path=malloc(1000*sizeof(char));
    strcpy(path, ".");

    DIR *dir=opendir(path);
    struct dirent *de;
    while (de = readdir(dir)) {
    	if (strcmp("add", de->d_name)==0)
    		printf("%d\n", dirTraveler(path,0));
    	if (strcmp("mul", de->d_name)==0)
    		printf("%d\n", dirTraveler(path,1));
    }

    closedir(dir);
    free(path);
    return 0;
}


