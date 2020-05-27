#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;

float po_znach(float x, float n)
{
	float E = 0.001, H = 1, HLast = x, Rezult = x;
	int K = 1;
	while (fabs(H) >= E && K < n) {
		H = HLast * (pow(-x, 2) / (2 * K * (2 * K + 1)));
		HLast = H;
		if (K % 2 != 0) {
			Rezult -= H;
		}
		else{
			Rezult += H;
		}
		K++;
	}
	return Rezult;
}

void po_ukaz(float *x, float *n, float *rez)
{
	float E = 0.001, H = 1, HLast = *x, Rezult = *x;
	int K = 1;
	while (fabs(H) >= E && K < *n) {
		H = HLast * (pow(-*x, 2) / (2 * K * (2 * K + 1)));
		HLast = H;
		if (K % 2 != 0) {
			Rezult -= H;
		}
		else {
			Rezult += H;
		}
		K++;
	}
	*rez = Rezult;
}

void po_ssil(float &x, float &n, float &rez)
{
	float E = 0.001, H = 1, HLast = x, Rezult = x;
	int K = 1;
	while (fabs(H) >= E && K < n) {
		H = HLast * (pow(-x, 2) / (2 * K * (2 * K + 1)));
		HLast = H;
		if (K % 2 != 0) {
			Rezult -= H;
		}
		else {
			Rezult += H;
		}
		K++;
	}
	rez = Rezult;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const double PI = 3.141592653589793;
	float rez, x = -2 * PI, n;
	int i;
	cout << "Введите n: ";
	cin >> n;
	cout << "Выбирите метод:" <<endl
		<<"1 - по значунию" <<endl
		<<"2 - по указателю" <<endl
		<<"3 - по ссылке" <<endl;
	cin >> i;
	switch (i)
	{
	case 1:
		while (x <= 0) {
			cout.precision(5);
			cout << "x = " << x << " = ";
			rez = po_znach(x, n);
			cout << rez << endl;
			x += 3.14 / 12;
		}
		break;

	case 2:
		while (x <= 0) {
			cout.precision(5);
			cout << "x = " << x << " = ";
			po_ukaz(&x, &n, &rez);
			cout << rez << endl;
			x += 3.14 / 12;
		}
		break;

	case 3:
		while (x <= 0) {
			cout.precision(5);
			cout << "x = " << x << " = ";
			po_ssil(x, n, rez);
			cout << rez << endl;
			x += 3.14 / 12;
		}
		break;
	};
	system("pause");
	return 0;
}
