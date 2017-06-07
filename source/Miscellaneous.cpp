#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TSettingsForm.h"
#include "mtkVCLUtils.h"
#include "mtkApplicationInfo.h"
#include "mtkVersion.h"
#include "TReticlePopupForm.h"
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
		mCamera1.exitCamera();
    	Close();
    }
}

void __fastcall TMainForm::mMainPhotoPanelResize(TObject *Sender)
{
	mFitToScreenButtonClick(Sender);
	if(mReticleForm.get() && mReticleForm->Visible)
    {
        mReticleForm->mReticleCenterXTB->Min = -mPB->Width/2;
        mReticleForm->mReticleCenterXTB->Max = mPB->Width/2;
        mReticleForm->mReticleCenterYTB->Min = -mPB->Height/2;
        mReticleForm->mReticleCenterYTB->Max = mPB->Height/2;
    }
}

int TMainForm::extractCoverSlipID(const string& bc)
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
void __fastcall TMainForm::mToggleLogPanelClick(TObject *Sender)
{
	mFitToScreenButtonClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::LogLevelCBChange(TObject *Sender)
{
	if(LogLevelCB->ItemIndex == -1)
    {
    	return;
    }

    string lvl = stdstr(LogLevelCB->Items->Strings[LogLevelCB->ItemIndex]);
    mLogLevel = toLogLevel(lvl);
    gLogger.setLogLevel(mLogLevel);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::populateAbout()
{
	//Populate MEMO
    stringstream ss;
    mtkApplicationInfo appInfo(Application);

    //Current Version Info
    Version version(stdstr(appInfo.mVersion));
    ss <<version.getMajor()<<"."<<version.getMinor()<<"."<<version.getPatch();
    String versionMajorMinorPatch(ss.str().c_str());
    versionLabel->Caption = String("Version: ") + versionMajorMinorPatch;


    if(fileExists("CHANGELOG.txt"))
    {
	    Memo1->Lines->LoadFromFile("CHANGELOG.txt");
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearLogMemo(TObject *Sender)
{
	infoMemo->Clear();
}

void __fastcall TMainForm::mCameraStreamPanelDblClick(TObject *Sender)
{
//	this->BorderStyle = (this->BorderStyle == bsNone) ? bsSingle : bsNone;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mExitBtnClick(TObject *Sender)
{
	Close();
}

//---------------------------------------------------------------------------
int	TMainForm::getCOMPortNumber()
{
	return mUC7ComportCB->ItemIndex + 1;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mSettingsBtnClick(TObject *Sender)
{
	//Open settings form
    if(!mSettingsForm)
    {
		mSettingsForm = new TSettingsForm(*this);
    }

    mSettingsForm->Show();
}
