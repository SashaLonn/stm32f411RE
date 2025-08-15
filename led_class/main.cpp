#include"led_class.h"

Led led1(RED,ON);

LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

int main(void){
	
	USART2_Init();
	
	Led led2(BLUE,ON);
	Led led3 (YELLOW,ON);
	
	 led1_state= led1.getState();
	 led3_state =led3.getState();
	
	led1.setState(OFF);
	led1_state= led1.getState();




while(1){}
}