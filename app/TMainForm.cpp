#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkLogger.h"
#include "core/atCore.h"
#include "ArrayCamMessages.h"
#include "TPGDataModule.h"
#include "mtkVCLUtils.h"
#include "TSelectIntegerForm.h"
#include "THandWheelPositionForm.h"
#include "TActionsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "mtkFloatLabel"
#pragma link "TApplicationSoundsFrame"
#pragma link "TArrayBotBtn"
#pragma link "TFFMPEGFrame"
#pragma link "TFloatLabeledEdit"
#pragma link "TImagesFrame"
#pragma link "TIntegerLabeledEdit"
#pragma link "TIntLabel"
#pragma link "TMoviesFrame"
#pragma link "TNavitarMotorFrame"
#pragma link "TPropertyCheckBox"
#pragma link "TSoundsFrame"
#pragma link "TSTDStringLabeledEdit"
#pragma link "TUC7StagePositionFrame"
#pragma link "TSyncMySQLToPostgresFrame"

#pragma resource "*.dfm"
TMainForm *MainForm;

extern string gApplicationRegistryRoot;
extern string gLogFileName;
extern string gAppDataFolder;
extern bool   gAppIsStartingUp;
extern bool   gAppIsClosing;

using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	:
    	TRegistryForm(gApplicationRegistryRoot, "MainForm", Owner),
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
        mLocalDBName(""),
        mReticle(mPB->Canvas),
        mReticle2(mPB->Canvas, TReticle::rtCrossHair, clBlue),
        mServiceCamera1(mCamera1, 1, this->Handle),
        mMovingReticle(false),
        mCheckArduinoServerConnection(true),
        mConnectToArduinoServerThread(mLightsArduinoClient, 50000),
        mUC7COMPort(0),
        mUC7(Handle),
        mCountTo(0),
	    mDBUserID(0),
	    mSpecimenID(0),
	    mSliceID(0),
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
   	SectionCounterLabel->setReference(mUC7.getSectionCounter().getCountReference());
    RibbonOrderCountLabel->setReference(mUC7.getRibbonOrderCounter().getCountReference());
    mZeroCutsE->setReference(mUC7.getNumberOfZeroStrokesReference());

    mCountToE->update();
    SectionCounterLabel->update();
    RibbonOrderCountLabel->update();
    mZeroCutsE->update();

    //Properties are retrieved and saved to an ini file
    setupProperties();
    mGeneralProperties.read();
    mSoundProperties.read();

    TFFMPEGFrame1->setupProperties(mIniFile);

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

    /******** Update UI controls *************/
    //Todo, put these in a container and call update in a loop

    MainContentPanel->Width = mMainContentPanelWidth;
	mCountToE->update();
    mPresetFeedRateE->update();
    mUC7.setFeedRatePreset(mPresetFeedRateE->getValue());

    PresetReturnSpeedE->update();
    SlowReturnSpeedE->update();
    UltraSlowReturnSpeedE->update();

    mStageMoveDelayE->update();
	mZeroCutsE->update();
	mUC7ComportCB->ItemIndex = mUC7COMPort - 1;
	ArrayCamServerPortE->update();
    MaxStagePosFrame->setValue(mKnifeStageMaxPos.getValue());
    BackOffStepFrame->setValue(mKnifeStageJogStep.getValue());
    ResumeDeltaDistanceFrame->setValue(mKnifeStageResumeDelta.getValue());
    mUC7.setKnifeStageResumeDelta(mKnifeStageResumeDelta.getValue());
    mUC7.setKnifeStageJogStepPreset(mKnifeStageJogStep.getValue());
    MediaFolderE->update();
	WinCaptionE->update();
    ClickXE->update();
    ClickYE->update();

	mZebraCOMPortCB->ItemIndex = mZebraCOMPort - 1;

	THeaderSection* Section = CameraHC->Sections->Items[2];
    Section->Text = mReticleVisible ? "Hide Reticle" : "Show Reticle";

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

	mReticle2.visible(false);
}

