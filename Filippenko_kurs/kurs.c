#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct First
{
	int **array;
	int m;
	int n;
}First;

typedef struct Second
{
	int **array;
	int m;
	int n;
}Second;

void multiplication(First , Second );

int main()
{
	FILE *f = fopen("1.txt", "r"); //открываем файл на чтение
	
	char *string = (char *)malloc(51);
	char *element = (char *)malloc(5);

	First FirstMatrix;
	Second SecondMatrix;
	
	int temp_m = 0; //m - столбцы, n - строки
	int n1 = 0, n2 = 0, m1 = 0, m2 = 0, log1 = 0, log2 = 0;
	int i;
	
	FirstMatrix.array=(int **)malloc(20*sizeof(int *));
	
	for (i = 0; i < 20; ++i)
	{ 
		(FirstMatrix.array)[i] = (int *)malloc(20*sizeof(int));
	}

	SecondMatrix.array=(int **)malloc(20*sizeof(int *));
	for (i = 0; i < 20; ++i)
	{ 
		(SecondMatrix.array)[i] = (int *)malloc(20*sizeof(int));
	}

	fgets(string, 50, f);
	
	while((strstr(string, "\n")-string)>=1)//проверка на то, пустая(только \n) ли строка
	{
		element = strtok(string," \n");	//разбиваем на строки по пробелам
		while(element)
		{
			(FirstMatrix.array)[n1][m1] = atoi(element); //переводим в число и записываем в массив
			m1++;																				 //увеличиваем количество столбцов
			element = strtok(NULL, " \n");
		}
		if (n1 == 0)			//первая строка
			temp_m = m1;  		//запись размера первой строки
		if ( (temp_m - m1) != 0 )	//проверка на размер
			log1++;									//если размер этой строки не  равен размеру первой увеличиваем итератор
		m1=0;										//обнуляем количество элементнов в строке
		n1++;										//увеличиваем количество строк
		fgets(string, 50, f);						//считываем следующую строку
	}

	if (log1)
		printf("Fail with first matrix\n"); //если итератор не равен нулю, значит где-то строка <> первой => ошибка
	m1=temp_m;

	fgets(string, 50, f); //считываем две пустые строки
	fgets(string, 50, f);

	while((strstr(string, "\n")-string)>=1)		//все аналогично первой
	{
		element = strtok(string," \n");

		while(element)
		{
			(SecondMatrix.array)[n2][m2] = atoi(element);
			m2++;
			element = strtok(NULL, " \n");
		}

		if (n2 == 0) 
			temp_m = m2;
		if ( (temp_m - m2) != 0 )
			log2++;
		m2=0;
		n2++;
		fgets(string, 50, f);
	}

	if (log2)
		printf("Fail with second matrix\n");
	m2=temp_m;

	fclose(f); //закрываем файл
	//записываем размеры матриц в структуры
	FirstMatrix.n=m1;
	FirstMatrix.m=n1;
	SecondMatrix.n=m2;
	SecondMatrix.m=n2;
	
	if ( (m1 == n2) && log1 == 0 && log2 == 0 ) 
		multiplication(FirstMatrix, SecondMatrix);
	else
		printf("Multiplication impossible\n");

	for (i = 0; i < 20; ++i)
	{ 
		free(SecondMatrix.array)[i]);
	}

	free(SecondMatrix.array);

	for (i = 0; i < 20; ++i)
	{ 
		free(FirstMatrix.array)[i]));
	}

free(FirstMatrix.array);

	return 0;
}

void multiplication(First FirstMatrix, Second SecondMatrix)
{
	FILE *result = fopen("result.txt", "w"); //открываем файл на запись
	
	int m = FirstMatrix.m;	//присвоение размеров
	int n = SecondMatrix.n;
	int k_max=FirstMatrix.n;
	int i,j,k;

	int **n_array = (int **)malloc(m*sizeof(int *)); //выделение памяти
	
	for(i=0; i < m; i++)
	{ 
		n_array[i] = (int *)malloc(n*sizeof(int));
	}

	for (i=0; i < m; i++)
	{
		for (j=0; j < n; j++)
		{
			int sum=0;
			for (k=0; k < k_max; k++)
				sum += (FirstMatrix.array)[i][k]*(SecondMatrix.array)[k][j]; //запись в новый массив(сразу в файл)
			fprintf(result, "%d ", sum);
		}

		fprintf(result,"\n");
	}
	fclose(result);	//закрываем файл
}