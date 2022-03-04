#include "Body.h"

Body::Body(int l, int t, int r, int b) : Shape(l, t, r, b)
{}

void Body::Draw(HWND hwnd, HDC hdc)
{
	FrameRect(hdc, rect, hbr);
}

Body::~Body()
{}
