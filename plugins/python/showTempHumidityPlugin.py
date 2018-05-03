import dsl

def getPluginMetaData():
    pInfo = dsl.PluginMetaData("showTempHumidityPlugin", "Basic")
    pInfo.setAuthor("Totte Karlsson")
    pInfo.setDescription("Show Temperature and Humidity as a function of time")
    return pInfo

def getPluginProperties():
        props = dsl.Properties("TempAndHumidity")
        nrOfdays = dsl.intProperty(30, "Days")
        props.add(nrOfdays)
        print (props.count())
        return props


def multiply(a,b):
    print("Compute", a, "times", b)
    return a * b

def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

def main():
    props = getPluginProperties()

    print (props.count())

if __name__ == '__main__':
    main()

