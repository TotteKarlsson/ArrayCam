#include <System.hpp>
#pragma hdrstop
USEFORM("forms\TSelectIntegerForm.cpp", SelectIntegerForm);
USEFORM("forms\TReticlePopupForm.cpp", ReticlePopupForm);
USEFORM("frames\TUC7StagePositionFrame.cpp", UC7StagePositionFrame); /* TFrame: File Type */
USEFORM("forms\TSettingsForm.cpp", SettingsForm);
USEFORM("forms\TAboutForm.cpp", AboutForm);
USEFORM("forms\THandWheelPositionForm.cpp", HandWheelPositionForm);
USEFORM("forms\TActionsForm.cpp", ActionsForm);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "mtkMath.lib")
#pragma comment(lib, "mtkIPC.lib")
#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atUC7API.lib")
#pragma comment(lib, "atDataBase.lib")
#pragma comment(lib, "atResources.lib")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

#pragma comment(lib, "VCLCommon.bpi")
#pragma comment(lib, "DuneForms.bpi")
#pragma comment(lib, "DuneComponents.bpi")
#pragma comment(lib, "atVCLCore.bpi")

#pragma comment(lib, "BindEngine.bpi")
#pragma comment(lib, "BindComp.bpi")
#pragma comment(lib, "BindCompVCL.bpi")

#pragma comment(lib, "uc480_B.lib")
#pragma comment(lib, "uc480_tools_B.lib")
#pragma comment(lib, "DBXDevartPostgreSQLDriver170.bpi")

