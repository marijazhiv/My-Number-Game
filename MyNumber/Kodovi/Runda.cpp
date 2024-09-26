#include "Runda.h"

// Marija Živanoviæ, SV 19/2021
// Poslednja izmena: 11.01.2023.

Runda::Runda() {}; //Prazan konstruktor


// Konstruktor sa atributima
Runda::Runda(Zadatak* problem, Odgovor* answer1, Odgovor* answer2) : zadatak(problem), odgovor1(answer1), odgovor2(answer2) {};


//dobavljanje zadatka odredjene runde
Zadatak* Runda::getZadatak() const {
	return zadatak;
}
//setovanje zadatka
void Runda::setZadatak(Zadatak* zadatak) {
	this->zadatak = zadatak;
}
//dobijanje odgovora 1. igraca
Odgovor* Runda::getOdgovor1() const {
	return odgovor1;
}
//postavljanje odgovora 1. igraca
void Runda::setOdgovor1(Odgovor* odgovor1) {
	this->odgovor1 = odgovor1;
}
// dobijanje odgovora 2. igraca
Odgovor* Runda::getOdgovor2() const {
	return odgovor2;
}
// postavljanje odgovora 2. igraca
void Runda::setOdgovor2(Odgovor* odgovor2) {
	this->odgovor2 = odgovor2;
}