#ifndef TMainFormH
#define TMainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TArrayBotBtn.h"
#include "TFFMPEGFrame.h"
#include "TSTDStringLabeledEdit.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include "mtkLogFileReader.h"
#include <Vcl.ExtCtrls.hpp>
#include "mtkLogLevel.h"
#include "mtkIniFile.h"
#include "atVideoCompressorThread.h"
#include "TIntLabel.h"
using mtk::IniFile;
using mtk::LogLevel;

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
    __published:	// IDE-managed Components
        TSTDStringLabeledEdit *InputFileE;
        TFFMPEGFrame *TFFMPEGFrame1;
        TArrayBotButton *Compress;
	TMemo *infoMemo;
        TProgressBar *ProgressBar1;
	TTimer *ShutDownTimer;
	TIntLabel *IntLabel1;
	void __fastcall ShutDownTimerTimer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall CompressClick(TObject *Sender);

    private:	// User declarations
        LogFileReader                       mLogFileReader;
        LogLevel							mLogLevel;
        void __fastcall                     logMsg();
        IniFile						        mIniFile;
		VideoCompressorThread				mVCThread;

   	    void 				                onEnter(int i, int j);
	    void 				                onProgress(int i, int j);
	    void 				                onExit(int i, int j);




public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};

extern PACKAGE TMainForm *MainForm;
#endif
