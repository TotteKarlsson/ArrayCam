#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include "TMainForm.h"
#include "TLoggerForm.h"
#include "ArrayCamUtilities.h"

#include "core/ATExceptions.h"
//---------------------------------------------------------------------------
USEFORM("TMainForm.cpp", MainForm);
USEFORM("forms\TLoggerForm.cpp", LoggerForm);
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

		Application->CreateForm(__classid(TMainForm), &MainForm);
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

