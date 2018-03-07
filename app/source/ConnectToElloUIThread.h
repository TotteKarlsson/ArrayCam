#ifndef ConnectToElloUIThreadH
#define ConnectToElloUIThreadH
#include "mtkThread.h"
#include "ello/atElloUIClient.h"
//---------------------------------------------------------------------------

using mtk::Thread;
class PACKAGE ConnectToElloUIThread : public mtk::Thread
{
	public:
    									ConnectToElloUIThread(ElloUIClient& c, int portNr);
    	void               				run();

    private:
		ElloUIClient&					mClient;
        int								mPort;
};

#endif
