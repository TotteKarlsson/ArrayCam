#pragma hdrstop
#include "TMainForm.h"
#include "mtkLogger.h"
using namespace mtk;

//---------------------------------------------------------------------------
void __fastcall TMainForm::ShutDownTimerTimer(TObject *Sender)
{
	ShutDownTimer->Enabled = false;

	if(mLogFileReader.isRunning())
	{
		Log(lDebug) << "Shutting down log file reader";
		mLogFileReader.stop();
	}

    if(mVCThread.isRunning())
    {
    	mVCThread.stop();
    }

	Close();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Log(lInfo) << "Closing down....";

	//Check if we can close.. abort all threads..
	CanClose = (
    			mLogFileReader.isRunning() ||
		    	mVCThread.isRunning()
        		)
         ? false : true;

	if(CanClose == false)
	{
		ShutDownTimer->Enabled = true;
	}
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Log(lInfo) << "In FormClose";
}

