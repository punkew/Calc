#include "Calculator.h"

TCHAR const *Calculator::titles[] = { "MC", "MR", "MS", "M +", "M -", "BS", "CE", " C", "+/-", "sqrt", " 7", " 8", " 9", " /", " %", " 4", " 5", " 6", " *", "1/x", " 1", " 2", " 3", " --", " 0", "  ,", " +", "  =" };
Calculator::Calculator() : fOp(0), sOp(0), mOp(0)
{
	int k = 0;
	hwnd = FindWindow("ConsoleWindowClass", NULL);
	hdc = GetDC(hwnd);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
			components.push_back(new Button(titles[k++], 185 + 100 * j, 150 + 75 * i, 270 + 100 * j, 215 + 75 * i));
	}
	for (int i = 0; i < 4; ++i)
		components.push_back(new Button(titles[k++], 185 + 100 * i, 450, 270 + 100 * i, 515));
	components.push_back(new Button(titles[k++], 185, 525, 370, 590));
	for (int i = 0; i < 2; ++i)
		components.push_back(new Button(titles[k++], 385 + 100 * i, 525, 470 + 100 * i, 590));
	components.push_back(new Button(titles[k++], 585, 450, 670, 590));
	body = new Body(170, 20, 685, 600);
	components.push_back(body);
	display = new Display(185, 35, 670, 140);
	components.push_back(display);
	Refresh();
}

void Calculator::Refresh()
{
	system("cls");
	for (int i = 0; i < components.size(); ++i)
		components[i]->Draw(hwnd, hdc);
	printf("\n'+'\t+\n'-'\t-\n'*'\t*\n'/'\t/\n'='\t=\n'%%'\t%%\n'MC'\tq\n'MR'\tw\n'MS'\te\n'M+'\tr\n'M-'\tt\n'BS'\ty\n'CE'\tu\n'C'\tc\n'+/-'\ti\n'sqrt'\ts\n'1/x'\to\n','\t,\n'EXIT'\tESC");
}

