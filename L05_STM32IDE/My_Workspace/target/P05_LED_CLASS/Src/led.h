#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "stm32f407xx.h"

#define LED_PORT           GPIOD
#define LED_PORT_CLOCK     (1U << 3)

#define LED_GREEN_PIN      (1U << 12)
#define LED_ORANGE_PIN     (1U << 13)
#define LED_RED_PIN        (1U << 14)
#define LED_BLUE_PIN       (1U << 15)

#define LED_GREEN_MODE_BIT     (1U << 24)
#define LED_ORANGE_MODE_BIT    (1U << 26)
#define LED_RED_MODE_BIT       (1U << 28)
#define LED_BLUE_MODE_BIT      (1U << 30)

#define LED_RED_MODE_CLEAR     (3U << 28)
#define LED_GREEN_MODE_CLEAR   (3U << 24)
#define LED_ORANGE_MODE_CLEAR  (3U << 26)
#define LED_BLUE_MODE_CLEAR    (3U << 30)

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
