from gpiozero import Button, LED

led = LED(17) # GPIO pin 17 is LED
button = Button(26) # GPIO pin 26 is Button

while True:
    if button.is_pressed: # 1 if pressed, 0 if not (boolean)
        led.on()
    else:
        led.off()