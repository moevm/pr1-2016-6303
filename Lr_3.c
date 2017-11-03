#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <malloc.h> 

int main() 
{ 
        int i=0,k=0,kold=0,kolp=0, count=5,c=1; 
            char subl[3] = {".;?"},a; 
            char* text; 
        text = (char*)malloc(count*sizeof(char)); 
        while((a = getchar()) != EOF){ 
        text[i] = a; 
        i++; 
        text = (char*)realloc(text, (count+c)*sizeof(char)); 
            c++; 
} 
        int n =i; 
        i = 0; 
        for (k=0;k<n;k++){ 
        if (((text[k] == ' ') && (strchr(subl,text[k-1]) != 0)) || (text[k] == '\n') || (text[k] == '\t')){ 
        i++;
        } 
    else{ 
    if (strchr(subl,text[k]) != 0){ 

    if (text[k] != '?'){ 
        for (int y=i;y<=k;y++){ 
        printf("%c",text[y]); 
        } 
        printf("\n"); 
        kolp++; 
        } 
        else{ 
        kold++; 
        } 
        i=k+1; 
        }} 

        } 
        printf("Количество предложений до %d и количество предложений после %d",kolp+kold,kolp); 
        free(text); 
        return 0; 
}
