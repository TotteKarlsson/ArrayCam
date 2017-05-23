#ifndef TMainFormH
#define TMainFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "mtkLogFileReader.h"
#include "mtkIniFileProperties.h"
#include "mtkIniFile.h"
#include "mtkLogger.h"
#include "TRegistryForm.h"
#include "uc480/uc480Class.h"
#include "arduino/atLightsArduinoClient.h"
#include "mtkFloatLabel.h"
#include "TPropertyCheckBox.h"
#include "uc7/atUC7Component.h"
#include "TATDBImagesAndMoviesDataModule.h"
#include "arraybot/atEnvironmentalSensorReader.h"
#include "TArrayBotBtn.h"
#include "sound/atSoundPlayer.h"
#include "atCameraServiceThread.h"
#include "atReticle.h"
#include "ConnectToArduinoServerThread.h"
#include "atVCLUtils.h"
#include "TIntegerLabeledEdit.h"
#include "TIntLabel.h"
#include "uc7/atUC7ApplicationMessages.h"
#include "TCoverSlipDataModule.h"
#include "TATDBConnectionFrame.h"
#include "barcodereader/atDS457.h"
#include "TATDBDataModule.h"
#include "ArrayCamServer.h"
//---------------------------------------------------------------------------
using Poco::Timestamp;
using mtk::IniFileProperties;
using mtk::IniFile;
using mtk::Property;

//#define UWM_MESSAGE   (WM_APP + 5)
#define UWM_MESSAGE      (WM_APP + 5)
enum ApplicationMessageEnum
{
    atUC7SplashWasClosed = 0,
    atUC7Message,
    atEnableResumeBtn
};

class TSettingsForm;
class TLocalArgs;
class TRegisterNewRibbonForm;
class TReticlePopupForm;



//---------------------------------------------------------------------------
class TMainForm  : public TRegistryForm
{
	friend TSettingsForm;
	friend TRegisterNewRibbonForm;
	friend TLocalArgs;

	__published:	// IDE-managed Components
	TMemo *infoMemo;
	TTimer *mShutDownTimer;
	TPanel *Panel2;
	TSplitter *Splitter2;
	TPanel *mMainPhotoPanel;
	TPanel *mCamera1BackPanel;
	TTimer *mCaptureVideoTimer;
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
	TPageControl *PageControl1;
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
	TTimer *mCheckSocketConnectionTimer;
	TPanel *MainTopPanel;
	TGroupBox *HandwheelGB;
	TShape *mHWPosShape;
	TLabel *mRetractLbl;
	TLabel *mCuttingLbl;
	TLabel *mAfterCuttingLbl;
	TLabel *mBeforeCuttingLbl;
	TGroupBox *NorthSouthGB;
	TIntegerLabeledEdit *mKnifeStageJogStep;
	TArrayBotButton *mMoveSouthBtn;
	TArrayBotButton *mMoveNorthBtn;
	TPanel *mTopPanel;
	TComboBox *mUC7ComportCB;
	TButton *mConnectUC7Btn;
	TGroupBox *GroupBox7;
	TIntegerLabeledEdit *mStageMoveDelayE;
	TIntegerLabeledEdit *mZeroCutsE;
	TGroupBox *CounterGB;
	TIntLabel *mSectionCounterLabel;
	TIntegerLabeledEdit *mCountToE;
	TArrayBotButton *mResetCounterBtn;
	TPanel *Panel6;
	TPanel *Panel4;
	TTabSheet *TabSheet3;
	TATDBConnectionFrame *TATDBConnectionFrame1;
	TIntLabel *mRibbonOrderCountLabel;
	TArrayBotButton *mResetRibbonOrderBtn;
	TPanel *MainContentPanel;
	TPanel *Panel1;
	TTabSheet *Main;
	TGroupBox *BlocksGB;
	TButton *mDecodeSessionBtn;
	TArrayBotButton *mRegisterRibbonBtn;
	TPanel *Panel9;
	TGroupBox *atdbGB;
	TGroupBox *UC7GB;
	TTabSheet *TabSheet1;
	TArrayBotButton *mSynchUIBtn;
	TArrayBotButton *mStartStopBtn;
	TArrayBotButton *mRibbonStartBtn;
	TGroupBox *BlockSelectionGB;
	TDBLookupComboBox *mUsersCB;
	TGroupBox *GroupBox1;
	TIntegerLabeledEdit *mArrayCamServerPortE;
	TArrayBotButton *SendServerStatusMessageBtn;
	TDBLookupComboBox *BlockIDCB;
	TLabel *Label3;
	TDBLookupComboBox *mBlockProcessIDCB;
	TLabel *Label1;
	TLabel *Label5;
	TLabel *Label6;
	TDBText *DBText1;
	TDBText *DBText2;
	TPanel *Panel10;
	TDBMemo *DBMemo1;
	TGroupBox *GroupBox3;
	TDBLookupComboBox *DBLookupComboBox1;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TDBText *DBText3;
	TDBText *DBText4;
	TDBText *DBText5;
	TDBText *DBText6;
	TDBMemo *DBMemo2;
	TLabel *Label11;
	TDBText *DBText7;
	TPageControl *PageControl2;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TGroupBox *RibbonsDataGB;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TGroupBox *GroupBox9;
	TGroupBox *GroupBox10;
	TPropertyCheckBox *mRibbonCreatorActiveCB;
	TGroupBox *GroupBox11;
	TIntegerLabeledEdit *mNorthLimitPosE;
	TArrayBotButton *PopulateMaxNorthPosBtn;
	TIntegerLabeledEdit *mKnifeStageNSAbsPosE;
	TGroupBox *GroupBox12;
	TArrayBotButton *mSetZeroCutBtn;
	TIntegerLabeledEdit *mPresetFeedRateE;
	TIntegerLabeledEdit *mFeedRateE;
	TGroupBox *UC7OperationGB;
	THeaderControl *CameraHC;
	TPopupMenu *CameraPopup;
	TMenuItem *FittoScreen1;
	TMenuItem *N111;
	TMenuItem *N121;
	TMenuItem *N1;
	TMenuItem *N2;
	TPopupMenu *ReticlePopup;
	TMenuItem *Reset1;
	TMenuItem *OpenSettings1;
	TPanel *LeftPanel;
	TLabel *mBCLabel;
	TTabSheet *TabSheet6;
	TGroupBox *BarCodeGB;
	TPanel *Panel3;
	TComboBox *mZebraCOMPortCB;
	TButton *mConnectZebraBtn;
	TComboBox *mZebraBaudRateCB;
	TGroupBox *mImagerSettingsGB;
	TRadioGroup *mScannerAimRG;
	TRadioGroup *mScannerEnabledRG;
	TButton *mBeepBtn;
	void __fastcall mCameraStartLiveBtnClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall mShutDownTimerTimer(TObject *Sender);
	void __fastcall mOneToTwoBtnClick(TObject *Sender);
	void __fastcall mOneToOneBtnClick(TObject *Sender);
	void __fastcall mFitToScreenButtonClick(TObject *Sender);
	void __fastcall mMainPhotoPanelResize(TObject *Sender);
	void __fastcall mToggleLogPanelClick(TObject *Sender);
//	void __fastcall mSnapShotBtnClick(TObject *Sender);
//	void __fastcall mRecordMovieBtnClick(TObject *Sender);
	void __fastcall mCaptureVideoTimerTimer(TObject *Sender);
	void __fastcall ClearLogMemo(TObject *Sender);
	void __fastcall mCameraStreamPanelDblClick(TObject *Sender);
	void __fastcall mExitBtnClick(TObject *Sender);
	void __fastcall mSettingsBtnClick(TObject *Sender);
	void __fastcall LogLevelCBChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall mStartupTimerTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall mPBMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall mPBMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall mPBMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

