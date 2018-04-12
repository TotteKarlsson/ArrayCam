#ifndef PythonPluginH
#define PythonPluginH
#include "dslPluginWithEvents.h"
#include "dslProperty.h"
#include "PythonPluginWorker.h"
//---------------------------------------------------------------------------

using dsl::PluginWithEvents;
using dsl::PluginManager;
using dsl::DSLObject;
using dsl::Property;
using dsl::Plugin;

//A Python plugin loads a pytho interpreter and executes a python script in a thread
class PythonPlugin : public PluginWithEvents
{
    friend class PythonPluginWorker;
    public:
                                        PythonPlugin(PluginManager* manager);
                                        ~PythonPlugin();

                                        //!The first argument allow the client to set
                                        //the initial value of the property, anInt
        bool                            execute(DSLObject* obj, bool inThread);

    private:

                                        //!The worker is doing the work..
        PythonPluginWorker     			mWorker;
};


#endif
