    #include <stdio.h>
    #include <string.h>
     
    int main() {
      char str[100];
      scanf("%s\n", str);
        for (int i = 0; i < strlen(str); i++) {
            if (i % 2 == 1) { 
                printf("%c", str[i]); 
            }
     
        }  
      return 0;
    }