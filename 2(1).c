#include <stdio.h>

int main(void) {
	int max=0;
	int count=0;
	char prevch, ch, mch;
	while((ch=getchar())!=EOF){
		if(ch!=' '){
		if(ch==prevch){
			prevch=ch;
			count+=1;
		}else{
			prevch=ch;
			count=1;
		}
		if(count>max){
			max=count;
			mch=ch;
			prevch=ch;
		}
		}
	}
	printf("%d (%c)", max, mch);
	return 0;
}
