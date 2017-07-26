#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TSettingsForm.h"
extern bool   gAppIsClosing;

//---------------------------------------------------------------------------
//Callback from socket client class
void TMainForm::onArduinoClientConnected()
{
    Log(lDebug) << "ArduinoClient was connected..";
	CheckArduinoServerConnectionTimer->Enabled = false;
    ArduinoServerStartStopButton->Caption = "Stop";

    //Send message to update UI
    mLightsArduinoClient.getBoardStatus();
    enableDisableClientControls(true);

  	TStatusPanel* p = mSBManager.getPanel(sbpArduinoConnection);
    p->Text = "ArduinoServer: Connected";
}

//---------------------------------------------------------------------------
void TMainForm::onArduinoClientDisconnected()
{
    Log(lDebug) << "Arduino Client was disconnected..";

	//Don't worry if we are closing down..
    if(gAppIsClosing != true)
    {
	    ArduinoServerStartStopButton->Caption = "Start";
    	enableDisableClientControls(false);
        if(mCheckArduinoServerConnection)
        {
			CheckArduinoServerConnectionTimer->Enabled = true;
        }
  		TStatusPanel* p = mSBManager.getPanel(sbpArduinoConnection);
	    p->Text = "ArduinoServer: Not Connected";
    }
}

void __fastcall TMainForm::ArduinoServerStartStopButtonClick(TObject *Sender)
{
	if(ArduinoServerStartStopButton->Caption == "Start")
    {
    	mLightsArduinoClient.connect(mArduinoServerPortE->getValue());
        ArduinoServerStartStopButton->Caption == "Connecting";
        mCheckArduinoServerConnection = true;
    }
    else
    {
		//User closed connection manually - don't restore automatically
		mCheckArduinoServerConnection = false;
    	mLightsArduinoClient.disConnect();
    }
}


//---------------------------------------------------------------------------
void TMainForm::enableDisableClientControls(bool enable)
{
	mArduinoServerPortE->Enabled = !enable;


	//Disable/Enable client related components..
    if(mSettingsForm)
    {
    	enableDisableGroupBox(mSettingsForm->LightIntensitiesGB, enable);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::CheckArduinoServerConnectionTimerTimer(TObject *Sender)
{
	Log(lDebug) << "Trying to connect to Arduino server";
    if(!mConnectToArduinoServerThread.isRunning() && !mLightsArduinoClient.isConnected())
    {
    	mConnectToArduinoServerThread.start();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mAutoCheckConnectionCBClick(TObject *Sender)
{
	CheckArduinoServerConnectionTimer->Enabled = mAutoCheckConnectionCB->Checked;
}
