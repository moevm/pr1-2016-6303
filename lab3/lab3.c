#include <stdio.h>
#include <stdlib.h>
int main(){
    char ch;
    int bef = 0, dif= 0, i, n, size;
    do{
        size = 25;
        n = 0;
        char* sent = (char*)malloc(size*sizeof(char));
        do{
            ch=getchar();
        }while(ch=='\t' || ch==' ' || ch=='\n');
        sent[n++]= ch;
        while((ch=getchar()) != '!' && ch != '?' && ch != '.' && ch != ';'){
            if(n>size){
                size+=10;
                sent = (char*)realloc(sent, size*sizeof(char));
            }
            sent[n++]= ch;
        }
        sent[n++]= ch;
        if(ch == '?'){
            bef++;
            dif++;
        }
        if(ch == '.' || ch == ';'){
            for(i=0;i<n;i++){
                if(sent[i]){
                    printf("%c", sent[i]);
                }
            }
            bef++;
            printf("\n");
        }
        free(sent);
    }while(ch != '!');
    printf("Количество предложений до %i и количество предложений после %i", bef, bef-dif);
    return 0;
}

