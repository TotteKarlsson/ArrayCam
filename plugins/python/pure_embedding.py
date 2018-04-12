import sys
import numpy
import cv2

def multiply(a,b):
    print("Will compute", a, "times", b)
    c = 0
    for i in range(0, a):
        c = c + b
    return c

def execute(a, b):
    print ("We are executing ..")
    multiply(a,b)

if __name__ == '__main__':
    execute()