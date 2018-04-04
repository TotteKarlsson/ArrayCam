#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TLoggerForm.h"
#include "dslLogger.h"
#include "ArrayCamUtilities.h"
//---------------------------------------------------------------------------
extern ArrayCamUtilities acu;
using namespace dsl;

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	acu.AppIsClosing = true;
	if(
    	mCamera1.IsInit() 						||
        mServiceCamera1.isRunning()				||
        LoggerForm
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

	//Check for frames to delete
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

	if(LoggerForm)
    {
        LoggerForm->Close();
        LoggerForm = NULL;
    }

    if(mACServer.isRunning())
    {
    	mACServer.shutDown();
    }

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	mMainContentPanelWidth = MainContentPanel->Width;
    mLogLevel = gLogger.getLogLevel();
	mGeneralProperties.write();
	//Write to file
	mIniFile.save();
}


