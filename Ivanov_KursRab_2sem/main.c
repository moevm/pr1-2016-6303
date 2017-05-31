/*

��� ��������, �� ����������� ����������:
+ � ����� �� ������ ������ ���������, ��� �� ������                                     - ������� ���-�� �����
+ ����������: � 1�� - �������/���/��������/���/����/������, �� 2�� - �������/���/����!  - ��������� ���������
+ �������� �� 2��� ��� � 1�� (� ������ ����������� ���-�� ��������� � ������)           - ����� �� ������� � ������
+ ������ ������ �������� ����� ���� ���-������� � 1��(+), �� 2��(+)                     - ������� ���-�� ���������� ��/�������� ������� ���
+ � ���� ���� �� ����																	- �����-������� �� ���� ��� atoi

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

//��������� ���������� ������.
//��������� ������ � ID �����, �� �������� ���� ������� ������. ������ ���� ID=6, ������ - ID=3
//���������� ��� ������.
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

//���������� ��� ��������� ������ � �������� ���������.
//��������� ��� ������ � ID �����, �� �������� ���� ������� ������
//���������� 0, ���� ������ ���, 1 - ���� ������ ����
int ParametrOfError(int ErrorCode, int ID)
{
	switch (ErrorCode)
	{
	case 0: return 0;
	case 1: if (ID == 6) printf("Failed with <Surname. File �1>\n"); else printf("Failed with <Surname. File �2>\n"); break;
	case 2: if (ID == 6) printf("Failed with <Name. File �1>\n"); else printf("Failed with <Name. File �2>\n"); break;
	case 3: if (ID == 6) return 0; else printf("Failed with <Score>\n"); break;							//�������� ����� �������������
	case 4: printf("Failed with <Git>\n"); break;
	case 5: printf("Failed with <Mail>\n"); break;
	case 6: printf("Failed with <Group>\n"); break;
	}
	return -1;
}

//��������� ��+���� �������� �� ������� ����� � ������ � ��������� ������������
//��������� ������ �� 2��� �����, ��������� �� ������ ��������� � ����� ����. ��������
//���������� -1 � ������, ���� ������� � ����� �� ��� ��� ������ ����� (������), 0 - ���� ��� Ok
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

//��������� ��+���� �������� �� ������� ����� � ������ � ��������� ������������
//��������� ������ �� 2��� �����, ��������� �� ������ ��������� � ����� ����. ��������
//���������� -1 � ������, ���� ������� � ����� �� ��� ��� ������ ����� (������), 0 - ���� ��� Ok
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

//���� �������� �� 2�� ����� � 1��.
//��������� ��������� �� ������ ���� � ��������.
//���������� -2, ���� � ����� ��������� ��������� � ����� ��, -1, ���� ������� �� ������ � ���� ��������, ���� �� Ok
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

//��������� ���������� ������ - �� �������������, ���������� �����, ������������ � ������; � ����� ��������� ��������� �� 2��� �����
//��������� ��������� �� ����� � �� ������ ���������
//���������� �������� � ����������� �� ������: -4 - ��������� ������� ��� ��� ������ �����
// -7 - ���������� �������� �� 2��, -6 - ���������� �������� � 1��, -5 - ��� 2��� �����, -4 - ��� 1��� �����, -3 - ��� ����� �� ����������, -2 - ������ � ����� �� ���������, -1 - ���-�� ����� � ������ �����������
//���� ������ ���, ���������� ���-�� �����(���������) � �����
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
			if (ParametrOfError(ValidityOfString(string, 6), 6) == -1)   //�������� ������ �� 1��� ����� �� ����������
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
			if (ParametrOfError(ValidityOfString(string, 3), 3) == -1)   //�������� ������ �� 2��� ����� �� ����������
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

//��������� ����� � ���������� ������
//��������� ��������� �� ����� � �� ������ ���������
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
	case -1:												//������ ���-�� ��������� � ������
	{
		printf("Failed with <Different Numbers of Students>\n");
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -2:												//������ �� ���������
	{
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -3:												//����� �� ����������
	{
		printf("input_file_1.csv doesn't exist\ninput_file_2.csv doesn't exist\n");
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -4:												//1�� ���� �� ����������
	{
		printf("input_file_1.csv doesn't exist\n");
		fclose(input2);
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -5:												//2�� ���� �� ����������
	{
		printf("input_file_2.csv doesn't exist\n");
		fclose(input1);
		BeforeEnd(StudFromFir, StudFromSec);
		system("pause");
		return 0;
	}
	case -6:
	{
		printf("Failed with <One name for a few students. File �1>\n");
		BeforeEnd(input1, input2, StudFromSec);
		system("pause");
		return 0;
	}
	case -7:
	{
		printf("Failed with <One name for a few students. File �2>\n");
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
		int ScoreOfStud = Search(StudFromFir, StudFromSec[i], NumOfStud);            //����� �������� �� 2��� ����� � 1��
		
		if (ScoreOfStud == -1)														//���� ������������ �������� �� ���� �������� - �����
		{
			printf("Failed with <Student isn't found>\n");
			BeforeEnd(StudFromFir, StudFromSec);
			system("pause");
			return 0;
		}

		if (ScoreOfStud > MaxScore)													//��������� ����� �������� � ������������
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