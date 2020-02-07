///////////////////////////////////////////
//PUERTO B CONTROL DE COSAS
//A0 toma de LM35
//C6 y 77 para rs232
//a1 a2 a3 a4 recibe rf
//
//
//
////////////////////////////////////////////


#include <16f877a.h>
#device ADC=10;
#include <stdio.h>
#include <STRING.h>

#use delay (clock=4000000)
#use rs232 (baud=2400,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
#fuses XT,NOWDT,PUT
#byte porta=0x05
#byte portd=0x08
#byte portb=0x06
#byte portc=0x07
#byte trisa=0x85
#byte trisd=0x88
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
char mensaje="";
char datos="";
void actuar(char mensaje, char datos);

#INT_RDA               //SERVICIO DE INTERRUPCIÓN POR RS232
void rda_isr()
{
mensaje=getch();

// PONER EN ALTO O BAJO CADA SALIDA SEGUN CORRESPONDA
actuar(mensaje,0);
mensaje="";
}

void actuar( char mensaje, char datos){
if (mensaje=='1' || datos== 0x01){
   printf("Presionaste el %c \r ",mensaje);
   if(bit_test(portb,0)){
      output_low(PIN_B0);
   }else{
      output_high(PIN_B0);}
   }//lateral 1
if (mensaje=='2' || datos== 0x02){
   printf("Presionaste el %c \r ",mensaje);
   if(!bit_test(portb,1)){
      output_high(PIN_B1);}else{output_low(PIN_B1);}
   }//centro
if (mensaje=='3' || datos==0x03){
   printf("Presionaste el  %c \r ",mensaje);
   if(!bit_test(portb,2)){
      output_high(PIN_B2);}else{output_low(PIN_B2);}
   }//lateral 2

if (mensaje=='4' || datos==0x04){
printf("Presionaste el  %c \r ",mensaje);
output_LOW(PIN_B0);
output_LOW(PIN_B1);
output_LOW(PIN_B2);
}//presiona no

if (mensaje=='5' || datos==0x05){
printf("Presionaste el  %c \r ",mensaje);
output_high(PIN_B0);
output_high(PIN_B1);
output_high(PIN_B2);
}//presiona si

if (mensaje=='6' || datos==0x06){
printf("Presionaste el  %c \r ",mensaje);
output_high(PIN_B3);

}//presiona prender ampli


if (mensaje=='7' || datos==0x07){
printf("Presionaste el  %c \r ",mensaje);
output_low(PIN_B3);
}//presiona apagar ampli

if (mensaje=='8' || datos==0x08){
printf("Presionaste el  %c \r ",mensaje);
output_high(PIN_B4);
delay_ms(500);
output_low(PIN_B4);
}//Volumen menos

if (mensaje=='9' || datos==0x09){
printf("Presionaste el  %c \r ",mensaje);
output_high(PIN_B5);
delay_ms(500);
output_low(PIN_B5);
}//volumen mas
delay_ms(500);
while(datos!=0){
datos=input_a();}

}


int16 medicion=0;
int8 temper=0;



void main(){
int8 datos1;
enable_interrupts(INT_RDA);      //Habilita interrupción por recepción RS232
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
enable_interrupts(INT_TIMER0);
enable_interrupts(GLOBAL);       //Habilita interrupcion global
setup_adc_ports(AN0);// PUERTO A0 COMO ANAL
setup_adc(ADC_CLOCK_INTERNAL); // configuro ADC
set_TIMER0(50); //inicializa el timer0
SET_TRIS_A(0xff);
SET_TRIS_B(0x00);
SET_TRIS_C(0x80);
SET_TRIS_D(0x00);
SET_TRIS_E(0x0f);
portb=0;
portd=0;
portc=0;
output_high(PIN_C4);
while(true){
if(!input(PIN_E0)){
delay_ms(60);
if(!input(PIN_E0)){
if((!bit_test(portb,0)) || (!bit_test(portb,1)) || (!bit_test(portb,2)) ){
output_high(PIN_B0);
output_high(PIN_B1);
output_high(PIN_B2);}else{
output_low(PIN_B0);
output_low(PIN_B1);
output_low(PIN_B2);
}
}
}
if(!input(PIN_E1)){
delay_ms(50);
if(!input(PIN_E1)){
if(!bit_test(portb,3)){
output_high(PIN_B3);}else{
output_low(PIN_B3);
}
}
}
while((!input(PIN_E0)) || (!input(PIN_E1))){
}

datos1=input_A();
datos1=datos1>>1;
if (datos1!=0){
delay_ms(50);
datos1=input_A();
datos1=datos1>>1;
if (datos1!=0){
actuar(0,datos1);
}
}

}

/// FALTA PPONER LA DETECCION DE EL CODIGO DE RF!!!!!!!!!!!!!!!!!!!!!!!!!///
}
#int_TIMER0
void  TIMER0_isr(void) 
{int8 decimal;
int8 unidad;

output_toggle(PIN_D0);

set_adc_channel (0);                // Elige canal a medir RA0
delay_us (20);
medicion=read_adc ();              // Hace conversión AD 
temper=medicion*(0.48852);     // Pasa binario a °C
decimal=(temper/10)& 0b00001111;
unidad=((temper - (decimal*10)) & 0b00001111);

if (bit_test(portc,4)){
output_low(PIN_C4);delay_us (20);
portc=portc & 0b11110000 ;
portc=decimal | portc;
output_high(PIN_C5);}else{
output_low(PIN_C5);delay_us (20);
portc=portc & 0b11110000 ;
portc=unidad | portc;
output_high(PIN_C4);
}


set_TIMER0(217); //inicializa el timer0
}
