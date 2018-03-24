#include <System.hpp>
#pragma hdrstop
USEFORM("frames\TUC7StagePositionFrame.cpp", UC7StagePositionFrame); /* TFrame: File Type */
USEFORM("forms\TReticlePopupForm.cpp", ReticlePopupForm);
USEFORM("forms\TSelectIntegerForm.cpp", SelectIntegerForm);
USEFORM("forms\TSettingsForm.cpp", SettingsForm);
USEFORM("forms\THandWheelPositionForm.cpp", HandWheelPositionForm);
USEFORM("forms\TAboutForm.cpp", AboutForm);
USEFORM("forms\TActionsForm.cpp", ActionsForm);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

#pragma comment(lib, "dslFoundation.lib")

#pragma comment(lib, "dslVCLCommon.lib")
#pragma comment(lib, "dslVCLComponents.bpi")
#pragma comment(lib, "dslVisuals.bpi")

#pragma comment(lib, "atVCLCommon.lib")
#pragma comment(lib, "atFoundation.lib")
#pragma comment(lib, "atComponents.bpi")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")
//
//#pragma comment(lib, "BindEngine.bpi")
//#pragma comment(lib, "BindComp.bpi")
//#pragma comment(lib, "BindCompVCL.bpi")
//
//#pragma comment(lib, "uc480_B.lib")
//#pragma comment(lib, "uc480_tools_B.lib")
//#pragma comment(lib, "DBXDevartPostgreSQLDriver250.bpi")
//#pragma comment(lib, "DBXMySQLDriver.bpi")

