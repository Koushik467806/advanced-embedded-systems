#include "led.h"


void LED_constructor(LED_Type* const me, LEDColor_Type _color, LEDState_Type _state){
	me->color = _color;
	me->state = _state;

	RCC->AHB1ENR |= LED_PORT_CLOCK;

	switch(_color){
	case RED:
		LED_PORT->MODER &= ~LED_RED_MODE_CLEAR;
		LED_PORT->MODER |= LED_RED_MODE_BIT;
		if(me->state == ON){
			LED_PORT->ODR |= LED_RED_PIN;
		}
		else{
			LED_PORT->ODR &= ~LED_RED_PIN;
		}
		break;
	case GREEN:
		LED_PORT->MODER &= ~LED_GREEN_MODE_CLEAR;
		LED_PORT->MODER |= LED_GREEN_MODE_BIT;
		if(me->state == ON){
			LED_PORT->ODR |= LED_GREEN_PIN;
		}
		else{
			LED_PORT->ODR &= ~LED_GREEN_PIN;
		}
		break;
	case ORANGE:
		LED_PORT->MODER &= ~LED_ORANGE_MODE_CLEAR;
		LED_PORT->MODER |= LED_ORANGE_MODE_BIT;
		if(me->state == ON){
			LED_PORT->ODR |= LED_ORANGE_PIN;
		}
		else{
			LED_PORT->ODR &= ~LED_ORANGE_PIN;
		}
		break;
	case BLUE:
		LED_PORT->MODER &= ~LED_BLUE_MODE_CLEAR;
		LED_PORT->MODER |= LED_BLUE_MODE_BIT;
		if(me->state == ON){
			LED_PORT->ODR |= LED_BLUE_PIN;
		}
		else{
			LED_PORT->ODR &= ~LED_BLUE_PIN;
		}
		break;
	}
}

void LED_SetState(LED_Type * const me, LEDState_Type _state){
    me->state = _state;

    uint32_t pin = 0;
    switch(me->color){
        case RED:    pin = LED_RED_PIN;    break;
        case GREEN:  pin = LED_GREEN_PIN;  break;
        case ORANGE: pin = LED_ORANGE_PIN; break;
        case BLUE:   pin = LED_BLUE_PIN;   break;
    }

    if(me->state == ON){
        LED_PORT->ODR |= pin;
    } else {
        LED_PORT->ODR &= ~pin;
    }
}

LEDState_Type LED_GetState(LED_Type * const me){
	return me->state;
}
