#ifndef TLoggerFormH
#define TLoggerFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include "TRegistryForm.h"

//---------------------------------------------------------------------------
class PACKAGE TLoggerForm : public TRegistryForm
{
    __published:	// IDE-managed Components
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TToolBar *ToolBar1;
        TBitBtn *mClearLogMemoBtn;
        TComboBox *LogLevelCB;
        TMemo *infoMemo;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    private:

    public:
        __fastcall TLoggerForm(const string& regRoot, TComponent* Owner);
        __fastcall ~TLoggerForm();
};

extern PACKAGE TLoggerForm *LoggerForm;

#endif
