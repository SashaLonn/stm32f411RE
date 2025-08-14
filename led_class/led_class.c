#include "led_class.h"



void Led_ctor(Led_Type * const me, LedColor_Type _color,LedState_Type _state){

	me->color = _color;
	me->state = _state;
	
		/*Hardware INIT*/
	
	RCC->AHB1ENR |= LED_PORT_CLOCK;
	
	switch(_color){
		
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
		if (me->state ==ON){
				LED_PORT->ODR |=LED_RED_PIN;
			printf("RED LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_RED_PIN;
			printf("RED LDE is set off \n\r");
		}
		break;
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
		if (me->state ==ON){
				LED_PORT->ODR |=LED_GREEN_PIN;
			printf("GREEN LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_GREEN_PIN;
			printf("GREEN LDE is set off \n\r");
		}
		break;
		case BLUE:
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;
		if (me->state ==ON){
				LED_PORT->ODR |=LED_BLUE_PIN;
			printf("BLUE LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_BLUE_PIN;
			printf("BLUE LDE is set off \n\r");
		}
		break;
		
		case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
		if (me->state ==ON){
				LED_PORT->ODR |=LED_YELLOW_PIN;
			printf("YELLOW LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_YELLOW_PIN;
			printf("YELLOW LDE is set off \n\r");
		}
		break;
		
	
	}
	
	


}

void Led_setState(Led_Type *const me,LedState_Type _state){
	
	me->state = _state;

	switch(me->color){
		
		case RED:
			LED_PORT->MODER |= LED_RED_MODE_BIT;
			if (me->state ==ON){
				LED_PORT->ODR |=LED_RED_PIN;
				printf("RED LDE is set on \n\r");
		} 
			else{
				LED_PORT->ODR &= ~LED_RED_PIN;
				printf("RED LDE is set off \n\r");
		}
		break;
		case GREEN:
			LED_PORT->MODER |= LED_GREEN_MODE_BIT;
			if (me->state ==ON){
				LED_PORT->ODR |=LED_GREEN_PIN;
				printf("GREEN LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_GREEN_PIN;
			printf("GREEN LDE is set off \n\r");
		}
		break;
		case BLUE:
			LED_PORT->MODER |= LED_BLUE_MODE_BIT;
		if (me->state ==ON){
				LED_PORT->ODR |=LED_BLUE_PIN;
			printf("BLUE LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_BLUE_PIN;
			printf("BLUE LDE is set off \n\r");
		}
		break;
		
		case YELLOW:
			LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
		if (me->state ==ON){
				LED_PORT->ODR |=LED_YELLOW_PIN;
			printf("YELLOW LDE is set on \n\r");
		} 
		else{
		LED_PORT->ODR &= ~LED_YELLOW_PIN;
			printf("YELLOW LDE is set off \n\r");
		}
		break;
		
		
	}

}
LedState_Type Led_getState(Led_Type *const me){
	
			switch(me->color){
		
		case RED:
			printf("The RED led is currently %d\n\r",me->state);
			break;
		case GREEN:	
			printf("The GREEN led is currently%d\n\r",me->state);
			break;
		case BLUE:	
			printf("The BLUE led is currently %d\n\r",me->state);
			break;
		case YELLOW:	
			printf("The YELLOW led is currently %d\n\r",me->state);
			break;
		
		
	}
	
	return me->state;

}
