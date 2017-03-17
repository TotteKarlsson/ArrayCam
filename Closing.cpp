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
        mServiceCamera1.isRunning()			||
        mLightsArduinoClient.isConnected() 	||
        mCheckSocketConnectionTimer->Enabled
        )

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

    if(mCamera1.IsInit())
    {
	    if(!mServiceCamera1.isRunning())
        {
	    	mServiceCamera1.closeCamera();
        }
    }

    if(!mCamera1.IsInit() && mServiceCamera1.isRunning())
    {
		mServiceCamera1.stop();
    }

    if(mLightsArduinoClient.isConnected())
    {
		mLightsArduinoClient.disConnect();
    }

    if(mCheckSocketConnectionTimer->Enabled)
    {
	    mCheckArduinoServerConnection = false;
	    mCheckSocketConnectionTimer->Enabled = false;
    }

	if(mLogFileReader.isRunning())
    {
		mLogFileReader.stop();
        mLogFileReader.assignOnMessageCallBack(NULL);
    }

    Close();
}

