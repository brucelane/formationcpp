#pragma once
#include "Cup.h"

namespace Agaz {
	class Player {
	private:
		const Name name;
		Score score{ 0 };
	public:
		// ne pas autoriser la copie
		Player(const Player&) = delete; // A mettre partout, tout le temps
		Player(const Name name) : name{ name } {
			if (name.empty())
				throw exception{ "empty name" };
		}
		Score getScore() const noexcept { return this->score; }
		//Name getName() const noexcept { return this->name; }
		void takeTurn(Cup& cup) noexcept;

		bool operator < (const Player& other) const {
			return this->score < other.score;
		}

		friend ostream& operator << (ostream& o, const Player& player) {
			return o << "(" << player.name << ")";
		}
	};
}