#ifndef TRegisterNewRibbonFormH
#define TRegisterNewRibbonFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TATDBDataModule.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "TArrayBotBtn.h"
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>

//---------------------------------------------------------------------------
class TRegisterNewRibbonForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TPanel *Panel1;
	TArrayBotButton *mCloseBtn;
	TDBGrid *mBlocksForRibbonsGrid;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);

private:	// User declarations
public:		// User declarations
	__fastcall TRegisterNewRibbonForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegisterNewRibbonForm *RegisterNewRibbonForm;
//---------------------------------------------------------------------------
#endif
