import sys
import numpy
import cv2

def getPluginMetaData():
    data = {}
    data["Author"] = "Totte Karlsson"
    data["Name"]   = __name__
    return data


def multiply(a,b):
    print("Will compute", a, "times", b)
    return a * b

def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

#if __name__ == '__main__':
#    execute()