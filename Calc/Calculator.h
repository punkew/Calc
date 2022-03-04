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
	char op; //текуща€ операци€
	HWND hwnd; //дескриптор окна консоли
	HDC hdc; //handle
	static const TCHAR *titles[]; //массив надписей дл€ кнопок
	std::vector<Shape*> components; //массив графических компонентов
	TCHAR screen[50]; //строка, вывод€ща€с€ на дисплей
	double fOp, sOp; //первый и второй операнд
	double mOp; //операнд в пам€ти
	Body *body; //указатель на "корпус" калькул€тора
	Display *display; //указатель на дисплей
public:
	Calculator(); //конструктор без параметров
	void Input(); //ввод значений
	void Refresh(); //обновить отображение на экране
	~Calculator(); //деструктор
};

