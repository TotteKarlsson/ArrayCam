//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFFMPEGFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TSTDStringLabeledEdit"
#pragma resource "*.dfm"
TFFMPEGFrame *FFMPEGFrame;
//---------------------------------------------------------------------------
__fastcall TFFMPEGFrame::TFFMPEGFrame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
