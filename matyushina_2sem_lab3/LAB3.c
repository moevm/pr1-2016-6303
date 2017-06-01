    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>

int takeAdd(const char *path) {

  int count, n;
  count=0;
  FILE *f = fopen(path, "r");
  int i=0;
  if(f) {
	while( fscanf(f,"%d" ,&n)!=EOF) {
		count=count+n;
  	}
  fclose(f);
  }
  return count;
}

int takeMul(const char *path) {

  int count, n;
  count=1;
  FILE *f = fopen(path, "r");
  int i=0;
  if(f) {
	while( fscanf(f,"%d" ,&n)!=EOF) {
		count=count*n;
	}
  	fclose(f);
  }
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
    		}
    		if (flag==1){
    			result=result*takeMul(path);
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


