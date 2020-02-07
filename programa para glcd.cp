#line 1 "C:/Users/Nico/Desktop/Programa para glcd/programa para glcd.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdio.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/string.h"





void * memchr(void *p, char n, unsigned int v);
int memcmp(void *s1, void *s2, int n);
void * memcpy(void * d1, void * s1, int n);
void * memmove(void * to, void * from, int n);
void * memset(void * p1, char character, int n);
char * strcat(char * to, char * from);
char * strchr(char * ptr, char chr);
int strcmp(char * s1, char * s2);
char * strcpy(char * to, char * from);
int strlen(char * s);
char * strncat(char * to, char * from, int size);
char * strncpy(char * to, char * from, int size);
int strspn(char * str1, char * str2);
char strcspn(char * s1, char * s2);
int strncmp(char * s1, char * s2, char len);
char * strpbrk(char * s1, char * s2);
char * strrchr(char *ptr, char chr);
char * strstr(char * s1, char * s2);
char * strtok(char * s1, char * s2);
#line 1 "c:/users/nico/desktop/programa para glcd/glcdnico.txt"
#line 118 "c:/users/nico/desktop/programa para glcd/glcdnico.txt"
BYTE glcd_readByte(BYTE chip);
void glcd_writeByte(BYTE chip, BYTE data);
void glcd_fillScreen(int1 color);
void dibujo(char a[]);
const BYTE TEXT[51][5] ={0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x5F, 0x00, 0x00,
 0x00, 0x03, 0x00, 0x03, 0x00,
 0x14, 0x3E, 0x14, 0x3E, 0x14,
 0x24, 0x2A, 0x7F, 0x2A, 0x12,
 0x43, 0x33, 0x08, 0x66, 0x61,
 0x36, 0x49, 0x55, 0x22, 0x50,
 0x00, 0x05, 0x03, 0x00, 0x00,
 0x00, 0x1C, 0x22, 0x41, 0x00,
 0x00, 0x41, 0x22, 0x1C, 0x00,
 0x14, 0x08, 0x3E, 0x08, 0x14,
 0x08, 0x08, 0x3E, 0x08, 0x08,
 0x00, 0x50, 0x30, 0x00, 0x00,
 0x08, 0x08, 0x08, 0x08, 0x08,
 0x00, 0x60, 0x60, 0x00, 0x00,
 0x20, 0x10, 0x08, 0x04, 0x02,
 0x3E, 0x51, 0x49, 0x45, 0x3E,
 0x04, 0x02, 0x7F, 0x00, 0x00,
 0x42, 0x61, 0x51, 0x49, 0x46,
 0x22, 0x41, 0x49, 0x49, 0x36,
 0x18, 0x14, 0x12, 0x7F, 0x10,
 0x27, 0x45, 0x45, 0x45, 0x39,
 0x3E, 0x49, 0x49, 0x49, 0x32,
 0x01, 0x01, 0x71, 0x09, 0x07,
 0x36, 0x49, 0x49, 0x49, 0x36,
 0x26, 0x49, 0x49, 0x49, 0x3E,
 0x00, 0x36, 0x36, 0x00, 0x00,
 0x00, 0x56, 0x36, 0x00, 0x00,
 0x08, 0x14, 0x22, 0x41, 0x00,
 0x14, 0x14, 0x14, 0x14, 0x14,
 0x00, 0x41, 0x22, 0x14, 0x08,
 0x02, 0x01, 0x51, 0x09, 0x06,
 0x3E, 0x41, 0x59, 0x55, 0x5E,
 0x7E, 0x09, 0x09, 0x09, 0x7E,
 0x7F, 0x49, 0x49, 0x49, 0x36,
 0x3E, 0x41, 0x41, 0x41, 0x22,
 0x7F, 0x41, 0x41, 0x41, 0x3E,
 0x7F, 0x49, 0x49, 0x49, 0x41,
 0x7F, 0x09, 0x09, 0x09, 0x01,
 0x3E, 0x41, 0x41, 0x49, 0x3A,
 0x7F, 0x08, 0x08, 0x08, 0x7F,
 0x00, 0x41, 0x7F, 0x41, 0x00,
 0x30, 0x40, 0x40, 0x40, 0x3F,
 0x7F, 0x08, 0x14, 0x22, 0x41,
 0x7F, 0x40, 0x40, 0x40, 0x40,
 0x7F, 0x02, 0x0C, 0x02, 0x7F,
 0x7F, 0x02, 0x04, 0x08, 0x7F,
 0x3E, 0x41, 0x41, 0x41, 0x3E,
 0x7F, 0x09, 0x09, 0x09, 0x06,
 0x1E, 0x21, 0x21, 0x21, 0x5E,
 0x7F, 0x09, 0x09, 0x09, 0x76};

