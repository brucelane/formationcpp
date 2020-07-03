#pragma once

#include "player.h"

namespace GameNS {

  class Game {
    unsigned nbTurns{ 3 };
    Cup cup;
    list<Player> players;

    void displayWinner() const noexcept;

  public:

    Game(unsigned nbDices) : cup{ nbDices } {}

    void enrol(const Name& name) { players.emplace_back(name); }

    void setup(unsigned nbTurns) noexcept (false) {
      const unsigned MIN_NB_TURNS{ 1 };
      if (nbTurns < MIN_NB_TURNS)
        throw exception{ "invalid number of turns"};
      this->nbTurns = nbTurns;
    }

    void start() noexcept;
  };

}