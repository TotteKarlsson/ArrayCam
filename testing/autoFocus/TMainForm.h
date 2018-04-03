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
#include "dslTFloatLabeledEdit.h"
#include "TImagesFrame.h"
#include "dslTIntegerLabeledEdit.h"
#include "dslTIntLabel.h"
#include "TMoviesFrame.h"
#include "TNavitarMotorFrame.h"
#include "dslTPropertyCheckBox.h"
#include "TSoundsFrame.h"
#include "dslTSTDStringLabeledEdit.h"
#include "TUC7StagePositionFrame.h"
#include "dslTFloatLabel.h"
#include "TPGConnectionFrame.h"
#include "THDMIStreamerFrame.h"
#include <memory>
#include "arduino/atLightsArduinoClient.h"
#include "ello/atElloUIClient.h"
#include "atReticle.h"
#include "atVCLUtils.h"
#include "barcodereader/atDS457.h"
#include "camera/atCameraServiceThread.h"
#include "core/atEnvironmentalSensorReader.h"
#include "forms/dslTRegistryForm.h"
#include "dslIniFile.h"
#include "dslIniFileProperties.h"
#include "navitar/atNavitarMotorController.h"
#include "source/ArrayCamServer.h"
#include "source/ConnectToArduinoServerThread.h"
#include "source/ConnectToElloUIThread.h"
#include "TApplicationSoundsFrame.h"
#include "TArrayBotBtn.h"
#include "TFFMPEGFrame.h"
#include "TImagesFrame.h"
#include "dslTIntegerLabeledEdit.h"
#include "dslTIntLabel.h"
#include "TMoviesFrame.h"
#include "TNavitarMotorFrame.h"
#include "dslTPropertyCheckBox.h"
#include "TSoundsFrame.h"
#include "dslTSTDStringLabeledEdit.h"
#include "TUC7StagePositionFrame.h"
#include "dslTFloatLabeledEdit.h"
#include "uc7/atUC7ApplicationMessages.h"
#include "uc7/atUC7Component.h"
#include "thirdparty/uc480/uc480Class.h"

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
using dsl::Property;
using Poco::Timestamp;
using dsl::IniFileProperties;
using dsl::IniFile;
using dsl::Property;

//---------------------------------------------------------------------------
class PACKAGE TMainForm  : public TRegistryForm
{
	friend TSettingsForm;
	friend TRegisterNewRibbonForm;
	friend TLocalArgs;

