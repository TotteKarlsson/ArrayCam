#include <vcl.h>
#pragma hdrstop
#include "TMoviesFrame.h"
#include "Poco/File.h"
#include "frames/TMovieItemFrame.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TIntLabel"
#pragma resource "*.dfm"
TMoviesFrame *MoviesFrame;
using namespace mtk;


//---------------------------------------------------------------------------
__fastcall TMoviesFrame::TMoviesFrame(TComponent* Owner)
	: TFrame(Owner),
    mBlockID(0)
{
}

void TMoviesFrame::populate(int blockID, Poco::Path& mediaPath)
{
	try
    {
		GetMoviesQuery->Open();
	    StringList l = fetchRecords();
        clearMovieFrames();
        if(l.count())
        {
            ScrollBox2->VertScrollBar->Visible = false;
        }

        //Current block nr


        //Create path
        Poco::Path p(mediaPath);
        p.append("Movies");
        p.append(mtk::toString(blockID));
        Log(lDebug) << "Looking for movies in folder: " << p.toString();

        for(int i = 0; i < l.count(); i++)
        {
            StringList item(l[i], ',');
            if(item.count() == 2)
            {
                Poco::File f(Poco::Path(p, item[1]));

                TMovieItemFrame* frame = new TMovieItemFrame(f,this);
                frame->Visible = false;
                frame->MovieLbl->Caption = item[0].c_str();
                mMovies.push_back(frame);
            }
            else
            {
                Log(lError) << "Bad movie record..";
            }
        }

        list<TMovieItemFrame*>::iterator i = mMovies.begin();
        while(i != mMovies.end())
        {
            (*i)->Parent = FlowPanel1;;
            (*i)->Visible = true;
            i++;
        }

        ScrollBox2->VertScrollBar->Visible = true;
        NrOfRecordsLbl->setValue(l.count());
    }
    catch(...)
    {
    	Log(lError) << "There was a problem...";
    }
}

StringList TMoviesFrame::fetchRecords()
{
	StringList records;
    while(!GetMoviesQuery->Eof)
    {
		stringstream rec;
        rec <<stdstr(GetMoviesQuery->FieldByName("created")->AsString) <<"," <<stdstr(GetMoviesQuery->FieldByName("id")->AsString) <<".mp4";
        records.append(rec.str());
        Log(lDebug4) << "Got record: "<< stdstr(GetMoviesQuery->FieldByName("id")->AsString) << " at " << stdstr(GetMoviesQuery->FieldByName("created")->AsString);
        GetMoviesQuery->Next();
    }

	return records;
}

void TMoviesFrame::clearMovieFrames()
{
	list<TMovieItemFrame*>::iterator i = mMovies.begin();
    while(i != mMovies.end())
    {
    	delete (*i);
    	mMovies.erase(i++);
    }
}

