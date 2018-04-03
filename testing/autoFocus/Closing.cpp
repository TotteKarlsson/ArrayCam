#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TPGDataModule.h"
#include "THandWheelPositionForm.h"
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
        BroadcastStatusTimer->Enabled  			||
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
    list<TFFMPEGOutputFrame*>::iterator i;
	for(i = mCompressionFrames.begin(); i != mCompressionFrames.end();)
    {
    	if((*i))
        {
			MessageDlg("Wait or stop ongoing video compressing jobs before closing..", mtWarning, TMsgDlgButtons() << mbOK, 0);
            return;
        }
    }

    if(mCaptureVideoTimer->Enabled)
    {
		MessageDlg("Wait or stop ongoing video recording jobs before closing..", mtWarning, TMsgDlgButtons() << mbOK, 0);
        return;
    }

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

    if(BroadcastStatusTimer->Enabled)
    {
		BroadcastStatusTimer->Enabled = false;
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
	mGeneralProperties.write();
	//Write to file
	mIniFile.save();
}


