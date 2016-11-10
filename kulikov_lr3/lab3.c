#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main() { 
char *str; 
char check[] = "Dragon flew away!"; 
int n = 0, m = 0, size = 10, len = 0, ch; 
str = realloc(NULL, sizeof(char)*size); 
	while(strstr(str,check)==NULL) { 
		do { 
			ch=getchar(); 
		} 
	while (ch == 9 || ch == 32 || ch == 10);
		str[len++] = ch; 
	while((ch = getchar()) != EOF && ch != '.' && ch != ';' && ch != '?') { 
	str[len++] = ch; 
		if (len == size) { 
			str = realloc(str, sizeof(char)*(size += 16)); 
			} 
		} 
str[len++] = '\0'; 
len = 0; 
switch((int)ch) { 
	
	case 63:
		n++;
		m++;
		break; 
	
	case 59:
		printf("%s;\n", str);
		n++;
		break; 
	
	case 46:
		printf("%s.\n", str);
		n++;
		break; 
	
	default:
		break; 
	} 
} 
printf("Количество предложений до %d и количество предложений после %d", n, n - m); 

}