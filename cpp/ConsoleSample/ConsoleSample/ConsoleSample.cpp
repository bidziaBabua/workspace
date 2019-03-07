#include "pch.h"
#include "pchar.h"
#include <iostream>
#include <ostream>
#include <string>

struct Color {
	float ARGB[4];

	void A(float value) { ARGB[0] = value; }
	float A(void) const { return ARGB[0]; }
	void R(float value) { ARGB[1] = value; }
	float R(void) const { return ARGB[1]; }
	void G(float value) { ARGB[2] = value; }
	float G(void) const { return ARGB[2]; }
	void B(float value) { ARGB[3] = value; }
	float B(void) const { return ARGB[3]; }
};

std::wostream& operator << (std::wostream& stream, const Color& c) {
	stream << L"ARGB:{ " << c.A() << L"f, " << c.R() << L"f, " << c.G() << L"f, " << c.B() << L"f, }";
	return stream;
}

int _pmain(int , _pchar* [])
{
	std::wcout << L"Please, input an integer and then press Enter: ";
	int a;
	std::wcin >> a;
	std::wcout << L"You entered '" << a << L"'." << std::endl;

	std::wcout << std::endl <<
		L"Please, enter a noun (one word, no spaces) " <<
		L"and then press Enter: ";

	std::wstring noun;

	std::wcin >> noun;
	std::wcerr << L"The" << noun << L" is on fire! oh, no!" << std::endl;

	Color c = { { 100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f, 1.0f } };

	std::wcout << std::endl <<
		L"Cornflower blue is " << c << L"." << std::endl;

	return 0;
}
