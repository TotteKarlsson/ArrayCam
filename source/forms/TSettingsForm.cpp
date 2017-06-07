#include <vcl.h>
#pragma hdrstop
#include "TSettingsForm.h"
#include <sstream>
#include "mtkVCLUtils.h"
#include "mtkMathUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma link "TPropertyCheckBox"
#pragma link "TSTDStringLabeledEdit"
#pragma link "mtkFloatLabel"
#pragma link "TIntLabel"
#pragma link "TATDBConnectionFrame"
#pragma resource "*.dfm"
TSettingsForm *SettingsForm;

using namespace std;
using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TSettingsForm::TSettingsForm(TMainForm& mf)
	: TForm(&mf),
    mMainForm(mf)
{
	//Retriew conenction credentials from inifile
	mIsStartingUp = true;

    //Bind properties
    mAutoExposureCB->setReference(mMainForm.mAutoExposure.getReference());
	mAutoExposureCB->Update();

    mAutoBlackLevelCB->setReference(mMainForm.mAutoBlackLevel.getReference());
    mAutoBlackLevelCB->Update();

    mAutoGainCB->setReference(mMainForm.mAutoGain.getReference());
	mAutoGainCB->Update();

    mAutoWhiteBalanceCB->setReference(mMainForm.mAutoWhiteBalance.getReference());
	mAutoWhiteBalanceCB->Update();


	mSoftwareGammaLbl->SetReference(mMainForm.mSoftwareGamma.getReference());
	mGammaSB->Position = 100.0 *mMainForm.mSoftwareGamma;

    mVerticalMirrorCB->setReference(mMainForm.mVerticalMirror.getReference());
	mVerticalMirrorCB->Update();

    mHorizontalMirrorCB->setReference(mMainForm.mHorizontalMirror.getReference());
	mHorizontalMirrorCB->Update();

    mPairLEDsCB->setReference(mMainForm.mPairLEDs.getReference());
    mPairLEDsCB->Update();

    mPhotoOutputBaseFolder->setReference(mMainForm.mSnapShotFolder.getReference());
    mMoviesFolderE->setReference(mMainForm.mMoviesFolder.getReference());


    if(mMainForm.mAutoExposure == false)
    {
	    enableManualExposureTimeSetting();
    }
    else
    {	//Initialize trackbar to current autoexposure time

        HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
        double dblMin, dblMax, dblInc, dCurrent;
        int nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MIN, (void*)&dblMin, sizeof(dblMin));
            nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX, (void*)&dblMax, sizeof(dblMax));
            nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_INC, (void*)&dblInc, sizeof(dblInc));

        nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE, &dCurrent, sizeof(dCurrent));
        mExposureTimeTB->Min = round(dblMin * 1000);
        mExposureTimeTB->Max = round(dblMax * 1000);
        mExposureTimeTB->Position = round(dCurrent * 1000);
        mExposureTimeTB->Enabled = false;
    }

	mIsStartingUp = false;
}

////---------------------------------------------------------------------------
//void __fastcall TSettingsForm::mASStartBtnClick(TObject *Sender)
//{
//	if(mASStartBtn->Caption == "Start")
//    {
//    	mMainForm.mLightsArduinoClient.connect(mArduinoServerPortE->getValue());
//        mASStartBtn->Caption == "Connecting";
//        mMainForm.mCheckArduinoServerConnection = true;
//    }
//    else
//    {
//		//User closed connection manually - don't restore automatically
//		mMainForm.mCheckArduinoServerConnection = false;
//    	mMainForm.mLightsArduinoClient.disConnect();
//    }
//}