const BYTE TEXT2[44][5]={0x26, 0x49, 0x49, 0x49, 0x32,
 0x01, 0x01, 0x7F, 0x01, 0x01,
 0x3F, 0x40, 0x40, 0x40, 0x3F,
 0x1F, 0x20, 0x40, 0x20, 0x1F,
 0x7F, 0x20, 0x10, 0x20, 0x7F,
 0x41, 0x22, 0x1C, 0x22, 0x41,
 0x07, 0x08, 0x70, 0x08, 0x07,
 0x61, 0x51, 0x49, 0x45, 0x43,
 0x00, 0x7F, 0x41, 0x00, 0x00,
#line 184 "c:/users/nico/desktop/programa para glcd/glcdnico.txt"
 0x02, 0x04, 0x08, 0x10, 0x20,
 0x04, 0x02, 0x01, 0x02, 0x04,
 0x40, 0x40, 0x40, 0x40, 0x40,
 0x00, 0x01, 0x02, 0x04, 0x00,
 0x20, 0x54, 0x54, 0x54, 0x78,
 0x7F, 0x44, 0x44, 0x44, 0x38,
 0x38, 0x44, 0x44, 0x44, 0x44,
 0x38, 0x44, 0x44, 0x44, 0x7F,
 0x38, 0x54, 0x54, 0x54, 0x18,
 0x04, 0x04, 0x7E, 0x05, 0x05,
 0x08, 0x54, 0x54, 0x54, 0x3C,
 0x7F, 0x08, 0x04, 0x04, 0x78,
 0x00, 0x44, 0x7D, 0x40, 0x00,
 0x20, 0x40, 0x44, 0x3D, 0x00,
 0x7F, 0x10, 0x28, 0x44, 0x00,
 0x00, 0x41, 0x7F, 0x40, 0x00,
 0x7C, 0x04, 0x78, 0x04, 0x78,
 0x7C, 0x08, 0x04, 0x04, 0x78,
 0x38, 0x44, 0x44, 0x44, 0x38,
 0x7C, 0x14, 0x14, 0x14, 0x08,
 0x08, 0x14, 0x14, 0x14, 0x7C,
 0x00, 0x7C, 0x08, 0x04, 0x04,
 0x48, 0x54, 0x54, 0x54, 0x20,
 0x04, 0x04, 0x3F, 0x44, 0x44,
 0x3C, 0x40, 0x40, 0x20, 0x7C,
 0x1C, 0x20, 0x40, 0x20, 0x1C,
 0x3C, 0x40, 0x30, 0x40, 0x3C,
 0x44, 0x28, 0x10, 0x28, 0x44,
 0x0C, 0x50, 0x50, 0x50, 0x3C,
 0x44, 0x64, 0x54, 0x4C, 0x44,
 0x00, 0x08, 0x36, 0x41, 0x41,
 0x00, 0x00, 0x7F, 0x00, 0x00,
 0x41, 0x41, 0x36, 0x08, 0x00,
 0x02, 0x01, 0x02, 0x04, 0x02};








void glcd_init(int1 mode)
{

 output_high( PIN_C0 );
 output_low( PIN_B5 );
 output_HIGH( PIN_B0 );
 output_HIGH( PIN_B1 );

 output_low( PIN_B2 );
 glcd_writeByte( PIN_B0 , 0xC0);
 glcd_writeByte( PIN_B1 , 0xC0);
 glcd_writeByte( PIN_B0 , 0x40);
 glcd_writeByte( PIN_B1 , 0x40);
 glcd_writeByte( PIN_B0 , 0xB8);
 glcd_writeByte( PIN_B1 , 0xB8);
 if(mode ==  1 )
 {
 glcd_writeByte( PIN_B0 , 0x3F);
 glcd_writeByte( PIN_B1 , 0x3F);
 }
 else
 {
 glcd_writeByte( PIN_B0 , 0x3E);
 glcd_writeByte( PIN_B1 , 0x3E);
 }

 glcd_fillScreen( 0 );
}







void glcd_pixel(int x, int y, int1 color)
{
 BYTE data;
 BYTE chip =  PIN_B0 ;

 if(x > 63)
 {
 x -= 64;
 chip =  PIN_B1 ;
 }

 output_low( PIN_B2 );
 bit_clear(x,7);
 bit_set(x,6);
 glcd_writeByte(chip, x);
 glcd_writeByte(chip, (y/8 & 0b10111111) | 0b10111000);
 output_high( PIN_B2 );
 data = glcd_readByte(chip);

 if(color ==  1 )
 bit_set(data, y%8);
 else
 bit_clear(data, y%8);
 output_low( PIN_B2 );
 glcd_writeByte(chip, x);
 output_high( PIN_B2 );
 glcd_writeByte(chip, data);
}








