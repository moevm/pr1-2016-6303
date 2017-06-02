#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define LENGTH 30

/*1 - surname
2 - name
3 - middle name
4 - email
5 - git account
6 - group*/
typedef struct Student
{
	char data[6][LENGTH];
}Student;

typedef struct Mark
{
	char data[2][LENGTH];
	int mark;
	int inUse;
}Mark;

char* getParameter(char** strptr);
void printError(int number, int file);
int checkForTheSame(Student* student, int nubmerOfStudents);


int main()
{
	setlocale(LC_ALL, "RUS");

	//Read files and checking them for emptiness
	FILE *file1 = fopen("input_file_1.csv", "r");
	if (!file1)
	{
		printf("Fail with first file(doesn`t exists)\n");
		return 0;
	}
	fseek(file1, 0, SEEK_END);
	int sizeofFile1 = ftell(file1);
	if (sizeofFile1 <= 2)
	{
		printf("Fail with first file(empty file)\n");
		fclose(file1);
		return 0;
	}
	char *table1 = (char*)calloc(sizeofFile1, sizeof(char));
	rewind(file1);
	fread(table1, sizeof(char), sizeofFile1, file1);
	fclose(file1);

	FILE *file2 = fopen("input_file_2.csv", "r");
	if (!file2)
	{
		printf("Fail with second file(doesn`t exists)\n");
		return 0;
	}
	fseek(file2, 0, SEEK_END);
	int sizeofFile2 = ftell(file2);
	if (sizeofFile2 <= 2)
	{
		printf("Fail with second file(empty file)\n");
		fclose(file2);
		return 0;
	}
	char *table2 = (char*)calloc(sizeofFile2, sizeof(char));
	rewind(file2);
	fread(table2, sizeof(char), sizeofFile2, file2);
	fclose(file2);

	//Get information from input_file_1
	int i, j;
	int numberOfStudentsFile1 = 0;
	int arrayLength = 10;
	int index = 0;
	char* buffer;
	Student * student = (Student*)malloc(arrayLength * sizeof(Student));
	char* string = strtok(table1, "\n");
	while (string)
	{
		numberOfStudentsFile1++;
		if (numberOfStudentsFile1 == (arrayLength + 1))
		{
			arrayLength += 10;
			student = (Student*)realloc(student, sizeof(Student)* arrayLength);
		}
		for (i = 0; i < 6; i++)
		{
			buffer = getParameter(&string);
			strcpy(student[index].data[i], buffer);
			if (!strcmp(buffer, ""))
			{
				printError(i, 1);
				free(student);
				return 0;
			}
		}
		index++;
		string = strtok(NULL, "\n");
	}
	free(table1);

	//Check for the repetitions
	if (checkForTheSame(student, numberOfStudentsFile1))
	{
		printf("Fail with the same students\n");
		free(student);
		return 0;
	}

	//Get information from input_file_2
	arrayLength = numberOfStudentsFile1;
	index = 0;
	Mark * marks = (Mark*)malloc(sizeof(Mark) * arrayLength);
	string = strtok(table2, "\n");
	int numberOfStudentsFile2 = 0;
	while (string)
	{
		numberOfStudentsFile2++;
		if (numberOfStudentsFile2 == (arrayLength + 1))
		{
			arrayLength += 10;
			marks = (Mark*)realloc(marks, sizeof(Mark)* arrayLength);
		}
		for (i = 0; i < 2; i++)
		{
			buffer = getParameter(&string);
			strcpy(marks[index].data[i], buffer);
			if (!strcmp(buffer, ""))
			{
				printError(i, 2);
				free(marks);
				free(student);
				return 0;
			}
		}
		buffer = getParameter(&string);
		marks[index].mark = atoi(buffer);
		marks[index].inUse = 0;
		string = strtok(NULL, "\n");
		index++;
	}
	free(table2);

	//If number of students isn`t eual in tables, print error 
	if (numberOfStudentsFile1 != numberOfStudentsFile2)
	{
		printf("Fail with number of students in files\n");
		free(marks);
		free(student);
		return 0;
	}

	//Compare students in tables
	int correct;
	for (i = 0; i < numberOfStudentsFile1; i++)
	{
		correct = 0;
		for (j = 0; j < numberOfStudentsFile1; j++)
		{
			if (!strcmp(student[i].data[0], marks[j].data[0]) && !strcmp(student[i].data[1], marks[j].data[1]))
			{
				if (!marks[j].inUse)
				{
					marks[j].inUse = 1;
					correct = 1;
				}
			}
		}
		if (!correct)
		{
			printf("Fail with students(different students in files)\n");
			free(marks);
			free(student);
			return 0;
		}
	}

	//Find maximal mark and count how many students got less than 60% of maximal mark
	int max = marks[0].mark;
	for (i = 1; i < numberOfStudentsFile1; i++)
	{
		if (marks[i].mark > max)
			max = marks[i].mark;
	}
	double sixtyPer = max*(0.6);
	int count = 0;
	for (i = 0; i < numberOfStudentsFile1; i++)
		if (marks[i].mark < sixtyPer)
		{
			marks[i].inUse = 2;
			count++;
		}
	printf("%d\n", count);
	free(student);
	free(marks);
	return 0;
}


char* getParameter(char** strptr)
{
	char* startPtr = *strptr;
	int i = 0;
	while (((*strptr)[i] != ';') && ((*strptr)[i] != '\0'))
		i++;
	(*strptr)[i] = '\0';
	(*strptr) += (strlen(startPtr) + 1);
	return startPtr;
}

//Students can have the same names, surname, middle names and groups, but can`t have the same mails and git accounts
int checkForTheSame(Student* student, int nubmerOfStudents)
{
	int i, j;
	for (i = 0; i < (nubmerOfStudents - 1); i++)
		for (j = (i + 1); j < nubmerOfStudents; j++)
			if (!strcmp(student[i].data[3], student[j].data[3]) && !strcmp(student[i].data[4], student[j].data[4]))
				return 1;
	return 0;
}


void printError(int number, int file)
{
	switch (number)
	{
	case 0:printf("Fail with Surname"); break;
	case 1:printf("Fail with Name"); break;
	case 2:printf("Fail with Middle name"); break;
	case 3:printf("Fail with Git account"); break;
	case 4:printf("Fail with Email"); break;
	case 5:printf("Fail with Group"); break;
	}
	printf("(File %d)\n", file);
}