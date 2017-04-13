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
#include "atCore.h"
#include "Forms/TRegisterNewRibbonForm.h"
using namespace mtk;
using namespace at;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TPropertyCheckBox"
#pragma link "mtkFloatLabel"
#pragma link "TArrayBotBtn"
#pragma link "TIntegerLabeledEdit"
#pragma link "TIntLabel"
#pragma link "TATDBConnectionFrame"
#pragma resource "*.dfm"
TMainForm *MainForm;

extern string gLogFileName;
extern string gAppName;
extern string gApplicationRegistryRoot;
extern string gLogFileLocation;
extern string gLogFileName;
extern string gAppDataFolder;
extern bool   gAppIsStartingUp;
extern bool   gAppIsClosing;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TRegistryForm(gApplicationRegistryRoot, "MainForm", Owner),
    	mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppName, gLogFileName), &logMsg),
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
        mCOMPort(0),
        mUC7(Handle),
        mCountTo(0),
	    mDBUserID(0),
	    mProcessID(0),
	    mZebraCOMPort(17),
    	mZebraBaudRate(9600),
	    mZebra()

{
   	mLogFileReader.start(true);

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

	//Setup UI/INI properties
    mProperties.setSection("GENERAL");
	mProperties.setIniFile(&mIniFile);
	mProperties.add((BaseProperty*)  &mLogLevel.setup( 	    	                "LOG_LEVEL",    		lAny));
	mProperties.add((BaseProperty*)  &mAutoGain.setup(			                "AUTO_GAIN",    		false));
	mProperties.add((BaseProperty*)  &mAutoExposure.setup( 		                "AUTO_EXPOSURE",    	false));
	mProperties.add((BaseProperty*)  &mAutoBlackLevel.setup(  	                "AUTO_BLACK_LEVEL",    	false));
	mProperties.add((BaseProperty*)  &mAutoWhiteBalance.setup( 	                "AUTO_WHITE_BALANCE",  	false));
	mProperties.add((BaseProperty*)  &mSoftwareGamma.setup( 	                "SOFTWARE_GAMMA",  		0));
	mProperties.add((BaseProperty*)  &mVerticalMirror.setup(	                "VERTICAL_MIRROR",    	false));
	mProperties.add((BaseProperty*)  &mHorizontalMirror.setup(	                "HORIZONTAL_MIRROR",    false));
	mProperties.add((BaseProperty*)  &mHorizontalMirror.setup(	                "HORIZONTAL_MIRROR",    false));
	mProperties.add((BaseProperty*)  &mPairLEDs.setup(			                "PAIR_LEDS",    		true));
    mProperties.add((BaseProperty*)  &mSnapShotFolder.setup(	                "SNAP_SHOT_FOLDER",     "C:\\Temp"	));
	mProperties.add((BaseProperty*)  &mMoviesFolder.setup(		                "MOVIES_FOLDER",   		"C:\\Temp"	));
	mProperties.add((BaseProperty*)  &mLocalDBName.setup(		                "LOCAL_DB",   			"umlocal.db"));
	mProperties.add((BaseProperty*)  &mDBUserID.setup( 	                    	"ATDB_USER_ID",                    	0));
	mProperties.add((BaseProperty*)  &mProcessID.setup( 	                   	"LAST_PROCESS_ID",                  0));

    //UC7
   	mProperties.add((BaseProperty*)  &mCOMPort.setup( 	                        "UC7_COM_PORT",    	   	0));
	mProperties.add((BaseProperty*)  &mCountToE->getProperty()->setup(       	"COUNT_TO",                     	5));
	mProperties.add((BaseProperty*)  &mZeroCutsE->getProperty()->setup(      	"NUMBER_OF_ZERO_CUTS",           	2));
	mProperties.add((BaseProperty*)  &mStageMoveDelayE->getProperty()->setup(	"KNIFE_STAGE_MOVE_DELAY",          	10));
	mProperties.add((BaseProperty*)  &mPresetFeedRateE->getProperty()->setup(	"PRESET_FEED_RATE",               	100));
	mProperties.add((BaseProperty*)  &mKnifeStageJogStep->getProperty()->setup(	"KNIFE_STAGE_JOG_SIZE",          	100));

    //Zebra
	mProperties.add((BaseProperty*)  &mZebraCOMPort.setup( 	                    "ZEBRA_COM_PORT",                   0));
	mProperties.add((BaseProperty*)  &mZebraBaudRate.setup( 	                "ZEBRA_BAUD_RATE",                  9600));

    mProperties.read();

	//Camera rendering mode
    mRenderMode = IS_RENDER_FIT_TO_WINDOW;

	mLightsArduinoClient.assignOnMessageReceivedCallBack(onLightsArduinoMessageReceived);

    mLightsArduinoClient.onConnected 		= onArduinoClientConnected;
	mLightsArduinoClient.onDisconnected 	= onArduinoClientDisconnected;

    gLogger.setLogLevel(mLogLevel);

    mServiceCamera1.onCameraOpen 	= onCameraOpen;
    mServiceCamera1.onCameraClose 	= onCameraClose;

    //Update UI controls
	mCountToE->update();
    mPresetFeedRateE->update();
    mKnifeStageJogStep->update();
    mStageMoveDelayE->update();
	mZeroCutsE->update();
	mComportCB->ItemIndex = mCOMPort - 1;

    //Setup UI elements
	mZebraCOMPortCB->ItemIndex = mZebraCOMPort - 1;

    //Find which item should be selected
    for(int i = 0; i < mZebraBaudRateCB->Items->Count; i++)
    {
		if(mZebraBaudRateCB->Items->Strings[i].ToInt() == mZebraBaudRate)
        {
			mZebraBaudRateCB->ItemIndex = i;
            break;
        }
    }



}

