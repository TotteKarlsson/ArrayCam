#ifndef TMoviesFrameH
#define TMoviesFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntLabel.h"
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "mtkStringList.h"
#include <list>
#include "Poco/Path.h"
using mtk::StringList;
using std::list;
class TMovieItemFrame;

//---------------------------------------------------------------------------
class TMoviesFrame : public TFrame
{
    __published:	// IDE-managed Components
        TPanel *Panel22;
        TLabel *Label4;
        TIntLabel *NrOfRecordsLbl;
        TScrollBox *ScrollBox2;
        TFlowPanel *FlowPanel1;
        TSQLQuery *GetMoviesQuery;

    private:
		StringList				fetchRecords();
		void			        clearMovieFrames();
        int						mBlockID;

    public:
                __fastcall 			TMoviesFrame(TComponent* Owner);
        void						populate(int blockID, Poco::Path& mediaPath);
		list<TMovieItemFrame*>      mMovies;
};

extern PACKAGE TMoviesFrame *MoviesFrame;

#endif
