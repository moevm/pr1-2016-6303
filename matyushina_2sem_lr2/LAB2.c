#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//формирование структуры
typedef struct Stack {
  int data;
  struct Stack * prev;
} Stack;

//добавление элемента в стек
void push (Stack** top, int element) {
  Stack* ptr=(Stack*)malloc(sizeof(Stack));
  ptr->prev= *top;
  ptr->data=element;
  *top=ptr;
}

//удаление элемента
void remove_element( Stack** top) {
 	*top=(*top)->prev;
} 

//подсчет элементов стека
int count(Stack* top) {
  int n=0;
  while (top!=NULL) {
	top=top->prev;
  	++n;
  }
  return n;
}
//элемент на вершине стека
int top_element(Stack* top) {
	return top->data;
}

//арифметическая операция над двумя крайними элементами стека, с последующим удалением этих элементов и добавлением резултата в стек
void math(char c, Stack** top){
 int a, b;
 a=top_element( *top);
 remove_element(top);
 b=top_element( *top);
 remove_element(top);
 int result;
 switch(c) {
 	case '+':
 		result=a+b;
 		break;
 	case '-':
 		result=b-a;
 		break;
 	case '*':
 		result=a*b;
 		break;
 	case '/':
 		result=a/b;
 		break;
 }
 push(top, result);
}
  
 
int main() {

 Stack* top=NULL;			//указатель на вершину стека
 char* str=malloc(100*sizeof(char));
 fgets(str, 100, stdin); 
 int element;
 int control;		//счетчик количества элементов в стеке
 char* part=strtok(str, " "); //разделение исходной строки str на лексемы part, по пробелам
 while (part!=NULL){
 	if ( (strlen(part)==1) || ((strlen(part)==2)&&(part[1]=='\n')) ) {
 		if ((part[0]=='+')||(part[0]=='-')||(part[0]=='*')||(part[0]=='/')){
 			control=count(top);
 			if (control>1) {
 				math(part[0], &top);
 			}
 			else {
 				printf("error\n");
 				return 0;
 			}
 		}
 		//atoi - интерпретирует содержания строки, как целое цисло 
 		else { 
 			element=atoi(part);
 			push(&top, element);
 		}
 	}
 	else if ((strlen(part)!=1)&&(part[strlen(part)-1]!='\n')) {
 		element=atoi(part);
 		push(&top, element);
 	}
 	part = strtok(NULL, " ");
 }
 control=count(top);
 if (control==1) {
	printf("%d\n", top->data);
 }
 else {
   printf("error\n");
 }
 return 0; 
  
}
