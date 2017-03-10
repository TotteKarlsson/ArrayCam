#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkLogger.h"
#include "mtkUtils.h"
#include "mtkWin32Utils.h"
#include "camera/uc480_tools.h"
#include "vcl/atVCLUtils.h"
#include "database/atDBUtils.h"
using namespace mtk;
using namespace ab;

//---------------------------------------------------------------------------
void __fastcall TMainForm::mCameraStartLiveBtnClick(TObject *Sender)
{
    Log(lDebug) << "Init camera..";

    //Live
    if(!mCamera1.IsInit())
    {
    	mServiceCamera1.openCamera();
    }

//    if(!mCamera2.IsInit())
//    {
//    	mServiceCamera2.openCamera();
//    }
}


//Called from a thread
void __fastcall	TMainForm::onCameraOpen(System::TObject* Sender)
{
	Log(lInfo) << "A Camera was open..";

	Cuc480* camera = (Cuc480*) Sender;

    if(!camera)
    {
    	Log(lError) << "Null camerapointer in onCameraOpen";
    }

   if(camera == &mCamera1 && mCamera1.IsInit())
    {
        int x, y, ret;
        mCamera1.GetMaxImageSize(&x,&y);
        Log(lInfo) << "Max image size (x,y): ("<<x<<", "<<y<<")";
        mCamera1.CaptureVideo( IS_WAIT );

        HCAM hCam = mCamera1.GetCameraHandle();

		//Setup camera using values from INI file

        //Enable/Disable auto gain control:
        double dEnable = mAutoGain.getValue() ? 1 : 0;
        ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_GAIN, &dEnable, 0);

		//Auto exposure
		dEnable = mAutoExposure.getValue() ? 1 : 0;

        //Enable/Disable auto exposure
        ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_SHUTTER, &dEnable, 0);

		//Auto Black Level
		dEnable = mAutoBlackLevel.getValue() ? 1 : 0;

        //Enable/Disable auto black Level
        int nMode = dEnable > 0 ? IS_AUTO_BLACKLEVEL_ON : IS_AUTO_BLACKLEVEL_OFF;
        ret = is_Blacklevel(hCam, IS_BLACKLEVEL_CMD_SET_MODE, (void*)&nMode , sizeof(nMode ));

		//Auto Black Level
		dEnable = mAutoWhiteBalance.getValue() ? 1 : 0;

        //Enable/Disable auto black Level
        ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_WHITEBALANCE, &dEnable, 0);;

        //Set software gamme
		ret = is_SetGamma (hCam, mSoftwareGamma * 100.0);

        //Mirror stuff
		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_LEFTRIGHT, mVerticalMirror.getValue(), 0);
		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_UPDOWN, 	mHorizontalMirror.getValue(), 0);
//		mStartupTimer->Enabled = true;
    }
//    else if (camera == &mCamera2 && mCamera2.IsInit())
//    {
//        int x, y;
//        mCamera2.GetMaxImageSize(&x,&y);
//        Log(lInfo) << "Max image size (x,y): ("<<x<<", "<<y<<")";
//        mCamera2.CaptureVideo( IS_WAIT );
//
//        HCAM hCam = mCamera2.GetCameraHandle();
//
//		//Setup camera using values from INI file
//
//        //Enable/Disable auto gain control:
//        double dEnable = mAutoGain.getValue() ? 1 : 0;
//        int ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_GAIN, &dEnable, 0);
//
//		dEnable = mAutoExposure.getValue() ? 1 : 0;
//
//        //Enable/Disable auto exposure
//        ret = is_SetAutoParameter (hCam, IS_SET_ENABLE_AUTO_SHUTTER, &dEnable, 0);
//
//        //Set brightness setpoint to 128:
//        double nominal = 128;
//        ret = is_SetAutoParameter (hCam, IS_SET_AUTO_REFERENCE, &nominal, 0);
//
//        //Mirror stuff
//		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_LEFTRIGHT, mVerticalMirror.getValue(), 0);
//		is_SetRopEffect (hCam, IS_SET_ROP_MIRROR_UPDOWN, 	mHorizontalMirror.getValue(), 0);
//    }
}

