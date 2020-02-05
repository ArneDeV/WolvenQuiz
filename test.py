from time import sleep
import serial

def print_scores(lijst):
    for i in range(len(lijst)):
        print(lijst[i])

ser = serial.Serial('COM7', 9600)

scores = [0, 0, 0, 0, 0]  # ? Rood, wit, blauw, groen, geel
delayT = 3

while True:
    hello = ser.readline()
    test = hello.decode('ascii')
    #sleep(5)
    if ('b' in test):
        scores[0] += 1
        # print(scores[0])
        print(scores[0])
        test = 'n'
        sleep(3)
        hello = ser.read(1)
'''    elif (hello == 'w'):
        scores[1] += 1
        print_scores(scores)
    elif (hello == 'b'):
        scores[2] += 1
        print_scores(scores)
    elif (hello == 'g'):
        scores[3] += 1
        print_scores(scores)
    elif(hello == 'y'):
        scores[4] += 1
        print_scores(scores) '''
