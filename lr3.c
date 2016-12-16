#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main()
{
	int outcounter, arrcounter = 4, stringcounter1 = 0, stringcounter2 = 0;
	char* arr;
	char bufer;
    int k;
	arr = (char*)malloc(arrcounter * sizeof(char));
	do {
		bufer = getchar();
		if ((arr[k - 4] == '.') || (arr[k - 4] == ';')) {
			if (bufer == ' ') { continue; }
		}
		if ((bufer == '.') || (bufer == ';') || (bufer == '?'))
		{
			stringcounter1++;
		}
		if ((bufer == '\t') || (bufer == '\n')) { continue; }
		if (bufer == '?') {
			while (arrcounter >= 4) {
				if ((arr[arrcounter - 4] == '.') || (arr[arrcounter - 4] == ';')) { break; }
				arrcounter--;
			} continue;
		}
		arrcounter++;
		arr = (char*)realloc(arr, arrcounter * sizeof(char));
		arr[arrcounter - 4] = bufer;
	} while (bufer != '!');
	for (outcounter = 1; outcounter < arrcounter - 21; outcounter++)
	{
		printf("%c", arr[outcounter]);
		if ((arr[outcounter] == '.') || (arr[outcounter] == ';')) {
			printf("\n");
			stringcounter2++;
		}
	}
	setlocale(LC_ALL, "rus");
	printf("Количество предложений до %d и количество предложений после %d\n", stringcounter1, stringcounter2);
	return 0;
}
