#ifndef ConnectToArduinoServerThreadH
#define ConnectToArduinoServerThreadH
#include "mtkThread.h"
#include "arduino/atArduinoClient.h"
//---------------------------------------------------------------------------

using mtk::Thread;


class PACKAGE ConnectToArduinoServerThread : public mtk::Thread
{
	public:
    									ConnectToArduinoServerThread(ArduinoClient& c, int portNr);
    	void               				run();

    private:
		ArduinoClient&					mClient;
        int								mPort;
};



#endif
