#include "uart.h"


void USART2_Init(void){
	
// enable clock acces to uart
 RCC->APB1ENR |= 0x20000; // (1<< 17)
//enable click accses to port A
	RCC->AHB1ENR |=  0x01; //(1<<0)
//enable pins for AF,pa2, pa3
	GPIOA->MODER  &=~0x00F0; //(0b 1111 << 4)
  GPIOA->MODER  |=0x000A0;	//(0b0101 <<4)

//config type of AF
GPIOA->AFR[0] &= ~0xFF00;   // Rensa bitar för PA2 och PA3 (bits 15:8)
                            // ~ (0b1111 << 8 | 0b1111 << 12)
                            // = ~ (0xF00 | 0xF000) = ~0xFF00

GPIOA->AFR[0] |= 0x7700;    // Sätt AF7 (0b0111) för PA2 och PA3
                            // (0b0111 << 8) | (0b0111 << 12)
                            // = 0x700 | 0x7000 = 0x7700

//Config uart

	USART2->BRR = 0x683;
	USART2->CR1 = 0x000c;
	USART2->CR2 = 0x000;
	USART2->CR1 |= 0x2000;
	

}

FILE __stdout = {1};

int USART2_write( int ch){
	while(!(USART2->SR & 0x0080)){}
		USART2->DR = (ch &0xFF);
		
		return ch;

}
int USART2_read(void){
while(!(USART2->SR & 0x0020)){}
	return USART2->DR;

}

/* The code below is the interface to the C standart I/O library.
	All the I/O are directed to the console
*/



int fgetc(FILE *f) {
    int c;

    c = USART2_read();      /* read the character from console */

    if (c == '\r') {        /* if '\r', after it is echoed, a '\n' is appended*/
        USART2_write(c);    /* echo */
        c = '\n';
    }

    USART2_write(c);        /* echo */

    return c;
}

// Called by library console /file output

int fputc(int c, FILE *f){
	return USART2_write(c);
}

int n;
char str[80];
void test_setup(void){
	printf("plese enter a number: ");
	/*scanf("%d",&n);
	printf("the number enterred is %d\r\n",n);
	printf("plese typr a character string: ");
	gets(str);
	printf("the character string is: ");
	puts(str);
	printf("\r\n");*/
}