void glcd_line(int x1, int y1, int x2, int y2, int1 color)
{
 signed int x, y, addx, addy, dx, dy;
 signed long P;
 int i;
 dx = abs((signed int)(x2 - x1));
 dy = abs((signed int)(y2 - y1));
 x = x1;
 y = y1;

 if(x1 > x2)
 addx = -1;
 else
 addx = 1;
 if(y1 > y2)
 addy = -1;
 else
 addy = 1;

 if(dx >= dy)
 {
 P = 2*dy - dx;

 for(i=0; i<=dx; ++i)
 {
 glcd_pixel(x, y, color);

 if(P < 0)
 {
 P += 2*dy;
 x += addx;
 }
 else
 {
 P += 2*dy - 2*dx;
 x += addx;
 y += addy;
 }
 }
 }
 else
 {
 P = 2*dx - dy;

 for(i=0; i<=dy; ++i)
 {
 glcd_pixel(x, y, color);

 if(P < 0)
 {
 P += 2*dx;
 y += addy;
 }
 else
 {
 P += 2*dx - 2*dy;
 x += addx;
 y += addy;
 }
 }
 }
}








void glcd_rect(int x1, int y1, int x2, int y2, int fill, int1 color)
{
 if(fill)
 {
 int y, ymax;
 if(y1 < y2)
 {
 y = y1;
 ymax = y2;
 }
 else
 {
 y = y2;
 ymax = y1;
 }

 for(; y<=ymax; ++y)
 glcd_line(x1, y, x2, y, color);
 }
 else
 {
 glcd_line(x1, y1, x2, y1, color);
 glcd_line(x1, y2, x2, y2, color);
 glcd_line(x1, y1, x1, y2, color);
 glcd_line(x2, y1, x2, y2, color);
 }
}







void glcd_bar(int x1, int y1, int x2, int y2, int width, int1 color)
{
 signed int x, y, addx, addy, j;
 signed long P, dx, dy, c1, c2;
 int i;
 dx = abs((signed int)(x2 - x1));
 dy = abs((signed int)(y2 - y1));
 x = x1;
 y = y1;
 c1 = -dx*x1 - dy*y1;
 c2 = -dx*x2 - dy*y2;

 if(x1 > x2)
 {
 addx = -1;
 c1 = -dx*x2 - dy*y2;
 c2 = -dx*x1 - dy*y1;
 }
 else
 addx = 1;
 if(y1 > y2)
 {
 addy = -1;
 c1 = -dx*x2 - dy*y2;
 c2 = -dx*x1 - dy*y1;
 }
 else
 addy = 1;

 if(dx >= dy)
 {
 P = 2*dy - dx;

 for(i=0; i<=dx; ++i)
 {
 for(j=-(width/2); j<width/2+width%2; ++j)
 {
 if(dx*x+dy*(y+j)+c1 >= 0 && dx*x+dy*(y+j)+c2 <=0)
 glcd_pixel(x, y+j, color);
 }
 if(P < 0)
 {
 P += 2*dy;
 x += addx;
 }
 else
 {
 P += 2*dy - 2*dx;
 x += addx;
 y += addy;
 }
 }
 }
 else
 {
 P = 2*dx - dy;

 for(i=0; i<=dy; ++i)
 {
 if(P < 0)
 {
 P += 2*dx;
 y += addy;
 }
 else
 {
 P += 2*dx - 2*dy;
 x += addx;
 y += addy;
 }
 for(j=-(width/2); j<width/2+width%2; ++j)
 {
 if(dx*x+dy*(y+j)+c1 >= 0 && dx*x+dy*(y+j)+c2 <=0)
 glcd_pixel(x+j, y, color);
 }
 }
 }
}







void glcd_circle(int x, int y, int radius, int1 fill, int1 color)
{
 signed int a, b, P;
 a = 0;
 b = radius;
 P = 1 - radius;

 do
 {
 if(fill)
 {
 glcd_line(x-a, y+b, x+a, y+b, color);
 glcd_line(x-a, y-b, x+a, y-b, color);
 glcd_line(x-b, y+a, x+b, y+a, color);
 glcd_line(x-b, y-a, x+b, y-a, color);
 }
 else
 {
 glcd_pixel(a+x, b+y, color);
 glcd_pixel(b+x, a+y, color);
 glcd_pixel(x-a, b+y, color);
 glcd_pixel(x-b, a+y, color);
 glcd_pixel(b+x, y-a, color);
 glcd_pixel(a+x, y-b, color);
 glcd_pixel(x-a, y-b, color);
 glcd_pixel(x-b, y-a, color);
 }

 if(P < 0)
 P+= 3 + 2*a++;
 else
 P+= 5 + 2*(a++ - b--);
 } while(a <= b);
}






