#include <vcl.h>
#pragma hdrstop
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "database/atDBUtils.h"
#include "vcl/atVCLUtils.h"
#include "database/atDBUtils.h"
#include "Poco/Data/RecordSet.h"
using namespace at;

//---------------------------------------------------------------------------
void __fastcall TMainForm::mAddImageFileBtnClick(TObject *Sender)
{
	TButton* b = dynamic_cast<TButton*>(Sender);

    if(b == mAddImageFileBtn)
    {
		//Browse for file
        string f = browseForFile(mSnapShotFolder);
        if(!f.size())
        {
            return;
        }

        //Add this file to DB and open a metadata entry form for the user
        try
        {
            mClientDBSession.insertImageFile(getFileNameNoPath(f), getCurrentUserID(mUsersCB), "Note..");
            DBNavigator1->BtnClick(nbRefresh);
            DBNavigator1->BtnClick(nbRefresh);
        }
        catch(...)
        {
            handleSQLiteException();
        }
    }
}

void __fastcall TMainForm::DBMemo1Change(TObject *Sender)
{
	//Enable update button
    mUpdateNoteBtn->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mUpdateNoteBtnClick(TObject *Sender)
{
	//Apply and post updates to database
	ImagesAndMoviesDM->notesCDS->ApplyUpdates(-1);
    mUpdateNoteBtn->Enabled = false;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::DBNavigator2Click(TObject *Sender, TNavigateBtn Button)
{
	switch(Button)
    {
    	case TNavigateBtn::nbInsert:
			{
                int uID = getCurrentUserID(mUsersCB);
                int imageID = ImagesAndMoviesDM->imagesCDSid->Value;
                string note("Image Note..");
                try
                {
                    mClientDBSession.insertImageNote(imageID, uID, note);
                }
                catch(...)
                {
                    handleMySQLException();
                }

                ImagesAndMoviesDM->imageNoteCDS->Refresh();
                ImagesAndMoviesDM->imageNoteCDS->Last();
            }
    }
}

void __fastcall TMainForm::DBNavigator2BeforeAction(TObject *Sender, TNavigateBtn Button)
{
	if(Button == nbInsert)
    {    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mNewNoteBtnClick(TObject *Sender)
{
    int imageID = ImagesAndMoviesDM->imagesCDS->Fields->FieldByName("id")->Value;
    Log(lInfo) <<"Current image note ID: "<<imageID;

	TButton* b = dynamic_cast<TButton*>(Sender);

	try
    {
//        if(b == mNewNoteBtn)
//        {
//        	int userID = getCurrentUserID(mUsersCB);
//            ImagesAndMoviesDM->notesCDS->Active = false;
//            mClientDBSession.insertImageNote(imageID, userID, "New note..");
//            ImagesAndMoviesDM->notesCDS->Active = true;
//            ImagesAndMoviesDM->notesCDS->Refresh();
//        }
//        else if(b == mDeleteNoteBtn)
//        {
//            int noteID = ImagesAndMoviesDM->notesCDS->Fields->FieldByName("id")->Value;
//            Log(lInfo) << "Removing image note with ID: "<<noteID;
//            ImagesAndMoviesDM->notesCDS->Active = false;
//            mClientDBSession.deleteNoteWithID(noteID);
//            ImagesAndMoviesDM->notesCDS->Active = true;
//            ImagesAndMoviesDM->notesCDS->Refresh();
//        }
    }
    catch(...)
    {
    	handleSQLiteException();
    }

}

void __fastcall TMainForm::DBMemo1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	mUpdateNoteBtn->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mImagesGridCellClick(TColumn *Column)
{
	loadCurrentImage();
}

void TMainForm::populateUsers()
{
    try
    {
    	populateUsersCB(mUsersCB, mClientDBSession);
    }
    catch(...)
    {
    	handleMySQLException();
    }
}

void __fastcall TMainForm::mImagesGridDblClick(TObject *Sender)
{
//    //Check if we have a valid file
//    string fName = stdstr(lb->Items->Strings[lb->ItemIndex]);
//    string fldr =  mSnapShotFolder;
//
//    fName = joinPath(fldr, fName);
//    if(fileExists(fName))
//    {
//        ShellExecuteA(NULL, NULL, stdstr(fName).c_str(), 0, 0, SW_SHOWNA);
//    }
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	ImagesAndMoviesDM->sensorsCDS->Active = false;
   	ImagesAndMoviesDM->sensorsCDS->Active = true;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mMoviesLBDblClick(TObject *Sender)
{
//	TListBox* lb = dynamic_cast<TListBox*>(Sender);
//    if(lb == mMoviesLB)
//    {
//        //Check if we have a valid file
//        string fName = stdstr(lb->Items->Strings[lb->ItemIndex]);
//        string fldr =  mMoviesFolder;
//
//        fName = joinPath(fldr, fName);
//        if(fileExists(fName))
//        {
//            ShellExecuteA(NULL, NULL, stdstr(fName).c_str(), 0, 0, SW_SHOWNA);
//        }
//    }
//    else if (lb == mShotsLB)
//    {
//        //Check if we have a valid file
//        string fName = stdstr(lb->Items->Strings[lb->ItemIndex]);
//        string fldr =  mSnapShotFolder;
//
//        fName = joinPath(fldr, fName);
//        if(fileExists(fName))
//        {
//            ShellExecuteA(NULL, NULL, stdstr(fName).c_str(), 0, 0, SW_SHOWNA);
//        }
//    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::Delete1Click(TObject *Sender)
{
//    TListBox* lb = dynamic_cast<TListBox*>(mMediaPopup->PopupComponent);
//
//   	if(lb && lb->ItemIndex == -1)
//    {
//		return;
//    }
//
//    if(lb == mMoviesLB)
//    {
//        //Delete current selected item
//        string fName = stdstr(lb->Items->Strings[lb->ItemIndex]);
//        string fldr  = mMoviesFolder;
//
//        fName = joinPath(fldr, fName);
//        if(fileExists(fName))
//        {
//            removeFile(fName);
//            updateVideoFileLB();
//        }
//    }
//    else if (lb == mShotsLB)
//    {
//        //Delete current selected item
//        string fName = stdstr(lb->Items->Strings[lb->ItemIndex]);
//        string fldr =  mSnapShotFolder;
//
//        fName = joinPath(fldr, fName);
//        if(fileExists(fName))
//        {
//            removeFile(fName);
//            updateShotsLB();
//        }
//    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteAll1Click(TObject *Sender)
{
//    TListBox* lb = dynamic_cast<TListBox*>(mMediaPopup->PopupComponent);
//
//   	if(lb && lb->ItemIndex == -1)
//    {
//		return;
//    }
//
//    if(lb == mMoviesLB)
//    {
//        while(lb->Count)
//        {
//            string fName = stdstr(lb->Items->Strings[0]);
//            string fldr =  mMoviesFolder;
//            fName = joinPath(fldr, fName);
//            if(fileExists(fName))
//            {
//                removeFile(fName);
//                updateVideoFileLB();
//            }
//        }
//    }
//    else if (lb == mShotsLB)
//    {
//        while(lb->Count)
//        {
//            string fName = stdstr(lb->Items->Strings[0]);
//            string fldr =  mSnapShotFolder;
//            fName = joinPath(fldr, fName);
//            if(fileExists(fName))
//            {
//                removeFile(fName);
//                updateShotsLB();
//            }
//        }
//    }
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::mATDBServerBtnConnectClick(TObject *Sender)
{
	if(ImagesAndMoviesDM->SQLConnection1->Connected)
    {
	    ImagesAndMoviesDM->SQLConnection1->Connected = false;
	    ImagesAndMoviesDM->SQLConnection1->Close();
    }
    else
    {
	    ImagesAndMoviesDM->connect("atdb", "atdb_client", "atdb123", "umlocal");
    }
}

void __fastcall	TMainForm::afterServerConnect(System::TObject* Sender)
{
	ImagesAndMoviesDM->afterConnect();
    enableDisableGroupBox(mATDBServerGB, true);
    mATDBServerBtnConnect->Caption = "Disconnect";
}

void __fastcall	TMainForm::afterServerDisconnect(System::TObject* Sender)
{
	ImagesAndMoviesDM->afterDisConnect();
    enableDisableGroupBox(mATDBServerGB, false);
    mATDBServerBtnConnect->Caption = "Connect";
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::mSyncUsersBtnClick(TObject *Sender)
{
	//Get users from server
    try
    {
        Poco::ScopedLock<Poco::Mutex> lock(mClientDBMutex);
        RecordSet* localUsers 	= mClientDBSession.getUsers();
	    RecordSet* remoteUsers 	= mServerDBSession.getUsers();

        if(!localUsers || !remoteUsers)
		{
        	Log(lError) << "Failed to fetch users from database";
            return;
        }

		//Insert ot Update users
        for (RecordSet::Iterator it = remoteUsers->begin(); it != remoteUsers->end(); ++it)
        {
        	Poco::Data::Row& row = *it;
            int id(row[0].convert<int>());
            string user(row[1].convert<std::string>());
            Log(lInfo) <<user;
			mClientDBSession.insertOrUpdateUser(id, user);
        }
		populateUsers();
    }
    catch(...)
    {
    	handleMySQLException();
    }
}

void __fastcall TMainForm::mImagesGridKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	loadCurrentImage();
}
