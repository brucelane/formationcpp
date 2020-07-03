#pragma once

#include "types.h"

namespace GameNS {

  class Dice {
    FaceValue faceValue;
  public:
    Dice() {roll();}

    void roll() noexcept {
      class Random {
      public:
        Random() { srand((unsigned)time(0)); }
        Value nextValue(Value minValue, Value maxValue) const noexcept {
          return minValue + (rand() % maxValue);
        }
      };

      static Random random;
      const FaceValue MIN_VALUE{ 1 };
      const FaceValue MAX_VALUE{ 6 };
      faceValue = random.nextValue(MIN_VALUE, MAX_VALUE);
    }
    void display() const noexcept { cout << faceValue; }
    FaceValue getFaceValue() const noexcept { return faceValue; }
  };

}