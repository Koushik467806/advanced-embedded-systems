from gpiozero import LED, Button
from signal import pause

led1 = LED(17) # GPIO pin 17 is LED
led2 = LED(27) # GPIO pin 27 is LED
led3 = LED(22) # GPIO pin 22 is LED
button = Button(26, bounce_time = 0.05) # GPIO pin 26 is Button

# bounce_time = 0.05 limits to 20cps (50ms per push) and this is necessary due to
# mechanical error of push button where we might see multiple 
# toggles even though we pressed only once

index = 0

def switch_led():
    global index

    if index % 3 == 0:
        led1.on()
        led2.off()
        led3.off()
    elif index % 3 == 1:
        led1.off()
        led2.on()
        led3.off()
    else:
        led1.off()
        led2.off()
        led3.on()

    index += 1

button.when_pressed = switch_led # We only give the pointer and not call the function
pause() # Pauses if there is no interrupt so that the code doesnt finish execution completely