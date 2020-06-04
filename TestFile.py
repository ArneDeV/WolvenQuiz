 # Eerste test Serial
    

from time import sleep
import serial

ser = serial.Serial('COM5', 9600, timeout=1)

print(ser)
print(ser.is_open)
while True: 
    hello = ser.readline().decode('ascii')
    if (hello == ''):
        pass
    else:
        test = float(hello)
        print(test)
