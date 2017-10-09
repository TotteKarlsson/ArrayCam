#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "THandWheelPositionForm.h"
#include "TLoggerForm.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace mtk;


extern bool gAppIsClosing;
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	gAppIsClosing = true;
	if(
    	mCamera1.IsInit() 						||
        mServiceCamera1.isRunning()				||
        mLightsArduinoClient.isConnected() 		||
        CheckArduinoServerConnectionTimer->Enabled 	||
        atdbDM->SQLConnection1->Connected 		||
        mZebra.isConnected()                    ||
        mHandWheelPositionForm                  ||
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

    if(mLightsArduinoClient.isConnected())
    {
		mLightsArduinoClient.disConnect();
    }

	if(mHandWheelPositionForm)
    {
    	mHandWheelPositionForm->setTimeToClose();
        mHandWheelPositionForm->Close();
        mHandWheelPositionForm = NULL;
    }

	if(LoggerForm)
    {
        LoggerForm->Close();
        LoggerForm = NULL;
    }

    if(CheckArduinoServerConnectionTimer->Enabled)
    {
	    CheckArduinoServerConnectionTimer->Enabled = false;
	    mCheckArduinoServerConnection = false;
    }

   	if(mZebra.isConnected())
    {
    	mZebra.disconnect();
    }

    if(mACServer.isRunning())
    {
    	mACServer.shutDown();
    }

    if(mUC7.isConnected())
    {
	    mUC7.disConnect();
    }

    if(atdbDM->SQLConnection1->Connected)
    {
    	atdbDM->SQLConnection1->Connected = false;
	    atdbDM->SQLConnection1->Close();
    }

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	mMainContentPanelWidth = MainContentPanel->Width;

	TATDBConnectionFrame1->purge();

	Log(lInfo) << "In FormClose";
	mUC7COMPort = mUC7ComportCB->ItemIndex + 1;

	mZebraCOMPort = mZebraCOMPortCB->ItemIndex + 1;
    mZebraBaudRate = mZebraBaudRateCB->Items->Strings[mZebraBaudRateCB->ItemIndex].ToInt();

    mKnifeStageMaxPos.setValue(MaxStagePosFrame->getValue());
    mKnifeStageJogStep.setValue(BackOffStepFrame->getValue());
    mKnifeStageResumeDelta.setValue(ResumeDeltaDistanceFrame->getValue());

	mGeneralProperties.write();
	mSoundProperties.write();
    TFFMPEGFrame1->writeToINI();

	//Write to file
	mIniFile.save();
}


