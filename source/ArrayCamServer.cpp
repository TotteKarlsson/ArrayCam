#pragma hdrstop
#include "TMainForm.h"
#include "ArrayCamServer.h"
#include "mtkLogger.h"
#include "mtkSocketWorker.h"
#include "mtkStringUtils.h"
#include "arraycam/atArrayCamProtocol.h"
//---------------------------------------------------------------------------
using namespace mtk;

ArrayCamServer::ArrayCamServer(TMainForm& mf, int portNumber)
:
IPCServer(portNumber, "ARRAYCAM_SERVER", createArrayCamIPCReceiver),
mMainForm(mf)
{
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

    broadcast(msg);
}

string ArrayCamServer::IPCCommand(ACMessageID id)
{
	return mProtocol[id];
}

void ArrayCamServer::broadcastStatus()
{
    stringstream msg;
    msg << "IS_RECORDING="<<mtk::toString(mMainForm.mCaptureVideoTimer->Enabled);
   	notifyClients(msg.str());
}

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

	ArrayCamProtocol ap;
    //INCOMING MESSAGES ******************************************
    if(compareStrings(ap[acrStartVideoRecorder], msg, csCaseInsensitive))
    {
    	Log(lInfo) << "Starting recording video";
        TThread::Synchronize(NULL, mMainForm.startRecordingMovie);

    }
    else if(compareStrings(ap[acrStopVideoRecorder], msg, csCaseInsensitive))
    {
    	Log(lInfo) << "Stop recording video";
       	TThread::Synchronize(NULL, mMainForm.stopRecordingMovie);

    }

    else if(compareStrings(ap[acrTakeSnapShot], msg, csCaseInsensitive))
    {
    	Log(lInfo) << "Take snapshot";
        TThread::Synchronize(NULL, mMainForm.takeSnapShot);
    }

    else if(compareStrings(ap[acrEnableBarcodeScanner], msg, csCaseInsensitive))
    {
    	Log(lInfo) << "Enabling barcode scanner";
        if(mMainForm.DecodeSessionBtn->Caption == "Stop Scan")
        {
        	Log(lError) << "Scanner already enabled.";
        }
        else
        {
	        TThread::Synchronize(NULL, mMainForm.DecodeSessionBtn->Click);
        }
    }
    else if(compareStrings(ap[acrDisableBarcodeScanner], msg, csCaseInsensitive))
    {
    	Log(lInfo) << "Disable Barcode scanner";
        if(mMainForm.DecodeSessionBtn->Caption == "Scan Barcode")
        {
        	Log(lError) << "Scanner already disabled.";
        }
        else
        {
        	TThread::Synchronize(NULL, mMainForm.DecodeSessionBtn->Click);
        }
    }

    else if(compareStrings("GET_SERVER_STATUS", msg, csCaseInsensitive))
    {
    	Log(lInfo) << "Broadcast status";
		broadcastStatus();
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
