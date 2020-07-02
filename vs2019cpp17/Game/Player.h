#pragma once
#include "Cup.h"

namespace Agaz {
class Player {
private:
	const Name name;
	Score score{ 0 };
public:
	Player(Name name) : name{ name } {
		if (name.empty())
			throw exception{ "empty name" };
	}
	Score getScore() const noexcept { return this->score; }
	Name getName() const noexcept { return this->name; }
	void takeTurn(Cup& cup) noexcept;
};
}