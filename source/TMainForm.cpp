#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "vcl/atVCLUtils.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
#include "mtkWin32Utils.h"
#include "mtkUtils.h"
#include "uc480/uc480_tools.h"
#include "database/atDBUtils.h"
#include "Poco/Data/RecordSet.h"
#include "TSettingsForm.h"
#include "sound/atSounds.h"
#include "core/atCore.h"
#include "TSelectIntegerForm.h"
#include "TReticlePopupForm.h"
#include "THandWheelPositionForm.h"
#include "forms/TAboutForm.h"
#include "forms/TLoggerForm.h"
#include "TActionsForm.h"
#include "TATDBDataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TPropertyCheckBox"
#pragma link "mtkFloatLabel"
#pragma link "TArrayBotBtn"
#pragma link "TIntegerLabeledEdit"
#pragma link "TIntLabel"
#pragma link "TATDBConnectionFrame"
#pragma link "TUC7StagePositionFrame"
#pragma link "TSoundsFrame"
#pragma link "TNavitarMotorFrame"
#pragma link "TNavitarPresetFrame"
#pragma link "TApplicationSoundsFrame"
#pragma resource "*.dfm"
TMainForm *MainForm;

extern string gApplicationRegistryRoot;
extern string gLogFileName;
extern string gAppDataFolder;
extern bool   gAppIsStartingUp;
extern bool   gAppIsClosing;

