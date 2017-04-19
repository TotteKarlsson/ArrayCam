#pragma hdrstop
#include "TMainForm.h"
#include "ArrayCamServer.h"
#include "mtkLogger.h"
#include "atArduinoIPCServerReceiver.h"
#include "mtkSocketWorker.h"
#include "mtkStringUtils.h"

//---------------------------------------------------------------------------
using namespace mtk;

ArrayCamServer::ArrayCamServer(TMainForm& mf, int portNumber)
:
IPCServer(portNumber, "ARRAYCAM_SERVER", createArrayCamIPCReceiver),
mMainForm(mf)
{
    //Assign receive callbacks
//    mSensorsArrayCam.assignSerialMessageReceivedCallBack(sensorsArrayCamMessageReceived);
}

ArrayCamServer::~ArrayCamServer()
{}

void ArrayCamServer::assignOnUpdateCallBack(OnMessageUpdateCB cb)
{
	onMessageUpdateCB = cb;
}

bool ArrayCamServer::shutDown()
{
    IPCServer::shutDown();
    return true;
}

void ArrayCamServer::notifyClients(const string& msg)
{
	if(!msg.size())
    {
    	return;
    }

    if(onMessageUpdateCB)
    {
    	//This one is synchronized
        onMessageUpdateCB(msg);
    }

//    broadcast(msg);
}

void ArrayCamServer::broadcastStatus()
{
    stringstream msg;
   	notifyClients(msg.str());
}

////This is called from the arduino devices class upon receiving
////a message from the arduino thread over the serial port
////Socket clients are updated using the notifyClients funtion
//void ArrayCamServer::lightsArrayCamMessageReceived(const string& msg)
//{
//	notifyClients(msg);
//}

//Handle incoming client requests over the socket
//These messages are handled in a thread
//Depending on the message, a response may be sent using the
//notifyClients function
bool ArrayCamServer::processRequest(IPCMessage& msg)
{
    stringstream clientMessage;
    if(msg.isPacked())
    {
        msg.unPack();
    }

    //LIGHTS ARDUINO MESSAGES ******************************************
    if(startsWith("START_RECORDING_VIDEO", msg))
    {
    	Log(lInfo) << "Starting recording video";
        if(mMainForm.mRecordMovieBtn->Caption != "Record Movie")
        {
        	Log(lError) << "Can't start recording video..";
        }
        else
        {
	        TThread::Synchronize(NULL, mMainForm.mRecordMovieBtn->Click);
        }
    }
    else if(startsWith("STOP_RECORDING_VIDEO", msg))
    {
    	Log(lInfo) << "Stop recording video";
        if(mMainForm.mRecordMovieBtn->Caption != "Stop Recording")
        {
        	Log(lError) << "Can't stop recording video..";
        }
        else
        {
        	TThread::Synchronize(NULL, mMainForm.mRecordMovieBtn->Click);
        }
    }

    else if(startsWith("TAKE_SNAPSHOT", msg))
    {
    	Log(lInfo) << "Take snapshot";
        TThread::Synchronize(NULL, mMainForm.mSnapShotBtn->Click);
    }
    else
    {
    	Log(lError) << "UNHANDLED ARDUINO SERVER MESSAGE: "<<msg;
    }

    if(clientMessage.str().size())
    {
   		notifyClients(clientMessage.str());
    }
    return msg.IsProcessed();
}