void __fastcall	TMainForm::onCameraClose(System::TObject* Sender)
{
	Log(lInfo) << "A Camera was closed..";
}


LRESULT TMainForm::OnUSBCameraMessage(TMessage msg)
{
    switch ( msg.WParam )
    {
        case IS_DEVICE_REMOVED:
        	Beep( 400, 50 );
        break;
        case IS_DEVICE_RECONNECTED:
        	Beep( 400, 50 );
        break;

        case IS_FRAME:
            if(mCamera1.mImageMemory != NULL)
            {
                mCamera1.RenderBitmap(mCamera1.mMemoryId, mCamera1DisplayHandle, mRenderMode);
				FormPaint(NULL);
            }

//            if(mCamera2.mImageMemory != NULL)
//            {
//                mCamera2.RenderBitmap(mCamera2.mMemoryId, mCamera2DisplayHandle, mRenderMode);
//            }
        break;
    }

    return 0;
}

//---------------------------------------------------------------------------
bool TMainForm::openCameras()
{
//	bool result = false;
//	Log(lInfo) << "Opening Camera 1";
//    if(mCamera1.openCamera(this->Handle, 0))
//    {
//    	Log(lInfo) << "Camera 1 was opened";
//        result = true;
//    }
//    else
//    {
//    	Log(lError) << "Failed opening Camera 1";
//        result = false;
//    }

//	Log(lInfo) << "Opening Camera 2";
//    if(mCamera2.openCamera(this->Handle,1))
//    {
//    	Log(lInfo) << "Camera 2 was opened";
//        result = true;
//    }
//    else
//    {
//    	Log(lError) << "Failed opening Camera 2";
//        result = false;
//    }

//	return result;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mOneToTwoBtnClick(TObject *Sender)
{
	mRenderMode = IS_RENDER_DOWNSCALE_1_2;

   	int x, y;
	mCamera1.GetMaxImageSize(&x,&y);
	mCamera1BackPanel->Width = x/2.;
	mCamera1BackPanel->Height = y/2.;
}

void __fastcall TMainForm::mOneToOneBtnClick(TObject *Sender)
{
    mRenderMode = IS_RENDER_FIT_TO_WINDOW;
    mCamera1BackPanel->Invalidate();

   	int x, y;
	mCamera1.GetMaxImageSize(&x,&y);
	mCamera1BackPanel->Width  = x;
	mCamera1BackPanel->Height = y;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mFitToScreenButtonClick(TObject *Sender)
{
	//Check widths and heights
    double wRatio = (double) mMainPanel->Width / mCamera1BackPanel->Width;
    double hRatio = (double) mMainPanel->Height / mCamera1BackPanel->Height;

    if(hRatio < wRatio)
    {
	    mCamera1BackPanel->Height = mMainPanel->Height;
        mCamera1BackPanel->Width *= hRatio;
    }
    else
    {
	    mCamera1BackPanel->Width = mMainPanel->Width;
        mCamera1BackPanel->Height *= wRatio;
    }

    mCamera1BackPanel->Invalidate();
	Log(lInfo) << "W x H = " <<mCamera1BackPanel->Width<<","<<mCamera1BackPanel->Height<<" Ratio = "<<(double) mCamera1BackPanel->Width / mCamera1BackPanel->Height;
}

void __fastcall TMainForm::mSnapShotBtnClick(TObject *Sender)
{
	string fldr =  mSnapShotFolder;

    if(!folderExists(fldr))
    {
    	Log(lInfo) << "Creating folder: "<<fldr;
    	createFolder(fldr);
    }

    string ext(".jpg");
    //Count files in folder
    int nrOfShots = countFiles(fldr, "*" + ext) + 1;
    string fName = joinPath(fldr, mtk::toString(nrOfShots) + ext);
    int i = 1;

    while(fileExists(fName))
    {
        nrOfShots = countFiles(fldr, "*" + ext) + ++i;
        fName = joinPath(fldr, mtk::toString(nrOfShots) + ext);
    }

	if(mCamera1.SaveImage(fName.c_str()))
    {
    	Log(lError) << "Failed saving snapshot..";
    }
    else
    {
    	Log(lInfo) << "Saved snapshot to file: "<< fName;

		try
        {
	        //save to DB
	        mClientDBSession.insertImageFile(getFileNameNoPath(fName), getCurrentUserID(mUsersCB), "Note..");
        }
        catch(...)
        {
        	handleMySQLException();
        }
    	    DBNavigator1->BtnClick(nbRefresh);
	        DBNavigator1->BtnClick(nbRefresh);
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mRecordMovieBtnClick(TObject *Sender)
{
	if(mRecordMovieBtn->Caption == "Record Movie")
    {
        mCaptureVideoTimer->Enabled = true;

        isavi_InitAVI(&mAVIID, mCamera1.GetCameraHandle());

        int w = mCamera1.mSizeX;
        int h = mCamera1.mSizeY;
        int retVal = isavi_SetImageSize(mAVIID, mCamera1.mColorMode, w, h, 0, 0, 0);

        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a SetImageSize AVI error: "<<retVal;
            return;
        }

        retVal = isavi_SetImageQuality(mAVIID, 100);
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a SetImageQuality AVI error: "<<retVal;
            return;
        }

        string fldr =  mMoviesFolder; //joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), "ArrayBot", "movies");
        if(!folderExists(fldr))
        {
            Log(lInfo) << "Creating folder: "<<fldr;
            createFolder(fldr);
        }

        //Count files in folder
        int nrOfMovies = countFiles(fldr, "*.avi") + 1;
        string fName = joinPath(fldr, mtk::toString(nrOfMovies) + ".avi");
        int i = 1;
        while(fileExists(fName))
        {
        	nrOfMovies = countFiles(fldr, "*.avi") + ++i;
        	fName = joinPath(fldr, mtk::toString(nrOfMovies) + ".avi");
        }

        retVal = isavi_OpenAVI(mAVIID, fName.c_str());
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a OpenAVI error: "<<retVal;
            return;
        }

        retVal = isavi_SetFrameRate(mAVIID, 25);
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a SetFrameRate AVI error: "<<retVal;
            return;
        }

        retVal = isavi_StartAVI(mAVIID);
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a StartAVI error: "<<retVal;
            return;
        }
        mRecordMovieBtn->Caption = "Stop Recording";
    }
    else
    {
        mCaptureVideoTimer->Enabled = false;
        mRecordMovieBtn->Caption = "Record Movie";
        int retVal = isavi_StopAVI(mAVIID);
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a StopAVI error: "<<retVal;
            return;
        }

        retVal = isavi_CloseAVI(mAVIID);
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a CloseAVI error: "<<retVal;
            return;
        }

        retVal = isavi_ExitAVI(mAVIID);
        if(retVal != IS_AVI_NO_ERR)
        {
            Log(lError) << "There was a ExitAVI error: "<<retVal;
            return;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mCaptureVideoTimerTimer(TObject *Sender)
{
	//Todo: this should be executed in its own thread and not in a timer..
    mCaptureVideo = true;
    static int frames(0);

    int retVal = isavi_AddFrame(mAVIID, mCamera1.mImageMemory);

    if(retVal != IS_AVI_NO_ERR)
    {
        //Log(lError) << "There was an AddFrame AVI error: "<<retVal;
    }
    else
    {
        frames++;
        Log(lInfo) << "Added frame: "<<frames;
    }
}
