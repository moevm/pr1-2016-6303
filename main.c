#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void copy(char *buffer, FILE *file_result, int len, char c)
{
    int i;
    for (i = 0; i < len; i++)
        fprintf(file_result, "%c", buffer[i]);
    fprintf(file_result,"%c", c);
}

int main()
{
    FILE *file_for_reading, *file_result, *file_amount;
    printf("Input Name of Source File:\n");
    char SOURCE_FILE[20];
    scanf("%s",SOURCE_FILE);
    if(!(strstr(SOURCE_FILE,".txt")))
        strcat(SOURCE_FILE,".txt");
    file_for_reading=fopen(SOURCE_FILE,"r");
    if (file_for_reading==NULL)
    {
        printf("Source file NOT Found or Empty\n");
        return 0;
    }
    printf("Input Name for Edited File:\n");
    char EDITED_V[20];
    scanf("%s",EDITED_V);
    if(!(strstr(EDITED_V,".txt")))
        strcat(EDITED_V,".txt");
    file_result=fopen(EDITED_V,"w");
    printf("Input Name for Amount File:\n");
    char AMOUNT_WRD[20];
    scanf("%s",AMOUNT_WRD);
    if(!(strstr(AMOUNT_WRD,".txt")))
        strcat(AMOUNT_WRD,".txt");
    file_amount=fopen(AMOUNT_WRD,"w");
    char c;
    char buffer[3000];
    int amount=0;
    int con, vow;
    con=vow=0;
    int len=0;
    while (!feof(file_for_reading))
    {
        c=fgetc(file_for_reading);
        switch (c)
        {
            case ' ':
                if (con>=vow)
                    copy(buffer, file_result, len,c);
                len=0;
                amount++;
                con=vow=0;
                break;

            case '!':
                if (con>=vow)
                    copy(buffer, file_result, len,c);
                len=0;
                con=vow=0;
                break;

            case '?':
                if (con>=vow)
                    copy(buffer, file_result, len,c);
                len=0;
                con=vow=0;
                break;

            case '.':
                if (con>=vow)
                    copy(buffer, file_result, len,c);
                len=0;
                con=vow=0;
                break;

            case '\n':
                fprintf(file_result,"%c", c);
                len=0;
                con=vow=0;
                break;

            default:
                if ((c>='A'&& c<='Z') || (c>='a'&& c<='z'))
                    {
                        if(c == 'e'|| c=='u' || c == 'i' || c == 'o' || c=='a' || c=='E' || c=='U'|| c=='I'|| c=='O' || c=='A' )
                            vow++;
                        else
                            con++;
                    }
                len++;
                buffer[len-1]=c;
            break;
        }
    }
    printf("Your Files Have been saved as:\n %s \n %s\n",EDITED_V,AMOUNT_WRD);
    fprintf(file_amount,"%i", amount+1); //учитывая последнее слово
    fclose(file_for_reading);
    fclose(file_result);
    fclose(file_amount);
    return 0;
}
