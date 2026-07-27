#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "drivers/uart.h"

typedef enum{
	GREEN = 0,
	ORANGE,
	RED,
	BLUE
}LEDColor_Type;

typedef enum{
	OFF = 0,
	ON
}LEDState_Type;

typedef struct{
	LEDColor_Type color;
	LEDState_Type state;
	uint32_t last_update;
}LED_Type;

void LED_constructor(LED_Type* const me, LEDColor_Type _color, LEDState_Type _state);

void LED_SetState(LED_Type * const me, LEDState_Type _state);

LEDState_Type LED_GetState(LED_Type * const me);

#endif
