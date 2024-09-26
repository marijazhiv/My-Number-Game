#include "Player.h"
#include <string>

// Marija Živanoviæ, SV 19/2021
// Poslednja izmena: 11.01.2023.

Player::Player() {}; // Prazan konstruktor - zbog ispisa i upisa

// Konstruktor sa atributima
Player::Player(int index, std::string uname, int br_dobijenih) : id(index), username(uname), br_dobijenih_rundi(br_dobijenih) {};

// Dobavljamo ID igraca
int Player::getId() const {
	return id;
}

// Postavljamo ID igraca
void Player::setId(int id) {
	this->id = id;
}

// Dobavljamo username igraca
std::string  Player::getUsername() const {
	return username;
}

// Postavljamo username igraca
void Player::setUsername(std::string username) {
	this->username = username;
}

// Dobavljamo broj dobijenih rundi jednog igraca
int Player::getBrDobijenih() const {
	return br_dobijenih_rundi;
}

// Postavljamo broj dobijenih rundi jednog igraca
void Player::setBrDobijenih(int dobijene) {
	this->br_dobijenih_rundi = dobijene;
}
