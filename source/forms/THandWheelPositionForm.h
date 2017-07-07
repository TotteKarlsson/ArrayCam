#ifndef THandWheelPositionFormH
#define THandWheelPositionFormH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include "atUC7StatusHistory.h"

class THandWheelPositionForm : public TForm
{
    __published:
        TChart*						            Chart1;
        TLineSeries*				            Series1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);

    private:
		UC7StatusHistory&			            mUC7StatusHistory;
        bool									mTimeToClose;
    public:
    					__fastcall              THandWheelPositionForm(UC7StatusHistory& h, TComponent* Owner);
		void						            reset();
        void									plot();
        void									setTimeToClose();


};


extern PACKAGE THandWheelPositionForm *HandWheelPositionForm;
#endif
