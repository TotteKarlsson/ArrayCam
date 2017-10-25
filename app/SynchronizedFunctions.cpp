#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "vcl/atVCLUtils.h"
#include "mtkStringList.h"

using namespace mtk;
//using namespace at;

class TLocalArgs
{
    public:
    	string msg;

    void __fastcall onLightsArduinoMessage()
    {
        //If mouse is down.. do not update certain UI objects
        bool isMouseBtnDown = (bool) GetAsyncKeyState(VK_LBUTTON);

        if(startsWith("AB_LIGHTS_DATA", msg) && isMouseBtnDown == false)
        {
            StringList l(msg,',');
            if(l.size() == 3)
            {
            	StringList val(l[1], '=');
                MainForm->FrontLEDTB->Tag = 1;
                MainForm->FrontLEDTB->Position = toInt(val[1]);
                MainForm->FrontLEDTB->Tag = 0;
            }
        }

        else if(startsWith("DHT22_DATA", msg))
        {
            //Parse the message
            StringList l(msg,',');
            if(l.size() == 4)
            {
                //Fourth parameter is sensor number
                int sensorNum = toInt(l[3]);

                MainForm->mEnvReader.addReading(toDouble(l[1]), toDouble(l[2]), toInt(l[3]));

                //Get average when it makes sense
                if(MainForm->mEnvReader.getNumberOfReadings() == MainForm->mEnvReader.getNumberOfSensors())
                {
                    MainForm->updateTemperature(MainForm->mEnvReader.getAverageTemperature());
					MainForm->updateHumidity(MainForm->mEnvReader.getAverageHumidity());

                    //Purge reader
                    MainForm->mEnvReader.purge();
                }
            }
        }
    }
};


void TMainForm::onLightsArduinoMessageReceived(const string& msg)
{
    TLocalArgs args;
    args.msg = msg;

    //This causes this fucntion to be called in the UI thread
	TThread::Synchronize(NULL, &args.onLightsArduinoMessage);
}



