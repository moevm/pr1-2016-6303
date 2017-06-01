#include<stdio.h>
#include<stdlib.h>

typedef unsigned short int WORD;
typedef unsigned long int DWORD;
typedef long int LONG;
typedef char BYTE;

typedef struct tagBITMAPFILEHEADER { 
      WORD    bfType; 
      DWORD   bfSize; 
      WORD    bfReserved1; 
      WORD    bfReserved2; 
      DWORD   bfOffBits; 
} BITMAPFILEHEADER, *PBITMAPFILEHEADER; 

typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize; 
	LONG biWidth; 
	LONG biHeight; 
	WORD biPlanes; 
	WORD biBitCount; 
	DWORD biCompression; 
	DWORD biSizeImage; 
	LONG biXPelsPerMeter; 
	LONG biYPelsPerMeter; 
	DWORD biClrUsed; 
	DWORD biClrImportant; 
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBTRIPLE {
  BYTE rgbtBlue;
  BYTE rgbtGreen;
  BYTE rgbtRed;
} RGBTRIPLE;


void Research_size(char* name, long int* h, long int* w) {
  FILE * f1;
  BITMAPFILEHEADER BFH;
  BITMAPINFOHEADER BIH;
  
  f1 = fopen(name, "rb");
  fread(&BFH,14,1,f1); 
  fread(&BIH,sizeof(BIH),1,f1);
  *h = BIH.biHeight;
  *w = BIH.biWidth;
  fclose(f1);
}

int main() {
  
  char* name = (char*)malloc(100*sizeof(char));
  printf("введите название исходного файла ");
  scanf("%s", name);
  int x0,  y0, x1, y1;
  printf("x0 = ");
  scanf("%d", &x0); 
  printf("y0 = ");
  scanf("%d", &y0); 
  printf("x1 = ");
  scanf("%d", &x1);
  printf("y1 = ");
  scanf("%d", &y1); 
  
  //проверка квадратности области
    if ( (x1-x0)!= (y1-y0) ) {
  	printf("Fail with  square\n");
  	return 0;
    }

   FILE * f1, * f2;
   	
   BITMAPFILEHEADER BFH;
   BITMAPINFOHEADER BIH;
   RGBTRIPLE RGB; 
        
   f1 = fopen(name, "rb");
   //проверка существования исходного файла
   if (f1==NULL) {
       	printf("Fail with  file_start \n" );
       	return 0;
   }
   
   long int heig, wid;	
   Research_size(name,&heig, &wid);
   //проверка корректности введенных координат
    if ( (x0<0)||(x1<0)||(y0<0)||(y1<0)|| (x1>heig) || (y1>wid) ) {
  	printf("Fail with coordinates\n");
  	return 0;
   }
    //новые координаты
    int x0_new=heig-x0;
    int x1_new=heig-x1;
 	 
     int mid_x = x0_new+(x1_new-x0_new)/2;
     int mid_y=y0+(y1-y0)/2;
     
     f2 = fopen("new.bmp", "wb");
     //проверка существования файла для записи
     if (f2==NULL) {
       	 printf("Fail with new_file\n" );
       	 return 0;
      }
        
     fread(&BFH,16,1,f1); 
     fwrite(&BFH, sizeof(BFH), 1, f2);  
	
     fread(&BIH,sizeof(BIH),1,f1);
     fwrite(&BIH, sizeof(BIH), 1, f2);  

     int i, j;
     size_t padding = 0; 
     if ((wid * 3) % 4) {
		padding = 4 - (wid * 3) % 4;
     }
     
     for( i=0; i < heig ;i++) {
            for (j = 0; j < wid; j++){
		
		fread(&RGB, sizeof(RGB),1, f1);
        
		if ( i<=mid_x && j<mid_y && i>=x1_new && j>=y0 && ((mid_x-i)>=(j-y0 ))  ) {
           
                        	RGB.rgbtBlue=0;
  				RGB.rgbtGreen=0;
   				RGB.rgbtRed=0;
				fwrite(&RGB, sizeof(RGB), 1, f2);	
		 }
                       
                 else{
                        fwrite(&RGB, sizeof(RGB), 1, f2);
 		 } 
            }     
            if(padding != 0) {
   	 	 fread(&RGB, padding,1, f1);
   	 	 fwrite(&RGB, padding, 1, f2);
	    }
              
    } 
   fclose(f1);
   fclose(f2);
   free(name);
   return 0;
}
  
