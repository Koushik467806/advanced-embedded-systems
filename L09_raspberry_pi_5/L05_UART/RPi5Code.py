import serial
import time

# (port, baudrate, timeout) - timeout tells when to stop
# Use ls /dev/tty* to find port
# Plug in and remove arduino to find the port
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(3) # Wait for 3 seconds so that arduino can start
ser.reset_input_buffer() # Erase everything which happens during time.sleep()
print('Serial OK')

def send_and_receive(number):
    # Send data to Arduino (must be encoded to bytes + end with '\n')
    message = f"{number}\n"
    ser.write(message.encode('utf-8'))
    print(f"Sent to Arduino: {number}")

    # Read the response
    response = ser.readline().decode('utf-8').rstrip() # rstrip() removes the '\n' from the received message
    if response:
        print(f"{response}\n")

try:
    while True:
        i = int(input("Enter a number: "))
        send_and_receive(i)
        time.sleep(1)
except KeyboardInterrupt: # Exit when Ctrl+C is pressed
    print("Closing connection")
    ser.close()
