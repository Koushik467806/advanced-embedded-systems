#ifndef _POWERLED_H
#define _POWERLED_H

#include <stdint.h>
#include "led.h"

typedef uint8_t led_elec_type;
typedef uint8_t led_dim_type;

typedef enum{
	CURR_LOW = 10,
	CURR_NORMAL = 20,
	CURR_HIGH = 35,
	CURR_VERY_HIGH = 60
}LEDCurrent_Type;

typedef enum{
	DIAM_2MM = 2,
	DIAM_5MM = 5,
	DIAM_7MM = 7
}LEDDiameter_Type;

typedef enum{
	VOL_LOW = 3,
	VOL_NORMAL = 5,
	VOL_HIGH = 9
}LEDVoltage_Type;

typedef struct{
	LED_Type super;
	LEDDiameter_Type diameter;
	LEDCurrent_Type current;
	LEDVoltage_Type voltage;
}PowerLED_Type;

void PowerLED_constructor(PowerLED_Type* const me,
		                  LEDColor_Type _color,
						  LEDState_Type _state,
						  LEDDiameter_Type _diameter,
						  LEDCurrent_Type _current,
						  LEDVoltage_Type _voltage);

void PowerLED_setCurrent(PowerLED_type* const me, LEDCurrent_Type _current);

void PowerLED_setDiameter(PowerLED_type* const me, LEDDiameter_Type _diameter);

void PowerLED_setVoltage(PowerLED_type* const me, LEDVoltage_Type _voltage);

led_elec_type PowerLED_computePower(PowerLED_type* const me);

led_elec_type PowerLED_getCurrent(PowerLED_type* const me);

led_elec_type PowerLED_getDiameter(PowerLED_type* const me);

led_elec_type PowerLED_getVoltage(PowerLED_type* const me);

#endif
