#include "game.h"

using namespace GameNS;

void Game::start() noexcept
{
  cout << "WELCOME TO LAS VEGAS\n\n";

  for (unsigned turn{ 1 }; turn <= nbTurns; ++turn) {
    cout << "\nturn #" << turn << "\n";

    for (Player& player : players)
      player.takeTurn(cup);
  }
  displayWinner();
}

void Game::displayWinner() const noexcept {

  const Player* winner{ &players.front() };

  for (const Player& player : players)
  {
    if (player.getScore() > winner->getScore())
      winner = &player;
  }

  cout << "\n" << *winner << " won with " << winner->getScore() << " points \n";
}
