#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push)
#pragma pack(2) // выравнивание по 2 байта

typedef struct BITMAPFILEHEADER
{
    unsigned char bfType[2];
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BITMAPFILEHEADER;

typedef struct BITMAPINFOHEADER
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)

typedef struct RGBTRIPPLE
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
} RGBTRIPPLE;

typedef struct IMAGE
{
    BITMAPFILEHEADER imageheader;
    BITMAPINFOHEADER imageinfo;
    RGBTRIPPLE ** imagepixels;
} IMAGE;

int main()
{
    int i, j, k, l=0, m=0;  //just counters for loops
    //printf("Enter bmp file name: \n");
   // char *filename=(char *)malloc(10);

   // fgets(filename, 10, stdin);
    FILE * fp = fopen("input.bmp", "rb");
    if (fp == NULL)
        {
            printf("Error! File doesn't exist\n");
            return 1;
        }
//    printf("File %s was opened \n",filename);
    IMAGE * bmp = (IMAGE*)malloc(sizeof(IMAGE));
    fread(&bmp->imageheader, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&bmp->imageinfo, sizeof(BITMAPINFOHEADER), 1, fp);

    int allx = bmp->imageinfo.biWidth; // считывание кол-ва пикселей изображения по горизонтали
    int ally = bmp->imageinfo.biHeight; // считывание кол-ва пикселей изображения по вертикали

    int x0, y0, x1, y1;
    printf("Enter the coordinates (x0 y0 x1 y1):\n");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1); // левая верхняя и правая нижняя точки области инвертирования
    if (x0 < 0 || y0 < 0 || x1 > allx - 1 || y1 > ally - 1 || x0 > x1 || y0 > y1)
    {
        printf("Wrong coordinates!\n");
        fclose(fp);
        free(bmp);
        return 1;
    }

    RGBTRIPPLE ** pixel = (RGBTRIPPLE**)malloc(sizeof(RGBTRIPPLE*) * ally); // выделение памяти для массива указателей на массивы структур
    for (i = 0; i < ally; i++)
        pixel[i] = (RGBTRIPPLE*)malloc(sizeof(RGBTRIPPLE) * allx); // выделение памяти в цикле для массивов пикселей соотв. строкам

    int fillingtrash = 4 - ((allx * 3) % 4); // вычисление кол-ва "мусорных" байт которые необходимо дописать
    if (fillingtrash == 4) // для выравнивания, они равны нулю
    {
        fillingtrash = 0;
    }

    for (i = 0; i < ally; i++) // считывание информации о цвете каждого из пикселей
    { // в ранее выделенные под это структуры в динамической памяти
        for (j = 0; j < allx; j++)
        {
            pixel[i][j].rgbBlue = getc(fp);
            pixel[i][j].rgbGreen = getc(fp);
            pixel[i][j].rgbRed = getc(fp);
        }
        for (k = 0; k < fillingtrash; k++) // пропуск "мусорных" байт записанных для выравнивания
        getc(fp); // они будут дописаны позже
    }
    fclose(fp);
    for (l = y0; l <= y1;l++)
    {
        for (m = x0; m <= x1; m++)
        {
            pixel[ally - l][m].rgbBlue = 255 - pixel[ally - l][m].rgbBlue;
            pixel[ally - l][m].rgbGreen = 255 - pixel[ally - l][m].rgbGreen;
            pixel[ally - l][m].rgbRed = 255 - pixel[ally - l][m].rgbRed;
        }
    }
    bmp->imagepixels = pixel; // привязка указателя из IMAGE к массиву пикселей изображения
    //Записываем новый файл
    FILE* outputfile = fopen("output.bmp", "wb");
    fwrite(&bmp->imageheader, sizeof(BITMAPFILEHEADER), 1, outputfile); // write headers into new .bmp
    fwrite(&bmp->imageinfo, sizeof(BITMAPINFOHEADER), 1, outputfile);
    for (i = 0; i < ally; i++) // write changed image into new .bmp
    {
        for (j = 0; j < allx; j++)
            fwrite(&bmp->imagepixels[i][j], 1, 3, outputfile);
        for (k = 0; k < fillingtrash; k++)
            fprintf(outputfile, "%c", 0);
    }
    return 0;
}

