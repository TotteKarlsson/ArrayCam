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
using std::string;
using namespace mtk;

USEFORM("TSettingsForm.cpp", SettingsForm);
USEFORM("P:\libs\atapi\source\vcl\datamodules\TATDBImagesAndMoviesDataModule.cpp", ImagesAndMoviesDM); /* TDataModule: File Type */
USEFORM("P:\libs\atapi\source\vcl\frames\TATDBConnectionFrame.cpp", ATDBConnectionFrame); /* TFrame: File Type */
USEFORM("P:\libs\atapi\source\vcl\datamodules\TATDBDataModule.cpp", atdbDM); /* TDataModule: File Type */
//---------------------------------------------------------------------------
extern string       gLogFileLocation            = "";
extern string		gAppName					= "ArrayCam";
extern string       gLogFileName                = gAppName + ".log";
extern string 		gApplicationRegistryRoot  	= "\\Software\\Allen Institute\\array_cam\\0.5.0";
extern string 		gAppDataFolder 				= joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppName);
extern bool         gAppIsStartingUp            = true;
extern bool         gAppIsClosing	            = false;
void setupLogging();

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		setupLogging();
		TStyleManager::TrySetStyle("Obsidian");
		Application->CreateForm(__classid(TatdbDM), &atdbDM);
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
#if defined DSL_STATIC
	#pragma comment(lib, "mtkCommon-static.lib")
	#pragma comment(lib, "mtkMath-static.lib")
	#pragma comment(lib, "mtkIPC-static.lib")
#else
	#pragma comment(lib, "mtkCommon.lib")
	#pragma comment(lib, "mtkMath.lib")
	#pragma comment(lib, "mtkIPC.lib")
#endif


//#pragma comment(lib, "SQLite-static.lib")
#pragma comment(lib, "libmysqlB.lib")

#pragma comment(lib, "poco_mysql_connector-static.lib")
#pragma comment(lib, "poco_sqlite_connector-static.lib")
#pragma comment(lib, "poco_data-static.lib")

#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atDataBase.lib")
#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "uc480_B.lib")
#pragma comment(lib, "uc480_tools_B.lib")

#pragma comment(lib, "atVCLCore.bpi")
#pragma comment(lib, "VCLCommon.bpi")
#pragma comment(lib, "DuneForms.bpi")
