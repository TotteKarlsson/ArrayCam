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
#include "TATDBImagesAndMoviesDataModule.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "frames/TMovieItemFrame.h"
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
#pragma link "TFFMPEGFrame"
#pragma link "TFFMPEGFrame"
#pragma link "TArrayBotBtn"
#pragma link "TSTDStringEdit"
#pragma link "TSTDStringLabeledEdit"
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
//        mSnapShotFolderE(""),
//        mMoviesFolderE(""),
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
    MoviesFolderE->update();
    SnapShotFolderE->update();

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
void __fastcall TMainForm::PageControl1Change(TObject *Sender)
{
	//Check if we need any processing as a tab changes
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mStartupTimerTimer(TObject *Sender)
{
	mStartupTimer->Enabled = false;

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
void __fastcall TMainForm::DB_CBCloseUp(TObject *Sender)
{
	TDBLookupComboBox* b = dynamic_cast<TDBLookupComboBox*>(Sender);
    if(b == SpecimenIDCB)
    {
        mSpecimenID.setValue(b->KeyValue);
        BlockIDCB->KeyValue = -1;
        SliceIDCB->KeyValue = -1;
    }
    else if(b == SliceIDCB)
    {
        mSliceID.setValue(b->KeyValue);
        BlockIDCB->KeyValue = -1;
    }
    else if(b == BlockIDCB )
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


//---------------------------------------------------------------------------
void __fastcall TMainForm::mBlockNoteNavigatorClick(TObject *Sender, TNavigateBtn Button)
{
	switch(Button)
    {
    	case TNavigateBtn::nbInsert:
			{
                int uID = atdbDM->usersCDS->FieldByName("id")->AsInteger;
                int blockID = atdbDM->blocksCDSid->Value;
                string note("Block Note..");
            	atdbDM->insertBlockNote(uID, blockID, note);
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
            String rID = atdbDM->mRibbonCDSid->Value;
            string note("Ribbon Note..");
           	atdbDM->insertRibbonNote(uID, stdstr(rID), note);
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
	static double recTime(0);
	if(mCaptureVideoTimer->Enabled)
    {
    	RecordVideoBtn->Caption = "Stop Recording (" + FloatToStrF(recTime, ffFixed, 0, 0) + " s)";
        recTime += .5;
    }
    else
    {
    	RecordVideoBtn->Caption = "Record Video";
		VideoRecTimer->Enabled = false;
        recTime = 0;
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
	    mACServer.broadcast(mACServer.IPCCommand(acrLEDIntensitySet));
    }
}

void __fastcall TMainForm::BlockIDSLLBMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	Log(lInfo) << "Mouse up................................";
	SQLQuery1->Open();
    StringList movies = fetchRecords();
	populateMovieFrames(movies);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::BlockIDSLLBKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkUp || Key == vkDown|| Key == vkLeft|| Key == vkRight)
    {
        //Log(lInfo) << "Key up................................";
        StringList movies = fetchRecords();
        populateMovieFrames(movies);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::BlockIDSLLBKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkUp || Key == vkDown || Key == vkLeft|| Key == vkRight)
    {
		SQLQuery1->Open();
    }
}

StringList TMainForm::fetchRecords()
{
	StringList movies;
    while(!SQLQuery1->Eof)
    {
		stringstream rec;
        rec <<stdstr(SQLQuery1->FieldByName("created")->AsString) <<"," <<stdstr(SQLQuery1->FieldByName("id")->AsString) <<".mp4";
        movies.append(rec.str());
        Log(lInfo) << "Got record: "<< stdstr(SQLQuery1->FieldByName("id")->AsString) << " at " << stdstr(SQLQuery1->FieldByName("created")->AsString);
        SQLQuery1->Next();
    }

	return movies;
}

void TMainForm::clearMovieFrames()
{
	list<TMovieItemFrame*>::iterator i = mMovies.begin();
    while(i != mMovies.end())
    {
    	delete (*i);
    	mMovies.erase(i++);
    }
}

void TMainForm::populateMovieFrames(const StringList& l)
{
	try
    {
        clearMovieFrames();

        if(l.count())
        {
            ScrollBox1->VertScrollBar->Visible = false;
        }

        //Current block nr
		if(BlockIDSLLB->KeyValue.IsNull())
        {
        	return;
        }

        //Create path
        Poco::Path p(stdstr(MoviesFolderE->Text));

        int blockID = BlockIDSLLB->KeyValue;

        p.append(mtk::toString(blockID));
        for(int i = 0; i < l.count(); i++)
        {
            StringList item(l[i], ',');
            if(item.count() == 2)
            {
                Poco::File f(Poco::Path(p, item[1]));

                TMovieItemFrame* frame = new TMovieItemFrame(f,this);
                frame->Visible = false;
                frame->MovieLbl->Caption = item[0].c_str();
                mMovies.push_back(frame);
            }
            else
            {
                Log(lError) << "Bad movie record..";
            }
        }

        list<TMovieItemFrame*>::iterator i = mMovies.begin();
        while(i != mMovies.end())
        {
            (*i)->Parent = FlowPanel1;;
            (*i)->Visible = true;
            i++;
        }

        ScrollBox1->VertScrollBar->Visible = true;
        NrOfRecordsLbl->setValue(l.count());
    }
    catch(...)
    {
    	Log(lError) << "There was a problem...";
    }
}




//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseForFolderClick(TObject *Sender)
{
	//Open Browse for folder dialog
	TButton* b = dynamic_cast<TButton*>(Sender);
    if(b == BrowseForImagesFolderBtn)
    {
        string f = browseForFolder(SnapShotFolderE->getValue());
        if(!f.size())
        {
            return;
        }

    	SnapShotFolderE->setValue(f);
    }
    else if(b == BrowseForMoviesFolderBtn)
    {
        string f = browseForFolder(MoviesFolderE->getValue());
        if(!f.size())
        {
            return;
        }

    	MoviesFolderE->setValue(f);
    }
}


