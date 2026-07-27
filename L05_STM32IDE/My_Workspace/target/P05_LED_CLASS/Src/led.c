#include "led.h"


void LED_constructor(LED_Type* const me, LEDColor_Type _color, LEDState_Type _state){
	me->color = _color;
	me->state = _state;
}

void LED_SetState(LED_Type * const me, LEDState_Type _state){
	me->state = _state;

	switch(me->color){
	case GREEN:
		printf("The GREEN LED is set to %d\r\n", me->state);
		break;
	case ORANGE:
		printf("The ORANGE LED is set to %d\r\n", me->state);
		break;
	case RED:
		printf("The RED LED is set to %d\r\n", me->state);
		break;
	case BLUE:
		printf("The BLUE LED is set to %d\r\n", me->state);
		break;
	default:
		printf("ERROR!");
		break;
	}
}

LEDState_Type LED_GetState(LED_Type * const me){
	return me->state;
}
