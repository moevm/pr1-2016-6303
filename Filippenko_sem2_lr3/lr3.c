#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define SIZE 20

typedef struct Path //объявляем структуру, в которую будем записывать пути до файлов
{
	char** array;
	int count;
}Path;

int findMinotaur(const char *, char *, Path *); //функция поиска минотавра
void print(Path ); //функция вывода пути к минотавру
 
int main(int c, char **v, char **env )
{
	Path Pt;
	Pt.array = (char **)malloc(SIZE*sizeof(char *));
	for (int i = 0; i < SIZE; ++i)
    {
	    (Pt.array)[i] = (char*)malloc(1000*sizeof(char));
    }

	Pt.count = 0;

	if(c==2)
	{
		findMinotaur(v[1], "file.txt", &Pt);
	} 
    
        else
        {
            findMinotaur(".","file.txt", &Pt);
        }
	print(Pt);
	return 0;
}

int findMinotaur(const char *startdir, char *filename, Path *Pt) //на вход подается корневая директория, указатель на название файла, который требуется найти и указатель на структуру
{
	int log = 0; //логическая переменная
	char current_path[1000];
	strcpy(current_path,startdir); //копируем стартовую директорию в строку
 
	DIR *dir = opendir(current_path); //открываем директорию
	struct  dirent *de = readdir(dir); //создаем структру, считываем директорию
 
	if(dir && !log) //если директория не пуста
		while(de)
		{ 
		 if( de->d_type == DT_DIR && 
			 0!=strcmp(".",de->d_name) && 0!=strcmp("..",de->d_name)) //определяем, является ли папкой, при этом не текущей и не вышестоящей
			{ 
				int path_len = strlen(current_path);
				strcat(strcat(current_path,"/"),de->d_name); //записываем в конец текущего пути / и имя папки
				log += findMinotaur(current_path, filename, Pt); 
				current_path[path_len] = '\0';
			}

			if (de->d_type == DT_REG && !strcmp(de->d_name, filename)) //проверяем, является ли файлом, и сравнием названия файлов
			{
				strcat(strcat(current_path,"/"),de->d_name);//записываем в конец текущего пути / и имя файла
				FILE *f = fopen(current_path, "r");//открываем файл на чтение
				char *str = (char *)malloc(51);
				fgets(str, 50, f);
				if (strstr(str, "Minotaur")) //определяем, является ли содержимое файла минотавром
				{
					strcpy((Pt->array)[Pt->count], current_path); //копируем путь к нему
					Pt->count++;

					return 1;
				}
				else
				{
					if (strstr(str, "Deadlock")) //если тупик
					{
						if (Pt->count) Pt->count--;
						return 0;
					}
					else
					{
						while(strstr(str, "\n")>0) //пока не дойдем до пустой строки
						{
							strcpy((Pt->array)[Pt->count], current_path);
							Pt->count++;
							char *obj = strtok(str," \n");
							obj = strtok(NULL, " \n"); //разбиваем содержимое строки 
							log += findMinotaur(".", obj, Pt); //ищем минотавра	
							if (!log) //если его не оказалось
								{
									fgets(str, 50, f); //считываем следующую строку файла
								}
							else 
							return 1;
						}
					}		
				}
			}
			de = readdir(dir);
		}
	closedir(dir);//закрываем директорию
	return log;
}

void print(Path Pt)
{
	for(int i=0; i<Pt.count; i++)
	{
		printf("%s\n", (Pt.array)[i]); //выводим путь
	}
}