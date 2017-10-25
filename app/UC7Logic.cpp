#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "atVCLUtils.h"
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
                    StartStopBtn->Caption = "Start";
                }
                else if(d == "01")
                {
                	Log(lInfo) << "Cutting motor is on";
                    StartStopBtn->Caption = "Stop";
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
                    UC7Shape->Left = 624;
                    UC7Shape->Width = 73;
                }
                else if(d == "01")  //Before cutting
                {
                   	Log(lDebug3) << "Before Cutting";
                   	mUC7.setStrokeState(ssBeforeCutting);
	                mKnifeBeforeCuttingSound.getReference().play();
                    p->Text += "Before Cutting";
                    UC7Shape->Left = 32;
                    UC7Shape->Width = 100;
                }
                else if(d == "03") //Cutting
                {
                   	Log(lDebug3) << "Cutting";
                   	mUC7.getSectionCounter().increase();
                   	mUC7.setStrokeState(ssCutting);
                    mKnifeCuttingSound.getReference().play();
                    p->Text += "Cutting";
                    UC7Shape->Left = 264;
                    UC7Shape->Width = 52;
                }
                else if(d == "02") //After cutting
                {
                   	Log(lDebug3) << "After Cutting";
                   	mUC7.setStrokeState(ssAfterCutting);
					mRibbonOrderCountLabel->update();
	                mKnifeAfterCuttingSound.getReference().play();
                    p->Text += "After Cutting";
                    UC7Shape->Left = 432;
                    UC7Shape->Width = 93;
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

//---------------------------------------------------------------------------
void __fastcall TMainForm::mSynchUIBtnClick(TObject *Sender)
{
    mUC7.getStatus();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mResetCounterBtnClick(TObject *Sender)
{
	TArrayBotButton* btn = dynamic_cast<TArrayBotButton*>(Sender);
    if(btn == mResetCounterBtn)
    {
    	mUC7.getSectionCounter().reset();
        mSectionCounterLabel->update();
    }
    else if(btn == mResetRibbonOrderBtn)
    {
		mUC7.getRibbonOrderCounter().reset();
        mRibbonOrderCountLabel->update();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mConnectUC7BtnClick(TObject *Sender)
{
	if(mConnectUC7Btn->Caption == "Open")
    {
        if(mUC7.connect(getCOMPortNumber()))
        {
            Log(lInfo) << "Connected to a UC7 device";
        }
        else
        {
            Log(lInfo) << "Connection failed";
        }
    }
    else
    {
        if(!mUC7.disConnect())
        {
			Log(lError) << "Failed to close serial port";
        }
    }

    //Give it some time to close down..
    //These should be UC7 callbacks..
    Sleep(100);

    if(mUC7.isConnected())
    {
	    onConnectedToUC7();
    }
    else
    {
		onDisConnectedToUC7();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::onConnectedToUC7()
{
	//Setup callbacks
    mUC7.getSectionCounter().assignOnCountCallBack(onUC7Count);
    mUC7.getSectionCounter().assignOnCountedToCallBack(onUC7CountedTo);
    mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());

	enableDisableUC7UI(true);
	mSynchUIBtnClick(NULL);

  	TStatusPanel* p = mSBManager.getPanel(sbpUC7Connection);
    p->Text = "UC7: Connected";
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::onDisConnectedToUC7()
{
	enableDisableUC7UI(false);
  	TStatusPanel* p = mSBManager.getPanel(sbpUC7Connection);
    p->Text = "UC7: Not Connected";
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::enableDisableUC7UI(bool enableDisable)
{
	//Buttons
    mConnectUC7Btn->Caption                 = enableDisable ? "Close" : "Open";
    mSynchUIBtn->Enabled					= enableDisable;

    //group boxes
	enableDisableGroupBox(CounterGB, 		enableDisable);
//    enableDisableGroupBox(NorthSouthGB,		enableDisable);
    enableDisableGroupBox(UC7OperationGB, 	enableDisable);
    enableDisableGroupBox(CuttingGB, 		enableDisable);
    enableDisableGroupBox(KnifeStageGB,		enableDisable);
}

//---------------------------------------------------------------------------
void TMainForm::onUC7Count()
{
	mSectionCounterLabel->update();
    if(mRibbonCreatorActiveCB->Checked)
    {
    	//Check if we are close to ribbon separation
        if(mSectionCounterLabel->getValue() >= (mCountToE->getValue() - 3))
        {
            mBeforeKnifeBackOffSound.getReference().play();
        }
    }
}

//---------------------------------------------------------------------------
void TMainForm::onUC7CountedTo()
{
	if(mUC7.isActive())
    {
	    mUC7.getSectionCounter().reset();
		Log(lInfo) << "Creating new ribbon";
	    mUC7.prepareToCutRibbon(true);
        //mRibbonStartBtn->Enabled = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateUC7Message(TObject *Sender)
{
	TArrayBotButton* btn = dynamic_cast<TArrayBotButton*>(Sender);

    if(!btn)
    {
    	Log(lError) << "Sender object was NULl!";
    	return;
    }

	if (btn == StartStopBtn)
    {
    	if(StartStopBtn->Caption == "Start")
        {
            mUC7.startCutter();
            mACServer.broadcast(mACServer.IPCCommand(acrUC7Started));
        }
        else
        {
            mUC7.stopCutter();
            mACServer.broadcast(mACServer.IPCCommand(acrUC7Stopped));
        }
    }
    else if(btn == mSetZeroCutBtn)
    {
		mUC7.setFeedRate(0);
    }
    else if(btn == SetPresetFeedBtn)
    {
		mUC7.setFeedRate(mPresetFeedRateE->getValue());
    }

    else if(btn == mRibbonStartBtn)
    {
    	if(btn->Caption == "Back off")
        {
			mUC7.prepareToCutRibbon(true);
            btn->Caption = "Preparing for IDLE";

            //check if this screws up things
			mUC7.setFeedRate(0);
        }
        else
        {
            mUC7.prepareForNewRibbon(true);
            btn->Caption = "Preparing start of Ribbon";
            //btn->Enabled = false;
        }
    }
    else if(btn == mMoveSouthBtn)
    {
   		mUC7.setFeedRate(0);
    	mUC7.jogKnifeStageSouth(BackOffStepFrame->getValue(), true);
    }
    else if(btn == mMoveNorthBtn)
    {
		mUC7.setFeedRate(0);
    	mUC7.jogKnifeStageNorth(BackOffStepFrame->getValue(), true);
    }
//    else if(btn == StopKnifeStageMotionBtn)
//    {
//    	mUC7.stopKnifeStageNSMotion();
//    }

    string msg = mUC7.getLastSentMessage().getMessage();
	Log(lDebug3) << "Sent message: "<<msg;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::uc7EditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	TIntegerLabeledEdit* 	e  = dynamic_cast<TIntegerLabeledEdit*>(Sender);
	TIntegerEdit* 			ie = dynamic_cast<TIntegerEdit*>(Sender);

    if(Key == VK_RETURN)
    {
        if(e == mPresetFeedRateE)
        {
            mUC7.setFeedRatePreset(e->getValue());
        }
        else if(e == mStageMoveDelayE)
        {
            mUC7.setStageMoveDelay(e->getValue());
        }

        else if(e == mFeedRateE)
        {
            //Set feedrate
            mUC7.setFeedRate(e->getValue());

            //This will also change preset feed
            mPresetFeedRateE->setValue(e->getValue());
	        mUC7.setFeedRatePreset(e->getValue());
        }
        else if(ie == MaxStagePosFrame->AbsPosE)
        {
	        MaxStagePosFrame->AbsPosEKeyDown(Sender, Key, Shift);
            mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());
        }
        else if(ie == CurrentStagePosFrame->AbsPosE)
        {
	        CurrentStagePosFrame->AbsPosEKeyDown(Sender, Key, Shift);
            mUC7.moveKnifeStageNSAbsolute(CurrentStagePosFrame->AbsPosE->getValue());
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::KnifePosChange(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    CurrentStagePosFrame->posEdit(Sender, Key, Shift);
		mUC7.moveKnifeStageNSAbsolute(CurrentStagePosFrame->AbsPosE->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::MaxKnifePosKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    MaxStagePosFrame->posEdit(Sender, Key, Shift);
		mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::BackOffStepFrameKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    BackOffStepFrame->posEdit(Sender, Key, Shift);
		mUC7.setKnifeStageJogStepPreset(BackOffStepFrame->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ResumeDeltaDistanceOnKey(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN)
    {
	    ResumeDeltaDistanceFrame->posEdit(Sender, Key, Shift);
		mUC7.setKnifeStageResumeDelta(ResumeDeltaDistanceFrame->AbsPosE->getValue());
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::PopulateMaxNorthPosBtnClick(TObject *Sender)
{
    MaxStagePosFrame->setValue(CurrentStagePosFrame->getValue());
	mUC7.setNorthLimitPosition(MaxStagePosFrame->AbsPosE->getValue());
}

