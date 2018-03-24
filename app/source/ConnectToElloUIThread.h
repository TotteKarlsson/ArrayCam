#ifndef ConnectToElloUIThreadH
#define ConnectToElloUIThreadH
#include "dslThread.h"
#include "ello/atElloUIClient.h"
//---------------------------------------------------------------------------

using dsl::Thread;
class PACKAGE ConnectToElloUIThread : public dsl::Thread
{
	public:
    									ConnectToElloUIThread(ElloUIClient& c, int portNr);
    	void               				run();

    private:
		ElloUIClient&					mClient;
        int								mPort;
};

#endif
