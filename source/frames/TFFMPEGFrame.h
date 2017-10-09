#ifndef TFFMPEGFrameH
#define TFFMPEGFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TSTDStringLabeledEdit.h"
#include <Vcl.ExtCtrls.hpp>
#include "TIntegerLabeledEdit.h"
#include "TPropertyCheckBox.h"
#include "mtkIniFileProperties.h"
//---------------------------------------------------------------------------

using mtk::IniFileProperties;
using mtk::IniFile;

class TFFMPEGFrame : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TIntegerLabeledEdit *FFMPEGThreads;
	TIntegerLabeledEdit *CRFValue;
	TComboBox *PresetCB;
	TLabel *Label1;
	TPropertyCheckBox *DeleteSourceFileCB;
	TPropertyCheckBox *RenameSourceFileCB;
	void __fastcall CBClick(TObject *Sender);


	private:
        IniFileProperties 	 	mFrameProperties;
        Property<string>		mH264Preset;

	public:
		__fastcall 		        TFFMPEGFrame(TComponent* Owner);
        string 			        getOutFileArguments();
        string 			        getInFileArguments();
		void 					setupProperties(mtk::IniFile& ini);
        void			        readFromINI();
        void			        writeToINI();

};

extern PACKAGE TFFMPEGFrame *FFMPEGFrame;
#endif
