from gpiozero import LED
import time

led = LED(17) # GPIO Pin 17

while True:
    led.on()
    time.sleep(1) # in seconds
    led.off()
    time.sleep(1)