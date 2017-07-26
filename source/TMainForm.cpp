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
#include "THandWheelPositionForm.h"
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
    mSBManager.addPanel(120, sbpUC7Connection, 		"UC7: Not Connected");
    mSBManager.addPanel(300, sbpHandWheelPosition, 	"Wheel Position: N/A");
    mSBManager.addPanel(180, sbpArrayBotConnection,	"ArrayBot: Not Connected");
    mSBManager.addPanel(150, sbpDBConnection, 		"MySQL Server: Not Connected");
    mSBManager.addPanel(200, sbpNavitarController,	"Navitar Controller: Not Connected");
    mSBManager.addPanel(220, sbpArduinoConnection,	"Arduino Server: Not Connected");
    mSBManager.addPanel(200, sbpBarcodeReader, 		"BarcodeReader: Not Connected");
}

__fastcall TMainForm::~TMainForm()
{}

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
void __fastcall TMainForm::mRibbonCreatorActiveCBClick(TObject *Sender)
{
	mRibbonCreatorActiveCB->OnClick(Sender);
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


