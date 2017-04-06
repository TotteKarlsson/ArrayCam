#ifndef TRegisterNewRibbonFormH
#define TRegisterNewRibbonFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "TArrayBotBtn.h"
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
//---------------------------------------------------------------------------
class TRegisterNewRibbonForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TPanel *Panel1;
	TArrayBotButton *mCloseBtn;
	TDBGrid *mBlocksForRibbonsGrid;
	TDBNavigator *mRibbonNavigator;
	TDBGrid *DBGrid1;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TLabel *mCSBarcode;
	TLabel *Label1;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mCloseBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall mProcessIDCBChange(TObject *Sender);
	void __fastcall mRibbonNavigatorClick(TObject *Sender, TNavigateBtn Button);


    private:


    public:
                        __fastcall TRegisterNewRibbonForm(TComponent* Owner);
};

extern PACKAGE TRegisterNewRibbonForm *RegisterNewRibbonForm;
#endif
