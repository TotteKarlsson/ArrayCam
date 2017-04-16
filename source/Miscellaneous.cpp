#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "TSettingsForm.h"
#include "mtkVCLUtils.h"
#include "mtkApplicationInfo.h"
#include "mtkVersion.h"
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
//	mFitToScreenButtonClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mToggleLogPanelClick(TObject *Sender)
{
//	mBottomPanel->Visible = !mBottomPanel->Visible;
//	mToggleLogPanelBtn->Caption =  (mBottomPanel->Visible) ? "Hide Bottom Panel" : "Show Bottom Panel";
	mFitToScreenButtonClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mShowBottomPanelBtnClick(TObject *Sender)
{
//	mBottomPanel->Visible = true;
//    mShowBottomPanelBtn->Visible = false;
//    Splitter2->Top = mBottomPanel->Top - 1;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mCloseBottomPanelBtnClick(TObject *Sender)
{
//	mBottomPanel->Visible = false;
//    mShowBottomPanelBtn->Visible = true;
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
	return mComportCB->ItemIndex + 1;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mSettingsBtnClick(TObject *Sender)
{
	//Open settings form
    if(!mSettingsForm)
    {
		mSettingsForm = new TSettingsForm(*this);
    }

//	this->Visible = true;
    mSettingsForm->Show();
}
