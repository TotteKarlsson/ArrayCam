#ifndef TImagesFrameH
#define TImagesFrameH
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
class TImageItemFrame;

//---------------------------------------------------------------------------
class TImagesFrame : public TFrame
{
    __published:	// IDE-managed Components
        TPanel *Panel22;
        TLabel *Label4;
        TIntLabel *NrOfRecordsLbl;
        TScrollBox *ScrollBox2;
        TFlowPanel *FlowPanel1;
		TSQLQuery *GetImagesQuery;

    private:
		StringList				fetchRecords();
		void			        clearItemFrames();
        int						mBlockID;

    public:
                __fastcall 			TImagesFrame(TComponent* Owner);
        void						populate(int blockID, Poco::Path& mediaPath);
		list<TImageItemFrame*>      mItems;
};

extern PACKAGE TImagesFrame *ImagesFrame;

#endif
