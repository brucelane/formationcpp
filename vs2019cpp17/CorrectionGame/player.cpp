#include "player.h"

void GameNS::Player::takeTurn(Cup& cup) noexcept
{
  cup.roll();
  Value value{ cup.getValue() };
  score += value;
  cout << name << " got " << value << " points ";
  cup.display();
  cout << "\n";
}