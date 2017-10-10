#ifndef TMainFormH
#define TMainFormH
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
#include <Vcl.FileCtrl.hpp>
#include "TSTDStringEdit.h"
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.DBCtrls.hpp>
#include "TATDBConnectionFrame.h"
#include "TATDBDataModule.h"
#include <list>
using mtk::IniFile;
using mtk::LogLevel;
using std::list;
class TFFMPEGOutputFrame;

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
    __published:	// IDE-managed Components
	TMemo *infoMemo;
	TTimer *ShutDownTimer;
	TGroupBox *GroupBox1;
	TSTDStringEdit *MovieFolder;
	TPanel *TopPanel;
	TPanel *Panel1;
	TButton *Button1;
	TActionList *ActionList1;
	TBrowseForFolder *BrowseForFolder1;
	TATDBConnectionFrame *TATDBConnectionFrame1;
	TGroupBox *Panel2;
	TDBLookupListBox *DBLookupListBox1;
	TDBText *DBText1;
	void __fastcall ShutDownTimerTimer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall BrowseForFolder1Accept(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

    private:	// User declarations
        LogFileReader                            mLogFileReader;
        LogLevel							     mLogLevel;
        void __fastcall                          logMsg();
        IniFile						             mIniFile;

	public:		// User declarations
					__fastcall 					TMainForm(TComponent* Owner);
		void       	__fastcall					afterDBServerConnect(System::TObject* Sender);
		void       	__fastcall					afterDBServerDisconnect(System::TObject* Sender);

};

extern PACKAGE TMainForm *MainForm;
#endif
