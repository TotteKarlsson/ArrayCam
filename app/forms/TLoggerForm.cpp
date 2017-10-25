#include <vcl.h>
#pragma hdrstop
#include "TLoggerForm.h"
#include "mtkUtils.h"
#include "mtkVCLUtils.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TLoggerForm *LoggerForm;
using namespace mtk;

extern string gLogFileName;
extern string gAppName;
extern string gApplicationRegistryRoot;
extern string gLogFileLocation;
extern string gLogFileName;

//---------------------------------------------------------------------------
__fastcall TLoggerForm::TLoggerForm(const string& regRoot, TComponent* Owner)
	:
TRegistryForm(regRoot, "LoggerForm", Owner),
mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppName, gLogFileName), &logMsg)
{
	Log(lInfo) << "Starting logfile reader";
   	mLogFileReader.start(true);
}

__fastcall TLoggerForm::~TLoggerForm()
{}

//---------------------------------------------------------------------------
//This one is called from the reader thread
void __fastcall TLoggerForm::logMsg()
{
	if(infoMemo->Lines->Count > 1000)
    {
	    infoMemo->Clear();
    }

    infoMemo->Lines->Insert(0, (vclstr(mLogFileReader.getData())));
}

void __fastcall TLoggerForm::FormShow(TObject *Sender)
{
   	mLogFileReader.start(true);
    mLogFileReader.assignOnMessageCallBack(&logMsg);
	ReadRegistry();
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Log(lInfo) << "In FormClose";
    TRegistryForm::FormClose(Sender, Action);
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(mLogFileReader.isRunning()
        )
    {
        CanClose = false;
        ShutDownTimer->Enabled = true;
        return;
    }

    CanClose = true;
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::ShutDownTimerTimer(TObject *Sender)
{
    ShutDownTimer->Enabled = false;

	if(mLogFileReader.isRunning())
    {
		mLogFileReader.stop();
        mLogFileReader.assignOnMessageCallBack(NULL);
    }

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::mClearLogMemoBtnClick(TObject *Sender)
{
	infoMemo->Clear();
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::FormCreate(TObject *Sender)
{
    //Setup LogLevel CB
    string lvl = mtk::toString(gLogger.getLogLevel());
    mLogLevel = toLogLevel(lvl);
    //Find item in CB with this loglevel
    int index = LogLevelCB->Items->IndexOf(vclstr(lvl));

    if(index > -1)
    {
		LogLevelCB->ItemIndex = index;
    }
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::LogLevelCBCloseUp(TObject *Sender)
{
	if(LogLevelCB->ItemIndex == -1)
    {
    	return;
    }

    string lvl = stdstr(LogLevelCB->Items->Strings[LogLevelCB->ItemIndex]);
    mLogLevel = toLogLevel(lvl);
    gLogger.setLogLevel(mLogLevel);
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        Close();
    }
}


