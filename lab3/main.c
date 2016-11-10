#include <stdio.h>
#include <malloc.h>
int main(){
    char ch;
    int bef = 0, dif= 0, i, n;
    do{
        n = 0;
        char* sent = (char*)malloc(100*sizeof(char));
        while((ch= getchar()) != '!' && ch != '?' && ch != '.' && ch != ';')
            if(ch != '\t' && ch != '\n'){
                sent[n]= ch;
                n++;
            }
        sent[n++]= ch;
        if(sent[0] == ' ')
            for(i = 0; i<100; i++){
                sent[i]= sent[i+1];
            }
        if(ch == '?'){
            bef++;
            dif++;
        }
        if(ch == '.' || ch == ';'){
            printf("%s\n", sent);
            bef++;
        }
    }while(ch != '!');
    printf("Количество предложений до %i и количество предложений после %i", bef, bef-dif);
    return 0;
}
