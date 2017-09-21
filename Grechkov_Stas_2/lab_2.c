#include <stdio.h>
void main()
{ 
	int n,index; // входные параметры
	scanf("%d %d",&n,&index);
	int mas[n];
	int i;
	for (i=0;i<n;i++)
	{
		scanf("%d",mas[i]); // заполнение массива
	}
	int max=0, count=0, sum=0,min=0; // max-максимальный элемент count-число повторов нулевого символа
	                         // sum- cумма четных элементов min- минимальный элемент
	switch (index)
	{
		case 0:
	   {   for(i=0;i<n;i++)
		{
           if (mas[i]>max)
           {
           	max = mas[i];
           }
		} printf("%d \n",max);
       }
        case 1:
       {
          for(i=0;i<n;i++)
         {
           if (mas[i]<min || min ==0)
           {
           	min = mas[i];
           }
		} printf("%d \n",min);
       }
        case 2:
       {   for(i=0;i<n;i++)
		{
           if (mas[i] % 2 ==0)
           {
           	sum = sum+mas[i];
           }
		} printf("%d \n",sum);
       } 
        case 3:
       {   for(i=1;i<n;i++)
		{
           if (mas[i] == mas[0])
           {
           	count++;
           }
		} printf("%d \n",count);
       }  
       default: printf("Данные некорректны");
	}
} 