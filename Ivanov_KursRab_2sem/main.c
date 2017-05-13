//Иванов Дмитрий Владимирович. Группа 6303
//Код Курсовой работы

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_NUM 1000

typedef struct Students
{
    char Surname[30];
    char Name[30];
    int Score;
} Students;

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
			if ((score == 0) && (strcmp(tmp,"0")!=0))
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
	case 1: if (ID == 6) printf("Failed with <Surname. File 1>\n"); else printf("Failed with <Surname. File 2>\n"); break;
	case 2: if (ID == 6) printf("Failed with <Name. File 1>\n"); else printf("Failed with <Name. File 2>\n"); break;
	case 3: if (ID == 6) return 0; else printf("Failed with <Score>\n"); break;
	case 4: printf("Failed with <Git>\n"); break;
	case 5: printf("Failed with <Mail>\n"); break;
	case 6: printf("Failed with <Group>\n"); break;
	}
	return -1;
}

//Сохраняет ФИ+балл студента в массив и проверяет дублирование
//Принимает строку из 2ого файла, указатель на массив студентов и номер след. студента
//Возвращает -1 в случае, если студент с таким ФИ уже был найден ранее (повтор), 0 - если все Ok
int SaveStud (char *string, Students *StudFromSec, int num)
{
    char *Surname = strtok(string, ";,");
	char *Name = strtok(NULL, ";,");
	char *Score = strtok(NULL, ";,");
	int i;
	if (num>1)
		for (i=0; i<num; i++)
			if ((strcmp(Surname, StudFromSec[i].Surname) == 0) && (strcmp(Name, StudFromSec[i].Name) == 0))
				return -1;

	strcpy(StudFromSec[num].Surname, Surname);
	strcpy(StudFromSec[num].Name, Name);
	StudFromSec[num].Score =atoi(Score);
	return 0;
}

//Ищет студента из 2го файла в 1ом.
//Принимает указатель на первый файл и студента.
//Возвращает -2, если в файле несколько студентов с одним ФИ, -1, если студент не найден и балл студента, если всё Ok
int Search(FILE *In1, Students StudFromSec)
{
	char StringFromFirst[200];
	int count = 0, score=0;

	while (!feof(In1))
	{
		fscanf(In1, "%s", StringFromFirst);
		if (StringFromFirst[0] != '\0')
		{
			char *Surname1 = strtok(StringFromFirst, ";,\n");
			if (strcmp(Surname1, StudFromSec.Surname) == 0)
			{
				char *Name1 = strtok(NULL, ";,\n");
				if (strcmp(Name1, StudFromSec.Name) == 0)
				{
					count++;
				}
			}
		}
		StringFromFirst[0] = '\0';
	}
	if (count > 1)
		return -2;
	else
		if (count == 1)
	        {
	            return StudFromSec.Score;
	        }
		else return -1;
}

//Проверяет валидность файлов - их существование, валидность строк, содержащихся в файлах; а также сохраняет студентов из 2ого файла
//Принимает указатели на файлы и на массив студентов
//Возвращает значение в зависимости от ошибки: -4 - считанный студент уже был найден ранее
//-3 - файл не существует, -2 - строка в файле не корректна, -1 - кол-во строк в файлах различается
//Если ошибок нет, возвращает кол-во строк(студентов) в файле
int ValidOfFile(FILE *file1, FILE *file2, Students *StudFromSec)
{
	int i1 = 0, i2 = 0;
	if ((file1 == NULL)||(file2 == NULL))
	{
		if (file1 == NULL)
        		printf("input_file_1.csv doesn't exist\n");
		if (file2 == NULL)
		        printf("input_file_2.csv doesn't exist\n");
		return -3;
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
			if (SaveStud(string, StudFromSec, i2)==-1)
		                return -4;
			i2++;
			string[0] = '\0';
		}
	}
	fclose(file1);
	fclose(file2);
	free(string);
	if (i1 == i2)
		return i1;
	return -1;
}

void BeforeEnd(FILE *file1, FILE *file2, Students *StudFromSec)
{
	fclose(file1);
	fclose(file2);
	free(StudFromSec);
}

int main()
{
	setlocale(LC_ALL, "");

	FILE *input1, *input2;
	input1 = fopen("input_file_1.csv", "r");
	input2 = fopen("input_file_2.csv", "r");

	Students *StudFromSec = (Students *)calloc(MAX_NUM, sizeof(Students));

	int Error = ValidOfFile(input1, input2, StudFromSec);

	switch(Error)
	{
	case -1:
	{
        	printf("Failed with <Different Numbers of Students>\n");
		BeforeEnd(input1, input2, StudFromSec);
	        return 0;
        }
	case -4:
        {
        	printf("Failed with <One name for a few students. File 2>\n");
		BeforeEnd(input1, input2, StudFromSec);
	        return 0;
        }
	case -2:
	case -3:
        {
            return 0;
        }
	default: break;
	}

	int NumOfStud = Error;
	input2 = fopen("input_file_2.csv", "r");

	int MaxScore = 0, count = 0;
	int i;
	for(i=0; i<NumOfStud; i++)
	{
		input1 = fopen("input_file_1.csv", "r");
		int ScoreOfStud = Search(input1, StudFromSec[i]);                    //Поиск студента из 2ого файла в 1ом
		switch (ScoreOfStud)                                                //Если возвращенное значение не балл студента - конец
		{
			case -1:
			{
				printf("Failed with <Student isn't found>\n");
				BeforeEnd(input1, input2, StudFromSec);
				return 0;
			}
			case -2:
			{
				printf("Failed with <One name for a few students. File 1>\n");
				BeforeEnd(input1, input2, StudFromSec);
				return 0;
			}
			case -3:
			{
				BeforeEnd(input1, input2, StudFromSec);
				return 0;
			}
		}
		if (ScoreOfStud > MaxScore)
		{
			MaxScore = ScoreOfStud;
			count = 1;
		}
		else if (ScoreOfStud == MaxScore)
			count++;
		fclose(input1);
	}

	printf("%d\n", count);
	fclose(input2);
	free(StudFromSec);
	return 0;
}
