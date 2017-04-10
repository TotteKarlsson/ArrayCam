#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "Poco/Data/RecordSet.h"
#include "TSettingsForm.h"
using namespace at;

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterServerConnect(System::TObject* Sender)
{
	Log(lInfo) << "Succesfully connected to DB Server";

	atdbDM->afterConnect();
    csDM->afterConnect();
	TATDBConnectionFrame1->afterConnect();
    mUsersCB->KeyValue = mDBUserID.getValue();
    enableDisableGroupBox(BlocksGB, true);
    enableDisableGroupBox(UsersGB, true);
    mRegisterRibbonBtn->Enabled = true;
}

void __fastcall	TMainForm::afterServerDisconnect(System::TObject* Sender)
{
	Log(lInfo) << "Disconnected from the DB Server";
	TATDBConnectionFrame1->afterDisconnect();
    mUsersCB->Enabled = false;
    BlocksGB->Enabled = false;
    enableDisableGroupBox(BlocksGB, false);
    enableDisableGroupBox(UsersGB, false);
    mRegisterRibbonBtn->Enabled = false;
}

int TMainForm::getCurrentUserID()
{
	return  mUsersCB->KeyValue;
}

string TMainForm::getCurrentUserName()
{
	return  stdstr(atdbDM->usersCDS->FieldByName("user_name")->Value);
}
