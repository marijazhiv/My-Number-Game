#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.
#include <string>

class Player {
private:
	int id;
	std::string username;
	int br_dobijenih_rundi;

public:
	Player();
	Player(int index, std::string uname, int br_dobijenih);
	int getId() const;
	void setId(int);
	std::string getUsername() const;
	void setUsername(std::string);
	int getBrDobijenih() const;
	void setBrDobijenih(int dobijene);



};