#pragma hdrstop
#include "TestPlugin.h"
#include "dslLogger.h"
#include "dslException.h"
#include "Poco/DateTimeFormatter.h"
#include "dslWin32Utils.h"
#include "dslFileUtils.h"
#include <Shlobj.h>
//---------------------------------------------------------------------------
#undef _DEBUG

using Poco::DateTimeFormatter;
using namespace dsl;

//---------------------------------------------------------------------------
TestPlugin::TestPlugin(PluginManager* manager)
:
PluginWithEvents( "TestPlugin",   "Test Plugin With Events", manager),
mUpdateDelay(100, "UpdateDelay"),
mWorker(*this)
{
    mVersion = "1.0.0";

    //Setup the plugins properties
    mProperties.add(&mUpdateDelay);
    mHint       = "Testing Plugin";
    mDescription= "Test Plugin with events";
}

TestPlugin::~TestPlugin()
{}

bool TestPlugin::execute(DSLObject* subject, bool inThread)
{
    Log(lInfo)<<"Testing Plugin";


    //go away and carry out the work in a thread
    return mWorker.start(inThread);
}

void TestPlugin::setPropertyValue(const string& nameOf, const void* value)
{
    BaseProperty* property = mProperties.getProperty(nameOf);
    if(property)
    {
        return Plugin::setPropertyValue(nameOf, value);
    }

    stringstream msg;
    msg<<"Failed setting property value. Plugin has no property with name: "<<nameOf;
    throw(DSLException(msg.str()));
}

int TestPlugin::TestConnection()
{
    return 0;
}

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

static int gPluginCount = 0;

// Plugin factory function
Plugin* createPlugin(void* manager)
{
    //allocate a new plugin object and return it
    Plugin* p = new TestPlugin((PluginManager*) manager);
    if(p)
    {
        gPluginCount++;
    }
    return p;
}

// Plugin factory function
bool destroyPlugin(Plugin* p)
{
    delete p;
    gPluginCount--;
    return true;
}
