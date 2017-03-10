#ifndef TMainFormH
#define TMainFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "TPropertyCheckBox.h"
#include <Vcl.Menus.hpp>
#include "mtkLogFileReader.h"
#include "mtkIniFileProperties.h"
#include "mtkIniFile.h"
#include "mtkLogger.h"
#include "TRegistryForm.h"
#include "camera/uc480Class.h"
#include "arduino/atLightsArduinoClient.h"
#include "arduino/atSensorsArduinoClient.h"
#include "mtkFloatLabel.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
#include "TArrayBotBtn.h"
#include "sound/atSoundPlayer.h"
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>

#include "TATDBImagesAndMoviesDataModule.h"
#include "arraybot/atEnvironmentalSensorReader.h"
#include "database/atATDBServerSession.h"
#include "/database/atATDBClientDBSession.h"
#include <Vcl.Imaging.pngimage.hpp>
#include "atCameraServiceThread.h"
#include "atReticle.h"
//---------------------------------------------------------------------------

using Poco::Timestamp;
using mtk::IniFileProperties;
using mtk::IniFile;
using mtk::Property;

class TSettingsForm;
class TLocalArgs;
//---------------------------------------------------------------------------
class TMainForm  : public TRegistryForm
{
	friend TSettingsForm;
	friend TLocalArgs;

