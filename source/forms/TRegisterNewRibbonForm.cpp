#include <vcl.h>
#pragma hdrstop
#include "TRegisterNewRibbonForm.h"
#include "mtkLogger.h"
#include "TATDBDataModule.h"
#include "mtkVCLUtils.h"


using namespace mtk;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"
TRegisterNewRibbonForm *RegisterNewRibbonForm;

//---------------------------------------------------------------------------
__fastcall TRegisterNewRibbonForm::TRegisterNewRibbonForm(TMainForm& mf)
	: TForm(&mf),
    mMainForm(mf)
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


void TRegisterNewRibbonForm::setCoverSlipBarcode(const string& barcode)
{
	mCSBarcode->Caption = vclstr(barcode);
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
	switch(Button)
    {
    	case TNavigateBtn::nbDelete:        break;
    	case TNavigateBtn::nbInsert:
        {
	        atdbDM->mRibbonCDS->FieldByName("created_by")->Value 	= atdbDM->usersCDS->FieldByName("id")->Value;
	        atdbDM->mRibbonCDS->FieldByName("id")->Value 			= getUUID().c_str();
	        atdbDM->mRibbonCDS->FieldByName("block_id")->Value 		= atdbDM->blocksCDS->FieldByName("id")->Value;
	        atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value = 12;
	        atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value  = 2;


//            atdbDM->mRibbonCDS->Post();

//			atdbDM->mRibbonCDS->First();
        }
        break;
        case TNavigateBtn::nbPost:        break;
        case TNavigateBtn::nbRefresh:
        	Log(lInfo) << "Refreshed Ribbons Dataset";
 		break;
    }
}


//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::mRibbonNotesNavigatorClick(TObject *Sender,
          TNavigateBtn Button)
{
	switch(Button)
    {
    	case TNavigateBtn::nbInsert:
        {
            int uID = mMainForm.getCurrentUserID();
            String rID = atdbDM->mRibbonCDSid->Value;
            string note("Ribbon Note..");

            try
            {
//                mServerDBSession.addNoteForRibbon(stdstr(rID), uID, note);
            }
            catch(...)
            {
//                handleMySQLException();
            }

            atdbDM->ribbonNotesCDS->Refresh();
            atdbDM->ribbonNotesCDS->Last();
        }
        break;

    	case TNavigateBtn::nbDelete:        break;
    }
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::miscBtnClick(TObject *Sender)
{
	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);
    if(b == mIncrementSectionBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value = (nr + 1);
//        atdbDM->mRibbonCDS->Post();
    }
    else if(b == mDecrementSectionBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value = (nr - 1);
//        atdbDM->mRibbonCDS->Post();
    }
    else if(b == mIncrementCuttingOrderBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value = (nr + 1);
//        atdbDM->mRibbonCDS->Post();

    }
    else if(b == mDecrementCuttingOrderBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value = (nr - 1);
//        atdbDM->mRibbonCDS->Post();
    }

}


