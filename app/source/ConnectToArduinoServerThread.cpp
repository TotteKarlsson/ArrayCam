#pragma hdrstop
#include "ConnectToArduinoServerThread.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
using namespace mtk;

ConnectToArduinoServerThread::ConnectToArduinoServerThread(ArduinoClient& c, int p)
:
mClient(c),
mPort(p)
{}

void ConnectToArduinoServerThread::run()
{
	mIsRunning = true;
	Log(lDebug3) << "Trying to connect to Arduino server";
	mClient.connect(mPort);
    mIsFinished = true;
    mIsRunning = false;
}