	void __fastcall mCloseBottomPanelBtnClick(TObject *Sender);
	void __fastcall mShowBottomPanelBtnClick(TObject *Sender);
	void __fastcall mCheckSocketConnectionTimerTimer(TObject *Sender);
	void __fastcall mConnectUC7BtnClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mSynchUIBtnClick(TObject *Sender);
	void __fastcall CreateUC7Message(TObject *Sender);
	void __fastcall mResetCounterBtnClick(TObject *Sender);
	void __fastcall mRibbonCreatorActiveCBClick(TObject *Sender);
	void __fastcall uc7EditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall mRegisterRibbonBtnClick(TObject *Sender);
	void __fastcall mConnectZebraBtnClick(TObject *Sender);
	void __fastcall mBtnClick(TObject *Sender);
	void __fastcall scannerSettingsClick(TObject *Sender);
	void __fastcall mUsersCBCloseUp(TObject *Sender);
	void __fastcall mBlockProcessIDCBCloseUp(TObject *Sender);
	void __fastcall SendServerStatusMessageBtnClick(TObject *Sender);
	void __fastcall mRibbonOrderCountLabelClick(TObject *Sender);
	void __fastcall PopulateMaxNorthPosBtnClick(TObject *Sender);
	void __fastcall CameraHCSectionClick(THeaderControl *HeaderControl, THeaderSection *Section);

    protected:
        LogFileReader                           mLogFileReader;
        void __fastcall                         logMsg();
		UC7						 				mUC7;
        int						 				getCOMPortNumber();

		void 									loadCurrentImage();
		bool									mMovingReticle;
    	EnvironmentaSensorReader				mEnvReader;
		TSettingsForm* 							mSettingsForm;

        IniFile						            mIniFile;
        IniFileProperties  			            mProperties;
		Property<mtk::LogLevel>            		mLogLevel;
        mtk::Property<int>                     	mMainContentPanelWidth;

        										//Camera Settings
        Property<bool>						    mAutoGain;
        Property<bool>						    mAutoExposure;
        Property<bool>						    mAutoBlackLevel;
        Property<bool>						    mAutoWhiteBalance;
        Property<double>   					    mSoftwareGamma;

        Property<bool>						    mVerticalMirror;
        Property<bool>						    mHorizontalMirror;

												//!Reticle
		auto_ptr<TReticlePopupForm>				mReticleForm;
        Property<bool>						    mReticleVisible;

