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
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Mask.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include "TApplicationSoundsFrame.h"
#include "TArrayBotBtn.h"
#include "TFFMPEGFrame.h"
#include "TFloatLabeledEdit.h"
#include "TImagesFrame.h"
#include "TIntegerLabeledEdit.h"
#include "TIntLabel.h"
#include "TMoviesFrame.h"
#include "TNavitarMotorFrame.h"
#include "TPropertyCheckBox.h"
#include "TSoundsFrame.h"
#include "TSTDStringLabeledEdit.h"
#include "TUC7StagePositionFrame.h"
#include "mtkFloatLabel.h"
#include "TPGConnectionFrame.h"
#include <memory>
#include "arduino/atLightsArduinoClient.h"
#include "atReticle.h"
#include "atVCLUtils.h"
#include "barcodereader/atDS457.h"
#include "camera/atCameraServiceThread.h"
#include "core/atEnvironmentalSensorReader.h"
#include "forms/TRegistryForm.h"
#include "mtkIniFile.h"
#include "mtkIniFileProperties.h"
#include "navitar/atNavitarMotorController.h"
#include "source/ArrayCamServer.h"
#include "source/ConnectToArduinoServerThread.h"
#include "TApplicationSoundsFrame.h"
#include "TArrayBotBtn.h"
#include "TFFMPEGFrame.h"
#include "TImagesFrame.h"
#include "TIntegerLabeledEdit.h"
#include "TIntLabel.h"
#include "TMoviesFrame.h"
#include "TNavitarMotorFrame.h"
#include "TPropertyCheckBox.h"
#include "TSoundsFrame.h"
#include "TStatusBarManager.h"
#include "TSTDStringLabeledEdit.h"
#include "TUC7StagePositionFrame.h"
#include "TFloatLabeledEdit.h"
#include "uc7/atUC7ApplicationMessages.h"
#include "uc7/atUC7Component.h"
#include "uc480/uc480Class.h"

//---------------------------------------------------------------------------
class TSettingsForm;
class TLocalArgs;
class TRegisterNewRibbonForm;
class TReticlePopupForm;
class THandWheelPositionForm;
class TLoggerForm;
class TActionsForm;
class TFFMPEGOutputFrame;
class TFFMPEGFrame;
class TMovieItemFrame;
using mtk::Property;
using Poco::Timestamp;
using mtk::IniFileProperties;
using mtk::IniFile;
using mtk::Property;

//---------------------------------------------------------------------------
class PACKAGE TMainForm  : public TRegistryForm
{
	friend TSettingsForm;
	friend TRegisterNewRibbonForm;
	friend TLocalArgs;

