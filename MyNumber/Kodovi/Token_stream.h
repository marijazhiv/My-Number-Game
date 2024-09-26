#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';


struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string name) :kind(ch), name(name) { }
};



class Token_stream {
	bool full;
	Token buffer;
	string line;
	int pozicija;
	stringstream ss;
public:
	Token_stream(string line) :full(0), buffer(0), line(line), pozicija(0) { ss << line; }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

};