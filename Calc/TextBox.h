#pragma once
#include "Shape.h"
class TextBox : public Shape
{
protected:
	static const int MAX = 50; //максимальная длина надписи
	HFONT hNewf1; //шрифт
	TCHAR title[MAX]; //надпись
public:
	TextBox(const TCHAR *name, int l, int t, int r, int b); //конструктор с указанием положения и надписи
 	void Draw(HWND hwnd, HDC hdc); //вывод на экран
	void SetText(TCHAR *t); //установить текст
	void AddText(TCHAR *t); //добавить текст
	~TextBox(); //деструктор
};

