# ifndef __UART_H
#define  __UART_H


#include "stm32f4xx.h"
#include "RTE_Components.h" 
#include <stdio.h>


void USART2_Init(void);
void test_setup(void);
int USART2_write( int ch);


#endif