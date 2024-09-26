#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.

#include "Zadatak.h"
#include "Odgovor.h"

class Runda {
private:
	Zadatak* zadatak;
	Odgovor* odgovor1;
	Odgovor* odgovor2;

public:
	Runda();
	Runda(Zadatak* problem, Odgovor* answer1, Odgovor* answer2);

	Zadatak* getZadatak() const;
	void setZadatak(Zadatak*);

	Odgovor* getOdgovor1() const;
	void setOdgovor1(Odgovor*);

	Odgovor* getOdgovor2() const;
	void setOdgovor2(Odgovor*);
};