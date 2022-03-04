#pragma once
//#include "Shape.h"
#include "TextBox.h"
class Button : public Shape
{
private:
	TextBox *tb;
public:
	Button(const TCHAR *name, int l, int t, int r, int b);
	void Draw(HWND hwnd, HDC hdc);
	~Button();
};

