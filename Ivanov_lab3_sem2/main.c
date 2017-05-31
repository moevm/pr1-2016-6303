//PR_6303 Иванов Дмитрий Владимирович
//Лабораторная работа 3
//Файл main.c, содержащий код программы.

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define INCLUDE_STR_LEN 8
#define MAX_STR_LEN 50

typedef struct Files
{
	char name[255];     //Имя файла
	char *way;          //Полный путь подключения до файла
	int sizeWay;        //Размер полного пути
}Files;


char findFiles(Files *FoundFiles, char *way, int *sizeOfWay, int *countFiles, int *sizeFilesArr);

int main()
{
	int sizeOfWay = 50;
	int countFiles = 0;
	int sizeFilesArr = 10;
	Files *FoundFiles = (Files *)malloc(sizeof(Files)*sizeFilesArr);
	strcpy(FoundFiles[countFiles].name, "file.txt");
	FoundFiles[countFiles].sizeWay = MAX_STR_LEN;
	FoundFiles[countFiles].way = (char *)calloc(MAX_STR_LEN, sizeof(char));
	char *way = (char *)malloc(MAX_STR_LEN);
	strcat(way, "./");
	DIR *dir;
	dir = opendir(way);
	if (!dir)
	{
		printf("Dir on this way %s doesn't root\n", way);
		return 0;
	}
	struct dirent *entry;
	do {
		if (findFiles(FoundFiles, way, &sizeOfWay, &countFiles, &sizeFilesArr))
		{
			printf("Way to minotaur: \n%s", FoundFiles[countFiles - 1].way);
			break;
		}
	} while (countFiles>0);
	closedir(dir);
	int i;
	for (i = 0; i < countFiles; i++)
		free(FoundFiles[i].way);
	free(FoundFiles);
	free(way);
	return 0;
}

char findFiles(Files *FoundFiles, char *way, int *sizeOfWay, int *countFiles, int *sizeFilesArr)
{
	int wayLen = strlen(way);
	DIR *dir;
	if (wayLen > ((*sizeOfWay) - 10))
	{
		(*sizeOfWay) += 100;										//расширение допустимой длины пути
		way = (char*)realloc(way, sizeof(char)*(*sizeOfWay));
	}
	struct dirent *entry;
	dir = opendir(way);											//открытие директории
	int i;
	while (entry = readdir(dir))								//просмотр директории
	{
		for (i = 0; i<*countFiles + 1; i++)                     //Поиск уже подключенных файлов
		{
			if (!strcmp(entry->d_name, FoundFiles[i].name))
			{
				//Найден подключенный ранее файл => нужно записать путь до него в полный путь его подключения
				strcat(way, entry->d_name);
				FILE * file = fopen(way, "r");                  //открытие файла
				char bufStr[MAX_STR_LEN];
				int sumLen = strlen(way) + strlen(FoundFiles[i].way);   //длина строки полного пути подключения после добавления пути до файла
				if (sumLen > FoundFiles[i].sizeWay)
				{
					FoundFiles[i].sizeWay = sumLen + 100;       //увеличение длины строки полного пути подключения
					FoundFiles[i].way = (char *)realloc(FoundFiles[i].way, sizeof(char)*FoundFiles[i].sizeWay);
				}
				strcat(FoundFiles[i].way, way);		//добавление в полный путь подключения файла фактический путь до этого файла
				strcat(FoundFiles[i].way, "\n");
				while (fgets(bufStr, 101, file))
				{
					if (strstr(bufStr, "@include "))
					{
						(*countFiles)++;
						if (*countFiles > *sizeFilesArr - 2)
						{
							sizeFilesArr += 10;															//увеличение допустимого кол-ва файлов
							FoundFiles = (Files *)realloc(FoundFiles, sizeof(Files)*(*sizeFilesArr));
						}
						if (strchr(bufStr, '\n'))
							bufStr[strlen(bufStr) - 2] = '\0';
						strcpy(FoundFiles[*countFiles].name, &bufStr[INCLUDE_STR_LEN + 1]);             //Добавление нового подключенного файла
						FoundFiles[*countFiles].sizeWay = MAX_STR_LEN;
						if (FoundFiles[i].sizeWay > FoundFiles[*countFiles].sizeWay)
						{
							FoundFiles[*countFiles].sizeWay = FoundFiles[i].sizeWay + 100;
							FoundFiles[*countFiles].way = (char *)realloc(FoundFiles[*countFiles].way, sizeof(char)*FoundFiles[*countFiles].sizeWay);
						}
						FoundFiles[*countFiles].way = (char *)calloc(6 * FoundFiles[*countFiles].sizeWay, sizeof(char));
						strcat(FoundFiles[*countFiles].way, FoundFiles[i].way);		//добавление в полный путь подключения нового файла полного пути "материнского" файла
					}
					if (!strcmp(bufStr, "Minotaur"))
					{
						closedir(dir);
						fclose(file);           //если найден файл-Минотавр - конец работы
						return 1;
					}
				}
				way[wayLen] = '\0';
				fclose(file);
				free(FoundFiles[i].way);
				FoundFiles[i] = FoundFiles[*countFiles];
				(*countFiles)--;
			}

		}
		if (!strchr(entry->d_name, '.'))        //если в имени есть "." - это файл (или текущая директория ".", или предыдущая "..") и вызывать фукнцию для поиска файлов не требуется
		{
			strcat(way, entry->d_name);
			strcat(way, "/");
			if (findFiles(FoundFiles, way, sizeOfWay, countFiles, sizeFilesArr))
			{
				closedir(dir);
				return 1;
			}
			way[wayLen] = '\0';
		}
	}
	closedir(dir);
	return 0;
}
