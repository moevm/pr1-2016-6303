#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Библиотека для подключения русской таблицы символов



int main()
{
	int outcounter, arrcounter = 4, stringcounter1 = 0, stringcounter2 = 0; // Инициализация переменных
	char* arr;
	char buf;
	arr = (char*)malloc(arrcounter * sizeof(char)); // Динамический массив
	do {
		buf = getchar();
		if ((arr[k - 4] == '.') || (arr[k - 4] == ';')) {
			if (buf == ' ') { continue; }
		}												  // Циклическое перемещение символа из stdin в буферную переменную
		if ((buf == '.') || (buf == ';') || (buf == '?')) // 17 - 35 строки: запись символа в буферную переменную
		{												  // Далее идет проверка на удовлетворение условиям задачи
			stringcounter1++;							  // Так-же происходит удаление (перезапись) строк неудовлетворяющих условям задачи
		}												  // Если символ удовлетворяет всем проверкам, происходит расширение массива на размер символа
		if ((buf == '\t') || (buf == '\n')) { continue; } // Затем происходит дозапись в массив символа из буферной переменной (buf)
		if (buf == '?') {								  // Цикл прерывается при нахождении восклицательного знака
			while (arrcounter >= 4) {
				if ((arr[arrcounter - 4] == '.') || (arr[arrcounter - 4] == ';')) { break; }
				arrcounter--;
			} continue;
		}
		arrcounter++;
		arr = (char*)realloc(arr, arrcounter * sizeof(char));
		arr[arrcounter - 4] = buf;
	} while (buf != '!');
	for (outcounter = 1; outcounter < arrcounter - 21; outcounter++)
	{
		printf("%c", arr[outcounter]);								// Вывод массива на stdout
		if ((arr[outcounter] == '.') || (arr[outcounter] == ';')) {	// Расставление символов переноса строки и забой пробелов
			printf("\n");
			stringcounter2++;										// Подсчёт строк ПОСЛЕ форматирования текста
		}
	}
	setlocale(LC_ALL, "rus");										// Подключение русского языка в качестве таблицы символов
	printf("Количество предложений до %d и количество предложений после %d\n", stringcounter1, stringcounter2);
	return 0;
}

