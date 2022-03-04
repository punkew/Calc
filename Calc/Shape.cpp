#include "Shape.h"

Shape::Shape(int l, int t, int r, int b)
{
	rect = new RECT;
	rect->left = l;
	rect->top = t;
	rect->right = r;
	rect->bottom = b;
}

Shape::~Shape()
{
	delete rect;
}
