#include "TextBox.h"


TextBox::TextBox(const TCHAR *name, int l, int t, int r, int b) : Shape(l, t, r, b)
{
	strncpy_s(title, name, MAX);
}

void TextBox::Draw(HWND hwnd, HDC hdc)
{
	HFONT hNewf1 = CreateFont(25, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FW_BOLD, "Arial");
	SelectObject(hdc, hNewf1); //установка созданного шрифта
	SetTextColor(hdc, RGB(255, 255, 255)); //установка цвета текста
	SetBkColor(hdc, RGB(0, 0, 0)); //установка фона для текста
	HBRUSH h = CreateSolidBrush(RGB(0, 0, 0)); 
	FillRect(hdc, rect, h); //заполнение цветом фона (очистка от старой надписи)
	TextOut(hdc, rect->left + 25, rect->top + (rect->bottom - rect->top)/2 - 10, title, strlen(title));
}

void TextBox::SetText(TCHAR *text)
{
	strncpy_s(title, text, MAX);
}

void TextBox::AddText(TCHAR *t)
{
	strcat_s(title, t);
}

TextBox::~TextBox()
{}
