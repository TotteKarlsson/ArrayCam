#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include "TMainForm.h"
#include "TRegisterNewRibbonForm.h"
#include "TLoggerForm.h"
#include "TPGDataModule.h"
#include "TPGCoverSlipDataModule.h"
#include "TPGImagesAndMoviesDataModule.h"
#include "ArrayCamUtilities.h"
#include "ATExceptions.h"
//---------------------------------------------------------------------------
USEFORM("P:\libs\atapi\source\vcl\frames\THDMIStreamerFrame.cpp", HDMIStreamerFrame); /* TFrame: File Type */
USEFORM("P:\libs\atapi\source\vcl\frames\TMoviesFrame.cpp", MoviesFrame); /* TFrame: File Type */
USEFORM("TMainForm.cpp", MainForm);
USEFORM("frames\TFFMPEGFrame.cpp", FFMPEGFrame); /* TFrame: File Type */
USEFORM("frames\TUC7StagePositionFrame.cpp", UC7StagePositionFrame); /* TFrame: File Type */
USEFORM("forms\TLoggerForm.cpp", LoggerForm);
USEFORM("forms\TRegisterNewRibbonForm.cpp", RegisterNewRibbonForm);
//---------------------------------------------------------------------------
ArrayCamUtilities acu;

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
    	//Setup application mutex, logging etc..
	    acu.init();

		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		TStyleManager::TrySetStyle("Glow");
		pgDM 	                = new TpgDM(NULL);
        csPGDM                  = new TcsPGDM(NULL);
        PGImagesAndMoviesDM     = new TPGImagesAndMoviesDM(NULL);

		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TMoviesFrame), &MoviesFrame);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
    catch (const ATException& ae)
    {
    	MessageDlg(ae.Message().c_str(), mtError, TMsgDlgButtons() << mbOK, 0);
    }
	catch (...)
	{
    	MessageDlg("Uncaught exception occured!", mtError, TMsgDlgButtons() << mbOK, 0);
	}
	return 0;
}

