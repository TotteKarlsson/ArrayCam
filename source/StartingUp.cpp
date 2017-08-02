#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "TATDBDataModule.h"
#include "TNavitarPresetFrame.h"
using namespace mtk;
using namespace at;
extern bool   gAppIsStartingUp;

void TMainForm::setupProperties()
{
	//Setup UI/INI properties
    mGeneralProperties.setSection("GENERAL");
	mGeneralProperties.setIniFile(&mIniFile);

	mGeneralProperties.add((BaseProperty*)  &mLogLevel.setup( 	    	                    "LOG_LEVEL",    					lAny));
	mGeneralProperties.add((BaseProperty*)  &mMainContentPanelWidth.setup( 	                "MAIN_CONTENT_PANEL_WIDTH",   		700));
	mGeneralProperties.add((BaseProperty*)  &mPairLEDs.setup(			                    "PAIR_LEDS",    		            true));
	mGeneralProperties.add((BaseProperty*)  &mDBUserID.setup( 	                    	    "ATDB_USER_ID",                    	0));
	mGeneralProperties.add((BaseProperty*)  &mSpecimenID.setup( 	               	        "SPECIMEN_ID",      	            0));
	mGeneralProperties.add((BaseProperty*)  &mSliceID.setup( 	              	 	        "SLICE_ID",      		            0));
	mGeneralProperties.add((BaseProperty*)  &mBlockID.setup( 	                   		    "BLOCK_ID",                  		0));
	mGeneralProperties.add((BaseProperty*)  &mLocalDBName.setup(		                    "LOCAL_DB",   			            "umlocal.db"));

    //Camera Settings
	mGeneralProperties.add((BaseProperty*)  &mAutoGain.setup(			                    "AUTO_GAIN",    		            false));
	mGeneralProperties.add((BaseProperty*)  &mAutoExposure.setup( 		                    "AUTO_EXPOSURE",    	            false));
	mGeneralProperties.add((BaseProperty*)  &mAutoBlackLevel.setup(  	                    "AUTO_BLACK_LEVEL",    	            false));
	mGeneralProperties.add((BaseProperty*)  &mAutoWhiteBalance.setup( 	                    "AUTO_WHITE_BALANCE",  	            false));
	mGeneralProperties.add((BaseProperty*)  &mSoftwareGamma.setup( 	                        "SOFTWARE_GAMMA",  		            0));
	mGeneralProperties.add((BaseProperty*)  &mVerticalMirror.setup(	                        "VERTICAL_MIRROR",    	            false));
	mGeneralProperties.add((BaseProperty*)  &mHorizontalMirror.setup(	                    "HORIZONTAL_MIRROR",                false));
    mGeneralProperties.add((BaseProperty*)  &mSnapShotFolder.setup(	                        "SNAP_SHOT_FOLDER",                 "C:\\Temp"	));
	mGeneralProperties.add((BaseProperty*)  &mMoviesFolder.setup(		                    "MOVIES_FOLDER",   		            "C:\\Temp"	));
	mGeneralProperties.add((BaseProperty*)  &mReticleVisible.setup(					        "RETICLE_VISIBILITY",              false));

    //UC7
   	mGeneralProperties.add((BaseProperty*)  &mUC7COMPort.setup( 	                        "UC7_COM_PORT",    	   				0));
	mGeneralProperties.add((BaseProperty*)  &mCountToE->getProperty()->setup(       	    "COUNT_TO",                     	5));
	mGeneralProperties.add((BaseProperty*)  &mZeroCutsE->getProperty()->setup(      	    "NUMBER_OF_ZERO_CUTS",           	2));
	mGeneralProperties.add((BaseProperty*)  &mStageMoveDelayE->getProperty()->setup(	    "KNIFE_STAGE_MOVE_DELAY",          	10));
	mGeneralProperties.add((BaseProperty*)  &mPresetFeedRateE->getProperty()->setup(	    "PRESET_FEED_RATE",               	100));
	mGeneralProperties.add((BaseProperty*)  &mKnifeStageJogStep.setup(	    				"KNIFE_STAGE_JOG_SIZE",          	100));
	mGeneralProperties.add((BaseProperty*)  &mKnifeStageResumeDelta.setup(	    			"KNIFE_STAGE_RESUME_DELTA",        	0));
	mGeneralProperties.add((BaseProperty*)  &mArrayCamServerPortE->getProperty()->setup(	"ARRAYCAM_SERVER_PORT",          	50001));
	mGeneralProperties.add((BaseProperty*)  &mKnifeStageMaxPos.setup(						"KNIFE_STAGE_MAX_POSITION",        	0));

    //Zebra
	mGeneralProperties.add((BaseProperty*)  &mZebraCOMPort.setup( 	                    	"ZEBRA_COM_PORT",                   0));
	mGeneralProperties.add((BaseProperty*)  &mZebraBaudRate.setup( 	                		"ZEBRA_BAUD_RATE",                  9600));

    mSoundProperties.setSection("SOUNDS");
	mSoundProperties.setIniFile(&mIniFile);
	mSoundProperties.add((BaseProperty*)  &mKnifeBeforeCuttingSound.setup( 	           		"KNIFE_BEFORE_CUTTING_SOUND",       ApplicationSound("BUTTON_CLICK_1")));
	mSoundProperties.add((BaseProperty*)  &mKnifeCuttingSound.setup( 	               		"KNIFE_CUTTING_SOUND",              ApplicationSound("BUTTON_CLICK_1")));
	mSoundProperties.add((BaseProperty*)  &mKnifeAfterCuttingSound.setup( 	           		"KNIFE_AFTER_CUTTING_SOUND",        ApplicationSound("BUTTON_CLICK_1")));
	mSoundProperties.add((BaseProperty*)  &mArmRetractingSound.setup( 	           			"ARM_RETRACTING_SOUND",       		ApplicationSound("BUTTON_CLICK_1")));
	mSoundProperties.add((BaseProperty*)  &mBeforeKnifeBackOffSound.setup( 	           		"BEFORE_KNIFE_BACKOFF_SOUND",       ApplicationSound("SHORT_BEEP_1")));

	mNavitarPreset1.setup("NAVITAR_PRESET_1", mIniFile);
	mNavitarPreset2.setup("NAVITAR_PRESET_2", mIniFile);
   	mNavitarPreset3.setup("NAVITAR_PRESET_3", mIniFile);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    //Camera stuff
	mCamera1DisplayHandle 	= this->mCamera1BackPanel->Handle;

    Log(lDebug) << "Init camera..";

    //Live
    if(!mCamera1.IsInit())
    {
    	mServiceCamera1.openCamera();
    }

	mCamera1BackPanel->Width 	= 1280;
	mCamera1BackPanel->Height 	= 1024;
	mCamera1BackPanel->Top 		= 0;
	mCamera1BackPanel->Left 	= 0;
    enableDisableClientControls(false);

	//Connect to the arduino server..
	CheckArduinoServerConnectionTimer->Enabled = true;

    //Setup the server
    mACServer.start(mArrayCamServerPortE->getValue());

    //Populate misc frames
	TSoundsFrame1->populate();
    TApplicationSoundsFrame1->populate(mSoundProperties);

    //Setup some navitar preset frames
    TNavitarPresetFrame* f1 = new TNavitarPresetFrame(mNavitarPreset1, this);
    f1->Parent = NavitarPresetGB;
    f1->Align = alTop;

    TNavitarPresetFrame* f2 = new TNavitarPresetFrame(mNavitarPreset2, this);
    f2->Parent = NavitarPresetGB;
    f2->Align = alTop;

    TNavitarPresetFrame* f3 = new TNavitarPresetFrame(mNavitarPreset3, this);
    f3->Parent = NavitarPresetGB;
    f3->Align = alTop;
    ReadRegistry();

}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	string dBase(mLocalDBName);
	try
    {

        atdbDM->SQLConnection1->AfterConnect 	= afterDBServerConnect;
        atdbDM->SQLConnection1->AfterDisconnect = afterDBServerDisconnect;

//        ImagesAndMoviesDM->SQLConnection1->AfterConnect 	= afterDBServerConnect;
//        ImagesAndMoviesDM->SQLConnection1->AfterDisconnect = afterDBServerDisconnect;
    }
    catch(...)
    {
    	handleMySQLException();
    }

    //UI DB connection
//    if (ImagesAndMoviesDM->connect("127.0.0.1", "atdb_client", "atdb123", dBase))
//    {
//       // Connection successfull
//        Log(lInfo) << "DataModule connected to the database: "<<dBase;
//    }
//    else
//    {
//        Log(lInfo) << "Datamodule failed to connect to database: "<<dBase;
//    }

    gAppIsStartingUp = false;
    enableDisableUC7UI(false);
    enableDisableGroupBox(mImagerSettingsGB, false);
    mBCLabel->Caption = "";
	mStartupTimer->Enabled = true;
	this->Caption = vclstr(createWindowTitle("ArrayCam", Application));
	FitToScreenAExecute(Sender);
}

