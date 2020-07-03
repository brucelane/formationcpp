#include "Game.h"


using namespace Agaz;

void Game::start() noexcept
{

	for (unsigned turn{ 1 }; turn < this->nbTurns; ++turn)
	{
		cout << "Tour " << turn << endl;
		// protégé par Player(const Player&) = delete; 
		/* list for (Player& player : players) { // ne pas oublier & pour ne pas faire de copie, avec la protection pas possible de l'enlever
			player.takeTurn(cup); // le score de la copie disparaitrait!
		}*/
		for (auto& paire : players) { // const ?
			paire.second.takeTurn(cup);
		}
		/*for (const pair<Name, Player>& paire : notes) {
			cout << paire.first << "" << paire.second << endl;
		}*/
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
	// list const Player& winner{ *max_element(cbegin(players), cend(players)) 
	const auto pair {
		max_element(
			cbegin(players),
			cend(players),
			[](const auto& paire1, const auto& paire2) {return paire1.second < paire2.second; }
		)
	};
	const Player& winner{ pair->second };
	cout << "Gagnant: " << winner << " " << winner.getScore() << endl;

};
