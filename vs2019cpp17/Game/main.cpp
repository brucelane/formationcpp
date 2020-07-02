
#include "Game.h"

using namespace Agaz;
// cpp17 static inline

int main()
{
	// choix nb dés puis fixe (frozen uml)
	try
	{
		
		unsigned nbDices{ 5 }; //verif 0 pas possible
		Game game{nbDices};
		game.enroll("Geronimo");
		game.enroll("Sitting Bull");
		game.enroll("Red Hat");
		Turns nbTurns{ 2 };
		game.setup(nbTurns);
		game.start();
	}
	catch (const std::exception& e)
	{
		cout << "Erreur" << e.what() << endl;
	}
	cout << "fin" << endl;

}
