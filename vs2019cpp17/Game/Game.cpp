#include "Game.h"


void Agaz::Game::start() noexcept
{

	for (unsigned turn{ 1 }; turn < this->nbTurns; ++turn)
	{
		cout << "Tour " << turn << endl;
		player1.takeTurn(cup);
		player2.takeTurn(cup);
	}
	displayWinner();

}
