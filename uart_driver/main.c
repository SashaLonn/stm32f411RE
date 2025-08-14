#include "stm32f4xx.h"
#include "uart.h"



void delay(volatile uint32_t count){
    while(count--) {
        __NOP(); // gör inget, bara väntar
    }
}

void SystemClock_Config_16MHz(void) {
    // Starta HSI (internt 16 MHz)
    RCC->CR |= RCC_CR_HSION;
    while(!(RCC->CR & RCC_CR_HSIRDY)); // Vänta tills HSI är redo

    // Välj HSI som systemklocka
    RCC->CFGR &= ~RCC_CFGR_SW;       // Rensa system clock switch bits
    RCC->CFGR |= RCC_CFGR_SW_HSI;    // Välj HSI som system clock

    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI) {
        // Vänta tills HSI används som systemklocka
    }

    // Sätt flash latency (0 wait states för 16 MHz är OK)
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
}


int main(void) {
	
	SystemClock_Config_16MHz();
    // 1. Aktivera klocka till GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // 2. Ställ in PA5 som output (LD2)
    GPIOA->MODER &= ~(0x3 << (5 * 2)); // Rensa bitar för PA5
    GPIOA->MODER |=  (0x1 << (5 * 2)); // Sätt som general purpose output (01)

		USART2_Init();
	USART2_write('H');  // Skickar bokstaven 'H'
	USART2_write('\n');
		test_setup();
		//printf("Hej hej");
	while(1) {
    //    GPIOA->ODR ^= (1 << 5); // Växla PA5 (tänd/släck LED)
			
      //  delay(1000000);          // Vänta ungefär 1 sekund
    }
}
