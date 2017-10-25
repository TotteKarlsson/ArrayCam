#pragma hdrstop
#include "ArrayCamUtils.h"
#include "mtkUtils.h"
#include "mtkIPCMessageEnums.h"
//---------------------------------------------------------------------------
using namespace mtk;

//---------------------------------------------------------------------------
int getArrayCamIPCMessageID(const string& cs)
{
    if(compareStrings(cs, "START_RECORDING_VIDEO",  csCaseInsensitive))    return cStartRecordingVideo;
    if(compareStrings(cs, "STOP_RECORDING_VIDEO",   csCaseInsensitive))    return cStopRecordingVideo;
    return getIPCMessageID(cs);
}

//---------------------------------------------------------------------------
string getArrayCamIPCMessageName(int cs)
{
    switch (cs)
    {
        case cStartRecordingVideo:	  				return  "START_RECORDING_VIDEO";
        case cStopRecordingVideo:    				return  "STOP_RECORDING_VIDEO";
        default: return getIPCMessageName(cs);
    }
}