void Calculator::Input()
{
	char key; //вводимый символ
	int prec1 = 0, prec2 = 0; //количество цифр после запятой
	bool reset = true; //ввод первого операнда, иначе используется результат предыдущей операции
	do
	{
		if (reset)
		{
			while (true) //выделяем первый операнд
			{
				key = _getch();
				if (key == 'y') //если нужно стереть последний символ
				{
					int tmp = static_cast<int>(fOp);
					fOp = tmp /= 10;
					sprintf_s(screen, "%.*f", prec1, fOp);
					display->SetText(screen);
					Refresh();
					continue;
				}
				prec1 = 0;
				if ((key == ',') || (key == '.')) //если вводится дробное число
				{
					int i = 1;
					while (true)
					{
						key = _getch();
						if (key == 'y') //если надо стереть последний символ
						{
							if (prec1 == 0)
							{
								_getch();
								break;
							}
							double tmp = fOp*i;
							tmp = static_cast<int>(tmp / 10);
							i /= 10;
							--prec1;
							tmp /= i;
							fOp = tmp;
							sprintf_s(screen, "%.*f", prec1, fOp);
							display->SetText(screen);
							Refresh();
							continue;
						}
						if (!((key >= '0') && (key <= '9'))) //если введена не цифра
							break;
						char tmp[1] = "";
						tmp[0] = key;
						i *= 10;
						++prec1;
						fOp *= i;
						fOp += atoi(tmp);
						fOp /= i;
						sprintf_s(screen, "%.*f", prec1, fOp);
						display->SetText(screen);
						Refresh();
					}
				}
				if (!((key >= '0') && (key <= '9'))) //если введена не цифра
				{
					reset = false;
					break;
				}
				char tmp[1] = "";
				tmp[0] = key;
				fOp *= 10;
				fOp += atoi(tmp);
				sprintf_s(screen, "%.*f", prec1, fOp);
				display->SetText(screen);
				Refresh();
			}
		}
		switch (key) //устанавливаем операцию
		{
		case '+':
		{
					op = '+';
					break;
		}
		case '-':
		{
					op = '-';
					break;
		}
		case '=':
		{
					op = '=';
					break;
		}
		case '/':
		{
					op = '/';
					break;
		}
		case '*':
		{
					op = '*';
					break;
		}
		case '%':
		{
					op = '%';
					break;
		}
		case 'e':
		{
					op = 'e';
					break;
		}
		case 'w':
		{
					op = 'w';
					break;
		}
		case 'c': 
		{
					fOp = sOp = 0;
					sprintf_s(screen, "%.*f", prec1, fOp);
					display->SetText(screen);
					Refresh();
					reset = true;
					continue;
		}
		case 'q':
		{
					mOp = 0;
					continue;
		}
		case 'r':
		{
					fOp += mOp;
					sprintf_s(screen, "%.*f", prec1, fOp);
					display->SetText(screen);
					Refresh();
					key = _getch();
					continue;
		}
		case 't':
		{
					fOp -= mOp;
					sprintf_s(screen, "%.*f", prec1, fOp);
					display->SetText(screen);
					Refresh();
					key = _getch();
					continue;
		}
		case 'i':
		{
					fOp = -fOp;
					sprintf_s(screen, "%f", fOp);
					display->SetText(screen);
					Refresh();
					key = _getch();
					continue;
		}
		case 's':
		{
					if (fOp >= 0)
					{
						fOp = sqrt(fOp);
						sprintf_s(screen, "%f", fOp);
						display->SetText(screen);
						Refresh();
						key = _getch();
						continue;
					}
					else
					{
						display->SetText("E");
						fOp = sOp = 0;
						reset = true;
						Refresh();
						continue;
					}
		}
		case 'o':
		{
					if (fOp != 0)
					{
						fOp = 1 / fOp;
						sprintf_s(screen, "%f", fOp);
						display->SetText(screen);
						Refresh();
						key = _getch();
						continue;
					}
					else
					{
						display->SetText("E");
						fOp = sOp = 0;
						reset = true;
						Refresh();
						continue;
					}
		}
		}
		if (op == 'e') //устанавливаем число в память
		{
			mOp = fOp;
			key = _getch();
			continue;
		}
		if (op == 'w') //берём число из памяти или вводим
		{
			fOp = mOp;
			sprintf_s(screen, "%f", fOp);
			display->SetText(screen);
			Refresh();
			key = _getch();
		}
		else
		{
			while (true) //выделяем второй операнд
			{
				key = _getch();
				prec2 = 0;
				if (key == 'y')
				{
					int tmp = static_cast<int>(sOp);
					sOp = tmp /= 10;
					sprintf_s(screen, "%.*f", prec1, sOp);
					display->SetText(screen);
					Refresh();
					continue;
				}
				if ((key == ',') || (key == '.'))
				{
					int i = 1;
					while (true)
					{
						key = _getch();
						if (key == 'y')
						{
							if (prec2 == 0)
							{
								_getch();
								break;
							}
							double tmp = sOp*i;
							tmp = static_cast<int>(tmp / 10);
							i /= 10;
							--prec2;
							tmp /= i;
							sOp = tmp;
							sprintf_s(screen, "%.*f", prec2, sOp);
							display->SetText(screen);
							Refresh();
							continue;
						}
						if (!((key >= '0') && (key <= '9')))
							break;
						char tmp[1] = "";
						tmp[0] = key;
						i *= 10;
						++prec2;
						sOp *= i;
						sOp += atoi(tmp);
						sOp /= i;
						sprintf_s(screen, "%.*f", prec2, sOp);
						display->SetText(screen);
						Refresh();
					}
				}
				if (!((key >= '0') && (key <= '9')))
					break;
				char tmp[1] = "";
				tmp[0] = key;
				sOp *= 10;
				sOp += atoi(tmp);
				sprintf_s(screen, "%.*f", prec2, sOp);
				display->SetText(screen);
				Refresh();
			}
		}
		if (key == 'u') //если надо сбросить введённое число
		{
			sOp = 0;
			sprintf_s(screen, "%.*f", prec2, sOp);
			display->SetText(screen);
			Refresh();
			continue;
		}
		if (key == '%') //если нажата кнопка "процент"
		{
			sOp = fOp / 100 * sOp;
		}
		switch (op)
		{
		case '+':
		{
					fOp += sOp;
					break;
		}
		case '-':
		{
					fOp -= sOp;
					break;
		}
		case '/':
		{
					if (sOp != 0)
						fOp /= sOp;
					else
					{
						display->SetText("E");
						fOp = sOp = 0;
						reset = true;
						Refresh();
						continue;
					}
					break;
		}
		case '*':
		{
					fOp *= sOp;
					break;
		}
		}
		sOp = 0;
		sprintf_s(screen, "%f", fOp);
		display->SetText(screen);
		Refresh();
	} while (key != 27);
}

Calculator::~Calculator()
{
	for (int i = 0; i < components.size(); ++i)
		delete components[i];
	ReleaseDC(hwnd, hdc);
}