        Property<string>						mSnapShotFolder;
        Property<string>						mMoviesFolder;
        Property<string>						mLocalDBName;
        Property<bool>						    mPairLEDs;

		mtk::Property<int>	              		mUC7COMPort;
        mtk::Property<int>                     	mCountTo;
								                // Camera variables
        								        //!The camera class
		Cuc480   						        mCamera1;
        CameraServiceThread						mServiceCamera1;
        TReticle								mReticle;

        long							        mRenderMode;
        HWND	                		        mCamera1DisplayHandle;	// handle to diplay window

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
        ConnectToArduinoServerThread			mConnectToArduinoServerThread;

        bool									mCheckArduinoServerConnection;

        										//Database stuff
		mtk::Property<int>	                    mDBUserID;
        mtk::Property<int>						mProcessID;
        mtk::Property<int>						mBlockID;
		int 									getCurrentUserID();
		string 									getCurrentUserName();
		void 									populateUsersCB();
		int 									extractCoverSlipID(const string& bc);

        										//Callbacks
        void									onArduinoClientConnected();
        void									onArduinoClientDisconnected();

		void __fastcall 						onConnectedToUC7();
        void __fastcall 						onDisConnectedToUC7();

        bool									handleUC7Message(const UC7Message& m);
		void __fastcall 						enableDisableUC7UI(bool enableDisable);
        void 									onUC7Count();
        void 									onUC7CountedTo();
		void __fastcall                         AppInBox(ATWindowStructMessage& Msg);		
		
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


        //Server functions
        ArrayCamServer							mACServer;

        // Barcode reader
        										//!The barcode reader
        DS457									mZebra;

                                                //INI Parameters...
		mtk::Property<int>	                	mZebraCOMPort;
		mtk::Property<int>	                	mZebraBaudRate;
        int										getZebraCOMPortNumber();
		void __fastcall 						onConnectedToZebra();
        void __fastcall 						onDisConnectedToZebra();

												//Decoder events
		void __fastcall                         onWMDecode(TMessage& Msg);
		void __fastcall                         onSSIEvent(TMessage& Msg);
		void __fastcall                         onSSIImage(TMessage& Msg);
		void __fastcall                         onSSIError(TMessage& Msg);
		void __fastcall                         onSSITimeout(TMessage& Msg);
		void __fastcall                         onSSICapabilities(TMessage& Msg);

    //=================================================================================================
    public:
    											//The environmenatl reader is accessed from a thread
 			       __fastcall 					TMainForm(TComponent* Owner);
 			       __fastcall 					~TMainForm();

												//!Camera stuff is processed in the message loop
		LRESULT 					  			OnUSBCameraMessage(TMessage msg);
		void 		__fastcall 		  			populateAbout();
        void 		__fastcall		  			takeSnapShot();
	    void 		__fastcall		  			startStopRecordingMovie();
	    void 		__fastcall		  			startRecordingMovie();
	    void 		__fastcall		  			stopRecordingMovie();

    BEGIN_MESSAGE_MAP
    	MESSAGE_HANDLER(IS_UC480_MESSAGE, 			TMessage, 						OnUSBCameraMessage);
        MESSAGE_HANDLER(UWM_UC7_MESSAGE,      		ATWindowStructMessage,         	AppInBox);
        MESSAGE_HANDLER(WM_DECODE, 					TMessage, 		                onWMDecode);
        MESSAGE_HANDLER(WM_CAPABILITIES, 			TMessage, 	                    onSSICapabilities)
		MESSAGE_HANDLER(WM_IMAGE,                   TMessage, 		                onSSIImage)
        MESSAGE_HANDLER(WM_ERROR,                   TMessage, 		                onSSIError)
        MESSAGE_HANDLER(WM_TIMEOUT,                 TMessage, 		                onSSITimeout)
        MESSAGE_HANDLER(WM_EVENT, 	                TMessage, 		                onSSIEvent)
//      ON_MESSAGE(WM_SWVERSION, OnSSIVersion)
//      ON_MESSAGE(WM_XFERSTATUS, OnSSIxferStatus)
//      ON_MESSAGE(WM_VIDEOIMAGE, OnSSIVideo)
//      ON_MESSAGE(WM_PARAMS, OnSSIParams)
//      ON_MESSAGE(WM_CMDCOMPLETEMSG, OnSSICommandCompleted)
//      ON_MESSAGE(WM_USER_GETSWTRIGPARAM, OnGetSWTrigParam)
//      ON_MESSAGE(WM_USER_GETIMAGETYPES, OnGetImageFileTypesParam)
//      ON_MESSAGE(WM_USER_GETVIEWFINDERPARAM, OnGetViewFinderParam)
//      ON_MESSAGE(WM_SENDGETVERSIONMSG, OnWM_SENDGETVERSIONMSG)
//      ON_MESSAGE(WM_SENDGETCAPABILITIESMSG, OnWM_SENDGETCAPABILITIESMSG)
    END_MESSAGE_MAP(TForm)
};

extern PACKAGE TMainForm *MainForm;
#endif
