//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <string>
#include "mtkLogger.h"
#include "mtkVCLUtils.h"

USEFORM("TMainForm.cpp", MainForm);
USEFORM("..\..\source\frames\TFFMPEGFrame.cpp", FFMPEGFrame); /* TFrame: File Type */
USEFORM("..\..\source\frames\TFFMPEGOutputFrame.cpp", FFMPEGOutputFrame); /* TFrame: File Type */
//---------------------------------------------------------------------------
using namespace mtk;
using namespace std;

extern string       gLogFileLocation            = "";
extern string		gAppExeName					= "VideoCompressor";
extern string       gLogFileName                = gAppExeName + ".log";
extern string 		gApplicationRegistryRoot  	= "\\Software\\Allen Institute\\VideoCompressor\\0.5.0";
extern string 		gAppDataFolder 				= joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppExeName);
extern string       gCommonAppDataLocation      = "";
void setupLogging();
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
        setupLogging();
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
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
	string fldr =  joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppExeName);
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


#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "mtkMath.lib")
#pragma comment(lib, "mtkIPC.lib")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "VCLCommon.bpi")
