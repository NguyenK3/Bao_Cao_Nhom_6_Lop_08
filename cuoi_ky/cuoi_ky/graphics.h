#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <math.h>
#include <windows.h>
#include <Windows.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

HPEN  getPen(int iPEN_STYLE, int iPEN_SIZE, int iCOLORREF);
BOOL  SetPoint(HDC hDC, HPEN hPen, COORD PNT);
BOOL  PlotLine(HDC hDC, HPEN hPen, COORD BGN, COORD END);
BOOL  PlotRect(HDC hDC, HPEN hPen, COORD BGN, COORD END);
BOOL  PlotCirc(HDC hDC, HPEN hPen, COORD BGN, COORD END);
COORD setCordScale(COORD POS, RECT pRECT);

HDC hDC;
HPEN PEN;
HANDLE StdOut;
WORD COLOR;
COORD BGN, POS;

short mov;
short movx;

void initgraph(void)
{
	system("cls");
	mov = 30;
	movx = 0;
	HWND hWnd = GetForegroundWindow();
	RECT    pRECT = { 0 };
	COORD   POS1 = { 0 };
	COORD   BGN1 = setCordScale(POS1, pRECT);
	GetWindowRect(hWnd, &pRECT);
	hDC = GetWindowDC(hWnd);
	PEN = getPen(PS_SOLID, 2, RGB(255, 255, 255));
	StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void changey(int value) { if (value > -1000 & value < 1000) mov = (short)value; }
void changex(int value) { if (value > -1000 & value < 1000) movx = (short)value; }
int getmaxx(void) { return 640; }
int getmaxy(void) { return 300; }
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void setcolorRGB(int r, int g, int b)
{
	PEN = getPen(PS_SOLID, 2, RGB(r, g, b));
}
void setcolor(int color)
{
	if (color < 0) color = -color;
	if (color > 15) color %= 16;
	switch (color)
	{
	case 0: PEN = getPen(PS_SOLID, 2, RGB(0, 0, 0)); break;
	case 1: PEN = getPen(PS_SOLID, 2, RGB(0, 0, 128)); break;
	case 2: PEN = getPen(PS_SOLID, 2, RGB(0, 128, 0)); break;
	case 3: PEN = getPen(PS_SOLID, 2, RGB(128, 0, 0)); break;
	case 4: PEN = getPen(PS_SOLID, 2, RGB(0, 128, 128)); break;
	case 5: PEN = getPen(PS_SOLID, 2, RGB(128, 0, 128)); break;
	case 6: PEN = getPen(PS_SOLID, 2, RGB(128, 128, 0)); break;
	case 7: PEN = getPen(PS_SOLID, 2, RGB(0, 0, 255)); break;
	case 8: PEN = getPen(PS_SOLID, 2, RGB(0, 255, 0)); break;
	case 9: PEN = getPen(PS_SOLID, 2, RGB(255, 0, 0)); break;
	case 10: PEN = getPen(PS_SOLID, 2, RGB(0, 255, 255)); break;
	case 11: PEN = getPen(PS_SOLID, 2, RGB(255, 0, 255)); break;
	case 12: PEN = getPen(PS_SOLID, 2, RGB(255, 255, 0)); break;
	case 13: PEN = getPen(PS_SOLID, 2, RGB(192, 192, 192)); break;
	case 14: PEN = getPen(PS_SOLID, 2, RGB(192, 192, 192)); break;
	case 15: PEN = getPen(PS_SOLID, 2, RGB(255, 255, 255)); break;
	}
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void setfontcolor(int color)
{
	if (color < 0) color = -color;
	if (color > 15) color %= 16;
	switch (color)
	{
	case 0: COLOR = (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); COLOR = COMMON_LVB_REVERSE_VIDEO; break;
	case 1: COLOR = (FOREGROUND_BLUE); break;
	case 2: COLOR = (FOREGROUND_GREEN); break;
	case 3: COLOR = (FOREGROUND_RED); break;
	case 4: COLOR = (FOREGROUND_BLUE | FOREGROUND_GREEN); break;
	case 5: COLOR = (FOREGROUND_BLUE | FOREGROUND_RED); break;
	case 6: COLOR = (FOREGROUND_GREEN | FOREGROUND_RED); break;
	case 7: COLOR = (FOREGROUND_BLUE | FOREGROUND_INTENSITY); break;
	case 8: COLOR = (FOREGROUND_GREEN | FOREGROUND_INTENSITY); break;
	case 9: COLOR = (FOREGROUND_RED | FOREGROUND_INTENSITY); break;
	case 10: COLOR = (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); break;
	case 11: COLOR = (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); break;
	case 12: COLOR = (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); break;
	case 13: COLOR = (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); break;
	case 14: COLOR = (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | COMMON_LVB_REVERSE_VIDEO); break;
	case 15: COLOR = (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | COMMON_LVB_REVERSE_VIDEO | FOREGROUND_INTENSITY); break;
	}
	SetConsoleTextAttribute(StdOut, COLOR);
}
void line(int x1, int y1, int x2, int y2)
{
	BGN.X = (short)x1 + movx;
	BGN.Y = (short)y1 + mov;
	POS.X = (short)x2 + movx;
	POS.Y = (short)y2 + mov;
	PlotLine(hDC, PEN, BGN, POS);
}
void putpixel(int x, int y)
{
	line(x, y, x, y);
}
void circle(int x, int y, int radius)
{
	BGN.X = (short)x + movx - radius / 2;
	BGN.Y = (short)y + mov - radius / 2;
	POS.X = (short)x + movx + radius / 2;
	POS.Y = (short)y + mov + radius / 2;
	PlotCirc(hDC, PEN, BGN, POS);
}
void rectangle(int x1, int y1, int x2, int y2)
{
	BGN.X = (short)x1 + movx;
	BGN.Y = (short)y1 + mov;
	POS.X = (short)x2 + movx;
	POS.Y = (short)y2 + mov;
	PlotRect(hDC, PEN, BGN, POS);
}
void gotoxy(int x, int y)
{
	BGN.X = (short)x;
	BGN.Y = (short)y;
	SetConsoleCursorPosition(StdOut, BGN);
}
void outtextxy(int x, int y, char* text)
{
	gotoxy(x / 8, y / 12);
	std::cout << text;
}
void outnumberxy(int x, int y, int a)
{
	gotoxy(x, y);
	cout << a;
}
void clrscr()
{
	setcolor(0);
	for (int i = 5; i <= 645; i++)
		line(i - movx, 32 - mov, i - movx, 331 - mov);
}
void textcolor(int i)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, i);
}

