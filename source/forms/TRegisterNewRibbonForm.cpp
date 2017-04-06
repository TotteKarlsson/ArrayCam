#include <vcl.h>
#pragma hdrstop
#include "TRegisterNewRibbonForm.h"
#include "mtkLogger.h"
#include "TATDBDataModule.h"
using namespace mtk;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"
TRegisterNewRibbonForm *RegisterNewRibbonForm;

//---------------------------------------------------------------------------
__fastcall TRegisterNewRibbonForm::TRegisterNewRibbonForm(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
    	Close();
    }
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Log(lInfo) << "Closed Register new ribbon form..";
}


//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::mCloseBtnClick(TObject *Sender)
{
	Close();
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::FormShow(TObject *Sender)
{
	//Make any necessary queries..


}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::mProcessIDCBChange(TObject *Sender)
{
	//Select blocks for the currently selected Process ID
}


//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::mRibbonNavigatorClick(TObject *Sender, TNavigateBtn Button)
{
	//
}


