#include <iostream>
#include <ostream>
#include "pchar.h"

using namespace std;

int CallingMsg(const wchar_t* cls) {
	wcout << L"Calling " << cls << L" constructor." << endl;
	return 0;
}

int InitializingIntMsg(int value, const wchar_t* mvarName) {
	wcout << L"Initializing " << mvarName << L"." << endl;
	return value;
}

class A {
public:
	A(void) :
		m_value(InitializingIntMsg(5, L"DEFAULT m_value")) {
		wcout << L"DEFAULT Constructing A. m_value is " <<
			m_value << L"." << endl;
	}

	explicit A(int) :
		m_value(InitializingIntMsg(20, L"m_value")) {
		wcout << L"Constructing A. m_value is " <<
			m_value << L"." << endl;
	}

	virtual ~A(void) {
		wcout << L"Destroying A." << endl;
	}

private:
	int m_value;
};

class B : virtual public A {
public:
	explicit B(int) :
		A(CallingMsg(L"A")),
		m_b(InitializingIntMsg(2, L"m_b")),
		m_a(InitializingIntMsg(5, L"m_a")) {
		wcout << L"Constructing B. m_a is '" <<
			m_a << L"' and m_b is '" << m_b << L"'." << endl;
	}

	virtual ~B(void) {
		wcout << L"Destroying B." << endl;
	}

private:
	int m_a;
	int m_b;
};

class C {
public:
	explicit C(int) :
		m_c(InitializingIntMsg(0, L"m_c")) {
		wcout << L"Constructing C. m_c is '" <<
			m_c << L"'." << endl;
	}

	virtual ~C(void) {
		wcout << L"Destroying C." << endl;
	}

private:
	int m_c;
};

class D {
public:
	explicit D(int) :
		m_d(InitializingIntMsg(3, L"m_d")) {
		wcout << L"Constructing D. m_d is '" <<
			m_d << L"'." << endl;
	}

	virtual ~D(void) {
		wcout << L"Destroying D." << endl;
	}

private:
	int m_d;
};

class Y : virtual public B, public D, virtual public C {
public:
	explicit Y(int value) :
		C(CallingMsg(L"C")),
		m_someInt(InitializingIntMsg(value, L"m_someInt")),
		D(CallingMsg(L"D")),
		B(CallingMsg(L"B")) {
		wcout << L"Constructing Y. m_someInt is '" <<
			m_someInt << L"'." << endl;
	}

	virtual ~Y(void) {
		wcout << L"Destroying Y." << endl;
	}

	int GetSomeInt(void) { return m_someInt; }

private:
	int m_someInt;
};

class Z : public D, virtual public B, public C {
public:
	explicit Z(int value) :
		D(CallingMsg(L"D")),
		A(CallingMsg(L"A")),
		C(CallingMsg(L"C")),
		m_someInt(InitializingIntMsg(value, L"m_someInt")),
		B(CallingMsg(L"B")) {
		wcout << L"Constructoring Z. m_someInt is '" <<
			m_someInt << L"." << endl;
	}

	virtual ~Z(void) {
		wcout << L"Destroying Z." << endl;
	}

	int GetSomeInt(void) { return m_someInt; }

private:
	int m_someInt;
};

int _pmain(int, _pchar* [])
{
	{
		Y someY(CallingMsg(L"Y"));
		wcout << L"Y::GetSomeInt returns '" <<
			someY.GetSomeInt() << L"'." << endl;
	}
	
	wcout << endl << "Break between Y and Z." << endl << endl;

	{
		Z someZ(CallingMsg(L"Z"));
		wcout << L"Z::GetSomeInt returns '" <<
			someZ.GetSomeInt() << L"'Z." << endl;
	}
	return 0;
}
