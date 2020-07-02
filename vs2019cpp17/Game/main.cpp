
#include "Game.h"

using namespace Agaz;
// cpp17 static inline

int main()
{
	// choix nb dés puis fixe (frozen uml)
	try
	{
		//Game game{ "Sitting Bull" , "Geronimo" };
		Game game;
		game.enroll("Geronimo");
		game.enroll("Sitting Bull");
		game.enroll("Red Hat");
		Turns nbTurns{ 2 };
		Turns nbDices{ 3 };
		game.setup(nbTurns/*, nbDices*/);
		game.start();
	}
	catch (const std::exception& e)
	{
		cout << "Erreur" << e.what() << endl;
	}
	cout << "fin" << endl;

}
