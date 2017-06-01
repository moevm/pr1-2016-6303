#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITTOBYTE 8								//для перевода бит в байты
#define WORD 4									//для выравнивания
#define FAILX0 1
#define FAILY0 2
#define FAILX1 3
#define FAILY1 4
#define FAILWRITE 5

typedef union BMP_HEADER						//заголовок BMP-файла
{
	char data[14];
	struct
	{
		unsigned short signature;
		unsigned int size;
		unsigned int reserved;
		unsigned int offset;
	}hdr;
}BMP_HEADER;

typedef union BMP_INFO							//информации о BMP-файле
{
	char data1[40];
	struct
	{
		unsigned int structSize;
		unsigned int width;
		unsigned short height;
		unsigned short following;
		unsigned short planes;
		unsigned short count;
		unsigned int compression;
		char asd[28];
	}info;
}BMP_INFO;

typedef struct File  							//указатель на файл и координаты вершин отражения
{
	FILE *oldf;
	int x0;
	int y0;
	int x1;
	int y1;
}File;

typedef struct StructOfDimensions				//вспомогательная структура
{
	int width;
	int height;
	int size_string;
}StructOfDimensions;

int newFile(File , BMP_HEADER, BMP_INFO);
char *reflection(char *, int, int);

int main()
{
	File f;
	f.oldf = NULL;
	BMP_HEADER header;
	BMP_INFO information;
	char *str = (char *)malloc(200);					//выделение памяти под чтение потока ввода
	char input_file[50];								//выделение памяти под название файла
	int x0=-1, x1=-1, y0=-1, y1=-1;

	fgets(str, 200, stdin);
	strcpy(input_file, strtok(str, " "));				//разбиение потока ввода на название файла и координаты вершин
	f.x0 = atoi(strtok(NULL, " "));
	f.y0 = atoi(strtok(NULL, " "));
	f.x1 = atoi(strtok(NULL, " "));
	f.y1 = atoi(strtok(NULL, " "));
	f.oldf = fopen(input_file, "rb");					//открытие бинарного файла на чтение
	if (f.oldf == NULL) 								//проверка на то, открылся ли файл
		printf("Fail with input_file\n");
	else
	{
	 if (f.x0 > 0)
		{
			if (f.y0 > 0)
			{
			if (f.x1 > 0 && f.x1>f.x0)
			{
				if (f.y1 > 0 && f.y1>f.y0)
				{
					int log = 0;
					log = newFile(f, header, information);
					if ( log == FAILX0 ) printf("Fail with x0\n");
					if ( log == FAILY0 ) printf("Fail with y0\n");
					if ( log == FAILX1 ) printf("Fail with x1\n");
					if ( log == FAILY1 ) printf("Fail with y1\n");
					if ( log == FAILWRITE) printf("Fail with write file\n");
					fclose(f.oldf);
				}
				else
				printf("Fail with y1\n");
			}
			else
				printf("Fail with x1\n");
			}
		 else
			printf("Fail with y0\n");
		}
		else
		printf("Fail with x0\n");
	}
	free(str);
	return 0;
}

int newFile(File f, BMP_HEADER header, BMP_INFO information)
{
	StructOfDimensions Dimensions;
	fread(header.data, sizeof(char), sizeof(header.data), f.oldf);					//чтение заголовка BMP-файла
	fread(information.data1, sizeof(char), sizeof(information.data1), f.oldf);		//чтение информации о BMP-файле
	Dimensions.width = information.info.width;
	Dimensions.height = information.info.height;
	int count = information.info.count/BITTOBYTE;									//колчиество байт на 1 пиксель
	int trash = Dimensions.width*count % WORD;										//количество байт, необходимых для выравнивания
	Dimensions.size_string = Dimensions.width*count;																								//длина строки с учетом выравнивания
	if ( trash ) Dimensions.size_string += (4-trash);
	if (f.x0 > Dimensions.width) return FAILX0;
	if (f.y0 > Dimensions.height) return FAILY0;
	if (f.x1 > Dimensions.width) return FAILX1;
	if (f.y1 > Dimensions.height) return FAILY1;

	FILE *newf = fopen("new.bmp", "w");											//открытие бинарного файла на запись
	if (newf == NULL) return FAILWRITE;
	else
	{
		fwrite(header.data, sizeof(char), sizeof(header.data), newf);					//запись заголовка в новый BMP-файл
		fwrite(information.data1, sizeof(char), sizeof(information.data1), newf);		//запись информации в новый BMP-файл
		char *string = (char *)malloc(Dimensions.size_string);

		for (int i=0; i<Dimensions.height; i++)
		{
			fread(string, sizeof(char), Dimensions.size_string, f.oldf);				//чтение строки файла
			if ( (Dimensions.height-i)>=f.y0 && (Dimensions.height-i)<=f.y1 )			//проверка на входение в указанную область
				string = reflection(string, f.x0, f.x1);								//вызов функции отражения
			fwrite(string, sizeof(char), Dimensions.size_string, newf);					//запись строки в новый файл
		}
		free(string);																	//очищение памяти
		fclose(newf);
	}
	return 0;
}

char *reflection(char *string, int x0, int x1)
{
	char *temp = (char *)malloc(3);													//массив на один пиксель для временного хранения 
	for(int i=0; i < (x1-x0+1)/2; i++)												//отражение относительно оси симметрии
	{
		int j = x0+i-1;
		int k = x1-(i+1);
		temp[0] = string[3*j];
		temp[1] = string[3*j+1];
		temp[2] = string[3*j+2];
		string[3*j] = string[3*k];
		string[3*j+1] = string[3*k+1];
		string[3*j+2] = string[3*k+2];
		string[3*k] = temp[0];
		string[3*k+1] = temp[1];
		string[3*k+2] = temp[2];
	}
	free(temp);
	return string;
}


/*113-117  printf("BMP_HEADER size = %ld\n", sizeof(BMP_HEADER));
	printf("[signature = %u, size = %u, reserv = %u, offset = %u]\n",header.hdr.signature,header.hdr.size, header.hdr.reserved,header.hdr.offset);
	printf("[struct size = %u, width =  %u, height = %u, following = %u, count = %u, compression = %u]\n",information.info.structSize,information.info.width,
							information.info.height, information.info.following,(information.info.count/BITTOBYTE),information.info.compression);*/
//133			printf("width = %d, height = %d, size = %d\n", Dimensions.width, Dimensions.height, Dimensions.size_string);
//155			printf("iteration = %d, j = %d, k = %d\n", i, j, k);
//156			printf("[j] %x %x %x\n", string[3*j], string[3*j+1], string[3*j+2]);
//157			printf("[k] %x %x %x\n", string[3*k], string[3*k+1], string[3*k+2]);
//161			printf("temp = %x %x %x\n", temp[0], temp[1], temp[2]);
//169			printf("[j_new] %x %x %x\n", string[3*j], string[3*j+1], string[3*j+2]);
//170			printf("[k_new] %x %x %x\n", string[3*k], string[3*k+1], string[3*k+2]);