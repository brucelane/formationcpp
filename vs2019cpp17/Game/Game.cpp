#include "Game.h"

using namespace Agaz;

void Game::start() noexcept
{

	for (unsigned turn{ 1 }; turn < this->nbTurns; ++turn)
	{
		cout << "Tour " << turn << endl;
		for (Player& player : players) { // ne pas oublier & pour ne pas faire de copie
			player.takeTurn(cup);
		}
	}
	displayWinner();

}
void Game::displayWinner() const noexcept {
	
	const Player* winner{ &players.front() };
	// const pour protéger les players contre modifs
	for (const Player& player : players) {
		if (player.getScore() > winner->getScore()) {
			winner = &player;
		}
	}
	
	cout << "Gagnant: " << winner->getName() << " " << winner->getScore() << endl;

};
