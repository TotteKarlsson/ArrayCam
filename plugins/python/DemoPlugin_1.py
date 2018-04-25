#import atexplorer
import dslfoundation

import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def getPluginMetaData():
    data = dslfoundation.PluginMetaData("DemoPlugin_1", "tests")
    data.setAuthor("Totte Karlsson")
    data.setDescription("Hello, Hello")
    data.add("Custom field", "Custom field value")
    # Data for plotting
    t = np.arange(0.0, 2.0, 0.01)
    s = 1 + np.sin(2 * np.pi * t)

    # Note that using plt.subplots below is equivalent to using
    # fig = plt.figure() and then ax = fig.add_subplot(111)
    fig, ax = plt.subplots()
    ax.plot(t, s)

    ax.set(xlabel='time (s)', ylabel='voltage (mV)',
           title='About as simple as it gets, folks')
    ax.grid()


    plt.show()

    return data

#def getAnAtObject():
#    a = atexplorer.ATObject()
#    return a

def multiply(a,b):
    print("Will compute", a, "times", b)
    return a * b

def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

#if __name__ == '__main__':
#    execute()import sys