int demchuso(int n)
{
	int dem = 0;
	if (n < 0) {
		dem = 1;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		dem++;
	}
	return dem;
}

void box(int x, int y, int h, int color, int number, int flag, int dung)
{
	int w = demchuso(number) + 2;
	//---------------------------
	textcolor(color);
	setcolor(4);
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int ix = x; ix <= x + w; ix++)
	{
		if (flag == 1)
		{
			if (dung == 1) {
				textcolor(4);
			}
			else {
				textcolor(9);
			}
			gotoxy(ix, y + h + 1);
			cout << char(196);
			textcolor(color);
		}
		else
		{
			textcolor(7);
			gotoxy(ix, y + h + 1);
			cout << "        ";
			textcolor(color);
		}
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
	textcolor(color + 3);
	gotoxy(x + 1, y + 1); cout << number;
	textcolor(7);
	gotoxy(0, y + h + 2);
}

void xoabox(int x, int y, int h, int number)
{
	int w = demchuso(number) + 2;
	//---------------------------
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << " ";
		gotoxy(ix, y + h);
		cout << " ";
	}
	for (int ix = x; ix <= x + w; ix++)
	{

			gotoxy(ix, y + h + 1);
			cout << " ";
		
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << " ";
		gotoxy(x + w, iy);
		cout << " ";
	}
	gotoxy(x, y); cout << " ";
	gotoxy(x + w, y); cout << " ";
	gotoxy(x, y + h); cout << " ";
	gotoxy(x + w, y + h); cout << " ";
	gotoxy(x + 1, y + 1); for (int i = 0; i <= w; i++) cout << " ";
	gotoxy(0, y + h + 2);
}

