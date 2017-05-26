#include <stdio.h>
#include <stdlib.h>

void print_sentence (char* sentence, int len_sentence)
{
  int i=0;
	while (sentence[i]==' ' || sentence[i]=='\n')
	{
		i++;
	}
  for (i; i < len_sentence; i++)
  {
    printf("%c", sentence[i]);
  }
}

int add_char (char* sentence, int sen_size, int i, char c)
{
  if (i > sen_size)
	{ 
		sentence = (char*) realloc(sentence, sen_size*sizeof(char)+10);
		sen_size = sen_size+10;
	}
	sentence[i] = c;
	return sen_size;
}


int main()
{
	int sen_size = 10;
  char c; 
	char* sentence= (char*) malloc(sen_size*sizeof(char));
  int lenght = 0, i=0;
	int sentence_count_before=0, sentence_count_after=0;
  while ((c = getchar()) != '!')
  {
    switch (c)
    {
      case '\t': break;
      case '.': 
      case ';':
			{
				sentence_count_before++;
				sentence_count_after++;
				sen_size = add_char(sentence, sen_size, i, c);
				i++;
				sen_size = add_char(sentence, sen_size, i, '\n');
				i++;
				print_sentence (sentence,i);
				i = 0; 
				break;
			}
      case '?': 
			{
				sentence_count_before++;
				i = 0; 
				break;
			}

      default:
      {
				sen_size = add_char(sentence, sen_size, i, c);
        i++;
      }
    }
  }
printf("Количество предложений до %d и количество предложений после %d\n",sentence_count_before, sentence_count_after);
free(sentence);
return 0;
}
