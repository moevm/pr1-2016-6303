/*

Все ситуации, за исключением нормальной:
+ В одном из файлов больше студентов, чем во втором                                     - провека кол-во строк
+ Отсутствие: в 1ом - Фамилия/Имя/Отчество/Гит/Мэйл/Группа, во 2ом - Фамилия/Имя/Балл!  - строковый валидатор
+ Студента из 2ого нет в 1ом (в случае одинакового кол-ва студентов в файлах)           - поиск из второго в первом
+ Больше одного студента имеют одно имя-фамилия в 1ом(+), во 2ом(+)                     - подсчёт кол-ва одинаковых фи/проверка массива имён
+ В поле балл не балл																	- супер-условие из лабы для atoi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_NUM 1000

typedef struct StudentsF1
{
	char Surname[30];
	char Name[30];
} StudentsF1;

typedef struct StudentsF2
{
	char Surname[30];
	char Name[30];
	int Score;
} StudentsF2;

//Проверяет валидность строки.
//Принимает строку и ID файла, из которого была считана строка. Первый файл ID=6, второй - ID=3
//Возвращает код ошибки.
int ValidityOfString(char *string, int ID)
{
	char tmp[200];
	unsigned int i = 0, count = 1;
	while ((string[i] != '\n') && (i<strlen(string)))
	{
		int j = 0;
		while ((string[i] != ';') && (string[i] != ',') && (i<strlen(string)))
		{
			tmp[j] = string[i];
			i++;
			j++;
		}
		tmp[j] = '\0';
		if (tmp[0] == '\0')
			return count;
		if ((ID == 3) && (count == 3))
		{
			int score = atoi(tmp);
			if ((score == 0) && (strcmp(tmp, "0") != 0))
				return 3;
		}
		count++;
		i++;
	}
	if ((count - 1) != ID)
		return count;
	else
		return 0;
}

//Определяет тип параметра ошибки и печатает сообщение.
//Принимает код ошибки и ID файла, из которого была считана строка
//Возвращает 0, если ошибки нет, 1 - если ошибка есть
int ParametrOfError(int ErrorCode, int ID)
{
	switch (ErrorCode)
	{
	case 0: return 0;
	case 1: if (ID == 6) printf("Failed with <Surname. File №1>\n"); else printf("Failed with <Surname. File №2>\n"); break;
	case 2: if (ID == 6) printf("Failed with <Name. File №1>\n"); else printf("Failed with <Name. File №2>\n"); break;
	case 3: if (ID == 6) return 0; else printf("Failed with <Score>\n"); break;							//Отчество может отсутствовать
	case 4: printf("Failed with <Git>\n"); break;
	case 5: printf("Failed with <Mail>\n"); break;
	case 6: printf("Failed with <Group>\n"); break;
	}
	return -1;
}

//Сохраняет ФИ+балл студента из первого файла в массив и проверяет дублирование
//Принимает строку из 2ого файла, указатель на массив студентов и номер след. студента
//Возвращает -1 в случае, если студент с таким ФИ уже был найден ранее (повтор), 0 - если все Ok
int SaveStudF1(char *string, StudentsF1 *StudFromFir, int num)
{
	char *Surname = strtok(string, ";,");
	char *Name = strtok(NULL, ";,");
	if (num>1)
		for (int i = 0; i<num; i++)
			if ((strcmp(Surname, StudFromFir[i].Surname) == 0) && (strcmp(Name, StudFromFir[i].Name) == 0))
				return -1;

	strcpy(StudFromFir[num].Surname, Surname);
	strcpy(StudFromFir[num].Name, Name);
	return 0;
}

//Сохраняет ФИ+балл студента из второго файла в массив и проверяет дублирование
//Принимает строку из 2ого файла, указатель на массив студентов и номер след. студента
//Возвращает -1 в случае, если студент с таким ФИ уже был найден ранее (повтор), 0 - если все Ok
int SaveStudF2(char *string, StudentsF2 *StudFromSec, int num)
{
	char *Surname = strtok(string, ";,");
	char *Name = strtok(NULL, ";,");
	char *Score = strtok(NULL, ";,");
	if (num>1)
		for (int i = 0; i<num; i++)
			if ((strcmp(Surname, StudFromSec[i].Surname) == 0) && (strcmp(Name, StudFromSec[i].Name) == 0))
				return -1;

	strcpy(StudFromSec[num].Surname, Surname);
	strcpy(StudFromSec[num].Name, Name);
	StudFromSec[num].Score = atoi(Score);
	return 0;
}

//Ищет студента из 2го файла в 1ом.
//Принимает указатель на первый файл и студента.
//Возвращает -2, если в файле несколько студентов с одним ФИ, -1, если студент не найден и балл студента, если всё Ok
int Search(StudentsF1 *StudFromFir, StudentsF2 StudFromSec, int NumOfStud)
{
	char StringFromFirst[200];
	int count = 0, score = 0;
	int i;
	for (i = 0; i < NumOfStud; i++)
	{
//		printf("%s!=%s %s!=%s\n", StudFromFir[i].Surname, StudFromSec.Surname, StudFromFir[i].Name, StudFromSec.Name);
		if (strcmp(StudFromFir[i].Surname, StudFromSec.Surname) == 0)
			{
				if (strcmp(StudFromFir[i].Name, StudFromSec.Name) == 0)
				{
					count++;
				}
			}
	}

	if (count > 1)
		return -2;
	else
		if (count == 1)
		{
			return StudFromSec.Score;
		}
		else
		{
			//printf("%s!=%s %s!=%s\n", StudFromFir[i].Surname, StudFromSec.Surname, StudFromFir[i].Name, StudFromSec.Name);
			return -1;
		}
}

//Проверяет валидность файлов - их существование, валидность строк, содержащихся в файлах; а также сохраняет студентов из 2ого файла
//Принимает указатели на файлы и на массив студентов
//Возвращает значение в зависимости от ошибки: -4 - считанный студент уже был найден ранее
// -7 - одинаковые студенты по 2ом, -6 - одинаковые студенты в 1ом, -5 - нет 2ого файла, -4 - нет 1ого файла, -3 - оба файла не существуют, -2 - строка в файле не корректна, -1 - кол-во строк в файлах различается
//Если ошибок нет, возвращает кол-во строк(студентов) в файле
int ValidOfFile(FILE *file1, FILE *file2, StudentsF1 *StudFromFir, StudentsF2 *StudFromSec)
{
	int i1 = 0, i2 = 0;
	if ((file1 == NULL) || (file2 == NULL))
	{
		if ((file1 == NULL) && (file2 == NULL))
			return -3;
		if (file1 == NULL)
		{
			return -4;
		}
		if (file2 == NULL)
		{
			return -5;
		}
	}

	char *string = (char *)malloc(200);
	while (!feof(file1))
	{
		fscanf(file1, "%s", string);
		if (string[0] != '\0')
		{
			if (ParametrOfError(ValidityOfString(string, 6), 6) == -1)   //Проверка строки из 1ого файла на валидность
			{
				return -2;
			}
			if (SaveStudF1(string, StudFromFir, i1) == -1)
				return -6;
			i1++;
			string[0] = '\0';
		}
	}
	while (!feof(file2))
	{
		fscanf(file2, "%s", string);
		if (string[0] != '\0')
		{
			if (ParametrOfError(ValidityOfString(string, 3), 3) == -1)   //Проверка строки из 2ого файла на валидность
			{
				return -2;
			}
			if (SaveStudF2(string, StudFromSec, i2) == -1)
				return -7;
			//printf("%s %s %d\n", StudFromSec[i2].Surname, StudFromSec[i2].Name, StudFromSec[i2].Score);
			i2++;
			string[0] = '\0';
		}
	}
	free(string);
	if (i1 == i2)
		return i1;
	return -1;
}

//Закрывает файлы и освобождет память
//Принимает указатели на файлы и на массив студентов
void BeforeEnd(StudentsF1 *StudFromFir, StudentsF2 *StudFromSec)
{
	free(StudFromFir);
	free(StudFromSec);
}

int main()
{
	setlocale(LC_ALL, "");

	FILE *input1, *input2;
	input1 = fopen("input_file_1.csv", "r");
	input2 = fopen("input_file_2.csv", "r");

	StudentsF1 *StudFromFir = (StudentsF1 *)calloc(MAX_NUM, sizeof(StudentsF1));
	StudentsF2 *StudFromSec = (StudentsF2 *)calloc(MAX_NUM, sizeof(StudentsF2));

	int Error = ValidOfFile(input1, input2, StudFromFir, StudFromSec);
		
	switch (Error)
	{
	case -1:												//Разное кол-во студентов в файлах
	{
		printf("Failed with <Different Numbers of Students>\n");
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -2:												//строка не корректна
	{
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -3:												//файлы не существуют
	{
		printf("input_file_1.csv doesn't exist\ninput_file_2.csv doesn't exist\n");
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -4:												//1ый файл не существует
	{
		printf("input_file_1.csv doesn't exist\n");
		fclose(input2);
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -5:												//2ой файл не существует
	{
		printf("input_file_2.csv doesn't exist\n");
		fclose(input1);
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -6:
	{
		printf("Failed with <One name for a few students. File №1>\n");
		BeforeEnd(input1, input2, StudFromSec);
		system("pause");
		return 0;
	}
	case -7:
	{
		printf("Failed with <One name for a few students. File №2>\n");
		BeforeEnd(input1, input2, StudFromSec);
		system("pause");
		return 0;
	}
	default: 
	{
		fclose(input1);
		fclose(input2);
		break;
	}
	}

	int NumOfStud = Error;

	int MaxScore = 0, count = 0;
	for (int i = 0; i<NumOfStud; i++)
	{
		int ScoreOfStud = Search(StudFromFir, StudFromSec[i], NumOfStud);            //Поиск студента из 2ого файла в 1ом
		
		if (ScoreOfStud == -1)														//Если возвращенное значение не балл студента - конец
		{
			printf("Failed with <Student isn't found>\n");
			BeforeEnd(StudFromFir, StudFromSec);
			system("pause");
			return 0;
		}

		if (ScoreOfStud > MaxScore)													//Сравнение балла студента с максимальным
		{
			MaxScore = ScoreOfStud;
			count = 1;
		}
		else if (ScoreOfStud == MaxScore)
			count++;
		fclose(input1);
	}

	printf("Max=%d, Count=%d\n", MaxScore, count);
	BeforeEnd(StudFromFir, StudFromSec);
	system("pause");
	return 0;
}