#include <vcl.h>
#pragma hdrstop
#include "TRegisterNewRibbonForm.h"
#include "mtkLogger.h"
#include "TATDBDataModule.h"
#include "TCoverSlipDataModule.h"
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
		atdbDM->mRibbonCDS->Cancel();
    }
    else if (b == mRegisterBtn)
    {
		atdbDM->mRibbonCDS->Post();
    	if(mRibbonNoteMemo->Lines->Count)
        {
        	Log(lDebug) << "Creating ribbon note";
            createNoteForCurrentRibbon();
        }

    }

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TRegisterNewRibbonForm::mProcessIDCBChange(TObject *Sender)
{
	//Select blocks for the currently selected Process ID
}

//---------------------------------------------------------------------------
bool TRegisterNewRibbonForm::createNoteForCurrentRibbon()
{
    int uID = mMainForm.getCurrentUserID();
    String rID = atdbDM->mRibbonCDS->FieldByName("id")->Value;

    //First insert a new note
    //Then use last insert id for this note to populate the ribbon_note table
    //Finally, select the note
    TSQLQuery* tq = new TSQLQuery(NULL);
    tq->SQLConnection = atdbDM->SQLConnection1;
    tq->SQLConnection->AutoClone = false;
    stringstream q;


    vector<string> lines(stdlines(mRibbonNoteMemo->Lines));

    StringList m(lines);
    q <<"INSERT INTO notes (created_by, note) VALUES ("<<uID<<", '"<<m.asString('\n')<<"')";
    Log(lInfo) << "Query is: "<<q.str();
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
    Log(lInfo) << "Query is: "<<q.str();
    tq->SQL->Add(q.str().c_str());
    tq->ExecSQL();
    tq->Close();
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
    }
    else if(b == mDecrementSectionBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value = (nr - 1);
    }
    else if(b == mIncrementCuttingOrderBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value = (nr + 1);

    }
    else if(b == mDecrementCuttingOrderBtn)
    {
    	int nr = atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value;
        atdbDM->mRibbonCDS->Edit();
        atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value = (nr - 1);
    }
}

void __fastcall TRegisterNewRibbonForm::FormCreate(TObject *Sender)
{
	//Make any necessary queries..
}

void __fastcall TRegisterNewRibbonForm::FormShow(TObject *Sender)
{
    atdbDM->mRibbonCDS->First();
    atdbDM->mRibbonCDS->Insert();
    atdbDM->mRibbonCDS->Edit();
    atdbDM->mRibbonCDS->FieldByName("created_by")->Value 	= atdbDM->usersCDS->FieldByName("id")->Value;
    atdbDM->mRibbonCDS->FieldByName("id")->Value 			= getUUID().c_str();
    atdbDM->mRibbonCDS->FieldByName("block_id")->Value 		= atdbDM->blocksCDS->FieldByName("id")->Value;
    atdbDM->mRibbonCDS->FieldByName("nr_of_sections")->Value = mMainForm.mUC7.getLastNumberOfSections();
    atdbDM->mRibbonCDS->FieldByName("cutting_order")->Value  = mMainForm.mRibbonOrderCountLabel->Caption.ToInt();
    atdbDM->mRibbonCDS->FieldByName("coverslip_id")->Value   = extractCoverSlipID(mBarCode);
}


