#include "pch.h"
#include <iostream>
#include <ostream>
#include "pchar.h"

int g_x = 10;

int AddTwoNumbers(int a, int b) {
	return a + b;
}

int _pmain(int, _pchar*[])
{
	int y = 20;
	std::wcout << L"The result of AddTwoNumbers (g_x, y) where g_x = " << g_x << L" and y = " << y << L" is " << AddTwoNumbers(g_x, y) << L"." << std::endl;

	if (true == 1) {
		std::wcout << L"true == 1!" << std::endl;
	}
	return 0;
}