//--------------------------------------------------------------------------
void __fastcall TSettingsForm::mUIUpdateTimerTimer(TObject *Sender)
{
//   	mASStartBtn->Caption 			= mMainForm.mLightsArduinoClient.isConnected()	? "Stop" : "Start";
//	mArduinoServerPortE->Enabled 	= !mMainForm.mLightsArduinoClient.isConnected();
//   	enableDisableGroupBox(LightIntensitiesGB, !mArduinoServerPortE->Enabled);

    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
    double dblMin, dblMax, dblInc, dCurrent;
    int nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MIN, (void*)&dblMin, sizeof(dblMin));
        nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX, (void*)&dblMax, sizeof(dblMax));
        nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_INC, (void*)&dblInc, sizeof(dblInc));

    nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE, &dCurrent, sizeof(dCurrent));
    mExposureTimeTB->Min = round(dblMin * 1000);
    mExposureTimeTB->Max = round(dblMax * 1000);

    if(mAutoExposureCB->Checked)
    {
	    mExposureTimeTB->Position = round(dCurrent * 1000);
    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mVerticalMirrorCBClick(TObject *Sender)
{
    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
	if(mVerticalMirrorCB->Checked)
    {
		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_LEFTRIGHT, 1, 0);
    }
    else
    {
		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_LEFTRIGHT, 0, 0);
    }
	mVerticalMirrorCB->OnClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mHorizontalMirrorCBClick(TObject *Sender)
{
    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
	if(mHorizontalMirrorCB->Checked)
    {
		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_UPDOWN, 1, 0);
    }
    else
    {
		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_UPDOWN, 0, 0);
    }
	mHorizontalMirrorCB->OnClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::AutoParaCBClick(TObject *Sender)
{
	TCheckBox* cb = dynamic_cast<TCheckBox*>(Sender);
	if(mIsStartingUp || cb == NULL)
    {
    	return;
    }

    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();

    double dEnable= cb->Checked ? 1 : 0;
	int ret;

    if(cb == mAutoGainCB)
    {
	    mAutoGainCB->OnClick(Sender);
    	mGainTB->Enabled = !cb->Checked;

	    //Enable /Disable auto gain control:
	    ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_GAIN, &dEnable, 0);
    }
    else if (cb == mAutoExposureCB)
    {
	    mAutoExposureCB->OnClick(Sender);

	    //Enable auto shutter:
	    ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_SHUTTER, &dEnable, 0);

        if(cb->Checked)
        {
        	mExposureTimeTB->Enabled = false;
        }
        else
        {
        	//INT is_Exposure (HIDS hCam, UINT nCommand, void* pParam, UINT cbSizeOfParam)
            enableManualExposureTimeSetting();
        }
    }
    else if (cb == mAutoBlackLevelCB)
    {
	    mAutoBlackLevelCB->OnClick(Sender);
        if(cb->Checked)
        {

        	mBlackLevelTB->Enabled = false;
			int nMode = IS_AUTO_BLACKLEVEL_ON;
			ret = is_Blacklevel(hCam, IS_BLACKLEVEL_CMD_SET_MODE, (void*)&nMode , sizeof(nMode ));
        }
        else
        {
            enableManualBlackLevelSetting();
        }
    }
    else if (cb == mAutoWhiteBalanceCB)
    {
	    mAutoWhiteBalanceCB->OnClick(Sender);
  	    ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_WHITEBALANCE, &dEnable, 0);
    }
}

void  __fastcall TSettingsForm::enableManualExposureTimeSetting()
{
    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
    double dblMin, dblMax, dblInc, dCurrent;
    int nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MIN, (void*)&dblMin, sizeof(dblMin));
    	nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX, (void*)&dblMax, sizeof(dblMax));
    	nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_INC, (void*)&dblInc, sizeof(dblInc));

    nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_GET_EXPOSURE, &dCurrent, sizeof(dCurrent));
    mExposureTimeTB->Min = round(dblMin * 1000);
    mExposureTimeTB->Max = round(dblMax * 1000);
    mExposureTimeTB->Position = round(dCurrent * 1000);
   	mExposureTimeTB->Enabled = true;
    mExposureTimeLbl->SetValue(dCurrent);
}

void  __fastcall TSettingsForm::enableManualBlackLevelSetting()
{
    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();

    // Get offset range
    IS_RANGE_S32 nRange;
    int ret = is_Blacklevel(hCam, IS_BLACKLEVEL_CMD_GET_OFFSET_RANGE, (void*)&nRange, sizeof(nRange));
    INT nOffsetMin = nRange.s32Min;
    INT nOffsetMax = nRange.s32Max;

    mBlackLevelTB->Min = nRange.s32Min;
    mBlackLevelTB->Max = nRange.s32Max;

   	INT nOffset = 0;

	// Get default blacklevel offset
	mBlackLevelTB->Enabled = true;

    int nMode = IS_AUTO_BLACKLEVEL_OFF;
    ret = is_Blacklevel(hCam, IS_BLACKLEVEL_CMD_SET_MODE, (void*)&nMode , sizeof(nMode ));
}

