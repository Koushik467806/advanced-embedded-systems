#include "powerLed.h"

void PowerLED_constructor(PowerLED_Type* const me,
		                  LEDColor_Type _color,
						  LEDState_Type _state,
						  LEDDiameter_Type _diameter,
						  LEDCurrent_Type _current,
						  LEDVoltage_Type _voltage){
	LED_constructor(&me->super, _color, _state);
	me->diameter = _diameter;
	me->voltage = _voltage;
	me->current = _current;
}

void PowerLED_setCurrent(PowerLED_type* const me, LEDCurrent_Type _current){
	me->current = _current;
}

void PowerLED_setDiameter(PowerLED_type* const me, LEDDiameter_Type _diameter){
	me->diameter = _diameter;
}

void PowerLED_setVoltage(PowerLED_type* const me, LEDVoltage_Type _voltage){
	me->voltage = _voltage;
}

led_elec_type PowerLED_computePower(PowerLED_type* const me){
	return (me->current)*(me->voltage);
}

led_elec_type PowerLED_getCurrent(PowerLED_type* const me){
	return me->current;
}

led_elec_type PowerLED_getDiameter(PowerLED_type* const me){
	return me->diameter;
}

led_elec_type PowerLED_getVoltage(PowerLED_type* const me){
	return me->voltage;
}
