#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "Poco/Data/RecordSet.h"
#include "TSettingsForm.h"
#include "mtkLogger.h"
#include "TPGDataModule.h"
#include "TPGCoverSlipDataModule.h"
//---------------------------------------------------------------------------
using namespace at;
using namespace mtk;

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterDBServerConnect(System::TObject* Sender)
{
	Log(lInfo) << "Succesfully connected to DB Server";

	pgDM->afterConnect();
    csPGDM->afterConnect();

    TPGConnectionFrame1->afterConnect();
    RegisterRibbonBtn->Enabled = true;

	//Setup UI
    mUsersCB->KeyValue  	= mDBUserID.getValue();
//    SpecimenIDCB->KeyValue 	= mSpecimenID.getValue();
//    SliceIDCB->KeyValue 	= mSliceID.getValue();
    BlockIDCB->KeyValue 	= mBlockID.getValue();

    BlockIDCB->KeyValue = mBlockID.getValue();
    enableDisableGroupBox(BlockSelectionGB, true);
    enableDisableGroupBox(RibbonRegistrationGB, true);
    enableDisableGroupBox(BlockInfoGB, true);
    enableDisableGroupBox(BlockNotesGB, true);

    enableDisableGroupBox(RibbonsDataGB, true);

  	TStatusPanel* p = mSBManager.getPanel(sbpDBConnection);
    p->Text = "ATDB: Connected";
}

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterDBServerDisconnect(System::TObject* Sender)
{
	Log(lInfo) << "Disconnected from the DB Server";
	pgDM->afterDisConnect();

	TPGConnectionFrame1->afterDisconnect();
	RegisterRibbonBtn->Enabled = false;

    enableDisableGroupBox(RibbonRegistrationGB, false);
    enableDisableGroupBox(BlockSelectionGB, false);
    enableDisableGroupBox(RibbonsDataGB, false);
    enableDisableGroupBox(BlockInfoGB, 	false);
    enableDisableGroupBox(BlockNotesGB, true);

  	TStatusPanel* p = mSBManager.getPanel(sbpDBConnection);
    p->Text = "ATDB: Not Connected";
}

//---------------------------------------------------------------------------
int TMainForm::getCurrentUserID()
{
	return  mUsersCB->KeyValue;
}
