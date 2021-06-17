/****************************
idock v1.9.1
12-10-2020 -> 17-06-2021
actualizado con git
****************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stddef.h>
#include <string.h>

#define WAIT 50
#define HEADER USART_SendByte(0xFF);USART_SendByte(0x55);
#define MAXBUFFER 20
#define BAUD 19200
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

void USART_Init(void){
  UBRRH = (BAUDRATE>>8);
  UBRRL = BAUDRATE;
  UCSRB|= (1<<TXEN)|(1<<RXEN);
  UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

unsigned char USART_ReceiveByte( void ){
  while ( !(UCSRA &(1 << RXC)) );
  return UDR;
}

void USART_SendByte( unsigned char data ){
  while ( !( UCSRA &(1 << UDRE)) );
  UDR = data;
}

void USART_SendString (volatile char *send){
  while (*send) {
    USART_SendByte(*send++);
  }
}

void Terminal_Init(void){
      USART_SendString("\e[2J");
      USART_SendString("-----------------------------------------\n");
      USART_SendString("Welcome to iPod's UART\n");
      USART_SendString("-----------------------------------------\n\n");
      USART_SendString("Commands:\n");
      USART_SendString(":p - Play/Pause\n");
      USART_SendString(":r - Replay\n");
      USART_SendString(":rr - Prev Track\n");
      USART_SendString(":f - Next track\n");
      USART_SendString(":vm - Volume Up\n");
      USART_SendString(":mv - Volume Down\n");
      USART_SendString(":c - Clear Screen\n");
      USART_SendString(":h - Help\n");
}

/*comandos de iPod*/
void IPOD_Init(void){
  HEADER
  USART_SendByte(0x03);
  USART_SendByte(0x00);
  USART_SendByte(0x01);
  USART_SendByte(0x02);
  USART_SendByte(0xFA);
}
void sin_boton(void){
  HEADER
  USART_SendByte(0x03);
  USART_SendByte(0x02);
  USART_SendByte(0x00);
  USART_SendByte(0x00);
  USART_SendByte(0xFB);
  _delay_ms(WAIT);
}

/*programa principal*/
int main (void){
DDRD |= (1 << PD6)|(1 << PD5);//set PD6 as output LED on pin 11 (PD6)
USART_Init();
IPOD_Init();
Terminal_Init();
while(1){
    static char command[10] = {0}; //command 10 bytes
    int i =0;
    char tmp = 0;
    while((tmp=USART_ReceiveByte())!= 0x0D){ //carriage return
      command[i]=tmp;
      i++;
    }
    if(strcmp(command,":p")==0){
      PORTD &= ~((1 << PD6)|(1 << PD5));
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x01);
      USART_SendByte(0xFA);
      sin_boton();
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("PLAY\n");
    }
    else if(strcmp(command,":r")==0){
      PORTD &= ~((1 << PD6)|(1 << PD5));
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x10);
      USART_SendByte(0xeb);
      sin_boton();
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("RESTART\n");
    }
    else if(strcmp(command,":rr")==0){
      PORTD &= ~((1 << PD6)|(1 << PD5));
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x10);
      USART_SendByte(0xeb);
      sin_boton();
      _delay_ms(WAIT);
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x10);
      USART_SendByte(0xeb);
      sin_boton();
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("PREV TRACK\n");
    }
    else if(strcmp(command,":f")==0){
      PORTD &= ~((1 << PD6)|(1 << PD5));
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x08);
      USART_SendByte(0xf3);
      sin_boton();
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("FORWARD\n");
    }
    else if(strcmp(command,":vm")==0){
      PORTD &= ~((1 << PD6)|(1 << PD5));
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x02);
      USART_SendByte(0xf9);
      sin_boton();
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("VOLUME UP\n");
    }
    else if(strcmp(command,":mv")==0){
      PORTD &= ~((1 << PD6)|(1 << PD5));
      HEADER
      USART_SendByte(0x03);
      USART_SendByte(0x02);
      USART_SendByte(0x00);
      USART_SendByte(0x04);
      USART_SendByte(0xf7);
      sin_boton();
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("VOLUME DOWN\n");
    }
    else if(strcmp(command,":c")==0){
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("\e[2J");//esc sequence to clear screen
    }
    else if(strcmp(command,":h")==0){
      PORTD |= (1 << PD6)|(1 << PD5);
      Terminal_Init();
    }
    else{
      PORTD |= (1 << PD6)|(1 << PD5);
      USART_SendString("COMMAND NOT FOUND\n");
    }
    for(i=0;i<=9;i++){
      command[i] = 0;
    }
    tmp=0;
  }
}