void glcd_text57(int x, int y, char* textptr, int size, int1 color)
{
 int i, j, k, l, m;
 BYTE pixelData[5];

 for(i=0; textptr[i] != '\0'; ++i, ++x)
 {
 if(textptr[i] < 'S')
 memcpy(pixelData, TEXT[textptr[i]-' '], 5);
 else if(textptr[i] <= '~')
 memcpy(pixelData, TEXT2[textptr[i]-'S'], 5);
 else
 memcpy(pixelData, TEXT[0], 5);

 if(x+5*size >=  128 )
 {
 x = 0;
 y += 7*size + 1;
 }
 for(j=0; j<5; ++j, x+=size)
 {
 for(k=0; k<7*size; ++k)
 {
 if(bit_test(pixelData[j], k))
 {
 for(l=0; l<size; ++l)
 {
 for(m=0; m<size; ++m)
 {
 glcd_pixel(x+m, y+k*size+l, color);
 }
 }
 }
 }
 }
 }
}







void glcd_fillScreen(int1 color)
{
 int i, j;


 for(i = 0; i < 8; ++i)
 {
 output_low( PIN_B2 );
 glcd_writeByte( PIN_B0 , 0b01000000);
 glcd_writeByte( PIN_B1 , 0b01000000);
 glcd_writeByte( PIN_B0 , i | 0b10111000);
 glcd_writeByte( PIN_B1 , i | 0b10111000);
 output_high( PIN_B2 );


 for(j = 0; j < 64; ++j)
 {
 glcd_writeByte( PIN_B0 , 0xFF*color);
 glcd_writeByte( PIN_B1 , 0xFF*color);
 }
 }
}





void glcd_writeByte(char chip, BYTE data)
{
 if(chip ==  PIN_B0 )
 output_LOW( PIN_B0 );
 else
 output_LOW( PIN_B1 );

 output_low( PIN_B4 );
 output_d(data);
 output_high( PIN_B5 );
 delay_us(2);
 output_low( PIN_B5 );

 output_HIGH( PIN_B0 );
 output_HIGH( PIN_B1 );
}




BYTE glcd_readByte(BYTE chip)
{
 BYTE data;
 if(chip ==  PIN_B0 )
 output_LOW( PIN_B0 );
 else
 output_LOW( PIN_B1 );

 input_d();
 output_high( PIN_B4 );
 output_high( PIN_B5 );
 delay_us(2);
 output_low( PIN_B5 );
 delay_us(2);
 output_high( PIN_B5 );
 delay_us(2);
 data = input_d();
 output_low( PIN_B5 );

 output_HIGH( PIN_B0 );
 output_HIGH( PIN_B1 );
 return data;
}
void dibujo(char a[]){
INT I=0;
OUTPUT_LOW( PIN_B4 );
OUTPUT_LOW( PIN_B2 );
glcd_writeByte( PIN_B0 ,0X40);
glcd_writeByte( PIN_B0 ,0XB8);
OUTPUT_HIGH( PIN_B2 );
glcd_writeByte( PIN_B0 ,a[i]);



}
#line 18 "C:/Users/Nico/Desktop/Programa para glcd/programa para glcd.c"
CONST CHAR NICO[6]={ 0X0FF,0X0F,0XFF,0X0F,0XFF,0X07};
char *ptr;
void main()
{
SET_TRIS_A(0x0f);
SET_TRIS_B(0x00) ;
SET_TRIS_C(0x8e) ;
SET_TRIS_D(0x00) ;
SET_TRIS_E(0x0f);



glcd_init(on);

glcd_fillScreen( 0 );
DELAY_MS(1000);

dibujo(nico);
delay_ms (8000);
printf("Hola Jose te amo mucho , yo tu novio el mas facha!");
glcd_rect(32,16,98,48,0,1);
delay_ms (2000);
glcd_fillScreen( 0 );
glcd_circle(64,32,30,0,1);
glcd_fillScreen( 0 );
delay_ms (2000);
glcd_circle(78, 15, 6 ,  1 ,  1 );
glcd_circle(100, 15, 6,  1 ,  1 );
delay_ms(1000);
glcd_circle(78, 15, 6 ,  1 ,  0 );
glcd_circle(78, 15, 6 ,  0  ,  1 );

glcd_rect(105, 35, 77, 28,  0  ,  1  );
glcd_rect(110, 40, 70, 25,  0  ,  0  );

glcd_rect(105, 35, 77, 28,  0  ,  0  );
glcd_rect(110, 40, 70, 25,  0  ,  1  );
glcd_rect(0,20,64,40,1,1);

}
