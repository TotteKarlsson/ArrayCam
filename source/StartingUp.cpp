#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "TATDBDataModule.h"
#include "TSettingsForm.h"

using namespace mtk;
using namespace at;
extern bool   gAppIsStartingUp;
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
	mFitToScreenButtonClick(Sender);

    enableDisableClientControls(false);

    //Setup LogLevel CB
    string logLevel = mtk::toString(gLogger.getLogLevel());

    //Find item in CB with this loglevel
    int index = LogLevelCB->Items->IndexOf(vclstr(logLevel));

    if(index > -1)
    {
		LogLevelCB->ItemIndex = index;
    }

	//Connect to the arduino server..
	mCheckSocketConnectionTimer->Enabled = true;

    //Setup the server
    mACServer.start(mArrayCamServerPortE->getValue());
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	string dBase(mLocalDBName);
	try
    {

        atdbDM->SQLConnection1->AfterConnect 	= afterServerConnect;
        atdbDM->SQLConnection1->AfterDisconnect = afterServerDisconnect;

//        ImagesAndMoviesDM->SQLConnection1->AfterConnect 	= afterServerConnect;
//        ImagesAndMoviesDM->SQLConnection1->AfterDisconnect = afterServerDisconnect;
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
}