	__published:
	TTimer *mShutDownTimer;
	TSplitter *Splitter2;
	TPanel *mMainPhotoPanel;
	TPanel *mCamera1BackPanel;
	TTimer *mCaptureVideoTimer;
	TPopupMenu *mMediaPopup;
	TMenuItem *Delete1;
	TMenuItem *DeleteAll1;
	TPageControl *MainPC;
	TTimer *mStartupTimer;
	TPaintBox *mPB;
	TPanel *MainContentPanel;
	TPanel *Panel1;
	TTabSheet *Main;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TIntegerLabeledEdit *ArrayCamServerPortE;
	TArrayBotButton *SendServerStatusMessageBtn;
	TPageControl *MiscPageControl;
	TTabSheet *TabSheet5;
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
	TScrollBox *ScrollBox1;
	TTabSheet *TabSheet4;
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
	TPanel *Panel8;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Misc1;
	TMenuItem *UC7StatusChart1;
	TActionList *MenuActions;
	TFileExit *FileExit1;
	TMenuItem *Exit1;
	TAction *OpenHandWheelPositionFormA;
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
	TMenuItem *N6;
	TMenuItem *Hide1;
	TAction *ToggleControlBar;
	TArrayBotButton *TakeSnapShotBtn;
	TArrayBotButton *RecordVideoBtn;
	TTimer *VideoRecTimer;
	TMenuItem *oggleControlBar1;
	TMenuItem *N7;
	TFlowPanel *MPEGPanel;
	TTabSheet *TabSheet11;
	TTimer *CleanupTimer;
	TBrowseForFolder *BrowseForFolder1;
	TTabSheet *RibbonSeparatorSheet;
	TGroupBox *GroupBox10;
	TButton *RunWiperBtn;
	TGroupBox *GroupBox6;
	TButton *BrowseForMediaFolderBtn;
	TSTDStringLabeledEdit *MediaFolderE;
	TTabSheet *TabSheet12;
	TPanel *Bpanel;
	TToolBar *ToolBar3;
	TTimer *BroadcastStatusTimer;
	TTabSheet *TabSheet2;
	TGroupBox *BarCodeGB;
	TPanel *Panel3;
	TComboBox *mZebraCOMPortCB;
	TButton *mConnectZebraBtn;
	TComboBox *mZebraBaudRateCB;
	TGroupBox *mImagerSettingsGB;
	TRadioGroup *mScannerAimRG;
	TRadioGroup *mScannerEnabledRG;
	TButton *mBeepBtn;
	TButton *ConnectWipterClientBtn;
	TArrayBotButton *KniveMovieBtn;
	TMenuItem *ThemesMenu;
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
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SendServerStatusMessageBtnClick(TObject *Sender);
	void __fastcall CameraHCSectionClick(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall NavitarControllerConnectBtnClick(TObject *Sender);
	void __fastcall StatusBar1Hint(TObject *Sender);
	void __fastcall FitToScreenAExecute(TObject *Sender);
	void __fastcall Zoom1To1AExecute(TObject *Sender);
	void __fastcall Zoom1To2AExecute(TObject *Sender);
	void __fastcall OpenCameraSettingsAExecute(TObject *Sender);
	void __fastcall ToggleMainContentPanelAExecute(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall OpenLoggerForm1Click(TObject *Sender);
	void __fastcall OpenCloseShortcutFormExecute(TObject *Sender);
	void __fastcall OpenCloseShortcutFormUpdate(TObject *Sender);
	void __fastcall TakeSnapShotBtnClick(TObject *Sender);
	void __fastcall VideoRecTimerTimer(TObject *Sender);
	void __fastcall RecordVideoBtnClick(TObject *Sender);
	void __fastcall ControlBar1StartDrag(TObject *Sender, TDragObject *&DragObject);
	void __fastcall CleanupTimerTimer(TObject *Sender);
	void __fastcall BrowseForFolderClick(TObject *Sender);
	void __fastcall PageControlExit(TObject *Sender);
	void __fastcall MediaFolderEKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall BroadCastStatusBtnClick(TObject *Sender);
	void __fastcall BroadcastStatusTimerTimer(TObject *Sender);
	void __fastcall ThemesMenuClick(TObject *Sender);

	protected:
		enum StatusBarPanels{	sbpTemperature = 0,		sbpHumidity,
								sbpArrayBotConnection,	sbpHandWheelPosition,
								sbpDBConnection,		sbpArduinoConnection,
								sbpUC7Connection,		sbpBarcodeReader,
								sbpNavitarController};

		void									loadCurrentImage();
		bool									mMovingReticle;
		TSettingsForm*							mSettingsForm;
		void									setupProperties();
		IniFile									mIniFile;
		IniFileProperties						mGeneralProperties;
		Property<dsl::LogLevel>					mLogLevel;
		Property<int>							mMainContentPanelWidth;

												//Camera Settings
		Property<bool>							mAutoGain;
		Property<bool>							mAutoExposure;
		Property<bool>							mAutoBlackLevel;
		Property<bool>							mAutoWhiteBalance;
		Property<double> 						mSoftwareGamma;
		Property<bool>							mVerticalMirror;
		Property<bool>							mHorizontalMirror;

												//!Reticle
		std::auto_ptr<TReticlePopupForm> 		mReticleForm;
		Property<bool>							mReticleVisible;

												//Camera variables
												//!The camera class
		Cuc480 									mCamera1;
		CameraServiceThread						mServiceCamera1;
		TReticle								mReticle;
		TReticle								mReticle2;

		long									mRenderMode;
		HWND									mCamera1DisplayHandle;	// handle to diplay window

												//!AVI ID is a handle for a
												//underlying avi object
		int										mAVIID;
		void __fastcall							AppInBox(ATWindowStructMessage& Msg);

 		void __fastcall							onCameraOpen( System::TObject* Sender);
		void __fastcall							onCameraClose(System::TObject* Sender);

												//Server functions
		ArrayCamServer							mACServer;

        										//Motor that wipes the ribbons off the knife
												//!Navitar motor controller stuff
		NavitarMotorController					mNavitarMotorController;
		void									onNavitarConnected();
		void									onNavitarDisconnected();

		TLoggerForm*							LoggerForm;
		TActionsForm*							ActionsForm;

		bool									startVideoCompression(const string& inputName);
		void __fastcall							onCompressionFinished(TFFMPEGOutputFrame* f);
		list<TFFMPEGOutputFrame*>				mCompressionFrames;


	//=================================================================================================
	public:

					__fastcall					TMainForm(TComponent* Owner);
					__fastcall					~TMainForm();

												//!Camera stuff is processed in the message loop
		LRESULT									onUSBCameraMessage(TMessage msg);
		void		__fastcall					takeSnapShot();
		void		__fastcall					startStopRecordingMovie();
		void		__fastcall					startRecordingMovie();
		void		__fastcall					stopRecordingMovie();
		void		__fastcall					setFocus(int f);
		void		__fastcall					focusIn(int z);
		void		__fastcall					focusOut(int z);
		void		__fastcall					setZoom(int z);
		void		__fastcall					zoomIn(int z);
		void		__fastcall					zoomOut(int z);
		void		__fastcall					setFocusAndZoom(int f, int z);

	BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(IS_UC480_MESSAGE,			TMessage,						onUSBCameraMessage);

	END_MESSAGE_MAP(TForm)
};

bool registerVideoInDB(const string& lUUID, const string& videoExtension, int userID, int coverslipID, int blockID , const string& ribbonID = "-1");


extern PACKAGE TMainForm *MainForm;
#endif
