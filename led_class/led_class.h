#ifndef LED_H
#define LED_H
#include <stdint.h>
#include "stm32f4xx.h"                  // Device header
#include "uart.h" 



#define LED_PORT  GPIOB
#define LED_PORT_CLOCK (1u <<1)

#define  LED_RED_PIN  (1u<<14)
#define LED_GREEN_PIN (1u <<12)
#define LED_BLUE_PIN  (1u<<15)
#define LED_YELLOW_PIN (1u << 13)

#define LED_RED_MODE_BIT (1u<<29)
#define LED_GREEN_MODE_BIT (1u<<24)
#define LED_YELLOW_MODE_BIT (1u<<26)
#define LED_BLUE_MODE_BIT (1u<<30)



typedef enum{

	RED =0,
	GREEN,
	YELLOW,
	BLUE
	
}LedColor_Type;

typedef enum{
	
	OFF =0,
	ON =1
}LedState_Type;


/* Led's atributes */
class Led{
	private:
						LedColor_Type color; //Color of Led
						LedState_Type state; //state of Led
	
	public:
					Led(LedColor_Type _color,LedState_Type _state);
					void setState(LedState_Type _state);
					LedState_Type getState() const;// can't change value inside func
};


#endif