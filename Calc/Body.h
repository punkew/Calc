#pragma once
#include "Shape.h"
class Body : public Shape
{
public:
	Body(int l, int t, int r, int b);
	void Draw(HWND hwnd, HDC hdc);
	~Body();
};

