#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_name.h"

char* get_name()
{
 char* name =(char*)malloc(80*sizeof(char));;
 int i =0;
 int ch;
 while ((ch=getchar()) != '\n')
  {
  name[i]=ch;
   i++;
  }
 name[i]='\0';
 return name;
}
