#include "Token_stream.h"

// Marija ivanoviæ, SV 19/2021
// Poslednja izmena: 11.01.2023.

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	ss >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);   
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':             //KAO TOKEN VRACA ILI NEKI KARAKTER TIPA (,),*,- (DAKLE OPERAND) ILI BROJ KOJI UPISUJE KAO TIP DOUBLE
	case '6':
	case '7':
	case '8':
	case '9':
	{	ss.unget();
	double val;
	ss >> val;
	return Token(number, val);
	}
	default:
		throw 505;
	}
}
