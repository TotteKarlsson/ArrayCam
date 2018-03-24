#pragma hdrstop
#include "ArrayCamUtilities.h"
#include "dslUtils.h"
#include "dslLogger.h"
#include "atExceptions.h"
#include "dslWin32Utils.h"
using namespace dsl;

int __stdcall FindOtherWindow(HWND hwnd, LPARAM lParam);

extern ArrayCamUtilities acu;
//---------------------------------------------------------------------------
ApplicationUtilities::ApplicationUtilities(const string& appName, const string& regRoot, const string& appVersion)
:
AppMutex(NULL),
AppName(appName),
AppVersion(appVersion),
AppRegistryRoot(joinPath(regRoot, appVersion)),
LogFileName(AppName + ".log"),
AppDataFolder(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), AppName)),
LogFileLocation(AppDataFolder),
RestartMutexName(AppName + "RestartMutex"),
OtherAppWindow(NULL),
AppIsStartingUp(true),
AppIsClosing(false)
{
}

void ApplicationUtilities::init()
{
    string appMutexName = string(AppName + "Mutex").c_str();
    AppMutex = ::CreateMutexA(NULL, FALSE, appMutexName.c_str());
    if(GetLastError() == ERROR_ALREADY_EXISTS)
    {
    	throw(ATException("Application \"" + AppName + "\" is already running!"));
    }

    setupLogging();
}

bool ApplicationUtilities::setupLogging()
{
	if(!folderExists(LogFileLocation))
	{
		createFolder(LogFileLocation);
	}

	string fullLogFileName(joinPath(LogFileLocation, LogFileName));
	clearFile(fullLogFileName);
	dsl::gLogger.logToFile(fullLogFileName);
    dsl::gLogger.setLogLevel(lDebug5);
	LogOutput::mShowLogLevel = true;
	LogOutput::mShowLogTime = true;
	LogOutput::mUseLogTabs 	= true;
	Log(lInfo) << "Logger was setup";
    return true;
}

///////////////////////////////////////////////////////////////////////////////

ArrayCamUtilities::ArrayCamUtilities()
:
ApplicationUtilities("ArrayCam", "\\Software\\Allen Institute\\array_cam", "0.5.0")
{
}

///////////////////////////////////////////////////////////////////////////////
int __stdcall FindOtherWindow(HWND hwnd, LPARAM lParam)
{
	int length = ::GetWindowTextLength(hwnd);
	if(!length)
    {
	    return TRUE;
    }

	vector<TCHAR> buffer(length + 1);
	GetWindowText(hwnd, &buffer[0], length + 1);

    string s(stdstr(buffer));
	if(startsWith(acu.AppName, s))
	{
		// do something with hwnd here
		acu.OtherAppWindow = hwnd;
        SetFocus(hwnd);

        //Stop enumerating..
		return false;
	}

	return true;
}



