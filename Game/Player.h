#pragma once
#include "Cup.h"
class Player {
private:
	const Name name;
	Score score{ 0 };
public:
	Player(Name name) : name{ name } {
	}
	Score getScore() const { return this->score; }
	Name getName() const { return this->name; }
	void takeTurn(Cup& cup) {
		cup.roll();
		Value value{ cup.getValue() };
		this->score += value;
		cout << cup.getValue() << " points pour " << this->name << endl;
	};
};