#ifndef PythonPluginWorkerH
#define PythonPluginWorkerH
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
//---------------------------------------------------------------------------

class PythonPlugin;

class PythonPluginWorker : public Poco::Runnable
{
    protected:
        Poco::Thread            mThread;
        PythonPlugin&   			mTheHost;

    public:
                                PythonPluginWorker(PythonPlugin& mTheHost);
        bool                    start(bool useThread = true);
        void                    run();
        bool                    isRunning() const;
};

#endif
