
#include "Game.h"

using namespace Agaz;
// cpp17 static inline

int main()
{
	try
	{
		Game game{ "Sitting Bull" , "Geronimo" };
		Turns nbTurns{ 2 };
		game.setup(nbTurns);
		game.start();
	}
	catch (const std::exception& e)
	{
		cout << "Erreur" << e.what() << endl;
	}
	cout << "fin";

}
