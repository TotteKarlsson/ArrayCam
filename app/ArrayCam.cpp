#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <string>
#include "mtkUtils.h"
#include "mtkVCLUtils.h"
#include "mtkWin32Utils.h"
#include "mtkLogger.h"
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include "TMainForm.h"
#include "TRegisterNewRibbonForm.h"
#include "TLoggerForm.h"
#include "TPGDataModule.h"
#include "TPGCoverSlipDataModule.h"
#include "TPGImagesAndMoviesDataModule.h"
#include "mtkRestartApplicationUtils.h"
//---------------------------------------------------------------------------
using std::string;
using namespace mtk;

USEFORM("frames\TUC7StagePositionFrame.cpp", UC7StagePositionFrame); /* TFrame: File Type */
USEFORM("P:\libs\atapi\source\vcl\frames\THDMIStreamerFrame.cpp", HDMIStreamerFrame); /* TFrame: File Type */
USEFORM("TMainForm.cpp", MainForm);
USEFORM("forms\TRegisterNewRibbonForm.cpp", RegisterNewRibbonForm);
USEFORM("frames\TFFMPEGFrame.cpp", FFMPEGFrame); /* TFrame: File Type */
USEFORM("forms\TLoggerForm.cpp", LoggerForm);
//---------------------------------------------------------------------------
string		gLogFileLocation            = "";
string	   	gAppName					= "ArrayCam";
string     	gLogFileName                = gAppName + ".log";
string 	   	gApplicationRegistryRoot  	= "\\Software\\Allen Institute\\array_cam\\0.5.0";
string 	   	gAppDataFolder 				= joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppName);
string      gRestartMutexName           = gAppName + "RestartMutex";
HWND        gOtherAppWindow             = NULL;
bool       	gAppIsStartingUp            = true;
bool       	gAppIsClosing	            = false;

void 		setupLogging();
int __stdcall FindOtherWindow(HWND hwnd, LPARAM lParam);

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    //The app mutex is used to check for already running instances
    HANDLE appMutex;

	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		setupLogging();
		TStyleManager::TrySetStyle("Obsidian");

   		// Initialize restart code
		// Check if this instance is restarted and
		// wait while previos instance finish
		if (mtk::checkForCommandLineFlag("--Restart"))
		{
            //TODO: Fix this.. not working properly..
            //            MessageDlg("Wait...", mtWarning, TMsgDlgButtons() << mbOK, 0);
			mtk::WaitForPreviousProcessToFinish(gRestartMutexName);
            Sleep(1000);
		}

        //Look at this later... does not work yet
        const char appMutexName [] = "arrayCamMutex";
        appMutex = ::CreateMutexA(NULL, FALSE, appMutexName);
        if( ERROR_ALREADY_EXISTS == GetLastError() )
        {
             Log(lInfo) << "Arraycam is already running!";
            // Program already running somewhere
            ::EnumWindows(FindOtherWindow, NULL);

            if(gOtherAppWindow != NULL)
            {
                //Send a custom message to restore window here..
                Log(lInfo) << "Arraycam is already running!";
            }
            MessageDlg("Arraycam is already running.\nClose or kill it before starting new instance.", mtWarning, TMsgDlgButtons() << mbOK, 0);

            return(1); // Exit program
        }

        pgDM 	                = new TpgDM(NULL);
        csPGDM                  = new TcsPGDM(NULL);
        PGImagesAndMoviesDM     = new TPGImagesAndMoviesDM(NULL);

		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}

void setupLogging()
{
	//Get Application folder
	string fldr =  joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppName);
	if(!folderExists(fldr))
	{
		createFolder(fldr);
	}

	gLogFileLocation = fldr;

	string fullLogFileName(joinPath(gLogFileLocation, gLogFileName));
	clearFile(fullLogFileName);
	mtk::gLogger.logToFile(fullLogFileName);
    mtk::gLogger.setLogLevel(lDebug5);
	LogOutput::mShowLogLevel = true;
	LogOutput::mShowLogTime = true;
	LogOutput::mUseLogTabs 	= true;
	Log(lInfo) << "Logger was setup";
}

//---------------------------------------------------------------------------
#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "mtkMath.lib")
#pragma comment(lib, "mtkIPC.lib")

#pragma comment(lib, "libmysqlB.lib")

#pragma comment(lib, "poco_mysql_connector-static.lib")
#pragma comment(lib, "poco_sqlite_connector-static.lib")
#pragma comment(lib, "poco_data-static.lib")

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

