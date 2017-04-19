#ifndef ArrayCamServerH
#define ArrayCamServerH
#include "mtkIPCServer.h"
#include "mtkSocketWorker.h"
#include <vector>
#include "mtkTimer.h"
//---------------------------------------------------------------------------
using mtk::IPCServer;
using mtk::IPCMessage;
using std::vector;

mtk::SocketWorker* createArrayCamIPCReceiver(int portNr, int socketHandle, void* parent);

typedef void (__closure *OnMessageUpdateCB)(const string& msg);

//!The ArrayCam server is a component that serve clients with ArrayCam connections over a
//tcp/ip socket. The ArrayCam server is designed to handle messages and data related to the
//arraybot project. The ArrayCam server is a descendant of the IPC server class that is implementing all
//network functionality.
//The ArrayCam server forwards any messages sent from the arduino board to any connected tcp/ip clients.

//There are currently two ArrayCam boards, the 'Lights' board, and a 'Sensor' board containing sensors and
//light controlling logic respectively.

class TMainForm;
class ArrayCamServer : public IPCServer
{
    public:
                                            ArrayCamServer(TMainForm& mf, int portNumber = 50000);
	                                        ~ArrayCamServer();

											//!Requests are sent to the server from a client.
                                            //!The process request is an overide from the IPCServer base class.
                                            //!ProcessRequest implements the ArrayCam server specific processing.
    	bool 					            processRequest(IPCMessage& msg);
        bool            		            shutDown();

        void								assignOnUpdateCallBack(OnMessageUpdateCB cb);
		void								onUpdateClientsTimer();
        void								broadcastStatus();

    protected:
        OnMessageUpdateCB					onMessageUpdateCB;
        TMainForm&							mMainForm;


        void								notifyClients(const string& msg);
};

#endif