__fastcall TMainForm::~TMainForm()
{}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mStartupTimerTimer(TObject *Sender)
{
	mStartupTimer->Enabled = false;

   	TPGConnectionFrame1->init(&mIniFile, "POSTGRESDB_CONNECTION");
    TPGConnectionFrame1->ConnectA->Execute();

	mConnectZebraBtnClick(Sender);

    //Connect to the UC7
    mConnectUC7Btn->Click();

    //Connect navitar motors
    NavitarControllerConnectBtn->Click();
    updateTemperature(-1);
	updateHumidity(-1);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject *Sender)
{;}

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
                Log(lDebug) << "Handling Misc message: \"" << *m;
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
void __fastcall TMainForm::mUsersCBCloseUp(TObject *Sender)
{
	if(!mUsersCB->KeyValue.IsNull())
    {
    	mDBUserID.setValue(mUsersCB->KeyValue);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::DB_CBCloseUp(TObject *Sender)
{
	TDBLookupComboBox* b = dynamic_cast<TDBLookupComboBox*>(Sender);
    if(b == SpecimenIDCB)
    {
       	if(!b->KeyValue.IsNull())
		{
            mSpecimenID.setValue(b->KeyValue);
            pgDM->blocksCDS->Active = false;
            pgDM->blockNotesCDS->Active = false;
        }
    }
    else if(b == SliceIDCB)
    {
    	if(!b->KeyValue.IsNull())
		{
            mSliceID.setValue(b->KeyValue);
            pgDM->blockNotesCDS->Active = false;
            pgDM->blocksCDS->Active = true;
        }
    }
    else if(b == BlockIDCB )
    {
    	if(!b->KeyValue.IsNull())
		{
        	mBlockID.setValue(b->KeyValue);
        	pgDM->blockNotesCDS->Active = true;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::SendServerStatusMessageBtnClick(TObject *Sender)
{
	mACServer.broadcastStatus();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::CountLabelClick(TObject *Sender)
{
	TIntLabel* lbl = dynamic_cast<TIntLabel*>(Sender);

    TSelectIntegerForm* f = new TSelectIntegerForm(this);
    f->setCurrentNumber(lbl->getValue());
    int res = f->ShowModal();
    if(res == mrOk)
    {
    	lbl->setValue(f->mTheNumberLbl->getValue());
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


//---------------------------------------------------------------------------
void __fastcall TMainForm::mBlockNoteNavigatorClick(TObject *Sender, TNavigateBtn Button)
{
	switch(Button)
    {
    	case TNavigateBtn::nbInsert:
			{
                int uID = pgDM->usersCDS->FieldByName("id")->AsInteger;
                int blockID = pgDM->blocksCDSid->Value;
                string note("Block Note..");
            	pgDM->insertBlockNote(uID, blockID, note);
            }
        break;
    }
}

void __fastcall TMainForm::mRibbonNotesNavigatorClick(TObject *Sender, TNavigateBtn Button)

{
	switch(Button)
    {
    	case TNavigateBtn::nbInsert:
        {
            int uID = getCurrentUserID();
            String rID = pgDM->ribbonsCDSid->Value;
            string note("Ribbon Note..");
           	pgDM->insertRibbonNote(uID, stdstr(rID), note);
        }
        break;

    	case TNavigateBtn::nbDelete:        break;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ToggleControlBarExecute(TObject *Sender)
{
	ControlBar1->Visible = !ControlBar1->Visible;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ToggleControlBarUpdate(TObject *Sender)
{
	ToggleControlBar->Caption = ControlBar1->Visible ? "Hide ControlBar" : "Show ControlBar";
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::TakeSnapShotBtnClick(TObject *Sender)
{
	takeSnapShot();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::VideoRecTimerTimer(TObject *Sender)
{
	static int recTime(0);   //(milliseconds)
	if(mCaptureVideoTimer->Enabled)
    {
    	time_t seconds(recTime / 1000.0);
        tm *p = gmtime(&seconds);
        stringstream time;
        time << "Stop Recording \r";
        if(p)
        {
        	time <<"(" << p->tm_min <<":"<<p->tm_sec <<")";
        }
    	RecordVideoBtn->Caption = vclstr(time.str());
        recTime += VideoRecTimer->Interval;
    }
    else
    {
    	RecordVideoBtn->Caption = "Record Video";
		VideoRecTimer->Enabled = false;
        recTime = 0;
    }

    int maxRecTime = 30 * (60 * 1000); //Minutes
    if(recTime > maxRecTime)
    {
    	Log(lInfo) << "Stoppped movie at: " << recTime;
		stopRecordingMovie();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::RecordVideoBtnClick(TObject *Sender)
{
	startStopRecordingMovie();

	if(mCaptureVideoTimer->Enabled)
    {
		VideoRecTimer->Enabled = true;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ControlBar1StartDrag(TObject *Sender, TDragObject *&DragObject)
{
	this->Align = alNone;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FrontLEDTBChange(TObject *Sender)
{
	TTrackBar* tb = dynamic_cast<TTrackBar*>(Sender);
    if(!tb)
    {
    	return;
    }

   	int pos = tb->Position;
    if(tb == FrontLEDTB)
    {
        if(tb->Tag != 1) //Means we are updating UI from thread
        {
	        setLEDIntensity(pos);
        }
        mFrontLEDLbl->Caption = "Front LED (" + IntToStr(pos) + ")";
    }
}

void TMainForm::setLEDIntensity(int intensity)
{
	TTrackBar* tb = FrontLEDTB;
	//Means we are updating UI from thread
    if(tb->Tag != 1)
    {
        stringstream s;
        s<<"SET_FRONT_LED_INTENSITY="<<intensity;
        mLightsArduinoClient.request(s.str());
	    mACServer.broadcast(acrLEDIntensitySet);
    }
}

void __fastcall TMainForm::BlockIDSLLBMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	populateMedia();
}

void TMainForm::populateMedia()
{
    if(BlockIDSLLB->KeyValue.IsNull())
    {
        return;
    }

    //Check what page is open, movies or images
    Poco::Path p(MediaFolderE->getValue());
    if(MediaPageControl->TabIndex == 0)
    {
		TMoviesFrame1->populate(BlockIDSLLB->KeyValue, p);
    }
    else //Populate Images
	{
		TImagesFrame1->populate(BlockIDSLLB->KeyValue, p);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BlockIDSLLBKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkUp || Key == vkDown|| Key == vkLeft|| Key == vkRight)
    {
        populateMedia();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseForFolderClick(TObject *Sender)
{
	//Open Browse for folder dialog
	TButton* b = dynamic_cast<TButton*>(Sender);
    if(b == BrowseForMediaFolderBtn)
    {
        string f = browseForFolder(MediaFolderE->getValue());
        if(!f.size())
        {
            return;
        }

    	MediaFolderE->setValue(f);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::MediaPageControlChange(TObject *Sender)
{
	populateMedia();
}

void __fastcall TMainForm::checkSyncWhiskerCB()
{
	SyncWhiskerCB->Checked = true;
    mACServer.broadcast(acrMoveWhiskerForwardOnSet);
}

void __fastcall TMainForm::unCheckSyncWhiskerCB()
{
	SyncWhiskerCB->Checked = false;
    mACServer.broadcast(acrMoveWhiskerForwardOffSet);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::SyncWhiskerCBClick(TObject *Sender)
{
	if(SyncWhiskerCB->Checked)
    {
    	mACServer.broadcast(acrMoveWhiskerForwardOnSet);
    }
    else
    {
       	mACServer.broadcast(acrMoveWhiskerForwardOffSet);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::TestClickWindowBtnClick(TObject *Sender)
{
    clickOnWindow(WinCaptionE->getValue(), ClickXE->getValue(), ClickYE->getValue());
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControlChange(TObject *Sender)
{
	//Check if we need any processing as a tab changes
	TPageControl* pc = dynamic_cast<TPageControl*>(Sender);

    if(pc == MiscPageControl)
    {
    	MouseClickTimer->Enabled = (pc->TabIndex == 4) ? true : false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControlExit(TObject *Sender)
{
	//Check if we need any processing as a tab changes
	TPageControl* pc = dynamic_cast<TPageControl*>(Sender);

    if(pc == MiscPageControl)
    {
       	MouseClickTimer->Enabled = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::MouseClickTimerTimer(TObject *Sender)
{
    HWND hwnd = FindWindow(0, WinCaptionE->getValue().c_str() );
    if(hwnd)
    {
    	WindowCheckLbl->Caption = "Found window";
    	enableDisableGroupBox(GroupBox10, true);
	    POINT p;
		if (GetCursorPos(&p))
        {
        	if (::ScreenToClient(hwnd, &p))
			{
			    //p.x and p.y are now relative to hwnd's client area
		        winXLbl->Caption = "X = " + IntToStr((int) p.x);
		        winYLbl->Caption = "Y = " + IntToStr((int) p.y);
			}
        }
    }
    else
    {
    	enableDisableGroupBox(GroupBox10, false);
    	WindowCheckLbl->Caption = "No such Window";
    }
}

//---------------------------------------------------------------------------
void __fastcall	TMainForm::fireRibbonSeparator()
{
	Log(lInfo) << "Firing the ribbon separator";
    clickOnWindow(WinCaptionE->getValue(), ClickXE->getValue(), ClickYE->getValue());
}
