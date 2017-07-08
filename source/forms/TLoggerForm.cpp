#include <vcl.h>
#pragma hdrstop
#include "TLoggerForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TLoggerForm *LoggerForm;

//---------------------------------------------------------------------------
__fastcall TLoggerForm::TLoggerForm(const string& regRoot, TComponent* Owner)
	: TRegistryForm(regRoot, "LoggerForm", Owner)
{
}

__fastcall TLoggerForm::~TLoggerForm()
{
}

void __fastcall TLoggerForm::FormShow(TObject *Sender)
{
	ReadRegistry();
}

//---------------------------------------------------------------------------
void __fastcall TLoggerForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    TRegistryForm::FormClose(Sender, Action);
}

