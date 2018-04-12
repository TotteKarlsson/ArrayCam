#pragma hdrstop
#include "PythonPlugin.h"
#include "dslLogger.h"
#include "dslException.h"
//---------------------------------------------------------------------------

using Poco::DateTimeFormatter;
using namespace dsl;

//---------------------------------------------------------------------------
PythonPlugin::PythonPlugin(PluginManager* manager)
:
PluginWithEvents( "PythonPlugin",   "Test Plugin With Events", manager),
mWorker(*this)
{
    mVersion = "1.0.0";

    //Setup the plugins properties
//    mProperties.add(&mAnInteger);
    mHint       = "Python Plugin";
    mDescription= "Set this up by running init function in the Python";
}

PythonPlugin::~PythonPlugin()
{}

bool PythonPlugin::execute(DSLObject* subject, bool inThread)
{
    Log(lInfo)<<"Testing Plugin";

    //go away and carry out the work in a thread, or not if inThread is false
    return mWorker.start(inThread);
}

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

static int gPluginCount = 0;


namespace dsl
{
    // Plugin factory function
    Plugin* createPlugin(void* manager)
    {
        //allocate a new plugin object and return it
        Plugin* p = new PythonPlugin((PluginManager*) manager);
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
}
