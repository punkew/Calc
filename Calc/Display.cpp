#include "Display.h"

Display::Display(int l, int t, int r, int b) : Shape(l, t, r, b)
{
	tb = new TextBox("0", l, t, r, b);
}

void Display::SetText(TCHAR *t)
{
	tb->SetText(t);
}

void Display::Draw(HWND hwnd, HDC hdc)
{
	tb->Draw(hwnd, hdc);
	FrameRect(hdc, rect, hbr);
}

void Display::AddText(TCHAR *t)
{
	tb->AddText(t);
}

Display::~Display()
{
	delete tb;
}
