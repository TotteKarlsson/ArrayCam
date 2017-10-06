#include <vcl.h>
#pragma hdrstop
#include "TFFMPEGFrame.h"
#include <sstream>
#include "mtkVCLUtils.h"

#pragma package(smart_init)
#pragma link "TSTDStringLabeledEdit"
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
TFFMPEGFrame *FFMPEGFrame;

using namespace std;
using namespace mtk;



//---------------------------------------------------------------------------
__fastcall TFFMPEGFrame::TFFMPEGFrame(TComponent* Owner)
	: TFrame(Owner)
{
}

//---------------------------------------------------------------------------
string TFFMPEGFrame::getFFMPEGLocation()
{
	return FFMPEGLocationE->getValue();
}

//---------------------------------------------------------------------------
string TFFMPEGFrame::getOutFileArguments()
{
	stringstream s;
//    s << "-vcodec libx264";
    s << "-vcodec libx264";
    s << " -crf " <<CRFValue->getValue();
	s << " -threads " << FFMPEGThreads->getValue();
    s << " -preset " <<stdstr(PresetCB->Text);
	return  s.str();
}



