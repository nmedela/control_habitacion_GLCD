//////////////////////////////////////////////////////////////////////////////////////////////
//Este programa sirve para revisar la correcta conexión entre el PIC18F4550 y             //
//el modulo ENC28J60, crea un WebServer en la direccion IP 192.168.1.111               //
//El cual muestra el siguiente mensaje "Test Conexión PIC18F4550 y ENC28J60 V1.0"          //
//También emula un puerto serial en el PC donde vamos viendo como se desarrolla el programa //                                                         //
//////////////////////////////////////////////////////////////////////////////////////////////

#include <18F4550.h>

#fuses HSPLL,MCLR,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN   // Ocupa cristal 4Mhz, cambiar a PLL5 para ocuparlo con 20Mhz.
#use delay(clock=48000000)

#define  ON    output_high
#define  OFF   output_low

#define  LedV  PIN_B4
#define  LedR  PIN_B2

// Conexión entre el PIC18F4550 y el Modulo ENC28J60 (Se conecta directamente sin adaptador de voltajes).
// Se adjunta el datasheet del Modulo ENC28J60.

#define  PIN_ENC_MAC_SO    PIN_C7   // Conectar con PIN MISO del ENC28J60.
#define  PIN_ENC_MAC_SI    PIN_B0   // Conectar con PIN MOSI del ENC28J60. 
#define  PIN_ENC_MAC_CLK   PIN_B1   // Conectar con PIN SCK del ENC28J60. 
#define  PIN_ENC_MAC_CS    PIN_B3   // Conectar con PIN CS del ENC28J60. 
#define  PIN_ENC_MAC_RST   PIN_B5   // Conectar con PIN RST del ENC28J60. 
#define  PIN_ENC_MAC_INT   PIN_D2   // Conectar con PIN INT del ENC28J60. 
#define  PIN_ENC_MAC_WOL   PIN_D3   // Conectar con PIN WOL del ENC28J60. 




//Protocolos a utilizar.

#define  STACK_USE_MCPENC  TRUE
#define  STACK_USE_ARP     TRUE
#define  STACK_USE_ICMP    TRUE
#define  STACK_USE_TCP     TRUE

#include "tcpip/stacktsk.c"

#define MY_HTTP_SOCKET  80

int8 HTTPSocket=INVALID_SOCKET;

// Microchip VendorID, MAC: 00-04-A3-XX-XX-XX
void MACAddrInit(void)
{
   MY_MAC_BYTE1=0x00;
   MY_MAC_BYTE2=0x04;
   MY_MAC_BYTE3=0xA3;
   MY_MAC_BYTE4=0x00;
   MY_MAC_BYTE5=0x00;
   MY_MAC_BYTE6=0x01;
}

void IPAddrInit(void)
{
   //Direccion IP
   MY_IP_BYTE1=192;
   MY_IP_BYTE2=168;
   MY_IP_BYTE3=1;
   MY_IP_BYTE4=111;

   //Puerta de Enlace
   MY_GATE_BYTE1=192;
   MY_GATE_BYTE2=168;
   MY_GATE_BYTE3=1;
   MY_GATE_BYTE4=1;

   //Mascara de Subred
   MY_MASK_BYTE1=255;
   MY_MASK_BYTE2=255;
   MY_MASK_BYTE3=255;
   MY_MASK_BYTE4=0;
}

void HTTPPut(char c)
{
   TCPPut(HTTPSocket, c);
}

void HTTPTask(void)
{
   static enum {HTTP_ST_CONNECT=0, HTTP_ST_WAIT_CONNECT=1, HTTP_ST_GET=2, HTTP_ST_PUT=3, HTTP_ST_DISCONNECT=4} state=0;
   static TICKTYPE timeout_counter;
   static char lc, lc2;
   char c;
   char content[250];
   
   if (HTTPSocket==INVALID_SOCKET)
      state=HTTP_ST_CONNECT;
   else if (!TCPIsConnected(HTTPSocket))
      state=HTTP_ST_WAIT_CONNECT;
   else if (TickGetDiff(TickGet(), timeout_counter) > TICKS_PER_SECOND*60)
      state=HTTP_ST_DISCONNECT;

   switch(state) {
      case HTTP_ST_CONNECT:
         HTTPSocket=TCPListen(MY_HTTP_SOCKET);
         if (HTTPSocket!=INVALID_SOCKET) {
           //printf(usb_cdc_putc,"\r\nHTTP: Listening");
            state=HTTP_ST_WAIT_CONNECT;
            timeout_counter=TickGet();
         }
         break;

      case HTTP_ST_WAIT_CONNECT:
         timeout_counter=TickGet();
         if (TCPIsConnected(HTTPSocket)) {
            state=HTTP_ST_GET;
            //printf(usb_cdc_putc,"\r\nHTTP: Connected");
         }
         break;

      case HTTP_ST_GET:
         if (TCPIsGetReady(HTTPSocket)) {
            while (TCPGet(HTTPSocket, &c)) {
               if ( (c=='\n') && (lc2=='\n') ) {
                  state=HTTP_ST_PUT;
                 // printf(usb_cdc_putc,"\r\nHTTP: Got Page Request");
               }
               lc2=lc;
               lc=c;
            }
         }
         break;

      case HTTP_ST_PUT:
         if (TCPIsPutReady(HTTPSocket)) {
            //printf(usb_cdc_putc,"\r\nHTTP: Putting Page Response");
            sprintf(content, "<HTML><HEAD><TITLE>WebServer PIC18F4550 ENC28J60</TITLE></HEAD><BODY><H1>Test Conexión PIC18F4550 y ENC28J60 V1.0</H1>");
            sprintf(&content[0]+strlen(content),"</BODY></HTML>");
            printf(HTTPPut, "HTTP/1.1 200 OK\r\n");
            printf(HTTPPut, "Content-Type: text/html\r\n");
            printf(HTTPPut, "Content-Length: %u\r\n",strlen(content));
            printf(HTTPPut, "\r\n");
            printf(HTTPPut, "%s", content);
            //printf(usb_cdc_putc,"\r\nHTTP: Flushing...");
            TCPFlush(HTTPSocket);
            //printf(usb_cdc_putc,"\r\nHTTP: Flushed!");
            state=HTTP_ST_GET;
         }
         break;

      case HTTP_ST_DISCONNECT:
         if (TCPIsPutReady(HTTPSocket)) {
            //printf(usb_cdc_putc,"\r\nHTTP: Force Disconnect");
            TCPDisconnect(HTTPSocket);
            state=HTTP_ST_WAIT_CONNECT;
         }
         break;
   }
}

void main(void)
{
   ON(LedR);
   OFF(LedV);
   
 

   MACAddrInit();
   IPAddrInit();
   StackInit();

    

   while(TRUE)
   {      
      StackTask();
      HTTPTask();
      ON(LedV);
   OFF(LedR);  
   }
}
