#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 2)

typedef struct
{
	unsigned short bfType;
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
} BITMAPINFOHEADER;

typedef struct
{
	unsigned char rgbtBlue;
	unsigned char rgbtGreen;
	unsigned char rgbtRed;
} RGBTRIPLE;

#pragma pack(pop)


typedef struct
{
	int x0;
	int y0;
	int x1;
	int y1;
	int squad;
} coordinates;


coordinates squad(int* histogram, int length)
{
	coordinates m_Rectang;
	int maxsquad = 0;

	for (int i = 0; i < length; i++)
	{
		int lenghtYSize = histogram[i];
		for (int j = i; j < length; j++)
		{
			if (lenghtYSize > histogram[j])
			{
				lenghtYSize = histogram[j];
			}
			if ((j - i + 1) * lenghtYSize >= maxsquad)
			{
				maxsquad = (j - i + 1) * lenghtYSize;
				m_Rectang.x0 = i;
				m_Rectang.x1 = j;
				m_Rectang.y1 = lenghtYSize;
			}
		}
	}

	m_Rectang.squad = maxsquad;
	return m_Rectang;
}


void search(RGBTRIPLE* rgb, int width, int height)
{
	int* addArrayForRGB = (int*)malloc(sizeof(int*)*width);

	for (int i = 0; i <width; i++)
	{
		if (rgb[i].rgbtBlue == 255 && rgb[i].rgbtGreen == 255
			&& rgb[i].rgbtRed == 255)
			addArrayForRGB[i] = 1;
		else
			addArrayForRGB[i] = 0;
	}

	coordinates m_Rectang = squad(addArrayForRGB, width);

	int result = m_Rectang.squad;
	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			if (rgb[j+i*width].rgbtBlue == 255 && rgb[j + i*width].rgbtGreen == 255	&& rgb[j + i*width].rgbtRed == 255)
					addArrayForRGB[j]++;
			else addArrayForRGB[j] = 0;

			coordinates newRectang =	squad(addArrayForRGB, width);

			if (newRectang.squad >= result)
			{
				m_Rectang = newRectang;
				m_Rectang.y0 = i;
				result = m_Rectang.squad;
			}
	}

	m_Rectang.y0 = height - m_Rectang.y0 - 1;
	m_Rectang.y1 = m_Rectang.y1 + m_Rectang.y0;

	printf("X0:%d\nY0:%d\nX1:%d\nY1:%d\n", m_Rectang.x0, height - m_Rectang.y0 , m_Rectang.x1, height - m_Rectang.y1);

	free(addArrayForRGB);
}

int readFile_(char *bmp)
{
	BITMAPFILEHEADER BFH;
	BITMAPINFOHEADER BIH;
	RGBTRIPLE rgb;

	FILE *f = fopen(bmp, "rb");
	if (f == NULL)
	{
		printf("Fail\n");
		return 0;
	}

	fread(&BFH, 1, sizeof(BFH), f);
	fread(&BIH, 1, sizeof(BIH), f);

	unsigned int Height = BIH.biHeight;
	unsigned int Width = BIH.biWidth;

	RGBTRIPLE* rgbArray = (RGBTRIPLE*)malloc(Height * Width * sizeof(RGBTRIPLE));

	int extraBytes = 4 - ((Width * 3) % 4);
	if (extraBytes == 4)
	{
		extraBytes = 0;
	}

	for (unsigned long i = 0; i< Height * Width; i++)
	{
		fread(&rgbArray[i].rgbtBlue, 1, 1, f);
		fread(&rgbArray[i].rgbtGreen, 1, 1, f);
		fread(&rgbArray[i].rgbtRed, 1, 1, f);
		if (extraBytes)
		{
			for (int j = 0; j < extraBytes; j++)
			{
				char zeroByte;
				fread(&zeroByte, 1, 1, f);
			}
		}
	}

	search(rgbArray, Width, Height);
	fclose(f);
	return 0;
}

int main()
{
	char bmp[15];
	printf("Enter the file name ");
	fgets(bmp, 15, stdin);
	bmp[strlen(bmp) - 1] = '\0';
	int read = readFile_(bmp);
	return 0;
}