using namespace mtk;
using namespace at;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TRegistryForm(gApplicationRegistryRoot, "MainForm", Owner),
        mCaptureVideo(false),
        mSettingsForm(NULL),
        mAVIID(0),
    	mIniFile(joinPath(gAppDataFolder, "ArrayCam.ini"), true, true),
    	mLogLevel(lAny),
        mAutoGain(false),
        mAutoExposure(false),
        mAutoBlackLevel(false),
        mAutoWhiteBalance(false),
        mSoftwareGamma(0.0),
        mVerticalMirror(false),
        mHorizontalMirror(false),
        mPairLEDs(false),
        mSnapShotFolder(""),
        mMoviesFolder(""),
        mLocalDBName(""),
        mReticle(mPB->Canvas),
        mServiceCamera1(mCamera1, 1, this->Handle),
        mMovingReticle(false),
        mCheckArduinoServerConnection(true),
        mConnectToArduinoServerThread(mLightsArduinoClient, 50000),
        mUC7COMPort(0),
        mUC7(Handle),
        mCountTo(0),
	    mDBUserID(0),
	    mProcessID(0),
	    mBlockID(0),
	    mZebraCOMPort(17),
    	mZebraBaudRate(9600),
	    mZebra(),
        mMainContentPanelWidth(700),
        mACServer(*this, -1),
        mReticleVisible(false),
        mKnifeStageMaxPos(0),
        mKnifeStageJogStep(0),
        mKnifeStageResumeDelta(0),
        mKnifeCuttingSound(ApplicationSound("")),
		mKnifeBeforeCuttingSound(ApplicationSound("")),
		mBeforeKnifeBackOffSound(ApplicationSound("")),
        mKnifeAfterCuttingSound(ApplicationSound("")),
		mArmRetractingSound(ApplicationSound("")),
        mNavitarPreset1(mNavitarMotorController, "NAVITAR_PRESET_1"),
        mNavitarPreset2(mNavitarMotorController, "NAVITAR_PRESET_2"),
        mNavitarPreset3(mNavitarMotorController, "NAVITAR_PRESET_3"),
	    mRenderMode(IS_RENDER_FIT_TO_WINDOW),
        mSBManager(*StatusBar1),
        mHandWheelPositionForm(NULL),
        LoggerForm(NULL),
        ActionsForm(NULL)
{
    //Init the DLL -> give intra messages their ID's
	initABCoreLib();

	//Setup references
  	//The following causes the editbox, and its property to reference the counters CountTo value
   	mCountToE->setReference(mUC7.getSectionCounter().getCountToReference());
   	mSectionCounterLabel->setReference(mUC7.getSectionCounter().getCountReference());
    mRibbonOrderCountLabel->setReference(mUC7.getRibbonOrderCounter().getCountReference());
    mZeroCutsE->setReference(mUC7.getNumberOfZeroStrokesReference());

    mCountToE->update();
    mSectionCounterLabel->update();
    mRibbonOrderCountLabel->update();
    mZeroCutsE->update();

	mRibbonCreatorActiveCB->setReference(mUC7.getRibbonCreatorActiveReference());

    //Properties are retrieved and saved to an ini file
    setupProperties();
    mGeneralProperties.read();
    mSoundProperties.read();

	//Navitarpresets
	mNavitarPreset1.read();
	mNavitarPreset2.read();
	mNavitarPreset3.read();

    //The loglevel is read from ini file
	gLogger.setLogLevel(mLogLevel);

    //Give all sounds a Handle (create a sound container..)
	mKnifeBeforeCuttingSound.getReference().setHandle(this->Handle);
	mBeforeKnifeBackOffSound.getReference().setHandle(this->Handle);
    mKnifeCuttingSound.getReference().setHandle(this->Handle);
	mKnifeAfterCuttingSound.getReference().setHandle(this->Handle);
	mArmRetractingSound.getReference().setHandle(this->Handle);

    //Setup callbacks
	mLightsArduinoClient.assignOnMessageReceivedCallBack(onLightsArduinoMessageReceived);
    mLightsArduinoClient.onConnected 		= onArduinoClientConnected;
	mLightsArduinoClient.onDisconnected 	= onArduinoClientDisconnected;

    mServiceCamera1.onCameraOpen 			= onCameraOpen;
    mServiceCamera1.onCameraClose 			= onCameraClose;

    //Update UI controls
    MainContentPanel->Width = mMainContentPanelWidth;

	mCountToE->update();
    mPresetFeedRateE->update();
    mUC7.setFeedRatePreset(mPresetFeedRateE->getValue());
    mStageMoveDelayE->update();
	mZeroCutsE->update();
	mUC7ComportCB->ItemIndex = mUC7COMPort - 1;
	mArrayCamServerPortE->update();
    MaxStagePosFrame->setValue(mKnifeStageMaxPos.getValue());
    BackOffStepFrame->setValue(mKnifeStageJogStep.getValue());
    ResumeDeltaDistanceFrame->setValue(mKnifeStageResumeDelta.getValue());
    mUC7.setKnifeStageResumeDelta(mKnifeStageResumeDelta.getValue());
    mUC7.setKnifeStageJogStepPreset(mKnifeStageJogStep.getValue());

	mZebraCOMPortCB->ItemIndex = mZebraCOMPort - 1;

    //Find out which item in the CB that should be selected
    for(int i = 0; i < mZebraBaudRateCB->Items->Count; i++)
    {
		if(mZebraBaudRateCB->Items->Strings[i].ToInt() == mZebraBaudRate)
        {
			mZebraBaudRateCB->ItemIndex = i;
            break;
        }
    }

    //Create statusbar panels
    mSBManager.addPanel(120, sbpTemperature);
    mSBManager.addPanel(120, sbpHumidity);
    mSBManager.addPanel(180, sbpUC7Connection, 		"UC7: Not Connected");
    mSBManager.addPanel(300, sbpHandWheelPosition, 	"Wheel Position: N/A");
    mSBManager.addPanel(180, sbpArrayBotConnection,	"ArrayBot: Not Connected");
    mSBManager.addPanel(220, sbpDBConnection, 		"MySQL Server: Not Connected");
    mSBManager.addPanel(200, sbpNavitarController,	"Navitar Controller: Not Connected");
    mSBManager.addPanel(220, sbpArduinoConnection,	"Arduino Server: Not Connected");
    mSBManager.addPanel(200, sbpBarcodeReader, 		"BarcodeReader: Not Connected");
}

