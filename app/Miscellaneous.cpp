#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "TReticlePopupForm.h"
#include "mtkLogger.h"
#include "forms/TAboutForm.h"
#include "forms/TLoggerForm.h"
//---------------------------------------------------------------------------
using namespace mtk;
extern string gApplicationRegistryRoot;
static HWND gOtherAppWindow = NULL;
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
		mCamera1.exitCamera();
    	Close();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenLoggerForm1Click(TObject *Sender)
{
	if(!LoggerForm)
    {
    	LoggerForm = new TLoggerForm(gApplicationRegistryRoot, this);
		mLogLevel.setReference(&(LoggerForm->mLogLevel));
        LoggerForm->Show();
    }
    else
    {
    	LoggerForm->Visible = true;
    }
}

void __fastcall TMainForm::mMainPhotoPanelResize(TObject *Sender)
{
	FitToScreenAExecute(Sender);

	if(mReticleForm.get() && mReticleForm->Visible)
    {
        mReticleForm->mReticleCenterXTB->Min = -mPB->Width/2;
        mReticleForm->mReticleCenterXTB->Max = mPB->Width/2;
        mReticleForm->mReticleCenterYTB->Min = -mPB->Height/2;
        mReticleForm->mReticleCenterYTB->Max = mPB->Height/2;
    }
}

void __fastcall	TMainForm::updateTemperature(double t)
{
	TStatusPanel* p = mSBManager.getPanel(sbpTemperature);
    p->Text = "Temperature: " + FloatToStrF(t, ffNumber, 4, 1);
}

void __fastcall	TMainForm::updateHumidity(double h)
{
	TStatusPanel* p = mSBManager.getPanel(sbpHumidity);
    if(p)
    {
    	p->Text = "Humidity: " + FloatToStrF(h, ffNumber, 4, 1);
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
	FitToScreenAExecute(Sender);
}

void __fastcall TMainForm::mCameraStreamPanelDblClick(TObject *Sender)
{
//	this->BorderStyle = (this->BorderStyle == bsNone) ? bsSingle : bsNone;
}

//---------------------------------------------------------------------------
int	TMainForm::getCOMPortNumber()
{
	return mUC7ComportCB->ItemIndex + 1;
}

void __fastcall TMainForm::About1Click(TObject *Sender)
{
	TAboutForm* f = new TAboutForm(this);
    f->ShowModal();
    delete f;
}

int __stdcall FindOtherWindow(HWND hwnd, LPARAM lParam)
{
	int length = ::GetWindowTextLength(hwnd);
	if(!length)
    {
	    return TRUE;
    }

	vector<TCHAR> buffer(length + 1);
	GetWindowText(hwnd, &buffer[0], length + 1);

    string s(stdstr(buffer));
	if(startsWith("ArrayCam", s))
	{
		// do something with hwnd here
		gOtherAppWindow = hwnd;
        SetFocus(hwnd);

        //Stop enumerating..
		return false;
	}

	return true;
}

