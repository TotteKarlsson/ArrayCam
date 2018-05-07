import dsl
import time

def getPluginMetaData():
    pInfo = dsl.PluginMetaData("showTempHumidityPlugin", "Basic")
    pInfo.setAuthor("Totte Karlsson")
    pInfo.setDescription("Show Temperature and Humidity as a function of time")
    return pInfo

def getPluginProperties():
        print("Retrieveing Plugin Properties")
        props = dsl.Properties("TempAndHumidity")
        nrOfdays = dsl.intProperty(30, "Days")
        sProp    = dsl.stringProperty("StringValue", "String property")
        props.add(nrOfdays)
        props.add(sProp)

        a = props.getProperty(0)
        val = a.getLabel()
        print("The label for the property: " + val)
        return props

def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

def main():
    try:
        pr = getPluginProperties()
        print(pr.count())

        print ("Got some plugin properties")

        a = pr.getProperty(0)
        val = a.getLabel()
        print("The label for the property: " + val)


        val = a.getINIRecord()
        print("The ini record for the property: " + val)

    except:
        print ("There was a problem")

if __name__ == '__main__':
    main()

