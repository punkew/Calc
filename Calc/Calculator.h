#pragma once
#include <vector>
#include <conio.h>
//#include "Shape.h"
#include "Button.h"
#include "Display.h"
#include "Body.h"

class Calculator
{
private:
	char op; //������� ��������
	HWND hwnd; //���������� ���� �������
	HDC hdc; //handle
	static const TCHAR *titles[]; //������ �������� ��� ������
	std::vector<Shape*> components; //������ ����������� �����������
	TCHAR screen[50]; //������, ����������� �� �������
	double fOp, sOp; //������ � ������ �������
	double mOp; //������� � ������
	Body *body; //��������� �� "������" ������������
	Display *display; //��������� �� �������
public:
	Calculator(); //����������� ��� ����������
	void Input(); //���� ��������
	void Refresh(); //�������� ����������� �� ������
	~Calculator(); //����������
};

