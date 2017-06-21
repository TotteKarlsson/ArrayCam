#include <System.hpp>
#pragma hdrstop
USEFORM("frames\TUC7StagePositionFrame.cpp", UC7StagePositionFrame); /* TFrame: File Type */
USEFORM("forms\TSelectIntegerForm.cpp", SelectIntegerForm);
USEFORM("forms\TReticlePopupForm.cpp", ReticlePopupForm);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#pragma argsused

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}


#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "atCore.lib")
#pragma comment(lib, "atDataBase.lib")
#pragma comment(lib, "atResources.lib")
#pragma comment(lib, "atArrayBotCore.lib")

#pragma comment(lib, "libmysqlB.lib")
#pragma comment(lib, "poco_mysql_connector-static.lib")
#pragma comment(lib, "poco_sqlite_connector-static.lib")
#pragma comment(lib, "poco_data-static.lib")

#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "tinyxml2-static.lib")

#pragma comment(lib, "DuneComponents.bpi")
#pragma comment(lib, "atVCLCore.bpi")
#pragma comment(lib, "DbxDevartSQLiteDriver170.bpi")
#pragma comment(lib, "DbxMySQlDriver.bpi")
#pragma comment(lib, "DbxMySQlDriver.bpi")
#pragma comment(lib, "BindEngine.bpi")
#pragma comment(lib, "BindComp.bpi")
#pragma comment(lib, "BindCompVCL.bpi")



