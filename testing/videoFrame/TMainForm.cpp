#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TMemoLogger.h"
#include "mtkVCLUtils.h"
#include "mtkLogger.h"
#include "TFFMPEGOutputFrame.h"

#include "database/atDBUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma link "TFFMPEGFrame"
#pragma link "TSTDStringLabeledEdit"
#pragma link "TIntLabel"
#pragma link "TSTDStringEdit"
#pragma link "TATDBConnectionFrame"
#pragma resource "*.dfm"

TMainForm *MainForm;
extern string           gLogFileLocation;
extern string           gLogFileName;
extern string           gAppDataFolder;
extern string 			gApplicationRegistryRoot;
extern string			gAppExeName;
extern bool             gAppIsStartingUp;
using namespace mtk;
using namespace at;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner),
	mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppExeName, gLogFileName), &logMsg),
    mIniFile(joinPath(gAppDataFolder, gAppExeName + ".ini"), true, true),
    mLogLevel(lAny)
{
	TMemoLogger::mMemoIsEnabled = false;
   	mLogFileReader.start(true);
}

//---------------------------------------------------------------------------
//This one is called from the reader thread
void __fastcall TMainForm::logMsg()
{
	string& msg = mLogFileReader.getData();

    if(infoMemo->Lines->Count > 1000)
    {
		infoMemo->Clear();
    }

    if(msg.size())
    {
    	infoMemo->Lines->Insert(0, vclstr(msg));
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        Close();
    }
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseForFolder1Accept(TObject *Sender)
{
	MovieFolder->setValue(stdstr(BrowseForFolder1->Folder));

}


//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	try
    {
    	if(!atdbDM)
        {
            throw(string("NULL data module"));
        }
        atdbDM->SQLConnection1->AfterConnect 	= afterDBServerConnect;
        atdbDM->SQLConnection1->AfterDisconnect = afterDBServerDisconnect;
    }
    catch(...)
    {
    	handleMySQLException();
    }
}

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterDBServerConnect(System::TObject* Sender)
{
	Log(lInfo) << "Succesfully connected to DB Server";

	atdbDM->afterConnect();

	TATDBConnectionFrame1->afterConnect();

	//Setup UI

}

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterDBServerDisconnect(System::TObject* Sender)
{
	Log(lInfo) << "Disconnected from the DB Server";
	atdbDM->afterDisConnect();

	TATDBConnectionFrame1->afterDisconnect();
}



