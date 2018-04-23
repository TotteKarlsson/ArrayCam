import atexplorer
import dslfoundation

def getPluginMetaData():
    data = dslfoundation.PluginMetaData("DemoPlugin_1", "tests")
    data.setAuthor("Totte Karlsson")
    data.setDescription("Hello, Hello")
    data.add("Custom field", "Custom field value")
    return data

def getAnAtObject():
    a = atexplorer.ATObject()
    return a

def multiply(a,b):
    print("Will compute", a, "times", b)
    return a * b

def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

#if __name__ == '__main__':
#    execute()import sys
