#include<stdio.h>
#include <stdlib.h>

#pragma pack(push, 2)
//даeт указание процессору не использовать выравнивание
//Помещает текущее значение выравнивания упаковки во внутренний стек компилятора и задает для текущего выравнивания упаковки значение n

typedef struct tagBITMAPFILEHEADER {
      unsigned short int    bfType;
      unsigned long int   bfSize;
      unsigned short int    bfReserved1;
      unsigned short int    bfReserved2;
      unsigned long int   bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	unsigned long int biSize;
	long int biWidth;
	long int biHeight;
	unsigned short int biPlanes;
	unsigned short int biBitCount;
	unsigned long int biCompression;
	unsigned long int biSizeImage;
	long int biXPelsPerMeter;
	long int biYPelsPerMeter;
	unsigned long int biClrUsed;
	unsigned long int biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBTRIPLE {
  char rgbtBlue;
  char rgbtGreen;
  char rgbtRed;
} RGBTRIPLE;

 #pragma pack(pop)
 //Удаляет запись из вершины внутреннего стека компилятора

int coordinates (int x0, int x1, int y0, int y1)
{
  if((x1-x0)==(y1-y0) && (x1-x0)!=0) return 0;
  else return 1;
}
//функция проверки координат(удовлетворяют ли условию)


int BMPpaint(int x0, int x1, int y0, int y1, char* str)
{
  BITMAPFILEHEADER BMP_FILE_HEADER;
  BITMAPINFOHEADER BMP_INFO_HEADER;
  RGBTRIPLE RGB;

     FILE * f, * new;

     f = fopen(str, "rb");
     if (f==NULL)
     {
       printf("Fail with file" );
       return 0;
     }
     new = fopen("USEROUT.bmp", "wb");

     fread(&BMP_FILE_HEADER,sizeof(BMP_FILE_HEADER),1,f);
     fwrite(&BMP_FILE_HEADER, sizeof(BMP_FILE_HEADER), 1, new);
     fread(&BMP_INFO_HEADER,sizeof(BMP_INFO_HEADER),1,f);
     fwrite(&BMP_INFO_HEADER, sizeof(BMP_INFO_HEADER), 1, new);

    long width = BMP_INFO_HEADER.biWidth;
    long height = BMP_INFO_HEADER.biHeight;


    if (coordinates(x0, x1, y0, y1) || x0<0 || y0<0 || x1>width || y1>height)
    {
        printf("Fail with coordinates" );
        return 0;
    }
    printf("Correct coordinates!\n");

    int empty = 0;
    if ((width *3) % 4)  empty = 4 - (width*3) % 4;

        for(int i=0;i< height;i++)
        {
                for (int j = 0; j < width; j++)
                {
                        fread(&RGB, sizeof(RGB),1, f);

                        if (j>=x0 && j<=x1 && height-i<=y1 && height-i>=y0)
                        {
                          if (height-i==j-x0+y0 || height-i==-(j-y1-x0)  )
                          {
                            RGB.rgbtBlue   = 0;
                            RGB.rgbtGreen = 0;
                            RGB.rgbtRed = 0;
                          }
                        }

                        fwrite(&RGB, sizeof(RGB), 1, new);
                }
                if(empty != 0)
                {
                    fread(&RGB, empty,1, f);
                    fwrite(&RGB, empty, 1, new);
                }
        }
        fclose(f);
        fclose(new);

        return 1;
}

int main()
{
  printf("Please enter name of file: " );
  char str[19];
  fgets(str, 10, stdin);
  printf("Please enter coordinates\n" );
  int x1, y1, x0, y0;
  printf("x0 = " );
  scanf("%d", &x0 );
  printf("y0 = " );
  scanf("%d", &y0 );
  printf("x1 = " );
  scanf("%d", &x1 );
  printf("y1 = " );
  scanf("%d", &y1 );

  if(BMPpaint(x0, x1, y0, y1, str))
  printf("Look OUT.bmp." );
  return 0;
  }