__fastcall TMainForm::~TMainForm()
{}

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
//    mFrontBackLEDBtn->Enabled = enable;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mFrontBackLEDBtnClick(TObject *Sender)
{
//	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);
//    if(b == mFrontBackLEDBtn)
//    {
//    	mLightsArduinoClient.toggleLED();
//    }
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

    if(!mSettingsForm)
    {
		mSettingsForm = new TSettingsForm(*this);
    }

   	TATDBConnectionFrame1->init(&(mIniFile));
    TATDBConnectionFrame1->mATDBServerBtnConnect->Click();

    //Auto connect to the barcode reader
	mConnectZebraBtnClick(Sender);
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
            	UC7Message* m = (UC7Message*) msg.lparam;
                Log(lDebug) << "Handling UC7 message: \"" << m->getMessageNameAsString()<<"\" with data: "<<m->getData();
                bool result = handleUC7Message(*m);
                if(!result)
                {
                	Log(lError) << "The message: "<<m->getFullMessage()<<" was not properly handled!";
                }
                delete m;
            }
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


	enableDisableUI(true);
	mSynchUIBtnClick(NULL);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::onDisConnectedToUC7()
{
	enableDisableUI(false);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::enableDisableUI(bool enableDisable)
{
	//Buttons
    mConnectUC7Btn->Caption                 = enableDisable ? "Close" : "Open";
    mSynchUIBtn->Enabled					= enableDisable;

    //group boxes
	enableDisableGroupBox(CounterGB, 		enableDisable);
	enableDisableGroupBox(CuttingMotorGB, 	enableDisable);
    enableDisableGroupBox(HandwheelGB, 		enableDisable);
    enableDisableGroupBox(NorthSouthGB,		enableDisable);
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
			playABSound(absBeforeBackOff, SND_ASYNC);
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
        mRibbonStartBtn->Enabled = false;
    }
}

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
    else if(btn == mRibbonStartBtn)
    {
    	if(btn->Caption == "Back off")
        {
			mUC7.prepareToCutRibbon(true);
            btn->Caption = "Preparing for IDLE";
        }
        else
        {
            mUC7.prepareForNewRibbon(true);
            btn->Caption = "Preparing start of Ribbon";
            btn->Enabled = false;
        }
    }
    else if(btn == mMoveSouthBtn)
    {
    	mUC7.moveKnifeStageSouth(mKnifeStageJogStep->getValue());
    }
    else if(btn == mMoveNorthBtn)
    {
    	mUC7.moveKnifeStageNorth(mKnifeStageJogStep->getValue());
    }

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
	TIntegerLabeledEdit* e = dynamic_cast<TIntegerLabeledEdit*>(Sender);

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
        }

        else if(e == mKnifeStageJogStep)
        {
            mUC7.setKnifeStageJogStepPreset(e->getValue());
        }

        else if(e == mNorthLimitPosE)
        {
            mUC7.setNorthLimitPosition(e->getValue());
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mRegisterRibbonBtnClick(TObject *Sender)
{
	//Check that we have a valid barcode for the coverslip
    //Block Label
    System::Variant lbl = atdbDM->blocksCDS->FieldByName("label")->Value;
    if(mBCLabel->Caption == "" || lbl.IsNull())
    {
    	MessageDlg("A valid coverslip barcode and a valid block is necesarry for ribbon registration!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    }
    else
    {
		TRegisterNewRibbonForm* rrf = new TRegisterNewRibbonForm(*this);
//        rrf->setCoverSlipBarcode(stdstr(mBCLabel->Caption));
        rrf->setCoverSlipBarcode("C0002632");

        if(rrf->ShowModal() == mrOk)
        {
	        mBCLabel->Caption = "";
        }
	    delete rrf;
    }
}

//---------------------------------------------------------------------------
int	TMainForm::getZebraCOMPortNumber()
{
	return mZebraCOMPortCB->ItemIndex + 1;
}

void __fastcall TMainForm::mConnectZebraBtnClick(TObject *Sender)
{
	int Comport = getZebraCOMPortNumber();
   	if(mConnectZebraBtn->Caption == "Open")
    {
        if(mZebra.connect(Comport, mZebraBaudRate, this->Handle) != true)
        {
        	Log(lError) << "Failed to connect barcode reader";
        }
    }
    else
    {
    	mZebra.disconnect();
    }

    if(mZebra.isConnected())
    {
	    onConnectedToZebra();
    }
    else
    {
    	onDisConnectedToZebra();
    }
}

void __fastcall TMainForm::onConnectedToZebra()
{
    mConnectZebraBtn->Caption = "Close";
    enableDisableGroupBox(mImagerSettingsGB, true);
	Log(lInfo) << "Connected to a Zebra barcode scanner";
    //Turn into a 'known' state
	//	mZebra.beep(ONESHORTLO);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::onDisConnectedToZebra()
{
    mConnectZebraBtn->Caption = "Open";
    enableDisableGroupBox(mImagerSettingsGB, false);
	Log(lInfo) << "DisConnected from a Zebra barcode scanner";
}

void __fastcall TMainForm::mBtnClick(TObject *Sender)
{
	TButton* b = dynamic_cast<TButton*>(Sender);
    int status(-1);
    if(b == mBeepBtn)
    {
		int status = mZebra.beep(ONESHORTLO);
    }
    else if(b == mDecodeSessionBtn)
    {
    	if(b->Caption == "Start")
        {
        	//Start session
			status = mZebra.startDecodeSession();
			b->Caption = "Stop";
        }
        else
        {
        	//Stop session
			status = mZebra.stopDecodeSession();
            b->Caption = "Start";
            Sleep(100);
            mZebra.illuminationOff();
        }
    }

    Log(lInfo) << "Command return status: "<<status;
}

void __fastcall TMainForm::onWMDecode(TMessage& Msg)
{
	WPARAM w = Msg.WParam;
    LPARAM l = Msg.LParam;

	//Time do decode
    Log(lInfo) << "Got a onWMDecode message..";

    // wparam contains the status bits for the data ,
	// lparam is the length of the data in bytes (cast to int).
	unsigned char decodeBuffer[3001];

	// first thing is to copy the contents of the dll's data buffer to our own.
	if((l < 3000) && ((w & BUFFERSIZE_MASK) == BUFFERSIZE_GOOD ))
	{
		memcpy(decodeBuffer, mZebra.getMemoryBuffer(), l);
		decodeBuffer[l] = 0;
	}
	else if( l && ((w & BUFFERSIZE_MASK) == BUFFERSIZE_ERROR ))
    {
		strcpy((char *)decodeBuffer, "TOO MUCH DECODE DATA");
    }
	else
   	{
    	strcpy((char *)decodeBuffer, "NO DECODE STORAGE BUFFER");
   	}

	decodeBuffer[3000] = 0;
    if(decodeBuffer[0] == 0x1B)
    {

        decodeBuffer[0] = ' ';
        string data(reinterpret_cast<char const*>(decodeBuffer));
        data = trimWS(data);
    	Log(lInfo) << "A Datamatrix barcode was encoded: "<<data;
        Log(lInfo) << decodeBuffer;
        mBCLabel->Caption = vclstr(data);
        //Stop session
//		mZebra.stopDecodeSession();
        mDecodeSessionBtn->Caption = "Start";
//        Sleep(100);
//        mZebra.illuminationOff();
//        Sleep(100);
//        mZebra.aimOff();
//        Sleep(100);
    }
    else
    {
    	Log(lError) << "Bad barcode reader memory buffer";
    }
}

void __fastcall TMainForm::onSSIEvent(TMessage& Msg)
{
	WPARAM w = Msg.WParam;
    LPARAM l = Msg.LParam;
    Log(lInfo) << "There was an onSSIEvent event..";
}

void __fastcall TMainForm::onSSIImage(TMessage& Msg)
{
//	WPARAM w = Msg.WParam;
//    LPARAM l = Msg.LParam;
//    Log(lInfo) << "There was an onSSIImage event..";
//
//	String msg;
//	unsigned char *pData = NULL;   //(unsigned char *) w;
//	DWORD length = (DWORD)l;
//	unsigned char *pImageType = pData;
//	int filetype = IMAGE_TYPE_UNKNOWN;
//	//CMainFrame * pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;  // This is our access to menu related stuff
//
//	if((w & BUFFERSIZE_MASK) == BUFFERSIZE_GOOD)
//	{
//    	msg.Format("Image Complete");	// Main pane of status bar gives status
//		pData = g_pImageData;
//		pImageType = pData;
//	}
//   	else if ((w & BUFFERSIZE_MASK) == BUFFERSIZE_ERROR)
//    {
//    	msg.Format("Image TOO BIG");	// Main pane of status bar gives status
//    }
//   	else
//    {
//    	msg.Format("NO Image BUFFER");	// Main pane of status bar gives status
//    }
//
////	MyMessage = "Received Image";	// Right side tells what message we got from the dll
//	//onSSIxferStatus((WPARAM)l, l);	// Update the transfer status display to show we got all of the expected image data
//
//
//	// Since we are done with the transfer, we'll enable the user to do whatever they want again
//	// ...(as long as it's supported).
//
////	GetDlgItem(IDC_BUTTON_VIDEO)->EnableWindow(1);
////	GetDlgItem(IDC_BUTTON_SNAPSHOT)->EnableWindow(1);
////	if(m_bViewFinderSupported)
////		GetDlgItem(IDC_CHECK_VIEWFINDER)->EnableWindow(1);
////	GetDlgItem(IDC_RADIO_BMP)->EnableWindow(1);
////	GetDlgItem(IDC_RADIO_TIFF)->EnableWindow(1);
////	GetDlgItem(IDC_RADIO_JPEG)->EnableWindow(1);
////	GetDlgItem(IDC_CHECK_SWTRIGGER)->EnableWindow(1);
//
//
//	// If the input data begins with "BM" it's a bitmap
//	// Else if it starts with "MM" or "II" its a tiff - note that we expect big endian from the scanner, and ignore
//	// ...the II for indication for byte ordering.
//
//	if(pImageType != NULL)
//   	{
//   		if((*pImageType == 'B') && (*(pImageType +1) == 'M'))
//	   	{
//        	filetype = BITMAP_TYPE;
//		   	SetupBMPforDisplay( pData,  l);			 // Process input and next Paint message will display our data
//		   	pFrame->m_ImgFileExtension = "bmp";  // Let user choose file save from menu, and set file filter to bmp extension.
//	   	}
//	   	else if (((*pImageType == 'M') && (*(pImageType +1) == 'M')) || ((*pImageType == 'I') && (*(pImageType +1) == 'I')))
//	   	{
//        	SetupTIFFforDisplay( pData,  l);			// Process input and next Paint message will display our data
//		   	filetype = TIFF_TYPE;
//		   	pFrame->m_ImgFileExtension = "tif"; // Let user choose file save from menu, and set file filter to tif extension.
//	   	}
//	   	else if((*pImageType == 0xff) && (*(pImageType +1) == 0xd8))
//	   	{
//        	filetype = JPEG_TYPE;
//			SetupJPEGforDisplay(pData,l, FALSE); // False indicates this is not video
//		   							// Process input and next Paint message will display our data
//
//		   	pFrame->m_ImgFileExtension = "jpg";	// Let user choose file save from menu, and set file filter to jpg extension.
//	   	}
//	   	else
//	   	{
//        	MessageBox("Unknown image format received");
////		   	pFrame->m_ImgFileExtension = "";		// This will indicate  file save from menu needs to be disabled.
//	   	}
//
//	   	m_ImgFileExt = 	pFrame->m_ImgFileExtension;	// Our copy, so we stay in sync with the menu.
//
//	   	if(filetype != IMAGE_TYPE_UNKNOWN)
//        {
//		   WriteImgfile((LPTSTR)pData, length, filetype);	// We always write a temp file since we can't hang on to the
//															// ...dll's data to do it later.
//        }
//   }
//	m_WaitingForSnapShot = FALSE;
}

void __fastcall TMainForm::onSSITimeout(TMessage& Msg)
{
	WPARAM w = Msg.WParam;
    LPARAM l = Msg.LParam;
    Log(lInfo) << "There was an onSSITimeout event..";
}

void __fastcall TMainForm::onSSIError(TMessage& Msg)
{
	WPARAM w = Msg.WParam;
    LPARAM l = Msg.LParam;
    Log(lInfo) << "There was an onSSIError event.."<<w<<" : "<<l;
}

void __fastcall TMainForm::onSSICapabilities(TMessage& Msg)
{
	WPARAM w = Msg.WParam;
    LPARAM l = Msg.LParam;
    Log(lInfo) << "There was an onSSICapabilities event..";
}



//---------------------------------------------------------------------------
void __fastcall TMainForm::scannerSettingsClick(TObject *Sender)
{
	//Check which one was clicked
    TRadioGroup* rg = dynamic_cast<TRadioGroup*>(Sender);

    int status;
    if(rg == mScannerAimRG)
    {
    	status  = (rg->ItemIndex == 0 ) ? mZebra.aimOn() : mZebra.aimOff();
    }
    else if(rg == mScannerEnabledRG)
    {
    	status  = (rg->ItemIndex == 0 ) ? mZebra.scanEnable() : mZebra.scanDisable();
    }

    Log(lInfo) << "Status: "<<status;
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::mUsersCBCloseUp(TObject *Sender)
{
    mDBUserID.setValue(mUsersCB->KeyValue);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mBlockProcessIDCBCloseUp(TObject *Sender)
{
    mProcessID.setValue(mBlockProcessIDCB->KeyValue);
}


