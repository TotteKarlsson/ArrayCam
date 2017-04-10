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
#include "TMainForm.h"
#include <Vcl.Mask.hpp>
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
	TSplitter *Splitter1;
	TLabel *mCSBarcode;
	TLabel *Label1;
	TGroupBox *GroupBox3;
	TLabel *Label2;
	TGroupBox *GroupBox5;
	TDBGrid *mRibbonNotesGrid;
	TDBMemo *mRibbonNoteMemo;
	TDBNavigator *mRibbonNoteNavigator;
	TDBNavigator *mRibbonNotesNavigator;
	TDBText *DBText1;
	TDBText *DBText2;
	TLabel *Label3;
	TArrayBotButton *mDecrementCuttingOrderBtn;
	TArrayBotButton *mIncrementSectionBtn;
	TLabel *Label4;
	TArrayBotButton *mDecrementSectionBtn;
	TArrayBotButton *mIncrementCuttingOrderBtn;
	TLabel *Label5;
	TDBText *DBText3;
	TLabel *Label6;
	TDBText *DBText4;
	TLabel *Label7;
	TDBText *DBText5;
	TDBText *DBText6;
	TDBText *DBText7;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mCloseBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall mProcessIDCBChange(TObject *Sender);
	void __fastcall mRibbonNavigatorClick(TObject *Sender, TNavigateBtn Button);
	void __fastcall mRibbonNotesNavigatorClick(TObject *Sender, TNavigateBtn Button);
	void __fastcall miscBtnClick(TObject *Sender);


    private:
		string						mBarcode;
        TMainForm&					mMainForm;
    public:
                        __fastcall	TRegisterNewRibbonForm(TMainForm& mf);
		void						setCoverSlipBarcode(const string& barcode);
};

extern PACKAGE TRegisterNewRibbonForm *RegisterNewRibbonForm;
#endif
