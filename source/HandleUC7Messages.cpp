#include <vcl.h>
#pragma hdrstop
#include "atVCLUtils.h"
#include "TMainForm.h"
#include "mtkLogger.h"
#include "THandWheelPositionForm.h"
using namespace mtk;

//---------------------------------------------------------------------------
bool TMainForm::handleUC7Message(const UC7Message& m)
{
	//Find out controller address from sender parameter
    int contr_address = toInt(m.getSender());
	switch(contr_address)
    {
        case gStepperControllerAddress:
        {
        	if(m.getCommand() == "20")
            {
				if(m.getData().size() == 8)
                {
                	//This is the absolute, current position of feed controller (the arm)
                	Log(lDebug) << "Handling Feedrate Motor Control Message: "<<m.getData();
                }
            }
            else if(m.getCommand() == "21")
            {
            	Log(lDebug) << "Autosend position at motion:" <<m.getData();
            }
            else if(m.getCommand() == "23") //Feed rate
            {
            	if(m.getData().size() == 6)
                {
	                string feedIn_nm  = m.getData().substr(2);
                    int rate = hexToDec(feedIn_nm);

                    //Transfer hardware data to UC7 'soft' data
                    mUC7.setFeedRate(rate, false);
                    mFeedRateE->setValue(rate);

                   	//mRibbonStartBtn->Enabled = (rate != 0) ? false : true;
                    if(rate)
                    {
                    	mRibbonStartBtn->Caption = "Back off Knife";
                        //mRibbonStartBtn->Enabled = true;
                        mSetZeroCutBtn->Enabled  = true;
                    }
                    else //Feed rate == zero
                    {
                    	mRibbonStartBtn->Caption = "Resume Knife";
                        mSetZeroCutBtn->Enabled  = false;
                    }
                }
            }
            else if(m.getCommand() == "30")
            {
	            //This is info about absolute North_south stage position
            	if(m.getXX() == "FF")
                {
	               string absPos  = m.getData().substr(2);
                   CurrentStagePosFrame->setValue(hexToDec(absPos));
                   mUC7.setNorthSouthStageAbsolutePosition(CurrentStagePosFrame->getValue(), false);

                }
            }
            else if(m.getCommand() == "31")
            {
            	Log(lDebug) << "Send position at movement (North/South)" <<m.getData();
            }
            else if(m.getCommand() == "40")
            {
            	Log(lDebug) << "East/West Motor control" <<m.getData();
            }
            else if(m.getCommand() == "41")
            {
            	Log(lDebug) << "Autosend position at motion (East/West):" <<m.getData();
            }
			else
            {
            	Log(lError) << "Unhandled message:" <<m.getFullMessage();
            }
        }
        break;

		case gMotorControllerAddress:
        {
        	if(m.getCommand() == "20")
            {
            	string d = m.getData().substr(2,2);
                if(d == "00")
                {
                	Log(lInfo) << "Cutting motor is off";
                    mStartStopBtn->Caption = "Start";
                }
                else if(d == "01")
                {
                	Log(lInfo) << "Cutting motor is on";
                    mStartStopBtn->Caption = "Stop";
                }
                else if(d == "E0")
                {
                	Log(lError) << "Invalid calibration";
                }
            }
        	else if(m.getCommand() == "30")
            {
               	Log(lInfo) << "Cutting speed.. unhandled message";
            }
        	else if(m.getCommand() == "31")
            {
               	Log(lInfo) << "Return speed.. unhandled message";
            }
        	else if(m.getCommand() == "40")
            {
            	TStatusPanel* p = mSBManager.getPanel(sbpHandWheelPosition);
                p->Text = "Wheel Position: ";
            	string d = m.getData().substr(2,2);
                if(d == "00")  //Retract
                {
                	Log(lDebug3) << "Retracting";
                	mUC7.setStrokeState(ssRetracting);
					mArmRetractingSound.getReference().play();
                    p->Text += "Retracting";
                }
                else if(d == "01")  //Before cutting
                {
                   	Log(lDebug3) << "Before Cutting";
                   	mUC7.setStrokeState(ssBeforeCutting);
	                mKnifeBeforeCuttingSound.getReference().play();
                    p->Text += "Before Cutting";
                }
                else if(d == "03") //Cutting
                {
                   	Log(lDebug3) << "Cutting";
                   	mUC7.getSectionCounter().increase();
                   	mUC7.setStrokeState(ssCutting);
                    mKnifeCuttingSound.getReference().play();
                    p->Text += "Cutting";
                }
                else if(d == "02") //After cutting
                {
                   	Log(lDebug3) << "After Cutting";
                   	mUC7.setStrokeState(ssAfterCutting);
					mRibbonOrderCountLabel->update();
	                mKnifeAfterCuttingSound.getReference().play();
                    p->Text += "After Cutting";
                }
                else if(d == "E0")
                {
                   	mUC7.setStrokeState(ssUndefined);
                }

               	if(mHandWheelPositionForm)
			    {
					mHandWheelPositionForm->plot();
                }

            }
            else
            {
            	Log(lError) << "Unhandled message:" <<m.getFullMessage();
            }
        }
        break;

        case gSystemCommands:
        {
        	string cmd = m.getCommand();
        	if(cmd == "F0")
            {
               	Log(lInfo) << "Software Reset!";
            }
            else if(cmd == "F1")
            {
               	Log(lInfo) << "Getting part ID data: "<<m.getData();
            }
            else if(cmd == "F2")
            {
               	Log(lInfo) << "Logging in";
            }
            else if(cmd == "F3")
            {
            	Log(lError) << "There was a Command/Transmission Error. Data: "<<m.getData();
            }
            else if(cmd == "F5")
            {
               	Log(lInfo) << "Getting version data: "<<m.getData();
            }
        }
		break;

        default:   return false;
    }

    return true;
}

