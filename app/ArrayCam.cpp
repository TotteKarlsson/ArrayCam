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
USEFORM("frames\TUC7StagePositionFrame.cpp", 						UC7StagePositionFrame);
USEFORM("P:\libs\atapi\source\vcl\frames\THDMIStreamerFrame.cpp", 	HDMIStreamerFrame);
USEFORM("P:\libs\atapi\source\vcl\frames\TMoviesFrame.cpp", 		MoviesFrame);
USEFORM("TMainForm.cpp", 											MainForm);
USEFORM("forms\TRegisterNewRibbonForm.cpp", 						RegisterNewRibbonForm);
USEFORM("frames\TFFMPEGFrame.cpp", 	                                FFMPEGFrame);
USEFORM("forms\TLoggerForm.cpp", 	                                LoggerForm);
//---------------------------------------------------------------------------


//Make ArrayCamUtilites a global
ArrayCamUtilities acu;

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
    	//Setup application mutex, logging etc..
	    acu.init();

		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		TStyleManager::TrySetStyle("Obsidian");

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


//---------------------------------------------------------------------------
#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "mtkMath.lib")
#pragma comment(lib, "mtkIPC.lib")

#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atDataBase.lib")
#pragma comment(lib, "atBarcodeReader.lib")
#pragma comment(lib, "atSSI.lib")
#pragma comment(lib, "atSerialAPI.lib")
#pragma comment(lib, "atUC7API.lib")
#pragma comment(lib, "atArduino.lib")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "uc480_B.lib")
#pragma comment(lib, "uc480_tools_B.lib")

#pragma comment(lib, "atVCLCore.bpi")
#pragma comment(lib, "VCLCommon.bpi")
#pragma comment(lib, "DuneForms.bpi")
#pragma comment(lib, "ArrayCamPackage.bpi")

