#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

int nextDir (char ** banList, char * way, char letter, int * sizeOfWay, int * sizeOfBanList)
{
	int wayLen = strlen(way);
	DIR *dir;
	struct dirent *entry;
	dir = opendir(way);
	while (entry = readdir(dir))
  {
    if(strstr(entry->d_name, ".txt"))
    {
      char * buf = &entry->d_name[strlen(entry->d_name)-4];
      if(!strcmp(buf, ".txt"))
				if(letter == entry->d_name[0])
				{
					strcat(way, entry->d_name);
					int i;
					int flag = 0;
					for(i = 0; i<(*sizeOfBanList); i++)
					{
						if(banList[i])
							if(!strcmp(banList[i], way))
							{
								flag = 1;
								break;
							}
					}
					if(!flag)
					{
						for(i = 0; i<(*sizeOfBanList); i++)
						{
							if(banList[i] == NULL)
							{
								banList[i] = (char*)malloc(sizeof(char)*strlen(way));
								strcpy(banList[i], way);
								printf("%s\n", way);
								closedir(dir);
								return 1;
							}
						}
					}
					way[wayLen]='\0';
				}
		}
		if(!strchr(entry->d_name, '.'))
		{
			strcat(way, entry->d_name);
			strcat(way, "/");
			if(nextDir(banList, way, letter, sizeOfWay, sizeOfBanList))
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


int main()
{
	int sizeOfWay = 100;
	int sizeOfBanList = 20;
	int i;
	char inputStr[100];
	char * way = (char*)malloc(sizeof(char)*sizeOfWay);
	char ** banList = (char**)malloc(sizeof(char*)*sizeOfBanList);
	for(i = 0; i<sizeOfBanList; i++)
		banList[i] = NULL;
  strcat(way, "./");
	printf("ÐÐ²ÐµÐ´Ð¸ÑÐµ ÑÑÑÐ¾ÐºÑ: \n");
	fgets(inputStr, 99, stdin);
	for (i=0;i<strlen(inputStr)-1;i++)
	{
		if(!nextDir(banList, way, inputStr[i], &sizeOfWay, &sizeOfBanList))
			printf("Ð¤Ð°Ð¹Ð»Ð° Ñ Ð½Ð°Ð·Ð²Ð°Ð½Ð¸ÐµÐ¼ '%c' Ð½Ðµ ÑÑÑÐµÑÑÐ²ÑÐµÑ\n", inputStr[i]);
		way[2] = '\0';
	}
	free(way);
	free(banList);
	return 0;
}

