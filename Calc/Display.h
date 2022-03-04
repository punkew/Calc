#pragma once
//#include "Shape.h"
#include "TextBox.h"
class Display: public Shape
{
private:
	TextBox *tb;
public:
	Display(int l, int t, int r, int b);
	void SetText(TCHAR *t);
	void AddText(TCHAR *t);
	void Draw(HWND hwnd, HDC hdc);
	~Display();
};

