#ifndef ArrayCamUtilsH
#define ArrayCamUtilsH
#include <string>
//---------------------------------------------------------------------------
using std::string;

int 	getArrayCamIPCMessageID(const string& msg);
string  getArrayCamIPCMessageName(int cs);

enum ARRAYCAM_IPC_ID
{
        cStartRecordingVideo   	= 100,
        cStopRecordingVideo   	= 101,
        cTakeSnapShot		 	= 102
};

#endif