__fastcall TMainForm::~TMainForm()
{}

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
void __fastcall TMainForm::PageControl1Change(TObject *Sender)
{
	//Check if we need any processing as a tab changes

}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mStartupTimerTimer(TObject *Sender)
{
	mStartupTimer->Enabled = false;

    if(!mSettingsForm)
    {
		mSettingsForm = new TSettingsForm(*this);
    }

   	TATDBConnectionFrame1->init(&(mIniFile));
    TATDBConnectionFrame1->mATDBServerBtnConnect->Click();

    //Auto connect to the barcode reader
	mConnectZebraBtnClick(Sender);

    //Connect to the UC7
    mConnectUC7Btn->Click();

    updateTemperature(-1);
	updateHumidity(-1);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject *Sender)
{
;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mPBMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	//If mouse is inside reticle center, allowe moving its center
	mMovingReticle = true;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mPBMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	mMovingReticle = false;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mPBMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	//Update reticle center
	if(mMovingReticle)
    {
    	int x = X - mPB->Width/2;
        int y = Y - mPB->Height/2;
    	mReticle.setReticleCenter(x, y);
		if(mReticleForm.get() && mReticleForm->Visible)
    	{
        	mReticleForm->mReticleCenterXTB->Position = x;
        	mReticleForm->mReticleCenterYTB->Position = y;
        }
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
void __fastcall TMainForm::AppInBox(ATWindowStructMessage& msg)
{
    if(msg.lparam == NULL)
    {
        return;
    }

    try
    {
        ApplicationMessageEnum aMsg = (ApplicationMessageEnum) msg.wparam;

        switch(aMsg)
        {
			case atUC7Message:
            {
            	//Cast data
            	UC7Message* m = (UC7Message*) msg.lparam;
                Log(lDebug) << "Handling UC7 message: \"" << m->getMessageNameAsString()<<"\" with data: "<<m->getData();
                bool result = handleUC7Message(*m);
                if(!result)
                {
                	Log(lError) << "The message: "<<m->getFullMessage()<<" was not properly handled!";
                }
                delete m;
            }
            break;

            case atMiscMessage:
            {
            	int* m = (int*) msg.lparam;
                Log(lDebug) << "Handling Misc message: \"" << *m;//m->getMessageNameAsString()<<"\" with data: "<<m->getData();
            }
            break;
            default:
            break ;
        }
	}
	catch(...)
	{
		Log(lError) << "An exception was thrown in AppInBox.";
	}
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::mConnectUC7BtnClick(TObject *Sender)
{
	if(mConnectUC7Btn->Caption == "Open")
    {
        if(mUC7.connect(getCOMPortNumber()))
        {
            Log(lInfo) << "Connected to a UC7 device";
        }
        else
        {
            Log(lInfo) << "Connection failed";
        }
    }
    else
    {
        if(!mUC7.disConnect())
        {
			Log(lError) << "Failed to close serial port";
        }
    }

    //Give it some time to close down..
    //These should be UC7 callbacks..
    Sleep(100);

    if(mUC7.isConnected())
    {
	    onConnectedToUC7();
    }
    else
    {
		onDisConnectedToUC7();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::onConnectedToUC7()
{
	//Setup callbacks
    mUC7.getSectionCounter().assignOnCountCallBack(onUC7Count);
    mUC7.getSectionCounter().assignOnCountedToCallBack(onUC7CountedTo);
    mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());

	enableDisableUC7UI(true);
	mSynchUIBtnClick(NULL);

  	TStatusPanel* p = mSBManager.getPanel(sbpUC7Connection);
    p->Text = "UC7: Connected";
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::onDisConnectedToUC7()
{
	enableDisableUC7UI(false);
  	TStatusPanel* p = mSBManager.getPanel(sbpUC7Connection);
    p->Text = "UC7: Not Connected";
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::enableDisableUC7UI(bool enableDisable)
{
	//Buttons
    mConnectUC7Btn->Caption                 = enableDisable ? "Close" : "Open";
    mSynchUIBtn->Enabled					= enableDisable;

    //group boxes
	enableDisableGroupBox(CounterGB, 		enableDisable);
//    enableDisableGroupBox(NorthSouthGB,		enableDisable);
    enableDisableGroupBox(UC7OperationGB, 	enableDisable);
    enableDisableGroupBox(CuttingGB, 		enableDisable);
    enableDisableGroupBox(KnifeStageGB,		enableDisable);
}

//---------------------------------------------------------------------------
void TMainForm::onUC7Count()
{
	mSectionCounterLabel->update();
    if(mRibbonCreatorActiveCB->Checked)
    {
    	//Check if we are close to ribbon separation
        if(mSectionCounterLabel->getValue() >= (mCountToE->getValue() - 3))
        {
            mBeforeKnifeBackOffSound.getReference().play();
        }
    }
}

//---------------------------------------------------------------------------
void TMainForm::onUC7CountedTo()
{
	if(mUC7.isActive())
    {
	    mUC7.getSectionCounter().reset();
		Log(lInfo) << "Creating new ribbon";
	    mUC7.prepareToCutRibbon(true);
        //mRibbonStartBtn->Enabled = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mSynchUIBtnClick(TObject *Sender)
{
    mUC7.getStatus();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateUC7Message(TObject *Sender)
{
	TArrayBotButton* btn = dynamic_cast<TArrayBotButton*>(Sender);

    if(!btn)
    {
    	Log(lError) << "Sender object was NULl!";
    	return;
    }

	if (btn == mStartStopBtn)
    {
    	if(mStartStopBtn->Caption == "Start")
        {
            mUC7.startCutter();
        }
        else
        {
            mUC7.stopCutter();
        }
    }
    else if(btn == mSetZeroCutBtn)
    {
		mUC7.setFeedRate(0);
    }
    else if(btn == SetPresetFeedBtn)
    {
		mUC7.setFeedRate(mPresetFeedRateE->getValue());
    }

    else if(btn == mRibbonStartBtn)
    {
    	if(btn->Caption == "Back off")
        {
			mUC7.prepareToCutRibbon(true);
            btn->Caption = "Preparing for IDLE";

            //check if this screws up things
			mUC7.setFeedRate(0);
        }
        else
        {
            mUC7.prepareForNewRibbon(true);
            btn->Caption = "Preparing start of Ribbon";
            //btn->Enabled = false;
        }
    }
    else if(btn == mMoveSouthBtn)
    {
   		mUC7.setFeedRate(0);
    	mUC7.jogKnifeStageSouth(BackOffStepFrame->getValue(), true);
    }
    else if(btn == mMoveNorthBtn)
    {
		mUC7.setFeedRate(0);
    	mUC7.jogKnifeStageNorth(BackOffStepFrame->getValue(), true);
    }
//    else if(btn == StopKnifeStageMotionBtn)
//    {
//    	mUC7.stopKnifeStageNSMotion();
//    }

    string msg = mUC7.getLastSentMessage().getMessage();
	Log(lDebug3) << "Sent message: "<<msg;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mResetCounterBtnClick(TObject *Sender)
{
	TArrayBotButton* btn = dynamic_cast<TArrayBotButton*>(Sender);
    if(btn == mResetCounterBtn)
    {
    	mUC7.getSectionCounter().reset();
        mSectionCounterLabel->update();
    }
    else if(btn == mResetRibbonOrderBtn)
    {
		mUC7.getRibbonOrderCounter().reset();
        mRibbonOrderCountLabel->update();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mRibbonCreatorActiveCBClick(TObject *Sender)
{
	mRibbonCreatorActiveCB->OnClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::uc7EditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	TIntegerLabeledEdit* 	e  = dynamic_cast<TIntegerLabeledEdit*>(Sender);
	TIntegerEdit* 			ie = dynamic_cast<TIntegerEdit*>(Sender);

    if(Key == VK_RETURN)
    {
        if(e == mPresetFeedRateE)
        {
            mUC7.setFeedRatePreset(e->getValue());
        }
        else if(e == mStageMoveDelayE)
        {
            mUC7.setStageMoveDelay(e->getValue());
        }

        else if(e == mFeedRateE)
        {
            //Set feedrate
            mUC7.setFeedRate(e->getValue());

            //This will also change preset feed
            mPresetFeedRateE->setValue(e->getValue());
	        mUC7.setFeedRatePreset(e->getValue());
        }
        else if(ie == MaxStagePosFrame->AbsPosE)
        {
	        MaxStagePosFrame->AbsPosEKeyDown(Sender, Key, Shift);
            mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());
        }
        else if(ie == CurrentStagePosFrame->AbsPosE)
        {
	        CurrentStagePosFrame->AbsPosEKeyDown(Sender, Key, Shift);
            mUC7.moveKnifeStageNSAbsolute(CurrentStagePosFrame->AbsPosE->getValue());
        }
    }
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::mUsersCBCloseUp(TObject *Sender)
{
    mDBUserID.setValue(mUsersCB->KeyValue);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mBlockProcessIDCBCloseUp(TObject *Sender)
{
	TDBLookupComboBox* b = dynamic_cast<TDBLookupComboBox*>(Sender);
    if(b == mBlockProcessIDCB)
    {
    	mProcessID.setValue(b->KeyValue);
        BlockIDCB->KeyValue = -1;
    }
    else if(b == BlockIDCB)
    {
    	mBlockID.setValue(b->KeyValue);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::SendServerStatusMessageBtnClick(TObject *Sender)
{
	mACServer.broadcastStatus();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mRibbonOrderCountLabelClick(TObject *Sender)
{
    TSelectIntegerForm* f = new TSelectIntegerForm(this);
    f->setCurrentNumber(mRibbonOrderCountLabel->getValue());
    int res = f->ShowModal();
    if(res == mrOk)
    {
    	mRibbonOrderCountLabel->setValue(f->mTheNumberLbl->getValue());
    }

    delete f;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::PopulateMaxNorthPosBtnClick(TObject *Sender)
{
    MaxStagePosFrame->setValue(CurrentStagePosFrame->getValue());
	mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::CameraHCSectionClick(THeaderControl *HeaderControl,
          THeaderSection *Section)
{
    POINT p;
    GetCursorPos(&p);

	if(Section == CameraHC->Sections->Items[0])
    {
        //Show popup
        CameraPopup->Popup(p.x, p.y);
    }
    else if(Section == CameraHC->Sections->Items[1])
    {
		if(mReticleForm.get() == NULL)
        {
        	mReticleForm = auto_ptr<TReticlePopupForm>(new TReticlePopupForm(mReticle, this));
            mReticleForm->mReticleVisibilityCB->setReference(mReticleVisible.getReference());
			mReticleForm->mReticleVisibilityCB->update();
        }

        mReticleForm->Top = p.y;// + mReticleForm->Height;
        mReticleForm->Left = p.x;
        mReticleForm->Show();
    }
    else if(Section == CameraHC->Sections->Items[2])
    {
	    takeSnapShot();
    }
    else if(Section == CameraHC->Sections->Items[3])
    {
	    startStopRecordingMovie();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::KnifePosChange(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    CurrentStagePosFrame->posEdit(Sender, Key, Shift);
		mUC7.moveKnifeStageNSAbsolute(CurrentStagePosFrame->AbsPosE->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::MaxKnifePosKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    MaxStagePosFrame->posEdit(Sender, Key, Shift);
		mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mAutoCheckConnectionCBClick(TObject *Sender)
{
	CheckArduinoServerConnectionTimer->Enabled = mAutoCheckConnectionCB->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::BackOffStepFrameKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    BackOffStepFrame->posEdit(Sender, Key, Shift);
		mUC7.setKnifeStageJogStepPreset(BackOffStepFrame->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ResumeDeltaDistanceOnKey(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    ResumeDeltaDistanceFrame->posEdit(Sender, Key, Shift);
		mUC7.setKnifeStageResumeDelta(ResumeDeltaDistanceFrame->AbsPosE->getValue());
    }
}

void  TMainForm::onNavitarConnected()
{
	ConnectBtn->Caption         = "Disconnect";
    ProdIdLbl->Caption 	        = vclstr(mNavitarMotorController.getProductID());
	HWVerLbl->Caption           = vclstr(mNavitarMotorController.getHardwareVersion());
   	SWVerLbl->Caption           = vclstr(mNavitarMotorController.getSoftwareVersion());
    FirmWareDateLbl->Caption   	= vclstr(mNavitarMotorController.getDriverSoftwareBuildDate());

    TNavitarMotorFrame1->populate(mNavitarMotorController.getZoom());
    TNavitarMotorFrame2->populate(mNavitarMotorController.getFocus());
    enableDisableGroupBox(ControllerInfoGB, true);
}

void  TMainForm::onNavitarDisconnected()
{
	ConnectBtn->Caption = "Connect";
    ProdIdLbl->Caption 	        = "N/A";
	HWVerLbl->Caption           = "N/A";
   	SWVerLbl->Caption           = "N/A";
    FirmWareDateLbl->Caption   	= "N/A";

    enableDisableGroupBox(ControllerInfoGB, false);

    TNavitarMotorFrame1->dePopulate();
    TNavitarMotorFrame2->dePopulate();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ConnectBtnClick(TObject *Sender)
{
	TButton* b = dynamic_cast<TButton*>(Sender);

    if(b == ConnectBtn)
    {
        if(!mNavitarMotorController.isConnected())
        {
            if(mNavitarMotorController.connect())
            {
            	onNavitarConnected();
            }
        }
        else
        {
            if(mNavitarMotorController.disConnect())
            {
            	onNavitarDisconnected();
            }
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::StatusBar1Hint(TObject *Sender)
{
	;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenHandWheelPositionFormAExecute(TObject *Sender)
{
	if(!mHandWheelPositionForm)
    {
    	mHandWheelPositionForm = new THandWheelPositionForm(mUC7.getStatusHistoryRef(), gApplicationRegistryRoot, this);
    }

    if(!mHandWheelPositionForm->Visible)
    {
    	mHandWheelPositionForm->Show();
    }
    else
    {
		mHandWheelPositionForm->Hide();
    }
}

void __fastcall TMainForm::ToggleMainContentPanelAExecute(TObject *Sender)
{
	MainContentPanel->Visible 		= !MainContentPanel->Visible;
	ToggleMainContentBtn->Visible 	= !MainContentPanel->Visible;
    Splitter2->Visible 				= MainContentPanel->Visible;

    if(MainContentPanel->Visible)
    {
		Splitter2->Left = MainContentPanel->Left - 1;
    }
}

void __fastcall TMainForm::About1Click(TObject *Sender)
{
	TAboutForm* f = new TAboutForm(this);
    f->ShowModal();
    delete f;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenLoggerForm1Click(TObject *Sender)
{
	if(!LoggerForm)
    {
    	LoggerForm = new TLoggerForm(gApplicationRegistryRoot, this);
		mLogLevel.setReference(&(LoggerForm->mLogLevel));
        LoggerForm->Show();
    }
    else
    {
    	LoggerForm->Visible = true;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenCloseShortcutFormExecute(TObject *Sender)
{
	if(!ActionsForm)
    {
    	ActionsForm = new TActionsForm(Handle, this);
    }

    if(!ActionsForm->Visible)
    {
    	ActionsForm->Show();
    }
    else
    {
    	ActionsForm->Hide();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenCloseShortcutFormUpdate(TObject *Sender)
{
	if(ActionsForm && ActionsForm->Visible)
    {
		OpenCloseShortcutForm->Caption = "Close Shortcuts";
    }
    else
    {
		OpenCloseShortcutForm->Caption = "Open ShortCuts";
    }
}


