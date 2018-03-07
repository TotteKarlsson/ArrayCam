#pragma hdrstop
#include "ConnectToElloUIThread.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
using namespace mtk;

ConnectToElloUIThread::ConnectToElloUIThread(ElloUIClient& c, int p)
:
mClient(c),
mPort(p)
{}

void ConnectToElloUIThread::run()
{
	mIsRunning = true;
	Log(lDebug3) << "Trying to connect to ElloUI";
	mClient.connect(mPort);
    mIsFinished = true;
    mIsRunning = false;
}
