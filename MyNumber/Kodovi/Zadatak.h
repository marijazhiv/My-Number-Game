#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctype.h>

#include "Izraz.h"
#include "Generator.h"

class Zadatak {
private:
	int tacan;
	vector<int> numbersPermutations;
	string generatedExpression;

	int brojevi[6];
public:

	static vector<char> operations;

	Zadatak();
	Zadatak(int tacno, int ponudjeni[]);

	int getTacan() const;
	void setTacan(int);

	string getBrojeviFormated() const;

	void printNumbers() const;


	std::string izracunaj();
	std::string izracunajPriblizno();

	bool pronadjenaVrednost(vector<int>);
	bool pronadjenaVrednostPriblizno(vector<int>);

	bool checkAllPermutationsWithRepetitions(int brMesta, int brojeva);
	bool checkAllPermutationsWithRepetitionsPriblizno(int brMesta, int brojeva);

	vector<int> getBrojevi() {
		vector<int> br;
		for (int i = 0; i < 6; i++) {
			br.push_back(brojevi[i]);
		}
		return br;
	}




};
