#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  char sym;
  scanf("%s\n", str);
  scanf("%c\n", &sym);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != sym) { 
           printf("%c", str[i]);
        }
        
    }  
    
  return 0;
}