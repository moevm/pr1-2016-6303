#include<stdio.h>
#include<stdlib.h>
	
void funk ( int *vopros, int *control, int *after );
	
int main() {
  int vopros = 0;
  int after = 0;
  int control = 0;
  while (control == 0){
    funk( &vopros, &control, &after);
  }
  printf ("Количество предложений до %d и количество предложений после %d\n",   (after+vopros), after );
  return 0;
}

void funk( int *vopros, int *control, int *after) {
 char c;
 int i=0;
 int n=1;
 char* str =(char*)malloc(n*sizeof(char));
 while ( ((c=getchar())!=';') && (c!='.') && (c!='?') ) {
    if (c =='!') {
        *control=1;
      	break;
    }
     if (  ((c!='\t') && (c!='\n') && (c!=' ')) ||  (i!=0)  ) {
   		str[i]=c;
         ++i;
     }
     str = realloc(str, sizeof(char)*(++n));
     
 }
 if(*control==0) {
	     
    if ((c=='.') || (c==';')) {
	         str = realloc(str, sizeof(char)*(++n));
	         str[i]=c;
             ++i;
             str[i]='\0';
             printf("%s\n", str );
             ++*after;
     }
	 else { ++*vopros ; }
 }
}
