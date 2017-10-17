#ifndef atCreateThumbNailThreadH
#define atCreateThumbNailThreadH
#include "mtkThread.h"
#include <functional>
#include "Poco/Process.h"
#include "Poco/Timespan.h"
//---------------------------------------------------------------------------

typedef boost::function<void(int, int)> Callback;


class CreateThumbNailThread : public mtk::Thread
{
    public:
								CreateThumbNailThread();
								~CreateThumbNailThread();
		void					setFFMPEGLocation(const string& loc);
        void					setFFMPEGOutFileArguments(const string& args);
		void					setInputFile(const string& f);

		void					assignCallBacks(Callback one, Callback two, Callback three);

        virtual void            run();
        string 					getInputFileName();


    protected:
    	string					mFFMPEGLocation;
        string				    mFFMPEGOutFileArguments;
        string					mInputFileName;

	    Callback 				onEnter;
	    Callback 				onProgress;
	    Callback 				onExit;
        int						parseFFMPEGOutput(const string& str);
};


#endif
