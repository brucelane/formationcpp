#include "Player.h"

void Agaz::Player::takeTurn(Cup & cup) noexcept
{
	cup.roll();
	Value value{ cup.getValue() };
	this->score += value;
	cout << cup.getValue() << " points pour " << this->name << endl;

}
