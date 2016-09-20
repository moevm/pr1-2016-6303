#include <stdio.h>

char

int main() {
	int c;
	int i = 0;
	char input[100];
	while((c = getchar()) != EOF) {
		input[i] = c;
		i++;
	}
	input[i] = '\0';
	printf("%s", input);
}