	__published:	// IDE-managed Components
	TTimer *mShutDownTimer;
	TSplitter *Splitter2;
	TPanel *mMainPhotoPanel;
	TPanel *mCamera1BackPanel;
	TTimer *mCaptureVideoTimer;
	TPopupMenu *mMediaPopup;
	TMenuItem *Delete1;
	TMenuItem *DeleteAll1;
	TPageControl *PageControl1;
	TTimer *mStartupTimer;
	TPaintBox *mPB;
	TTimer *CheckArduinoServerConnectionTimer;
	TGroupBox *CounterGB;
	TIntLabel *SectionCounterLabel;
	TIntegerLabeledEdit *mCountToE;
	TArrayBotButton *mResetCounterBtn;
	TIntLabel *RibbonOrderCountLabel;
	TArrayBotButton *mResetRibbonOrderBtn;
	TPanel *MainContentPanel;
	TPanel *Panel1;
	TTabSheet *Main;
	TGroupBox *RibbonRegistrationGB;
	TButton *DecodeSessionBtn;
	TArrayBotButton *RegisterRibbonBtn;
	TPanel *Panel9;
	TTabSheet *TabSheet1;
	TArrayBotButton *StartStopBtn;
	TGroupBox *GroupBox1;
	TIntegerLabeledEdit *ArrayCamServerPortE;
	TArrayBotButton *SendServerStatusMessageBtn;
	TLabel *Label11;
	TDBText *DBText7;
	TPageControl *MiscPageControl;
	TTabSheet *TabSheet5;
	TGroupBox *BlockInfoGB;
	TGroupBox *CuttingGB;
	TArrayBotButton *PopulateMaxNorthPosBtn;
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
	TTabSheet *TabSheet8;
	TGroupBox *UC7GB;
	TGroupBox *GroupBox4;
	TIntegerLabeledEdit *mStageMoveDelayE;
	TPanel *mTopPanel;
	TComboBox *mUC7ComportCB;
	TButton *mConnectUC7Btn;
	TArrayBotButton *mSynchUIBtn;
	TArrayBotButton *mSetZeroCutBtn;
	TIntegerLabeledEdit *mFeedRateE;
	TUC7StagePositionFrame *CurrentStagePosFrame;
	TArrayBotButton *mMoveNorthBtn;
	TArrayBotButton *mMoveSouthBtn;
	TUC7StagePositionFrame *MaxStagePosFrame;
	TGroupBox *KnifeStageGB;
	TIntegerLabeledEdit *mZeroCutsE;
	TIntegerLabeledEdit *mPresetFeedRateE;
	TLabel *Label6;
	TScrollBox *ScrollBox1;
	TGroupBox *GroupBox11;
	TGroupBox *GroupBox12;
	TArrayBotButton *SetPresetFeedBtn;
	TTabSheet *TabSheet4;
	TSoundsFrame *TSoundsFrame1;
	TApplicationSoundsFrame *TApplicationSoundsFrame1;
	TTabSheet *TabSheet9;
	TGroupBox *GroupBox13;
	TButton *NavitarControllerConnectBtn;
	TGroupBox *ControllerInfoGB;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *ProdIdLbl;
	TLabel *HWVerLbl;
	TLabel *SWVerLbl;
	TLabel *FirmWareDateLbl;
	TNavitarMotorFrame *TNavitarMotorFrame1;
	TPanel *Panel8;
	TNavitarMotorFrame *TNavitarMotorFrame2;
	TStatusBar *StatusBar1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Misc1;
	TMenuItem *UC7StatusChart1;
	TControlBar *ControlBar1;
	TActionList *MenuActions;
	TFileExit *FileExit1;
	TMenuItem *Exit1;
	TAction *OpenHandWheelPositionFormA;
	TUC7StagePositionFrame *BackOffStepFrame;
	TUC7StagePositionFrame *ResumeDeltaDistanceFrame;
	TGroupBox *KnifeGB;
	TMenuItem *Camera1;
	TActionList *CameraActions;
	TAction *FitToScreenA;
	TAction *Zoom1To1A;
	TAction *Zoom1To2A;
	TAction *OpenCameraSettingsA;
	TMenuItem *FitToScreenA1;
	TMenuItem *Zoom111;
	TMenuItem *Zoom121;
	TMenuItem *CameraSettings1;
	TMenuItem *N3;
	TMenuItem *N4;
	TAction *ToggleMainContentPanelA;
	TMenuItem *Help1;
	TMenuItem *About1;
	TMenuItem *N5;
	TMenuItem *OpenLoggerForm1;
	TAction *OpenCloseShortcutForm;
	TMenuItem *Actions1;
	TArrayBotButton *ArrayBotButton2;
	TToolBar *ToolBar1;
	TBindingsList *BindingsList2;
	TButton *Button1;
	TMenuItem *ShowHideMainContentPanel1;
	TButton *ToggleMainContentBtn;
	TToolBar *ToolBar2;
	TTabSheet *TabSheet3;
	TGroupBox *GroupBox2;
	TIntegerLabeledEdit *mArduinoServerPortE;
	TButton *ArduinoServerStartStopButton;
	TPropertyCheckBox *mAutoCheckConnectionCB;
	TIntLabel *NrOfArrayCamServerClients;
	TLabel *Label2;
	TTabSheet *TabSheet7;
	TGroupBox *BlockSelectionGB;
	TPanel *Panel2;
	TLabel *Label3;
	TDBLookupComboBox *BlockIDCB;
	TDBLookupComboBox *mUsersCB;
	TGroupBox *RibbonsDataGB;
	TDBGrid *DBGrid1;
	TGroupBox *BlockNotesGB;
	TPanel *Panel4;
	TDBMemo *mBlockNoteMemo;
	TDBNavigator *DBNavigator2;
	TPanel *Panel5;
	TDBNavigator *mBlockNoteNavigator;
	TDBGrid *mBlockNotesGrid;
	TGroupBox *GroupBox3;
	TPanel *Panel6;
	TDBGrid *mRibbonNotesGrid;
	TDBNavigator *mRibbonNotesNavigator;
	TPanel *Panel7;
	TDBMemo *mRibbonNoteMemo;
	TDBNavigator *mRibbonNoteNavigator;
	TArrayBotButton *ArrayBotButton1;
	TMenuItem *N6;
	TMenuItem *Hide1;
	TAction *ToggleControlBar;
	TArrayBotButton *TakeSnapShotBtn;
	TArrayBotButton *RecordVideoBtn;
	TTimer *VideoRecTimer;
	TMenuItem *oggleControlBar1;
	TMenuItem *N7;
	TTabSheet *TabSheet10;
	TGroupBox *LightIntensitiesGB;
	TLabel *mFrontLEDLbl;
	TPanel *Panel10;
	TTrackBar *FrontLEDTB;
	TFlowPanel *MPEGPanel;
	TFFMPEGFrame *TFFMPEGFrame1;
	TTabSheet *TabSheet11;
	TTimer *CleanupTimer;
	TTabSheet *TabSheet12;
	TGroupBox *GroupBox16;
	TDBLookupListBox *BlockIDSLLB;
	TPageControl *MediaPageControl;
	TBrowseForFolder *BrowseForFolder1;
	TGroupBox *GroupBox6;
	TButton *BrowseForMediaFolderBtn;
	TSTDStringLabeledEdit *MediaFolderE;
	TTabSheet *TabSheet15;
	TTabSheet *TabSheet13;
	TImagesFrame *TImagesFrame1;
	TMoviesFrame *TMoviesFrame1;
	TPanel *CutterStatusPanel;
	TPanel *Panel11;
	TShape *UC7Shape;
	TLabel *Label4;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TGroupBox *GroupBox5;
	TFloatLabeledEdit *BlockFaceHeight;
	TPageControl *BlocksAndRibbonsPC;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet16;
	TRadioGroup *StopOptionsRG;
	mtkFloatLabel *RibbonLengthLbl;
	TLabel *Label19;
	TPGConnectionFrame *TPGConnectionFrame1;
	TGroupBox *GroupBox7;
	TPropertyCheckBox *SyncWhiskerCB;
	TGroupBox *GroupBox8;
	TFloatLabeledEdit *PresetReturnSpeedE;
	TFloatLabeledEdit *SlowReturnSpeedE;
	TFloatLabeledEdit *UltraSlowReturnSpeedE;
	TArrayBotButton *PresetReturnSpeedBtn;
	TArrayBotButton *SlowReturnSpeedBtn;
	TGroupBox *GroupBox9;
	TArrayBotButton *UltraSlowReturnSpeedBtn;
	TTimer *MouseClickTimer;
	TTabSheet *RibbonSeparatorSheet;
	TGroupBox *GroupBox10;
	TLabel *winXLbl;
	TLabel *winYLbl;
	TIntegerLabeledEdit *ClickXE;
	TIntegerLabeledEdit *ClickYE;
	TButton *TestClickWindowBtn;
	TPanel *Panel12;
	TSTDStringLabeledEdit *WinCaptionE;
	TLabel *WindowCheckLbl;
	void __fastcall mCameraStartLiveBtnClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall mShutDownTimerTimer(TObject *Sender);
	void __fastcall mMainPhotoPanelResize(TObject *Sender);
	void __fastcall mToggleLogPanelClick(TObject *Sender);
	void __fastcall mCaptureVideoTimerTimer(TObject *Sender);
	void __fastcall mCameraStreamPanelDblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PageControlChange(TObject *Sender);
	void __fastcall mStartupTimerTimer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall mPBMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall mPBMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall mPBMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall CheckArduinoServerConnectionTimerTimer(TObject *Sender);
	void __fastcall mConnectUC7BtnClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mSynchUIBtnClick(TObject *Sender);
	void __fastcall CreateUC7Message(TObject *Sender);
	void __fastcall mResetCounterBtnClick(TObject *Sender);
	void __fastcall uc7EditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall RegisterRibbonBtnClick(TObject *Sender);
	void __fastcall mConnectZebraBtnClick(TObject *Sender);
	void __fastcall DecodeBarcodeClick(TObject *Sender);
	void __fastcall scannerSettingsClick(TObject *Sender);
	void __fastcall mUsersCBCloseUp(TObject *Sender);
	void __fastcall DB_CBCloseUp(TObject *Sender);
	void __fastcall SendServerStatusMessageBtnClick(TObject *Sender);
	void __fastcall CountLabelClick(TObject *Sender);
	void __fastcall PopulateMaxNorthPosBtnClick(TObject *Sender);
	void __fastcall CameraHCSectionClick(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall KnifePosChange(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall MaxKnifePosKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ArduinoServerStartStopButtonClick(TObject *Sender);
	void __fastcall mAutoCheckConnectionCBClick(TObject *Sender);
	void __fastcall BackOffStepFrameKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ResumeDeltaDistanceOnKey(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall NavitarControllerConnectBtnClick(TObject *Sender);
	void __fastcall StatusBar1Hint(TObject *Sender);
	void __fastcall OpenHandWheelPositionFormAExecute(TObject *Sender);
	void __fastcall FitToScreenAExecute(TObject *Sender);
	void __fastcall Zoom1To1AExecute(TObject *Sender);
	void __fastcall Zoom1To2AExecute(TObject *Sender);
	void __fastcall OpenCameraSettingsAExecute(TObject *Sender);
	void __fastcall ToggleMainContentPanelAExecute(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall OpenLoggerForm1Click(TObject *Sender);
	void __fastcall OpenCloseShortcutFormExecute(TObject *Sender);
	void __fastcall OpenCloseShortcutFormUpdate(TObject *Sender);
	void __fastcall mBlockNoteNavigatorClick(TObject *Sender, TNavigateBtn Button);
	void __fastcall mRibbonNotesNavigatorClick(TObject *Sender, TNavigateBtn Button);
	void __fastcall ToggleControlBarExecute(TObject *Sender);
	void __fastcall ToggleControlBarUpdate(TObject *Sender);
	void __fastcall TakeSnapShotBtnClick(TObject *Sender);
	void __fastcall VideoRecTimerTimer(TObject *Sender);
	void __fastcall RecordVideoBtnClick(TObject *Sender);
	void __fastcall ControlBar1StartDrag(TObject *Sender, TDragObject *&DragObject);
	void __fastcall FrontLEDTBChange(TObject *Sender);
	void __fastcall CleanupTimerTimer(TObject *Sender);
	void __fastcall BlockIDSLLBMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BlockIDSLLBKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall BrowseForFolderClick(TObject *Sender);
	void __fastcall MediaPageControlChange(TObject *Sender);
	void __fastcall SyncWhiskerCBClick(TObject *Sender);
	void __fastcall TestClickWindowBtnClick(TObject *Sender);
	void __fastcall PageControlExit(TObject *Sender);
	void __fastcall MouseClickTimerTimer(TObject *Sender);

    protected:
    	enum StatusBarPanels{ 	sbpTemperature = 0, 	sbpHumidity,
        						sbpArrayBotConnection, 	sbpHandWheelPosition,
                                sbpDBConnection, 		sbpArduinoConnection,
                                sbpUC7Connection, 		sbpBarcodeReader,
                                sbpNavitarController};

		UC7						 				mUC7;
        int						 				getCOMPortNumber();

		void 									loadCurrentImage();
		bool									mMovingReticle;
    	EnvironmentaSensorReader				mEnvReader;
		TSettingsForm* 							mSettingsForm;

		void							        setupProperties();
        IniFile						            mIniFile;
        IniFileProperties  			            mGeneralProperties;
		Property<mtk::LogLevel>            		mLogLevel;
        Property<int>                     		mMainContentPanelWidth;

        										//Camera Settings
        Property<bool>						    mAutoGain;
        Property<bool>						    mAutoExposure;
        Property<bool>						    mAutoBlackLevel;
        Property<bool>						    mAutoWhiteBalance;
        Property<double>   					    mSoftwareGamma;
        Property<bool>						    mVerticalMirror;
        Property<bool>						    mHorizontalMirror;

												//!Reticle
		std::auto_ptr<TReticlePopupForm>   		mReticleForm;
        Property<bool>						    mReticleVisible;

        Property<string>						mLocalDBName;
        Property<bool>						    mPairLEDs;

		Property<int>	              			mUC7COMPort;
        Property<int>                     		mCountTo;

        										//Sound properties
        IniFileProperties  			            mSoundProperties;
        Property<ApplicationSound>				mBeforeKnifeBackOffSound;
        Property<ApplicationSound>				mKnifeBeforeCuttingSound;
        Property<ApplicationSound>				mKnifeCuttingSound;
        Property<ApplicationSound>				mKnifeAfterCuttingSound;
        Property<ApplicationSound>				mArmRetractingSound;

        										// Camera variables
        								        //!The camera class
		Cuc480   						        mCamera1;
        CameraServiceThread						mServiceCamera1;
        TReticle								mReticle;
        TReticle								mReticle2;

        long							        mRenderMode;
        HWND	                		        mCamera1DisplayHandle;	// handle to diplay window

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

        Property<int>	                    	mKnifeStageMaxPos;
        Property<int>	                    	mKnifeStageJogStep;
        Property<int>	                    	mKnifeStageResumeDelta;

        										//Database stuff
		Property<int>	                    	mDBUserID;
        Property<int>							mSpecimenID;
        Property<int>							mSliceID;
        Property<int>							mBlockID;
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

        void									enableDisableArduinoClientControls(bool enable);
		void    								populateUsers();
		void       __fastcall					afterDBServerConnect(System::TObject* Sender);
		void       __fastcall					afterDBServerDisconnect(System::TObject* Sender);

   		void       __fastcall					onCameraOpen( System::TObject* Sender);
		void       __fastcall					onCameraClose(System::TObject* Sender);

        										//Server functions
        ArrayCamServer							mACServer;

        										//!The barcode reader
        DS457									mZebra;

												//!Navitar motor controller stuff
		NavitarMotorController					mNavitarMotorController;
		void  									onNavitarConnected();
		void  									onNavitarDisconnected();

                                                //INI Parameters...
		Property<int>	     		           	mZebraCOMPort;
		Property<int>	                		mZebraBaudRate;
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

		TStatusBarManager						mSBManager;
        THandWheelPositionForm* 				mHandWheelPositionForm;

		TLoggerForm*							LoggerForm;
		TActionsForm*							ActionsForm;

		bool 									startVideoCompression(const string& inputName);
	    void __fastcall 	                	onCompressionFinished(TFFMPEGOutputFrame* f);
	    list<TFFMPEGOutputFrame*>				mCompressionFrames;
		void            						populateMedia();


    //=================================================================================================
    public:

 			        __fastcall 					TMainForm(TComponent* Owner);
 			        __fastcall 					~TMainForm();

												//!Camera stuff is processed in the message loop
		LRESULT 					  			onUSBCameraMessage(TMessage msg);
        void 		__fastcall		  			takeSnapShot();
	    void 		__fastcall		  			startStopRecordingMovie();
	    void 		__fastcall		  			startRecordingMovie();
	    void 		__fastcall		  			stopRecordingMovie();
	    void 		__fastcall		  			setFocus(int f);
	    void 		__fastcall		  			focusIn(int z);
	    void 		__fastcall		  			focusOut(int z);
	    void 		__fastcall		  			setZoom(int z);
	    void 		__fastcall		  			zoomIn(int z);
	    void 		__fastcall		  			zoomOut(int z);
	    void 		__fastcall		  			setFocusAndZoom(int f, int z);
        void		__fastcall					updateTemperature(double t);
        void		__fastcall					updateHumidity(double h);
        void									setLEDIntensity(int intensity);
        void		__fastcall 					checkSyncWhiskerCB();
        void		__fastcall 					unCheckSyncWhiskerCB();
        void __fastcall							fireRibbonSeparator();

    BEGIN_MESSAGE_MAP
    	MESSAGE_HANDLER(IS_UC480_MESSAGE, 		TMessage, 						onUSBCameraMessage);
        MESSAGE_HANDLER(UWM_UC7_MESSAGE,      	ATWindowStructMessage,         	AppInBox);
        MESSAGE_HANDLER(WM_DECODE, 				TMessage, 		                onWMDecode);
        MESSAGE_HANDLER(WM_CAPABILITIES, 		TMessage, 	                    onSSICapabilities)
		MESSAGE_HANDLER(WM_IMAGE,               TMessage, 		                onSSIImage)
        MESSAGE_HANDLER(WM_ERROR,               TMessage, 		                onSSIError)
        MESSAGE_HANDLER(WM_TIMEOUT,             TMessage, 		                onSSITimeout)
        MESSAGE_HANDLER(WM_EVENT, 	            TMessage, 		                onSSIEvent)
    END_MESSAGE_MAP(TForm)
};

extern PACKAGE TMainForm *MainForm;
#endif