void boxCot(int x, int y, int w, int h, int color, int bg)
{
	textcolor(color);
	/*for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y - h);
		cout << char(196);
	}*/
	for (int ix = x; ix <= x + w; ix++)
	{
		for (int iy = y; iy >= y - h; iy--)
		{
			textcolor(bg);
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	//for (int iy = y; iy >= y - h; iy--)
	//{
	//	gotoxy(x, iy);
	//	cout << char(179);
	//	gotoxy(x + w, iy);
	//	cout << char(179);
	//}
	//gotoxy(x, y); /*cout << char(218);*/ cout << char(192);
	//gotoxy(x + w, y); /*cout << char(191);*/ cout << char(217);
	//gotoxy(x, y - h); /*cout << char(192);*/ cout << char(218);
	//gotoxy(x + w, y - h); /*cout << char(217);*/ cout << char(191);
	textcolor(color);
	gotoxy(x + 2, y + 1); cout << h;
}

void xoaboxCot(int x, int y, int w, int h)
{
	/*for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y - h);
		cout << char(196);
	}*/
	for (int ix = x; ix <= x + w; ix++)
	{
		for (int iy = y; iy >= y - h; iy--)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	textcolor(7);
	gotoxy(x + 2, y + 1); cout << "      ";
}

void boxMenu(int x, int y,int w, int h, int t_color, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoxy(ix, iy); cout << " ";
		}
	}
	SetColor(y/2+19);
	gotoxy(x + 1, y + 1); cout << nd;
	textcolor(1);
	SetColor(b_color);
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);
}

void Khung_Menu(int x, int y, int w, int h, int t_color, int b_color, string nd, int sl)
{
	for (int i = 0; i < sl; i++)
	{
		if (i == 0) nd = "ComparisonCounting";
		if (i == 1) nd = "ShellSort";
		if (i == 2) nd = "QuickSort";
		if (i == 3) nd = "SelectionSort";
		if (i == 4) nd = "MergeSort";
		boxMenu(x, y + (i*2), w, h, t_color, b_color, nd);
		if (i != 0)
		{
			gotoxy(x, y + (i * 2)); cout << char(195);
			gotoxy(x + w, y + (i * 2)); cout << char(180);
		}
	}
}

void thanh_sang(int x, int y, int w, int h, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoxy(ix, iy); cout << " ";
		}
	}
	SetColor(y / 2 + 19);
	gotoxy(x + 1, y + 1);
	cout << nd;
}

HPEN getPen(int iPEN_STYLE, int iPEN_SIZE, int iCOLORREF)
{
	return CreatePen(iPEN_STYLE, iPEN_SIZE, iCOLORREF);
}

BOOL SetPoint(HDC hDC, HPEN hPen, COORD PNT)
{
	EXTLOGPEN pINFO;
	GetObject(hPen, sizeof(EXTLOGPEN), &pINFO);
	SelectObject(hDC, hPen);
	return Ellipse
	(
		hDC,
		PNT.X - pINFO.elpWidth,
		PNT.Y + pINFO.elpWidth,
		PNT.X + pINFO.elpWidth,
		PNT.Y - pINFO.elpWidth
	);
}

BOOL PlotLine(HDC hDC, HPEN hPen, COORD BGN, COORD END)
{
	SelectObject(hDC, hPen);
	MoveToEx(hDC, BGN.X, BGN.Y, NULL);
	return LineTo(hDC, END.X, END.Y);
}

BOOL PlotRect(HDC hDC, HPEN hPen, COORD BGN, COORD END)
{
	SelectObject(hDC, hPen);
	return Rectangle(hDC, BGN.X, BGN.Y, END.X, END.Y);
}

BOOL  PlotCirc(HDC hDC, HPEN hPen, COORD BGN, COORD END)
{
	SelectObject(hDC, hPen);
	return Ellipse(hDC, BGN.X, BGN.Y, END.X, END.Y);
}

COORD setCordScale(COORD POS, RECT pRECT)
{
	if (POS.X == 0)
		POS.X = 1;
	if (POS.Y == 0)
		POS.Y = 1;

	int nROWS = 25;
	int nCOLS = 80;

	double CX = (pRECT.right - pRECT.left) / nCOLS;
	double CY = (pRECT.bottom - pRECT.top) / nROWS;

	//При текстовом режиме(text mode) экран  делится  на  ячейки
	//(80  или 40 колонок в ширину и 25 строк в высоту)
	POS.X *= CX;
	POS.Y *= CY;

	int xBORDER = GetSystemMetrics(SM_CXBORDER);//Ширина границы окна
	int yBORDER = GetSystemMetrics(SM_CYMENU);  //Высота заголовка окна ~= высоте строк меню
	int xDRAG = GetSystemMetrics(SM_CXDRAG);  //Число пикселей на гориз дрожение мыши
	int yDRAG = GetSystemMetrics(SM_CYDRAG);  //Число пикселей на вертик дрожение мыши

	POS.X += xBORDER + xDRAG;//Ширина границы окна + число пикселей на дрожение мыши
	POS.Y += yBORDER + yDRAG;
	return POS;
}

#endif
