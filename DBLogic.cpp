#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "database/atDBUtils.h"
#include "Poco/Data/RecordSet.h"
#include "TSettingsForm.h"
using namespace at;

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterServerConnect(System::TObject* Sender)
{
	Log(lInfo) << "Succesfully connected to DB Server";

    if(mSettingsForm)
    {
		mSettingsForm->afterServerConnect(Sender);
    }
}

void __fastcall	TMainForm::afterServerDisconnect(System::TObject* Sender)
{
	Log(lInfo) << "Disconnected from the DB Server";
    if(mSettingsForm)
    {
		mSettingsForm->afterServerDisconnect(Sender);
    }

}

