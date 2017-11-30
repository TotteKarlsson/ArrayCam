#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void MouseClick(int x, int y);

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        Close();
    }
}



//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	HWND phwnd = GetForegroundWindow();

    HWND ButtonHandle;
    HWND hwnd;
    if( (hwnd = FindWindow(0, L"ELLO")) )
    {
        ShowWindow(hwnd, SW_RESTORE);
        RECT rect;
        GetWindowRect(hwnd, &rect);
        SetForegroundWindow(hwnd);
        MouseClick(rect.left + ClickX->getValue(), rect.top + ClickY->getValue() + 30);
        ShowWindow(hwnd, SW_SHOWMINIMIZED);

    }
	SetForegroundWindow(phwnd); // To activate previous window
}


void MouseClick(int x, int y)
{
    const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
    const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

    POINT cursorPos;
    GetCursorPos(&cursorPos);

    double cx = cursorPos.x * XSCALEFACTOR;
    double cy = cursorPos.y * YSCALEFACTOR;

    double nx = x * XSCALEFACTOR;
    double ny = y * YSCALEFACTOR;

    INPUT Input={0};
    Input.type = INPUT_MOUSE;

    Input.mi.dx = (LONG)nx;
    Input.mi.dy = (LONG)ny;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    SendInput(1,&Input,sizeof(INPUT));

    Input.mi.dx = (LONG)cx;
    Input.mi.dy = (LONG)cy;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Sleep(100);
    SendInput(1,&Input,sizeof(INPUT));
}


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    HWND hwnd;
    if( (hwnd = FindWindow(0, L"ELLO")) )
    {
	    POINT p;
		if (GetCursorPos(&p))
        {
        	if (::ScreenToClient(hwnd, &p))
			{
			    //p.x and p.y are now relative to hwnd's client area
		        winXLbl->Caption = "X = " + IntToStr((int) p.x);
		        winYLbl->Caption = "Y = " + IntToStr((int) p.y);
			}
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

