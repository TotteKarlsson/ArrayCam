import dsl
import time
import sys

def getPluginMetaData():
    #Plugin Name and Plugin Category
    pInfo = dsl.PluginMetaData("showTempHumidityPlugin", "Basic")
    pInfo.setAuthor("Totte Karlsson")
    pInfo.setDescription("Show Temperature and Humidity as a function of time")
    pInfo.setCopyright("Allen Institute for Brain Science, 2018")
    pInfo.setHint("Show Temperature History")
    pInfo.setCategory("Misc Plugins")
    return pInfo

def getPluginProperties():
        #Create the plugins properties
        props = dsl.Properties("TempAndHumidity")
        i1    = dsl.intProperty(30, "Days")
        props.add(i1)
        i1.thisown=0
        return props

def execute(val):
    print ("Get environmental data for the last consecutive " + str(val) + " days.")
    p = dsl.PluginManager.getPlugin(0)

    return val + 3

def main():
    try:
        res = execute(43)
        print("result is: " + str(res))

    except: # catch exceptions
        e = sys.exc_info()[0]
        print ("There was a problem: " + str(e))

if __name__ == '__main__':
    main()

