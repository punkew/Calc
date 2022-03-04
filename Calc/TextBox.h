#pragma once
#include "Shape.h"
class TextBox : public Shape
{
protected:
	static const int MAX = 50; //������������ ����� �������
	HFONT hNewf1; //�����
	TCHAR title[MAX]; //�������
public:
	TextBox(const TCHAR *name, int l, int t, int r, int b); //����������� � ��������� ��������� � �������
 	void Draw(HWND hwnd, HDC hdc); //����� �� �����
	void SetText(TCHAR *t); //���������� �����
	void AddText(TCHAR *t); //�������� �����
	~TextBox(); //����������
};

