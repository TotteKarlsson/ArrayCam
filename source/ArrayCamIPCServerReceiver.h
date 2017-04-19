#ifndef abArduinoIPCServerReceiverH
#define abArduinoIPCServerReceiverH
#include "mtkIPCReceiver.h"
#include "mtkIPCServer.h"
//---------------------------------------------------------------------------

class ArrayCamIPCReceiver : public mtk::IPCReceiver
{
    public:
						        		ArrayCamIPCReceiver(int portNr = -1, int socket_handle = -1, mtk::IPCServer* server = NULL);
						        		~ArrayCamIPCReceiver();
		virtual void                    Worker();

    protected:

};

#endif
