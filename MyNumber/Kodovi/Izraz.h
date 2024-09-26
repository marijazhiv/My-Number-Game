#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.
#include <string>
#include "Token_stream.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


template<class T>
class Izraz {
private:
	std::string izraz;
	T vrednost;
	Token_stream ts;
public:
	Izraz(std::string expression, T value) : izraz(expression), vrednost(value), ts(expression) {};


	std::string getIzraz() const {
		return izraz;
	}
	void setIzraz(std::string) {
		this->izraz = izraz;
	}

	T getVrednost() const {
		return vrednost;
	}
	void setVrednost(T) {
		this->vrednost = vrednost;
	}



	T primary()
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
	T term() {
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

	T expression() {
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

	}

};
