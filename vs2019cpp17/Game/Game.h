#pragma once
#include "Player.h"

namespace Agaz {

	class Game {
	private:
		Turns nbTurns{ 3 };
		list<Player> players;
		Cup cup;
		void displayWinner() const noexcept;
	public:
		Game(unsigned nbDices) : cup{ nbDices } {};
		void enroll(const Name& name) {
			players.emplace_back( name );
		};
		void setup(Turns nbTurns) noexcept(false) {
			const unsigned MIN_NB_TURNS{ 1 };
			if (nbTurns < MIN_NB_TURNS)
				throw exception("invalid number of turns");
			this->nbTurns = nbTurns;
		};
		void start() noexcept;
	};
}