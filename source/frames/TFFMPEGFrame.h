#ifndef TFFMPEGFrameH
#define TFFMPEGFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TSTDStringLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
#include "TIntegerLabeledEdit.h"

//---------------------------------------------------------------------------
class TFFMPEGFrame : public TFrame
{
__published:	// IDE-managed Components
	TSTDStringLabeledEdit *FFMPEGLocationE;
	TGroupBox *GroupBox1;
	TIntegerLabeledEdit *FFMPEGThreads;
	TIntegerLabeledEdit *CRFValue;
	TComboBox *PresetCB;
	TLabel *Label1;


private:	// User declarations

	public:		// User declarations
		__fastcall 		TFFMPEGFrame(TComponent* Owner);
		string			getFFMPEGLocation();
        string 			getOutFileArguments();
        string 			getInFileArguments();
};

extern PACKAGE TFFMPEGFrame *FFMPEGFrame;
#endif
