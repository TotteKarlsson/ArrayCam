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

    StringList msgList(msg, ',');

    /* CAMERA */
    if(compareStrings(ap[acrStartVideoRecorder], msgList[0], csCaseInsensitive))
    {
    	Log(lInfo) << "Starting recording video";
        TThread::Synchronize(NULL, mMainForm.startRecordingMovie);

    }
    else if(compareStrings(ap[acrStopVideoRecorder], msgList[0], csCaseInsensitive))
    {
    	Log(lInfo) << "Stop recording video";
       	TThread::Synchronize(NULL, mMainForm.stopRecordingMovie);

    }

    else if(compareStrings(ap[acrTakeSnapShot], msgList[0], csCaseInsensitive))
    {
    	Log(lInfo) << "Take snapshot";
        TThread::Synchronize(NULL, mMainForm.takeSnapShot);
    }

	/* Navitar controller */
    else if(compareStrings(ap[acrSetZoomAndFocus], msgList[0], csCaseInsensitive))
    {

    	Log(lInfo) << "Setting Navitar zoom and focus";

        struct TLocalArgs
	    {
    	    int focus;
            int zoom;
	        TMainForm*	MainForm;
        	void __fastcall setZoomAndFocus()
	        {
    	        MainForm->setFocusAndZoom(focus, zoom);
        	}
    	};

    	TLocalArgs Args;

        if(msgList.count() == 3)
        {
	    	Args.focus = toInt(msgList[1]);
	        Args.zoom = toInt(msgList[2]);
        }

        Args.MainForm = &mMainForm;

        TThread::Synchronize(NULL, Args.setZoomAndFocus);
    }

	/* Barcode Scanner */
    else if(compareStrings(ap[acrEnableBarcodeScanner], msgList[0], csCaseInsensitive))
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

    else if(compareStrings(ap[acrDisableBarcodeScanner], msgList[0], csCaseInsensitive))
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

    else if(compareStrings("GET_SERVER_STATUS", msgList[0], csCaseInsensitive))
    {
    	Log(lInfo) << "Broadcast status";
		broadcastStatus();
    }

    else
    {
    	Log(lError) << "UNHANDLED SERVER MESSAGE: "<<msgList[0];
    }

    if(clientMessage.str().size())
    {
   		notifyClients(clientMessage.str());
    }
    return msg.IsProcessed();
}
