#pragma once
#include <windows.h>
class Shape
{
protected:
	RECT *rect; //��������� �� ������
	HBRUSH hbr = CreateSolidBrush(RGB(255, 255, 255)); //���� �����
public:
	Shape(int l, int t, int r, int b);
	virtual void Draw(HWND hwnd, HDC hdc) = 0;
	virtual ~Shape();
};

