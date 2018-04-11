#ifndef TestPluginH
#define TestPluginH
#include "dslPluginWithEvents.h"
#include "dslProperty.h"
#include "TestPluginWorker.h"
#include "PluginExporter.h"
//---------------------------------------------------------------------------
using dsl::PluginWithEvents;
using dsl::PluginManager;
using dsl::DSLObject;
using dsl::Property;
using dsl::Plugin;

class TestPlugin : public PluginWithEvents
{
    friend class TestPluginWorker;
    public:
                                        TestPlugin(PluginManager* manager);
                                        ~TestPlugin();

        bool                            execute(DSLObject* obj, bool inThread);
        virtual void                    setPropertyValue(const string& nameOf, const void* value);
        int                             TestConnection();
        int                             TestConnectionByToken(string& theToken);

    private:
        Property<int>                   mUpdateDelay;
        TestPluginWorker      			mWorker;
};

extern "C"
{
    PLUGIN_DS Plugin*   createPlugin(void* manager);
    PLUGIN_DS bool      destroyPlugin(Plugin* p);
}


#endif