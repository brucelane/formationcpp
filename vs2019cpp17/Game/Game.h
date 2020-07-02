#pragma once
#include "Player.h"


namespace Agaz {

	class Game {
	private:
		Turns nbTurns{ 3 };
		Player player1;
		Player player2;
		Cup cup;
		void displayWinner() const {
			const Player& winner{
				player1.getScore() > player2.getScore() ? player1 : player2
			};
			cout << "Gagnant: " << winner.getName() << " " << winner.getScore() << endl;

		};
	public:
		Game(const Name& name1, const Name& name2) noexcept(false) :
			player1{ name1 },
			player2{ name2 }
		{
		}
		void setup(Turns nbTurns) noexcept(false) {
			const unsigned MIN_NB_TURNS{ 1 };
			if (nbTurns < MIN_NB_TURNS)
				throw exception("invalid number of turns");
			this->nbTurns = nbTurns;
		};
		void start() noexcept;
	};
}