#ifndef atVideoCompressorThreadH
#define atVideoCompressorThreadH
#include "mtkThread.h"
#include <functional>
#include "Poco/Process.h"
#include "Poco/Timespan.h"
//---------------------------------------------------------------------------

typedef boost::function<void(int, int)> Callback;


class VideoCompressorThread : public mtk::Thread
{
    public:
								VideoCompressorThread();
								~VideoCompressorThread();
		void					setFFMPEGLocation(const string& loc);
        void					setFFMPEGOutFileArguments(const string& args);
		void					setInputFile(const string& f);
		void					assignCallBacks(Callback one, Callback two, Callback three);
        virtual void            run();

    protected:
    	string					mFFMPEGLocation;
        string				    mFFMPEGOutFileArguments;
        string					mInputFile;
	    Callback 				onEnter;
	    Callback 				onProgress;
	    Callback 				onExit;
	    Poco::Timespan 			mEstimatedDuration;
        int						parseFFMPEGOutput(const string& str);
};
#endif
