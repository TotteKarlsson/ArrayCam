#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
void  TMainForm::onNavitarConnected()
{
	NavitarControllerConnectBtn->Caption         = "Disconnect";
    ProdIdLbl->Caption 	        = vclstr(mNavitarMotorController.getProductID());
	HWVerLbl->Caption           = vclstr(mNavitarMotorController.getHardwareVersion());
   	SWVerLbl->Caption           = vclstr(mNavitarMotorController.getSoftwareVersion());
    FirmWareDateLbl->Caption   	= vclstr(mNavitarMotorController.getDriverSoftwareBuildDate());

    TNavitarMotorFrame1->populate(mNavitarMotorController.getZoom());
    TNavitarMotorFrame2->populate(mNavitarMotorController.getFocus());
    enableDisableGroupBox(ControllerInfoGB, true);
}

void  TMainForm::onNavitarDisconnected()
{
	NavitarControllerConnectBtn->Caption = "Connect";
    ProdIdLbl->Caption 	        = "N/A";
	HWVerLbl->Caption           = "N/A";
   	SWVerLbl->Caption           = "N/A";
    FirmWareDateLbl->Caption   	= "N/A";

    enableDisableGroupBox(ControllerInfoGB, false);

    TNavitarMotorFrame1->dePopulate();
    TNavitarMotorFrame2->dePopulate();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::NavitarControllerConnectBtnClick(TObject *Sender)
{
	TButton* b = dynamic_cast<TButton*>(Sender);

    if(b == NavitarControllerConnectBtn)
    {
        if(!mNavitarMotorController.isConnected())
        {
            if(mNavitarMotorController.connect())
            {
            	onNavitarConnected();
            }
        }
        else
        {
            if(mNavitarMotorController.disConnect())
            {
            	onNavitarDisconnected();
            }
        }
    }
}

