#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "vcl/atVCLUtils.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
#include "mtkWin32Utils.h"
#include "mtkUtils.h"
#include "camera/uc480_tools.h"
#include "database/atDBUtils.h"
#include "Poco/Data/RecordSet.h"
#include "TSettingsForm.h"

using namespace mtk;
using namespace at;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TPropertyCheckBox"
#pragma link "mtkFloatLabel"
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"
TMainForm *MainForm;

extern string gLogFileName;
extern string gApplicationRegistryRoot;
extern string gLogFileLocation;
extern string gLogFileName;
extern string gAppDataFolder;
extern bool   gAppIsStartingUp;
extern bool   gAppIsClosing;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TRegistryForm(gApplicationRegistryRoot, "MainForm", Owner),
    	mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), "ArrayBot", gLogFileName), &logMsg),
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
        mClientDBSession("umlocal"),
		mServerDBSession("atdb"),
        mReticle(mPB->Canvas),
        mServiceCamera1(mCamera1, 1, this->Handle),
        mMovingReticle(false),
        mCheckArduinoServerConnection(true),
        mConnectToArduinoServerThread(mLightsArduinoClient, 50000)

{
   	mLogFileReader.start(true);

	//Setup UI/INI properties
    mProperties.setSection("GENERAL");
	mProperties.setIniFile(&mIniFile);
	mProperties.add((BaseProperty*)  &mLogLevel.setup( 	    	"LOG_LEVEL",    		lAny));
	mProperties.add((BaseProperty*)  &mAutoGain.setup(			"AUTO_GAIN",    		false));
	mProperties.add((BaseProperty*)  &mAutoExposure.setup( 		"AUTO_EXPOSURE",    	false));
	mProperties.add((BaseProperty*)  &mAutoBlackLevel.setup(  	"AUTO_BLACK_LEVEL",    	false));
	mProperties.add((BaseProperty*)  &mAutoWhiteBalance.setup( 	"AUTO_WHITE_BALANCE",  	false));
	mProperties.add((BaseProperty*)  &mSoftwareGamma.setup( 	"SOFTWARE_GAMMA",  		0));
	mProperties.add((BaseProperty*)  &mVerticalMirror.setup(	"VERTICAL_MIRROR",    	false));
	mProperties.add((BaseProperty*)  &mHorizontalMirror.setup(	"HORIZONTAL_MIRROR",    false));
	mProperties.add((BaseProperty*)  &mHorizontalMirror.setup(	"HORIZONTAL_MIRROR",    false));
	mProperties.add((BaseProperty*)  &mPairLEDs.setup(			"PAIR_LEDS",    		true));
    mProperties.add((BaseProperty*)  &mSnapShotFolder.setup(	"SNAP_SHOT_FOLDER",     "C:\\Temp"	));
	mProperties.add((BaseProperty*)  &mMoviesFolder.setup(		"MOVIES_FOLDER",   		"C:\\Temp"	));
	mProperties.add((BaseProperty*)  &mLocalDBName.setup(		"LOCAL_DB",   			"umlocal.db"));

    mProperties.read();

	//Camera rendering mode
    mRenderMode = IS_RENDER_FIT_TO_WINDOW;

	mLightsArduinoClient.assignOnMessageReceivedCallBack(onLightsArduinoMessageReceived);

    mLightsArduinoClient.onConnected 		= onArduinoClientConnected;
	mLightsArduinoClient.onDisconnected 	= onArduinoClientDisconnected;

    gLogger.setLogLevel(mLogLevel);

    mServiceCamera1.onCameraOpen 	= onCameraOpen;
    mServiceCamera1.onCameraClose 	= onCameraClose;
}

__fastcall TMainForm::~TMainForm()
{
	mProperties.write();
    mIniFile.save();
}

//This one is called from the reader thread
void __fastcall TMainForm::logMsg()
{
	if(infoMemo->Lines->Count > 1000)
    {
	    infoMemo->Clear();
    }

    infoMemo->Lines->Insert(0, (vclstr(mLogFileReader.getData())));
}

//Callback from socket client class
void TMainForm::onArduinoClientConnected()
{
    Log(lDebug) << "ArduinoClient was connected..";
	mCheckSocketConnectionTimer->Enabled = false;

    //Send message to update UI
    mLightsArduinoClient.getBoardStatus();
    enableDisableClientControls(true);
}

void TMainForm::onArduinoClientDisconnected()
{
    Log(lDebug) << "Arduino Client was disconnected..";

	//Don't worry if we are closing down..
    if(gAppIsClosing != true)
    {
    	enableDisableClientControls(false);
        if(mCheckArduinoServerConnection)
        {
			mCheckSocketConnectionTimer->Enabled = true;
        }
    }
}

void TMainForm::enableDisableClientControls(bool enable)
{
	//Disable client related components..
    if(mSettingsForm)
    {
    	enableDisableGroupBox(mSettingsForm->LightIntensitiesGB, enable);
    }
    mFrontBackLEDBtn->Enabled = enable;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mFrontBackLEDBtnClick(TObject *Sender)
{
	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);
    if(b == mFrontBackLEDBtn)
    {
    	mLightsArduinoClient.toggleLED();
    }
}


void __fastcall TMainForm::Panel3Resize(TObject *Sender)
{
	mOneToOneBtn->Width = Panel3->Width / 2;
	mOneToTwoBtn->Width = Panel3->Width / 2;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControl1Change(TObject *Sender)
{
	//Check if we are opening About tab
    if(PageControl1->TabIndex == 2)
    {
    	populateAbout();
    }
}

void __fastcall TMainForm::mStartupTimerTimer(TObject *Sender)
{
	mStartupTimer->Enabled = false;
}

void __fastcall TMainForm::mReticleRadiusTBChange(TObject *Sender)
{
	TTrackBar* tb = dynamic_cast<TTrackBar*>(Sender);

    if(!mMovingReticle)
    {
        if(tb == mReticleRadiusTB)
        {
            mReticle.setCircleRadius(tb->Position);
        }
        else if(tb == mReticleCenterXTB)
        {
            mReticle.setReticleCenter(tb->Position, mReticleCenterYTB->Position);
        }
        else if(tb == mReticleCenterYTB)
        {
            mReticle.setReticleCenter(mReticleCenterXTB->Position, tb->Position);
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	//
    mReticleCenterXTB->Min = -mPB->Width/2;
    mReticleCenterXTB->Max = mPB->Width/2;

    mReticleCenterYTB->Min = -mPB->Height/2;
    mReticleCenterYTB->Max = mPB->Height/2;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mPBMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	//If mouse is inside reticle center, allowing moving its center
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
    	int x =X - mPB->Width/2;
        int y = Y - mPB->Height/2;
    	mReticle.setReticleCenter(x, y);
        mReticleCenterXTB->Position = x;
        mReticleCenterYTB->Position = y;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mCenterReticleBtnClick(TObject *Sender)
{
    mReticle.setReticleCenter(0,0);
    mReticleCenterXTB->Position = 0;
    mReticleCenterYTB->Position = 0;
}

void __fastcall TMainForm::mCheckSocketConnectionTimerTimer(TObject *Sender)
{
	Log(lDebug) << "Trying to connect to Arduino server";
    if(!mConnectToArduinoServerThread.isRunning() && !mLightsArduinoClient.isConnected())
    {
    	mConnectToArduinoServerThread.start();
    }

}


