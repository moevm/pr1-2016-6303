#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 2)

typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;
typedef unsigned char BYTE;

typedef struct COORDINATES
{
   BYTE    rgbtBlue;
   BYTE    rgbtGreen;
   BYTE    rgbtRed;
}COORDINATES;

typedef struct tagBITMAPFILEHEADER
 {
   WORD    bfType;
   DWORD   bfSize;
   WORD    bfReserved1;
   WORD    bfReserved2;
   DWORD   bfOffBits;
 } BITMAPFILEHEADER, *PBITMAPFILEHEADER;


 typedef struct tagBITMAPINFOHEADER
 {
  DWORD  biSize;
  LONG   biWidth;
  LONG   biHeight;
  WORD   biPlanes;
  WORD   biBitCount;
  DWORD  biCompression;
  DWORD  biSizeImage;
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;


 typedef struct RGBTRIPLE
 {
   BYTE    rgbtBlue;
   BYTE    rgbtGreen;
   BYTE    rgbtRed;
 } RGBTRIPLE;

 #pragma pack(pop)

int swap(int x0, int y0, int x1, int y1, char *bmp)
{
  BITMAPFILEHEADER BITMAP_FILE;
  BITMAPINFOHEADER BITMAP_INFO;
  RGBTRIPLE RGB;
  COORDINATES** cord;

  FILE *bmp1;
  FILE *bmp2;

  bmp1 = fopen(bmp, "rb"); //открытие файла для чтения
  if(bmp1 == NULL)
  {
    printf("Fail with file opening\n"); //проверка на корректное открытие файла
    return 0;
  }
  bmp2 = fopen("file2.bmp", "wb");
  if(bmp2 == NULL)
  {
    printf("Fail with file opening\n"); //проверка на корректное открытие файла
    return 0;
  }

  fread(&BITMAP_FILE, sizeof(BITMAP_FILE), 1, bmp1);   //копирование заголовков
  fwrite(&BITMAP_FILE, sizeof(BITMAP_FILE), 1, bmp2);
  fread(&BITMAP_INFO, sizeof(BITMAP_INFO), 1, bmp1);
  fwrite(&BITMAP_INFO, sizeof(BITMAP_INFO), 1, bmp2);

  int width = BITMAP_INFO.biWidth;
  int height = BITMAP_INFO.biHeight;

//  y0=height-y0;
//  y1=height-y1;

  cord=(COORDINATES**)malloc(height*sizeof(COORDINATES*));   //создание двумерного массива структур
  for(int i=0;i<height;i++)
    cord[i]=(COORDINATES*)malloc(width*sizeof(COORDINATES));

 size_t padding = 0;
 if ((width * 3) % 4)
   padding = 4 - (width * 3) % 4;

  for(int i=height-1; i>=0; i--)
  {
    for (int j=0; j<(width); j++)
    {
      fread(&RGB, sizeof(RGB),1, bmp1);
      if(i >= y0 && i <= y0+(y1-y0)/2 && j >= x0 && j <= x0 + (x1-x0)/2)
      {
        cord[i+(y1+1-y0)/2][j+(x1+1-x0)/2].rgbtBlue = RGB.rgbtBlue;
        cord[i+(y1+1-y0)/2][j+(x1+1-x0)/2].rgbtGreen = RGB.rgbtGreen;
        cord[i+(y1+1-y0)/2][j+(x1+1-x0)/2].rgbtRed = RGB.rgbtRed;
      }
      if(j > (x0+(x1-x0)/2) && j<=x1 && i >= y0 && i<=y0+(y1-y0)/2)
      {
        cord[i+(y1+1-y0)/2][j-(x1+1-x0)/2].rgbtBlue = RGB.rgbtBlue;
        cord[i+(y1+1-y0)/2][j-(x1+1-x0)/2].rgbtGreen = RGB.rgbtGreen;
        cord[i+(y1+1-y0)/2][j-(x1+1-x0)/2].rgbtRed = RGB.rgbtRed;
      }
      if(i > y0+(y1-y0)/2 && i<=y1 && j>=x0 && j <= x0+(x1-x0)/2)
      {
        cord[i-(y1+1-y0)/2][j+(x1+1-x0)/2].rgbtBlue = RGB.rgbtBlue;
        cord[i-(y1+1-y0)/2][j+(x1+1-x0)/2].rgbtGreen = RGB.rgbtGreen;
        cord[i-(y1+1-y0)/2][j+(x1+1-x0)/2].rgbtRed = RGB.rgbtRed;
      }
      if(i <= y1 && i > y0+(y1-y0)/2 && j <= x1 && j > x0+(x1-x0)/2)
      {
        cord[i-(y1+1-y0)/2][j-(x1+1-x0)/2].rgbtBlue = RGB.rgbtBlue;
        cord[i-(y1+1-y0)/2][j-(x1+1-x0)/2].rgbtGreen = RGB.rgbtGreen;
        cord[i-(y1+1-y0)/2][j-(x1+1-x0)/2].rgbtRed = RGB.rgbtRed;
      }
      if(i<y0 || i>y1 || j>x1 || j<x0)
      {
      cord[i][j].rgbtBlue = RGB.rgbtBlue;
      cord[i][j].rgbtGreen = RGB.rgbtGreen;
      cord[i][j].rgbtRed = RGB.rgbtRed;
      }
    }
    for(int k = 0; k<padding; k++)
    {
      getc(bmp1);
    }
  }

  for(int i=height-1; i>=0; i--)
  {
    for(int j=0; j<width; j++)
      fwrite(&cord[i][j], sizeof(RGB), 1, bmp2);
    for(int k = 0; k<padding; k++)
    {
        fprintf(bmp2, "%c", 0);
    }
  }

  fclose(bmp1);
  fclose(bmp2);

  return 0;
}

int main()
{
  int x0, y0, x1, y1;
  char bmp[30];
  fgets(bmp, 30, stdin);
  bmp[strlen(bmp)-1] = '\0';
  scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
  if((x1-x0)<=0 && (y1-y0)<=0)
  {
    printf("Fail with coordinates");
    return 0;
  }
  if((x1-x0)%2 == 0 || (y1-y0)%2 == 0)
  {
    printf("Fail with coordinates");
    return 0;
  }
  swap(x0, y0, x1, y1, bmp);
  return 0;
}
