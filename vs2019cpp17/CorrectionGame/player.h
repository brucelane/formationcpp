#pragma once

#include "Cup.h"

namespace GameNS {

  class Player {
    const Name name;
    Score score{ 0 };

  public:
    Player(const Player&) = delete;
    Player(const Name& name) noexcept (false):
      name{ name }
    {
      if (name.empty())
        throw exception{ "empty name" };
    }

    void takeTurn(Cup& cup) noexcept;
    Score getScore() const noexcept { return score; }

    friend ostream& operator<< (ostream& o, const Player& player) {
      return o << player.name;
    }
  };
}