#pragma once
#include "Cup.h"
namespace Agaz {
class Player {
private:
	const Name name;
	Score score{ 0 };
public:
	Player(Name name) : name{ name } {
	}
	Score getScore() const { return this->score; }
	Name getName() const { return this->name; }
	void takeTurn(Cup& cup);
};
}