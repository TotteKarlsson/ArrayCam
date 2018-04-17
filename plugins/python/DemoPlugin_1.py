import sys
import numpy
import cv2

def getPluginMetaData():
    pass

def multiply(a,b):
    print("Will compute", a, "times", b)
    return a * b

def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

#if __name__ == '__main__':
#    execute()