	__published:	// IDE-managed Components
	TMemo *infoMemo;
	TTimer *mShutDownTimer;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TSplitter *Splitter2;
	TPanel *mMainPanel;
	TPanel *mCamera1BackPanel;
	TTimer *mCaptureVideoTimer;
	TPanel *mBottomPanel;
	TPopupMenu *mMediaPopup;
	TMenuItem *Delete1;
	TMenuItem *DeleteAll1;
	TGroupBox *GroupBox6;
	mtkFloatLabel *mHumidityE;
	TGroupBox *GroupBox5;
	mtkFloatLabel *mTemperatureLbl;
	TGroupBox *GroupBox8;
	TToolBar *ToolBar1;
	TBitBtn *mClearLogMemoBtn;
	TComboBox *LogLevelCB;
	TScrollBox *ScrollBox1;
	TArrayBotButton *mFitToScreenButton;
	TArrayBotButton *mFrontBackLEDBtn;
	TArrayBotButton *mOneToOneBtn;
	TArrayBotButton *mOneToTwoBtn;
	TArrayBotButton *mRecordMovieBtn;
	TArrayBotButton *mSettingsBtn;
	TArrayBotButton *mSnapShotBtn;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TPageControl *PageControl2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TDBGrid *mImagesGrid;
	TDBNavigator *DBNavigator1;
	TDBGrid *mNotesGrid;
	TButton *mAddImageFileBtn;
	TDBMemo *DBMemo1;
	TButton *mUpdateNoteBtn;
	TImage *Image1;
	TGroupBox *GroupBox1;
	TPanel *Panel4;
	TComboBox *mUsersCB;
	TLabel *Label1;
	TPanel *Panel3;
	TTabSheet *TabSheet5;
	TDBGrid *DBGrid1;
	TButton *Button1;
	TTabSheet *TabSheet6;
	TGroupBox *mATDBServerGB;
	TButton *mSyncUsersBtn;
	TGroupBox *GroupBox3;
	TDBGrid *DBGrid2;
	TButton *mATDBServerBtnConnect;
	TDBNavigator *DBNavigator2;
	TTabSheet *TabSheet7;
	TGroupBox *GroupBox2;
	TMemo *Memo1;
	TPanel *Panel5;
	TImage *Image2;
	TLabel *Label2;
	TLabel *logLabel;
	TLabel *versionLabel;
	TTimer *mStartupTimer;
	TPaintBox *mPB;
	TTrackBar *mReticleRadiusTB;
	TGroupBox *GroupBox4;
	TTrackBar *mReticleCenterXTB;
	TTrackBar *mReticleCenterYTB;
	TArrayBotButton *mCenterReticleBtn;
	TButton *mShowBottomPanelBtn;
	TButton *mCloseBottomPanelBtn;
	void __fastcall mCameraStartLiveBtnClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall mShutDownTimerTimer(TObject *Sender);
	void __fastcall mOneToTwoBtnClick(TObject *Sender);
	void __fastcall mOneToOneBtnClick(TObject *Sender);
	void __fastcall mFitToScreenButtonClick(TObject *Sender);
	void __fastcall mMainPanelResize(TObject *Sender);
	void __fastcall mToggleLogPanelClick(TObject *Sender);
	void __fastcall mSnapShotBtnClick(TObject *Sender);
	void __fastcall mRecordMovieBtnClick(TObject *Sender);
	void __fastcall mCaptureVideoTimerTimer(TObject *Sender);
	void __fastcall ClearLogMemo(TObject *Sender);
	void __fastcall mMoviesLBDblClick(TObject *Sender);
	void __fastcall Delete1Click(TObject *Sender);
	void __fastcall DeleteAll1Click(TObject *Sender);
	void __fastcall mCameraStreamPanelDblClick(TObject *Sender);
	void __fastcall mExitBtnClick(TObject *Sender);
	void __fastcall mSettingsBtnClick(TObject *Sender);
	void __fastcall mFrontBackLEDBtnClick(TObject *Sender);
	void __fastcall LogLevelCBChange(TObject *Sender);
	void __fastcall mAddImageFileBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBMemo1Change(TObject *Sender);
	void __fastcall mUpdateNoteBtnClick(TObject *Sender);
	void __fastcall DBNavigator2Click(TObject *Sender, TNavigateBtn Button);
	void __fastcall DBNavigator2BeforeAction(TObject *Sender, TNavigateBtn Button);
	void __fastcall mNewNoteBtnClick(TObject *Sender);
	void __fastcall DBMemo1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall mImagesGridCellClick(TColumn *Column);
	void __fastcall mImagesGridDblClick(TObject *Sender);
	void __fastcall Panel3Resize(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall mATDBServerBtnConnectClick(TObject *Sender);
	void __fastcall mSyncUsersBtnClick(TObject *Sender);
	void __fastcall mImagesGridKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall mStartupTimerTimer(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall mReticleRadiusTBChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall mPBMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall mPBMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall mPBMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall mCenterReticleBtnClick(TObject *Sender);
	void __fastcall mCloseBottomPanelBtnClick(TObject *Sender);
	void __fastcall mShowBottomPanelBtnClick(TObject *Sender);


    protected:
        LogFileReader                           mLogFileReader;
        void __fastcall                         logMsg();
		void 									loadCurrentImage();

		bool									mMovingReticle;
    	EnvironmentaSensorReader				mEnvReader;
		TSettingsForm* 							mSettingsForm;


        Poco::Mutex								mClientDBMutex;
		ATDBClientDBSession						mClientDBSession;

		Poco::Mutex								mServerDBMutex;
		ATDBServerSession						mServerDBSession;

        IniFile						            mIniFile;
        IniFileProperties  			            mProperties;
		Property<mtk::LogLevel>            		mLogLevel;

        										//Camera Settings
        Property<bool>						    mAutoGain;
        Property<bool>						    mAutoExposure;
        Property<bool>						    mAutoBlackLevel;
        Property<bool>						    mAutoWhiteBalance;
        Property<double>   					    mSoftwareGamma;

        Property<bool>						    mVerticalMirror;
        Property<bool>						    mHorizontalMirror;

        Property<string>						mSnapShotFolder;
        Property<string>						mMoviesFolder;
        Property<string>						mLocalDBName;
        Property<bool>						    mPairLEDs;

								                // Camera variables
        								        //!The camera class
		Cuc480   						        mCamera1;
        CameraServiceThread						mServiceCamera1;
        TReticle								mReticle;

        long							        mRenderMode;
        HWND	                		        mCamera1DisplayHandle;	// handle to diplay window
		bool							        openCameras();

        								        //!Boolean to check if we are
                                                //capturing video to file
        bool							        mCaptureVideo;

        								        //!AVI ID is a handle for a
                                                //underlying avi object
		int 							        mAVIID;

        										//!The arduino client connects to
                                                //an arduino server. The client processes
                                                //incoming messages over a socket, in
                                                //onArduinoMessageReceived
		LightsArduinoClient    			        mLightsArduinoClient;

        										//!The arduino client connects to
                                                //an arduino server. The client processes
                                                //incoming messages over a socket, in
                                                //onArduinoMessageReceived
		SensorsArduinoClient    	   	        mSensorsArduinoClient;

        										//Callbacks
        void									onArduinoClientConnected();
        void									onArduinoClientDisconnected();

        										//Callbacks
		void 									onLightsArduinoMessageReceived(const string& msg);
		void 									onSensorsArduinoMessageReceived(const string& msg);
		void 									onPufferArduinoMessageReceived(const string& msg);

        void									enableDisableClientControls(bool enable);
		void    								populateUsers();
		void       __fastcall					afterServerConnect(System::TObject* Sender);
		void       __fastcall					afterServerDisconnect(System::TObject* Sender);

   		void       __fastcall					onCameraOpen( System::TObject* Sender);
		void       __fastcall					onCameraClose(System::TObject* Sender);

    //=================================================================================================
    public:
    											//The environmenatl reader is accessed from a thread
 			       __fastcall 					TMainForm(TComponent* Owner);
 			       __fastcall 					~TMainForm();

//		SoundPlayer								mGetReadyForZeroCutSound;
//        SoundPlayer								mSetZeroCutSound;
//        SoundPlayer								mRestoreFromZeroCutSound;
        void									stopSounds();

												//!Camera stuff is processed in the message loop
	LRESULT 									OnUSBCameraMessage(TMessage msg);
	void 		__fastcall 						populateAbout();

    BEGIN_MESSAGE_MAP
          MESSAGE_HANDLER(IS_UC480_MESSAGE, TMessage, OnUSBCameraMessage);
    END_MESSAGE_MAP(TForm)
};

extern PACKAGE TMainForm *MainForm;
#endif
