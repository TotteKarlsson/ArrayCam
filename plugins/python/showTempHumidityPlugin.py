import dsl

def getPluginMetaData():
    pInfo = dsl.PluginMetaData("showTempHumidityPlugin", "Basic")
    pInfo.setAuthor("Totte Karlsson")
    pInfo.setDescription("Show Temperature and Humidity as a function of time")
    return pInfo

def getPluginProperties():
        props = dsl.Properties("TempAndHumidity")
        nrOfdays = dsl.intProperty(30, "Days")
        sProp   = dsl.stringProperty("sds", "String property")
        props.add(nrOfdays)
        props.add(sProp)
        return props


def execute(a, b):
    print ("We are executing ..")
    return multiply(a,b)

def main():
    a = dsl.intProperty(3, "sdasd")
    b = a
    b.getLabel()
    print(b.getLabel())


    pr = getPluginProperties()
    print(pr.count())
    a = pr.getProperty(0)
    a.getINIRecord()
    a.getLabel()

if __name__ == '__main__':
    main()

