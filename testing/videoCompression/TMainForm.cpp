#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TMemoLogger.h"
#include "mtkVCLUtils.h"
#include "mtkLogger.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma link "TFFMPEGFrame"
#pragma link "TSTDStringLabeledEdit"
#pragma link "TIntLabel"
#pragma resource "*.dfm"

TMainForm *MainForm;
extern string           gLogFileLocation;
extern string           gLogFileName;
extern string           gAppDataFolder;
extern string 			gApplicationRegistryRoot;
extern string			gAppExeName;
extern bool             gAppIsStartingUp;
using namespace mtk;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner),
	mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppExeName, gLogFileName), &logMsg),
    mIniFile(joinPath(gAppDataFolder, "VideoCompressor.ini"), true, true),
    mLogLevel(lAny)

{
	TMemoLogger::mMemoIsEnabled = false;
   	mLogFileReader.start(true);

	mVCThread.assignCallBacks(
    boost::bind(&TMainForm::onEnter, 	this, _1, _1),
	boost::bind(&TMainForm::onProgress, this, _1, _1),
	boost::bind(&TMainForm::onExit, 	this, _1, _1)
    );
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

void __fastcall TMainForm::CompressClick(TObject *Sender)
{
	mVCThread.start();
}

void TMainForm::onEnter(int i, int j)
{
	Log(lInfo) << "Thread was entered..";
}

void TMainForm::onProgress(int i, int j)
{
    Log(lInfo) << "Thread is progressing: "<<i;

    //Updating UI controls need to be synchronized
	//with the main thread
	IntLabel1->setValue(i);
    ProgressBar1->Position = i;
}

void TMainForm::onExit(int i, int j)
{
	Log(lInfo) << "Thread is exiting..";
}


