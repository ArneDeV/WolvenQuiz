from time import sleep
import serial

def print_scores(lijst):
    for i in range(len(scores)):
        print(scores[i])
    print('\n')
    print('\n')


ser = serial.Serial('COM6', 9600)

scores = [0, 0, 0, 0, 0]  # ? Rood, wit, blauw, groen, geel
delayT = 3

while True:
    hello = ser.readline()
    test = hello.decode('ascii')
    test = float(test)
    #sleep(5)
    if (test == 0):
        scores[0] += 1
        print_scores(scores)
        test = 50
        sleep(3)
    elif (test == 1):
        scores[1] += 1
        print_scores(scores)
        test = 50
        sleep(3)
    elif (test == 2):
        scores[2] += 1
        print_scores(scores)
        test = 50
        sleep(3)
    elif (test == 3):
        scores[3] += 1
        print_scores(scores)
        test = 50
        sleep(3)
    elif (test == 4):
        scores[4] += 1
        print_scores(scores)
        test = 50
        sleep(3)