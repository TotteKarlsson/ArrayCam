#ifndef TestPluginWorkerH
#define TestPluginWorkerH
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
//---------------------------------------------------------------------------

class TestPlugin;

class PythonPluginWorker : public Poco::Runnable
{
    protected:
        Poco::Thread            mThread;
        TestPlugin&   			mTheHost;

    public:
                                PythonPluginWorker(TestPlugin& mTheHost);
        bool                    start(bool useThread = true);
        void                    run();
        bool                    isRunning() const;
};

#endif
