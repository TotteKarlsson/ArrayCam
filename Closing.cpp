#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
//---------------------------------------------------------------------------

extern bool gAppIsClosing;
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	gAppIsClosing = true;
	if(mLogFileReader.isRunning() 			||
    	mCamera1.IsInit() 					||
//        mCamera2.IsInit() 					||
        mLightsArduinoClient.isConnected() 	||
        mSensorsArduinoClient.isConnected())
    {
        CanClose = false;
        mShutDownTimer->Enabled = true;
        return;
    }

    CanClose = true;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mShutDownTimerTimer(TObject *Sender)
{
    mShutDownTimer->Enabled = false;
	if(mLogFileReader.isRunning())
    {
		mLogFileReader.stop();
    }

    if(mCamera1.IsInit())
    {
	    mServiceCamera1.closeCamera();
    }
    if(!mCamera1.IsInit() && mServiceCamera1.isRunning())
    {
		mServiceCamera1.stop();
    }

//    if(mCamera2.IsInit()|| mServiceCamera2.isRunning())
//    {
//	    mServiceCamera2.closeCamera();
//    }

    if(mLightsArduinoClient.isConnected())
    {
		mLightsArduinoClient.disConnect();
    }

    if(mSensorsArduinoClient.isConnected())
    {
		mSensorsArduinoClient.disConnect();
    }

    Close();
}

