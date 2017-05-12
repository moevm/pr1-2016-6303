#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(){
	char c;
	int N=0, K=0;
	int consta=10;
	do{
		c=getchar();
		while (c==' ' || c=='	' || c=='\n'){
			c=getchar();
		}
		char* S=(char*)malloc(consta*sizeof(char)); 
		S[0]=c;
		int n=1;
		while (c!='.' && c!=';' && c!='?' && c!='!'){
			c=getchar();
			if (n>=consta) S=(char*)realloc((consta+50)*sizeof(char));
			S[n]=c;
			++n;
			if (n>=consta-1){
				S=(char*)realloc(S, consta);
				consta+=50;
			}
		}
		if (c=='?'){ 
			K++;
			N++;
		}	
		if (c==';' || c=='.'){
			for(int i=0; i<n; i++)
				printf("%c",S[i]);
			printf("\n");
			N++;
		}
	} while(c!='!');
	printf("Количество предложений до %i и количество предложений после %i", N, N-K);
	return 0;
}
