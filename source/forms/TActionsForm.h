#ifndef TActionsFormH
#define TActionsFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------


class PACKAGE TActionsForm : public TForm
{
    __published:
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
    private:


    public:
        					__fastcall TActionsForm(TComponent* Owner);
};


extern PACKAGE TActionsForm *ActionsForm;
#endif
