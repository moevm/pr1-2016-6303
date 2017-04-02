#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
char *str;
int n=0, nn=0, size = 10, len=0,ch;
str = realloc(NULL, sizeof(char)*size);
while(strstr(str,"Dragon flew away!")==NULL){
	do{
			ch=getchar();
		}while(ch==9 || ch==32 || ch==10);
		str[len++]=ch;
while((ch=getchar())!=EOF && ch != '.' && ch != ';' && ch != '?'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
        }
    }
    str[len++]='\0';
    len=0;
	output(&ch, &n, &nn, str);
}
printf("Количество предложений до %d и количество предложений после %d", n, n-nn);
}
int output(int* ch, int* n, int* nn, int str){
	    switch((int)*ch){
    	case 63:*n+=1;*nn+=1;break;
    	case 59:printf("%s;\n", str);*n+=1;break;
    	case 46:printf("%s.\n", str);*n+=1;break;
    }
}
