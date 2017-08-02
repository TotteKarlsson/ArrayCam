#ifndef TSettingsFormH
#define TSettingsFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntegerLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
#include "TMainForm.h"
#include "TPropertyCheckBox.h"
#include <Vcl.ComCtrls.hpp>
#include "TSTDStringLabeledEdit.h"
#include "mtkFloatLabel.h"
#include "TIntLabel.h"
#include "TATDBConnectionFrame.h"
//---------------------------------------------------------------------------

class PACKAGE TSettingsForm : public TForm
{
    __published:
        TTimer *mUIUpdateTimer;
        TGroupBox *GroupBox2;
        TPropertyCheckBox *mVerticalMirrorCB;
        TPropertyCheckBox *mHorizontalMirrorCB;
        TGroupBox *GroupBox3;
        TButton *mCloseButton;
        TPropertyCheckBox *mAutoExposureCB;
        TSTDStringLabeledEdit *mPhotoOutputBaseFolder;
        TSTDStringLabeledEdit *mMoviesFolderE;
        TButton *mBrowseForImagesFolderBtn;
        TButton *mBrowseForMoviesFolderBtn;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TPanel *Panel1;
        TTabSheet *TabSheet3;
        TPropertyCheckBox *mPairLEDsCB;
        TGroupBox *GroupBox6;
        TGroupBox *LightIntensitiesGB;
        TLabel *mBackLEDLbl;
        TLabel *mFrontLEDLbl;
        TPanel *Panel2;
        TTrackBar *mBackLEDTB;
        TTrackBar *mFrontLEDTB;
        TTabSheet *TabSheet4;
        TGroupBox *GroupBox4;
        TLabel *mGainLbl;
        TPropertyCheckBox *mAutoGainCB;
        TTrackBar *mGainTB;
        TTrackBar *mBlackLevelTB;
        TLabel *Label2;
        TLabel *Label3;
        TPropertyCheckBox *mAutoBlackLevelCB;
        TCheckBox *mGainBoostCB;
        TTrackBar *mGammaSB;
        TGroupBox *Gamma;
        TLabel *Label4;
        TTrackBar *mExposureTimeTB;
        TLabel *Label1;
        mtkFloatLabel *mExposureTimeLbl;
        TIntLabel *mBlackLevelLbl;
        TGroupBox *GroupBox5;
        TPropertyCheckBox *mAutoWhiteBalanceCB;
        mtkFloatLabel *mSoftwareGammaLbl;
        void __fastcall mUIUpdateTimerTimer(TObject *Sender);
        void __fastcall mVerticalMirrorCBClick(TObject *Sender);
        void __fastcall mHorizontalMirrorCBClick(TObject *Sender);
        void __fastcall AutoParaCBClick(TObject *Sender);
        void __fastcall mCloseButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall mPairLEDsCBClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall BrowseForFolder(TObject *Sender);
        void __fastcall mGammaSBChange(TObject *Sender);
        void __fastcall SettingsChange(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall mGainTBChange(TObject *Sender);
        void __fastcall mGainBoostCBClick(TObject *Sender);
        void __fastcall mExposureTimeTBChange(TObject *Sender);
        void __fastcall mBlackLevelTBChange(TObject *Sender);
        void __fastcall mAutoCheckConnectionCBClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);


    private:
        void  			__fastcall  enableManualExposureTimeSetting();
        void  			__fastcall  enableManualBlackLevelSetting();
		void 						populateUsersCB();

    public:
        TMainForm&					mMainForm;
        __fastcall 					TSettingsForm(TMainForm& mf);
};

extern PACKAGE TSettingsForm *SettingsForm;

#endif
