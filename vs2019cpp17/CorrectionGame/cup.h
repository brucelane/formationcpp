#pragma once

#include "dice.h"

namespace GameNS {

  class Cup {
    vector<Dice> dices;

  public:

    Cup(unsigned nbDices) : dices( nbDices ) {
      static const unsigned MIN_NB_DICES{ 1 };
      static const unsigned MAX_NB_DICES{ 10 };
      if (nbDices < MIN_NB_DICES or nbDices > MAX_NB_DICES)
        throw exception{ "invalid number of dices" };
    }

    void roll() {
      for (Dice& dice : dices)
        dice.roll();
    }

    void display() const noexcept {
      cout << "[ ";
      
      for (const Dice& dice : dices)
        cout << dice.getFaceValue() << " ";
      
      cout << "]";
    }

    Value getValue() const noexcept {
      Value value{};
      for (const Dice& dice : dices)
        value += dice.getFaceValue();
      return value;
    }
  };
}