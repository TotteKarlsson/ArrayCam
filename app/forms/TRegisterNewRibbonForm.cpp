#include <vcl.h>
#pragma hdrstop
#include "TRegisterNewRibbonForm.h"
#include "mtkLogger.h"
#include "TPGDataModule.h"
#include "mtkVCLUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TArrayBotBtn"
#pragma resource "*.dfm"
TRegisterNewRibbonForm *RegisterNewRibbonForm;

using namespace mtk;
using std::vector;
//---------------------------------------------------------------------------
__fastcall TRegisterNewRibbonForm::TRegisterNewRibbonForm(TMainForm& mf)
	: TForm(&mf),
    mMainForm(mf),
    mBarCode("")
{}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
    	Close();
    }
}

void TRegisterNewRibbonForm::setCoverSlipBarcode(const string& barcode)
{
	mBarCode = barcode;
	mCSBarcode->Caption = vclstr(barcode);
}

int TRegisterNewRibbonForm::extractCoverSlipID(const string& bc)
{
	string temp(bc);
    //Make sure first char is a 'C'
    if(!bc.size() || bc[0] != 'C')
    {
    	Log(lError) << bc << " is not a valid barcode!";
        return -1;
    }

	temp.erase(0,1);
    int id = toInt(temp);
    Log(lDebug3) << "Extracted id "<<id<<" from "<<bc;
    return id;
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::mOkCancelBtnClick(TObject *Sender)
{
	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);
	if(b == mCancelBtn)
    {
		pgDM->ribbonsCDS->Cancel();
	}
    else if (b == mRegisterBtn)
    {
    	//Update coverslip status to post sectioning
		if(!updateCoverSlipStatus())
        {
        	Log(lError) << "There was a problem updating status for current coverslip (" <<mBarCode<<")";
        }

        //Post data
		pgDM->ribbonsCDS->Post();
    	if(mRibbonNoteMemo->Lines->Count)
        {
        	Log(lDebug) << "Creating ribbon note";
            createNoteForCurrentRibbon();
        }
    }
}

bool TRegisterNewRibbonForm::updateCoverSlipStatus()
{
    TSQLQuery* tq = new TSQLQuery(NULL);
    tq->SQLConnection = pgDM->SQLConnection1;
    tq->SQLConnection->AutoClone = false;
    stringstream q;
    q <<"UPDATE coverslips SET status = 6 WHERE id = "<<extractCoverSlipID(mBarCode);
    tq->SQL->Add(q.str().c_str());
    int rAffected = tq->ExecSQL();
    tq->Close();

	Log(lInfo) <<"Updated status for " <<rAffected<<" coverslip";
    tq->SQL->Clear();
    return true;
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Log(lInfo) << "Closed Register new ribbon form. Modal result is: " <<this->ModalResult;
}

//---------------------------------------------------------------------------
bool TRegisterNewRibbonForm::createNoteForCurrentRibbon()
{
    int uID = mMainForm.getCurrentUserID();
    String rID = pgDM->ribbonsCDS->FieldByName("id")->Value;

    //First insert a new note
    //Then use last insert id for this note to populate the ribbon_note table
    //Finally, select the note
    TSQLQuery* tq = new TSQLQuery(NULL);
    tq->SQLConnection = pgDM->SQLConnection1;
    tq->SQLConnection->AutoClone = false;
    stringstream q;
    vector<string> lines(stdlines(mRibbonNoteMemo->Lines));

    StringList m(lines);
    q <<"INSERT INTO notes (created_by, note) VALUES ("<<uID<<", '"<<m.asString('\n')<<"')";
    tq->SQL->Add(q.str().c_str());

    tq->ExecSQL();
    tq->Close();
    tq->SQL->Clear();
    q.str("");

    q << "SELECT LAST_INSERT_ID() AS li";
    tq->SQL->Add(q.str().c_str());
    tq->Open();
    int noteID = tq->FieldByName("li")->AsInteger;
    tq->Close();
    tq->SQL->Clear();

    q.str("");
    q << "INSERT INTO ribbon_note (ribbon_id, note_id) VALUES ('"<<stdstr(rID)<<"', "<<noteID<<")";
    tq->SQL->Add(q.str().c_str());
    tq->ExecSQL();
    tq->Close();
    return true;
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::miscBtnClick(TObject *Sender)
{
	TArrayBotButton* b = dynamic_cast<TArrayBotButton*>(Sender);
    if(b == mIncrementSectionBtn)
    {
    	int nr = pgDM->ribbonsCDS->FieldByName("nr_of_sections")->Value;
        pgDM->ribbonsCDS->Edit();
        pgDM->ribbonsCDS->FieldByName("nr_of_sections")->Value = (nr + 1);
    }
    else if(b == mDecrementSectionBtn)
    {
    	int nr = pgDM->ribbonsCDS->FieldByName("nr_of_sections")->Value;
        pgDM->ribbonsCDS->Edit();
        pgDM->ribbonsCDS->FieldByName("nr_of_sections")->Value = (nr - 1);
    }
    else if(b == mIncrementCuttingOrderBtn)
    {
    	int nr = pgDM->ribbonsCDS->FieldByName("cutting_order")->Value;
        pgDM->ribbonsCDS->Edit();
        pgDM->ribbonsCDS->FieldByName("cutting_order")->Value = (nr + 1);

    }
    else if(b == mDecrementCuttingOrderBtn)
    {
    	int nr = pgDM->ribbonsCDS->FieldByName("cutting_order")->Value;
        pgDM->ribbonsCDS->Edit();
        pgDM->ribbonsCDS->FieldByName("cutting_order")->Value = (nr - 1);
    }
}

void __fastcall TRegisterNewRibbonForm::FormCreate(TObject *Sender)
{
	//Make any necessary queries..
}

void __fastcall TRegisterNewRibbonForm::FormShow(TObject *Sender)
{
    pgDM->ribbonsCDS->First();
    pgDM->ribbonsCDS->Insert();
    pgDM->ribbonsCDS->Edit();
    pgDM->ribbonsCDS->FieldByName("created_by")->Value 	= pgDM->usersCDS->FieldByName("id")->Value;
    pgDM->ribbonsCDS->FieldByName("id")->Value 			= getUUID().c_str();
    pgDM->ribbonsCDS->FieldByName("block_id")->Value 		= pgDM->blocksCDS->FieldByName("id")->Value;
    pgDM->ribbonsCDS->FieldByName("nr_of_sections")->Value = mMainForm.mUC7.getLastNumberOfSections();
    pgDM->ribbonsCDS->FieldByName("cutting_order")->Value  = mMainForm.mRibbonOrderCountLabel->Caption.ToInt();
    pgDM->ribbonsCDS->FieldByName("coverslip_id")->Value   = extractCoverSlipID(mBarCode);
}



