#ifndef ConnectToArduinoServerThreadH
#define ConnectToArduinoServerThreadH
#include "dslThread.h"
#include "arduino/atArduinoClient.h"
//---------------------------------------------------------------------------

using dsl::Thread;


class PACKAGE ConnectToArduinoServerThread : public dsl::Thread
{
	public:
    									ConnectToArduinoServerThread(ArduinoClient& c, int portNr);
    	void               				run();

    private:
		ArduinoClient&					mClient;
        int								mPort;
};



#endif
