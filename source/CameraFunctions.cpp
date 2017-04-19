#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkLogger.h"
#include "mtkUtils.h"
#include "mtkVCLUtils.h"
#include "mtkWin32Utils.h"
#include "uc480/uc480_tools.h"
#include "vcl/atVCLUtils.h"
#include "database/atDBUtils.h"
#include "TATDBDataModule.h"

using namespace mtk;
using namespace at;

//---------------------------------------------------------------------------
void __fastcall TMainForm::mCameraStartLiveBtnClick(TObject *Sender)
{
    Log(lDebug) << "Init camera..";

    //Live
    if(!mCamera1.IsInit())
    {
    	mServiceCamera1.openCamera();
    }
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
    }
}

void __fastcall	TMainForm::onCameraClose(System::TObject* Sender)
{
	Log(lInfo) << "A Camera was closed..";
}

LRESULT TMainForm::OnUSBCameraMessage(TMessage msg)
{
    switch ( msg.WParam )
    {
        case IS_DEVICE_REMOVED:        	Beep( 400, 50 );        break;
        case IS_DEVICE_RECONNECTED:    	Beep( 400, 50 );        break;

        case IS_FRAME:
            if(mCamera1.mImageMemory != NULL)
            {
	            if(CameraEnabledCB->Checked)
                {
                	mCamera1.RenderBitmap(mCamera1.mMemoryId, mCamera1DisplayHandle, mRenderMode);
                }

                if(mReticleVisibilityCB->Checked)
                {
					mReticle.draw(mPB->Width, mPB->Height);
                }
            }
        break;
    }

    return 0;
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
    double wRatio = (double) mMainPhotoPanel->Width / mCamera1BackPanel->Width;
    double hRatio = (double) mMainPhotoPanel->Height / mCamera1BackPanel->Height;

    if(hRatio < wRatio)
    {
	    mCamera1BackPanel->Height = mMainPhotoPanel->Height;
        mCamera1BackPanel->Width *= hRatio;
    }
    else
    {
	    mCamera1BackPanel->Width = mMainPhotoPanel->Width;
        mCamera1BackPanel->Height *= wRatio;
    }

    mCamera1BackPanel->Invalidate();
	Log(lInfo) << "W x H = " <<mCamera1BackPanel->Width<<","<<mCamera1BackPanel->Height<<" Ratio = "<<(double) mCamera1BackPanel->Width / mCamera1BackPanel->Height;
}

void __fastcall TMainForm::mSnapShotBtnClick(TObject *Sender)
{
    string ext(".jpg");
	string uuid = getUUID();
	int csID = extractCoverSlipID(stdstr(mBCLabel->Caption));
    if(csID == -1)
    {
    	csID = 0; //So we can create fileFolder '0'
    }

    int blockID = atdbDM->getCurrentBlockID();
    if(blockID == -1)
    {
    	blockID = 0;
    }

	string base_fldr =  joinPath(mSnapShotFolder, mtk::toString(blockID));
    string fName = joinPath(base_fldr, mtk::toString(csID) + string("_") + uuid + ext);

    if(!folderExists(base_fldr))
    {
    	Log(lInfo) << "Creating folder: "<<base_fldr;
    	createFolder(base_fldr);
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
			if(atdbDM->SQLConnection1->Connected == false)
            {
            	MessageDlg("Not connected to the database!\nThis image is not registered!", mtError, TMsgDlgButtons() << mbOK, 0);
                return;
            }

        	//Add image to database
            //Make sure the barcode exists in the database..
            TSQLQuery* tq = new TSQLQuery(NULL);
            tq->SQLConnection = atdbDM->SQLConnection1;
            tq->SQLConnection->AutoClone = false;
            stringstream q;
            q <<"INSERT INTO images (id, fileextension, created_by, coverslip_id, block_id) VALUES ('"
            			<<uuid<<"', '"
                        <<getFileExtension(fName)<<"', '"
                        <<getCurrentUserID()<<"', '"
						<<csID<<"', '"
	                    <<blockID<<"')";

            string s(q.str());
			Log(lDebug) <<"Image Insertion Query: "<<s;
            tq->SQL->Add(q.str().c_str());
            tq->ExecSQL();
            tq->Close();
            tq->SQL->Clear();
            q.str("");

        }
        catch(...)
        {
        	handleMySQLException();
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mRecordMovieBtnClick(TObject *Sender)
{
	static string lCurrentVideoFileName;
    static string lUUID;
    static int lCSID;
    static int lBlockID;

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

        lCSID = extractCoverSlipID(stdstr(mBCLabel->Caption));
        if(lCSID == -1)
        {
            lCSID = 0; //So we can create fileFolder '0'
        }

        string ext(".avi");
        lUUID = getUUID();
        lBlockID = atdbDM->getCurrentBlockID();
        if(lBlockID == -1)
        {
            lBlockID = 0;
        }

        string base_fldr =  joinPath(mMoviesFolder, mtk::toString(lBlockID));
        string fName = joinPath(base_fldr, mtk::toString(lCSID) + string("_") + lUUID + ext);

        if(!folderExists(base_fldr))
        {
            Log(lInfo) << "Creating folder: "<<base_fldr;
            createFolder(base_fldr);
        }

		lCurrentVideoFileName = fName;

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

        //Register in the database
    	string fName(lCurrentVideoFileName);
    	Log(lInfo) << "Saving movie to file: "<< fName;

		try
        {
        	//Add image to database
            //Make sure the barcode exists in the database..
            TSQLQuery* tq = new TSQLQuery(NULL);
            tq->SQLConnection = atdbDM->SQLConnection1;
            tq->SQLConnection->AutoClone = false;
            stringstream q;
            q <<"INSERT INTO movies (id, fileextension, created_by, coverslip_id, block_id) VALUES ('"
            			<<lUUID<<"', '"
                        <<getFileExtension(fName)<<"', '"
                        <<getCurrentUserID()<<"', '"
                        <<lCSID<<"', '"
	                    <<lBlockID<<"')";

            string s(q.str());
			Log(lDebug) <<"Image Insertion Query: "<<s;
            tq->SQL->Add(q.str().c_str());
            tq->ExecSQL();
            tq->Close();
            delete tq;
        }
        catch(...)
        {
        	handleMySQLException();
        }
    }

  	mACServer.broadcastStatus();
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
        Log(lDebug5) << "Added frame: "<<frames;
    }
}
