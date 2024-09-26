#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.

#include "Player.h"
#include "Izraz.h"
#include "Zadatak.h"

class Odgovor {
private:
	Player* igrac;
	Izraz<int>* izraz;
public:
	Odgovor();
	Odgovor(Player*, Izraz<int>*);

	Player* getIgrac() const;
	void setIgrac(Player*);

	Izraz<int>* getIzraz() const;
	void setIzraz(Izraz<int>*);


};