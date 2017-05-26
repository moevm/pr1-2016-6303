#include <stdio.h>
#include <stdlib.h>

 struct Node
{
    char *data;
    struct Node *next;
};

char*topdata(struct Node*top)
{
    return top->data;
}

void push(struct Node**top,char*sign)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data=sign;
    tmp->next=*top;
    *top=tmp;
}

void pop(struct Node **head)
{
    struct Node*tmp = *head;
    *head=(*head)->next;
    free(tmp);
}

int isempty(struct Node*top) {

   if(top == NULL)
      return 1;
   else
      return 0;
}

int main()
{
    struct Node* top=NULL;
   int i,y,x;
    char*arr=(char*)malloc(3001*sizeof(char));
    fgets (arr, 3001, stdin);
    arr[strlen(arr) - 1] = '\0';
    for(i=0;arr[i];i++)
    {
        if(arr[i]=='<'&&arr[i+1]!='/')
        {
            char *wordin=(char*)malloc(20*sizeof(char));
            y=i+1;
            for(x=0;arr[y]!='>';x++,y++)
            {
                wordin[x]=arr[y];
            }
            wordin[x]='\0';
            if((strcmp(wordin,"br")!=0)&&(strcmp(wordin,"hr")!=0))
            push(&top,wordin);
            i=y;
        }
         if(arr[i]=='<'&&arr[i+1]=='/')
        {
            if(isempty(top)== 1)
            {
                printf("wrong");
                free(top);
                return 0;
            }
            else
            {
                char*wordout=(char*)malloc(20*sizeof(char));
                y=i+2;
                for(x=0;arr[y]!='>';x++,y++)
                {
                    wordout[x]=arr[y];
                }
                wordout[x]='\0';
                i=y;
                if(strcmp(wordout,topdata(top))!=0)
                {
                    printf("wrong");
                    free(top);
                    return 0;
                }
                else
                    pop(&top);
            }
        }

    }
    if(isempty(top)== 1)
        printf("correct");
    else
        printf("wrong");
    free(top);
    return 0;
}

