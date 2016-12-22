#include <stdio.h>
#include <stdlib.h>
#define con 60                   // константа, задающая кол-во элементов массива
void write(char *arr,int a);     // объявление функции записи
void clean(char *arr,int a,int* i);     // объявление функции очистки 
 int main(int argc, char **argv) 
 {
 	int endsimbol=con;  // кол-во символов в массиве
 	char *text = (char*)malloc(sizeof(char)*endsimbol); // выделение первичной памати
    char c;
    int i=0;                      // индекс символа 
    int precount=0, postcount=0;
    int control=0;              // проверка на начало файла
    while ((c=getchar())!=EOF) // цикл чтения из потока
    {
       if (i==endsimbol)
        {
        	endsimbol+=con;   // и увеличения количества символов
        	text=(char*)realloc(text,endsimbol); // дополнительно выделение памяти 
        } 	             
       if ((c!='\t')&&(c!=' ')&&(c!='\n')&&(c!='.')&&(c!=';')&&(c!='?'))   // проверка на начало предложения
        {
            ++control;             
       	}	
       if (control)
        {
           text[i]=c;   // запись в массив
        }	
       if ((c==';')||(c=='.'))
        {
        write(text,endsimbol);
        clean(text,endsimbol,&i);
        ++postcount;
        ++precount;
        control=0;
        }
       else if(c=='?') 
       	{
       	clean(text,endsimbol,&i);
       	++precount;
       	control=0;           
        }
       ++i;
    }
    free(text);
    printf("Количество предложений до %d и количество предложений после %d",precount,postcount);
    return 0;
 }  
 void write(char *arr,int a)  // функция записи 
 {
    for(int i=0;i<a;++i)
    {   if (arr[i]!='\0')
        {
    	printf("%c",arr[i]);
        }
    }
    printf("\n");
 }  
 void clean(char *arr,int a, int* i) // функция отчистки 
 {
 	for(int k=0;k<a;++k)
 	{
 		arr[k]='\0';
 	}
 	*i=0;
 }