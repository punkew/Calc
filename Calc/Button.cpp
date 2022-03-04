#include "Button.h"

Button::Button(const TCHAR *name, int l, int t, int r, int b) : Shape(l, t, r, b)
{
	tb = new TextBox(name, l, t, r, b);
}

void Button::Draw(HWND hwnd, HDC hdc)
{
	tb->Draw(hwnd, hdc);
	FrameRect(hdc, rect, hbr);
}

Button::~Button()
{
	delete tb;
}
