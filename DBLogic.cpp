#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "database/atDBUtils.h"
#include "Poco/Data/RecordSet.h"
using namespace at;

//---------------------------------------------------------------------------
void __fastcall	TMainForm::afterServerConnect(System::TObject* Sender)
{
}

void __fastcall	TMainForm::afterServerDisconnect(System::TObject* Sender)
{
}

