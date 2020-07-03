#include "Game.h"


using namespace Agaz;

void Game::start() noexcept
{

	for (unsigned turn{ 1 }; turn < this->nbTurns; ++turn)
	{
		cout << "Tour " << turn << endl;
		// protégé par Player(const Player&) = delete; 
		for (Player& player : players) { // ne pas oublier & pour ne pas faire de copie, avec la protection pas possible de l'enlever
			player.takeTurn(cup); // le score de la copie disparaitrait!
		}
	}
	displayWinner();

}
void Game::displayWinner() const noexcept {
	
	/*const Player* winner{ &players.front() };
	// const pour protéger les players contre modifs
	for (const Player& player : players) {
		if (player.getScore() > winner->getScore()) {
			winner = &player;
		}
	}*/
	const Player& winner{ *max_element(cbegin(players), cend(players)) };
	cout << "Gagnant: " << winner << " " << winner.getScore() << endl;

};
