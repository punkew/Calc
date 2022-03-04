#pragma once
#include <windows.h>
class Shape
{
protected:
	RECT *rect; //положение на экране
	HBRUSH hbr = CreateSolidBrush(RGB(255, 255, 255)); //цвет кисти
public:
	Shape(int l, int t, int r, int b);
	virtual void Draw(HWND hwnd, HDC hdc) = 0;
	virtual ~Shape();
};

