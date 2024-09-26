#include "Odgovor.h"
// Marija Živanoviæ, SV 19/2021
// Poslednja izmena: 11.01.2023.

Odgovor::Odgovor() {}; // Prazan konstruktor

// Konstruktor sa atributima
Odgovor::Odgovor(Player* player, Izraz<int>* expression) : igrac(player), izraz(expression) {};

//Dobavljamo igraca
Player* Odgovor::getIgrac() const {
	return igrac;
}
//Postavljamo igraca
void Odgovor::setIgrac(Player* igrac) {
	this->igrac = igrac;
}
//Dobavljamo izraz
Izraz<int>* Odgovor::getIzraz() const {
	return izraz;
}
//Setujemo, tj. postavljamo izraz
void Odgovor::setIzraz(Izraz<int>* izraz) {
	this->izraz = izraz;
}

