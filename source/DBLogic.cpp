#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "Poco/Data/RecordSet.h"
#include "TSettingsForm.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
using namespace at;
using namespace mtk;

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterDBServerConnect(System::TObject* Sender)
{
	Log(lInfo) << "Succesfully connected to DB Server";

	atdbDM->afterConnect();
    csDM->afterConnect();
	TATDBConnectionFrame1->afterConnect();

	//Setup UI
    mUsersCB->KeyValue = mDBUserID.getValue();
    mBlockProcessIDCB->KeyValue = mProcessID.getValue();
    BlockIDCB->KeyValue = mBlockID.getValue();
    enableDisableGroupBox(BlockSelectionGB, true);
    enableDisableGroupBox(BlocksGB, true);
    enableDisableGroupBox(RibbonsDataGB, true);

    RegisterRibbonBtn->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterDBServerDisconnect(System::TObject* Sender)
{
	Log(lInfo) << "Disconnected from the DB Server";
	TATDBConnectionFrame1->afterDisconnect();

    enableDisableGroupBox(BlocksGB, false);
    enableDisableGroupBox(BlockSelectionGB, false);
    enableDisableGroupBox(RibbonsDataGB, false);
    RegisterRibbonBtn->Enabled = false;
}

//---------------------------------------------------------------------------
int TMainForm::getCurrentUserID()
{
	return  mUsersCB->KeyValue;
}
