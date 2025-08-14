#include "led_class.h"



void Led_ctor(Led_Type * const me, LedColor_Type _color,LedState_Type _state){

	me->color = _color;
	me->state = _state;


}

void Led_setState(Led_Type *const me,LedState_Type _state){
	
	me->state = _state;
	switch(me->color){
		
		case RED:
			printf("The RED led is set to %d\n\r",me->state);
			break;
		case GREEN:	
			printf("The GREEN led is set to %d\n\r",me->state);
			break;
		case BLUE:	
			printf("The BLUE led is set to %d\n\r",me->state);
			break;
		case YELLOW:	
			printf("The YELLOW led is set to %d\n\r",me->state);
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
