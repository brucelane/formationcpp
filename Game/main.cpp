
#include "Game.h"

using namespace Agaz;
// cpp17 static inline

int main()
{
	Game game{ "Sitting Bull" , "Geronimo" };
	Turns nbTurns{ 6 };
	game.setup(nbTurns);
	game.start();
	cout << "fin";

}
