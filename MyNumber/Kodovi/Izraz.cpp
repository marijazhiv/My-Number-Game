#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

/*template <class T>
Izraz<T>::Izraz(std::string expression, T value) : izraz(expression), vrednost(value), ts(expression) {};

template <class T>
std::string Izraz<T>::getIzraz() const {
	return izraz;
}

template <class T>
void Izraz<T>::setIzraz(std::string izraz) {
	this->izraz = izraz;
}

template <class T>
T Izraz<T>::getVrednost() const {
	return vrednost;
}

template <class T>
void Izraz<T>::setVrednost(T vrednost) {
	this->vrednost = vrednost;
}*/





/*template <class T>
T Izraz<T>::primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	T d = expression();
	t = ts.get();
	if (t.kind != ')') throw 505;
	return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	default:
		throw 505;
		cout << ("primary expected");

	}
}

template <class T>
T Izraz<T>::term()
{
	T left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	T d = primary();
		if (d == 0)  throw 505;
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

template <class T>
T Izraz<T>::expression()
{

	try {

		T left = term();
		while (true) {
			Token t = ts.get();
			switch (t.kind) {
			case '+':
				left += term();
				break;
			case '-':
				left -= term();
				break;
			default:
				ts.unget(t);
				vrednost = left;
				return left;
			}
		}
	}
	catch (const runtime_error& error)
	{
		return -1;
	}
	catch (...) {
		return -1;

	}

}*/


