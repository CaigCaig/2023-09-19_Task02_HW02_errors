#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;

double div(double a, double b)
{
	return a * b;											// семантическая ошибка. Вместо деления производится умножение
}

double mul(double a, double b);								// ошибка линковки. Нет реализации функции.

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto arr = { 4, 7, 9, 14, 12 };
	double x, y;

	struct {
		void operator()(int i) const { cout << i << ' ' }	// синтаксическая ошибка, пропущена ;
	} in_show;

	cout << "Входные данные: ";
	for_each(arr.begin(), arr.end(), in_show);
	cout << endl;

	struct {
		void operator(int i) const							// синтаксическая ошибка, пропущены ()
		{
			switch (i % 2)
			{
			case 0:
				cout << i << ' ';
				break;
			case 1:
				cout << i * 3 << ' ';
			}
		}
	} out_show;

	cout << "Выходные данные: ";
	for_each(arr.begin(), arr.end(), out_show);
	cout << endl;

	cout << "Введите x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	cout << "x * y = " << div(x, y);
	cout << "x * y = " << mul(x, y);

	system("pause");
}