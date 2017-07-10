#include <vcl.h>
#pragma hdrstop
#include "TActionsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TActionsForm *ActionsForm;

//---------------------------------------------------------------------------
__fastcall TActionsForm::TActionsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
