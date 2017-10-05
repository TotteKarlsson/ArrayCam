//---------------------------------------------------------------------------

#ifndef TFFMPEGFrameH
#define TFFMPEGFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TSTDStringLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFFMPEGFrame : public TFrame
{
__published:	// IDE-managed Components
	TSTDStringLabeledEdit *FFMPEGLocationE;
	TGroupBox *GroupBox1;
private:	// User declarations
public:		// User declarations
	__fastcall TFFMPEGFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFFMPEGFrame *FFMPEGFrame;
//---------------------------------------------------------------------------
#endif
