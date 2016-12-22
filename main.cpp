#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char s[3] = ".;?",*text,c;
int n,k,i,kolx,koly,q;
void vvod(){
 if (q == 0){text = (char*)malloc(65*sizeof(char));q++;}

 if ((c = getchar()) == EOF){
              printf("Количество предложений до %d и количество предложений после %d",kolx+koly,kolx);
              return 0;}
    if (strchr(s,c) == NULL){
                             text[k] = c;
                             k++;}
                             else{
                                  if (c == s[2]){koly++;}
                                                else{
                                                     kolx++;
                                                     while(!iswalpha(text[n])){n++;}
                                                     for (i = n;i < k;i++){
                                                                        printf("%c",text[i]);};
                                                                        printf("%c\n",c);}
                                  k=0;n=k;q=k;free(text);}
 vvod();
}
int main()
{
    vvod();}
