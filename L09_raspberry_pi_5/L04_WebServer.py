from flask import Flask
from gpiozero import LED, Button

# App to toggle between 3 LEDs when push button is pressed

led_list = [LED(17), LED(27), LED(22)] # LEDs at GPIO pins 17, 27 and 22
button = Button(26) # Button at GPIO pin 26

app = Flask(__name__)

# Main webpage
@app.route("/")
def index():
    return "Hello from Raspberry Pi 5!"

# To check if button is pressed
# Refresh to check (does'nt auto refresh)
@app.route("/push-button")
def press():
    if button.is_pressed:
        return "Button is pressed"
    return "Button is not pressed"

# Input led number and state as numbers in the link to turn on/off a specific LED
@app.route("/led/<int:led_number>/state/<int:state>")
def switch_led(led_number, state):
    # 3 LEDs only -- 0, 1, 2
    if led_number < 0 or led_number >= len(led_list):
        return "LED Number " + str(led_number) + " is invalid"
    # 0 - OFF, 1 - ON
    if state not in (0, 1):
        return "State " + str(state) + " is invalid"
    if state == 0:
        led_list[led_number].off()
    else:
        led_list[led_number].on()
    return "OK"

# Run on localhost port 5000
app.run(host="0.0.0.0", port=5000)

