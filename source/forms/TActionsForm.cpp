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
void __fastcall TActionsForm::FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	int sc_DragMove = 0xF012;
    ReleaseCapture();
    Perform( WM_SYSCOMMAND, sc_DragMove, 0 );
}


