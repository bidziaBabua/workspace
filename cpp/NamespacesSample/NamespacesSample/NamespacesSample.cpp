#include "pch.h"
#include <iostream>
#include <ostream>
#include <string>
#include "pchar.h"

using namespace std;

namespace Places {
	namespace Cities {
		struct City {
			City(const wchar_t* name) {
				Name = wstring(name);
			}

			wstring Name;
		};
	}
}

int _pmain(int, _pchar*[])
{
	auto nyc = Places::Cities::City(L"New Yourk City");

	wcout << L"City name is " << nyc.Name.c_str() << L"." << endl;

	return 0;
}