void __fastcall TSettingsForm::mCloseButtonClick(TObject *Sender)
{
//	this->Visible = false;
	Close();
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	mUIUpdateTimer->Enabled = false;
}

void __fastcall TSettingsForm::mPairLEDsCBClick(TObject *Sender)
{
	mPairLEDsCB->OnClick(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
    	Close();
    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::BrowseForFolder(TObject *Sender)
{
	//Open Browse for folder dialog

	TButton* b = dynamic_cast<TButton*>(Sender);
    if(b == mBrowseForImagesFolderBtn)
    {
        string f = browseForFolder(mMainForm.mSnapShotFolder);
        if(!f.size())
        {
            return;
        }

    	mPhotoOutputBaseFolder->setValue(f);
    }
    else if(b == mBrowseForMoviesFolderBtn)
    {
        string f = browseForFolder(mMainForm.mSnapShotFolder);
        if(!f.size())
        {
            return;
        }

    	mMoviesFolderE->setValue(f);
    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mGammaSBChange(TObject *Sender)
{
	int pos = mGammaSB->Position;
    mSoftwareGammaLbl->SetValue((double) pos/100.0);

    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
	int ret = is_SetGamma (hCam, pos);

    switch(ret)
    {
	    case IS_GET_GAMMA:
        	Log(lInfo) << "Gamma setting succeded";
        break;

		case IS_CANT_COMMUNICATE_WITH_DRIVER:
        	Log(lError) << "Communication with the driver failed because no driver has been loaded.";
		break;

        case IS_CANT_OPEN_DEVICE:
        	Log(lError) << "An attempt to initialize or select the camera failed (no camera connected or initialization error).";
    	break;

		case IS_INVALID_CAMERA_HANDLE:
        	Log(lError) << "Invalid camera handle";
        break;

		case IS_INVALID_PARAMETER:
        	Log(lError) << "One of the submitted parameters is outside the \
valid range or is not supported for this sensor or \
is not available in this mode.";
		break;

        case IS_IO_REQUEST_FAILED:
        	Log(lError) << "An IO request from the uc480 driver failed. \
Possibly the versions of the uc480.dll (API) and \
the driver file (uc480_usb.sys) do not match. ";
		break;

        case IS_NO_SUCCESS:
        	Log(lError) << "General error message";
        break;

        case IS_NOT_SUPPORTED:
        	Log(lError) <<"The camera model used here does not support this function or setting.";
		break;

		case IS_SUCCESS:
        	Log(lInfo) << "Function executed successfully";
        break;

        default:
        	Log(lInfo) << "Unknown return value";
        break;
    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::SettingsChange(TObject *Sender)
{
	TTrackBar* tb = dynamic_cast<TTrackBar*>(Sender);
    if(!tb)
    {
    	return;
    }

   	int pos = tb->Position;
    if(tb == mFrontLEDTB)
    {
    	if(mMainForm.mPairLEDs.getValue() == true)
        {
        	if(mBackLEDTB->Position != mFrontLEDTB->Position)
            {
				mBackLEDTB->Position = mFrontLEDTB->Position;
            }
        }

        if(tb->Tag != 1) //Means we are updating UI from thread
        {
        	stringstream s;
	        s<<"SET_FRONT_LED_INTENSITY="<<pos;
	        mMainForm.mLightsArduinoClient.request(s.str());
        }
        mFrontLEDLbl->Caption = "Front LED (" + IntToStr(pos) + ")";
    }
    else if(tb == mBackLEDTB)
    {
        if(tb->Tag != 1) //Means we are updating UI
        {
	        stringstream s;
	        s<<"SET_BACK_LED_INTENSITY="<<pos;
    	    mMainForm.mLightsArduinoClient.request(s.str());
        }
        mBackLEDLbl->Caption = "Back LED (" + IntToStr(pos) + ")";

    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormHide(TObject *Sender)
{
	mUIUpdateTimer->Enabled = false;
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormShow(TObject *Sender)
{
	mUIUpdateTimer->Enabled = true;
}

void __fastcall TSettingsForm::mGainTBChange(TObject *Sender)
{
	int pos = mGainTB->Position/1;
    mGainLbl->Caption = mtk::toString(pos).c_str();

    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
	int ret = is_SetHardwareGain(hCam, pos, pos, pos ,pos);

    switch(ret)
    {
	    case IS_GET_GAMMA:
        	Log(lInfo) << "Gamma setting succeded";
        break;

		case IS_CANT_COMMUNICATE_WITH_DRIVER:
        	Log(lError) << "Communication with the driver failed because no driver has been loaded.";
		break;

        case IS_CANT_OPEN_DEVICE:
        	Log(lError) << "An attempt to initialize or select the camera failed (no camera connected or initialization error).";
    	break;

		case IS_INVALID_CAMERA_HANDLE:
        	Log(lError) << "Invalid camera handle";
        break;

		case IS_INVALID_PARAMETER:
        	Log(lError) << "One of the submitted parameters is outside the \
valid range or is not supported for this sensor or \
is not available in this mode.";
		break;

        case IS_IO_REQUEST_FAILED:
        	Log(lError) << "An IO request from the uc480 driver failed. \
Possibly the versions of the uc480.dll (API) and \
the driver file (uc480_usb.sys) do not match. ";
		break;

        case IS_NO_SUCCESS:
        	Log(lError) << "General error message";
        break;

        case IS_NOT_SUPPORTED:
        	Log(lError) <<"The camera model used here does not support this function or setting.";
		break;

		case IS_SUCCESS:
        	Log(lInfo) << "Function executed successfully";
        break;

        default:
        	Log(lInfo) << "Unknown return value";
        break;
    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mGainBoostCBClick(TObject *Sender)
{
    HCAM hCam = mMainForm.mCamera1.GetCameraHandle();


	int ret = is_SetGainBoost(hCam, IS_GET_SUPPORTED_GAINBOOST);
    if(ret != IS_SET_GAINBOOST_ON)
    {
    	Log(lError) << "This Camera does not support Hardware Gain Boost";
		mGainBoostCB->Checked = false;
        return;
    }

    //turn on or off gain boost
    if(mGainBoostCB->Checked)
    {
		ret = is_SetGainBoost(hCam, IS_SET_GAINBOOST_ON);
    }
    else
    {
		ret = is_SetGainBoost(hCam, IS_SET_GAINBOOST_OFF);
    }

    switch(ret)
    {
		case IS_INVALID_CAMERA_HANDLE:
        	Log(lError) << "Invalid camera handle";
        break;

        case IS_NO_SUCCESS:     Log(lError) << "General error message";
        break;

        case IS_NOT_SUPPORTED: 	Log(lError) <<"The camera model used here does not support this function or setting.";
		break;

		case IS_SUCCESS:      	Log(lInfo) << "Function executed successfully";
        break;

        default:                Log(lInfo) << "Unknown return value";
        break;
    }
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mExposureTimeTBChange(TObject *Sender)
{
    double dCurrent = mExposureTimeTB->Position / 1000.0;
	if(mAutoExposureCB->Checked == false)
    {
        HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
        int nRet = is_Exposure(hCam, IS_EXPOSURE_CMD_SET_EXPOSURE, &dCurrent, sizeof(dCurrent));
        mExposureTimeTB->Position = round(dCurrent * 1000);
     }
     mExposureTimeLbl->SetValue(dCurrent);
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mBlackLevelTBChange(TObject *Sender)
{
    int Current = mBlackLevelTB->Position;
	if(mAutoBlackLevelCB->Checked == false)
    {
        HCAM hCam = mMainForm.mCamera1.GetCameraHandle();
		int ret = is_Blacklevel(hCam, IS_BLACKLEVEL_CMD_SET_OFFSET, (void*)&Current, sizeof(Current));
     }
     mBlackLevelLbl->setValue(Current);
}

//---------------------------------------------------------------------------
void __fastcall TSettingsForm::mAutoCheckConnectionCBClick(TObject *Sender)
{
//	mMainForm.mCheckSocketConnectionTimer->Enabled = mAutoCheckConnectionCB->Checked;
}




