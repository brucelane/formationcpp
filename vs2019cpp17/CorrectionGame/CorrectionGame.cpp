#include "game.h"

using namespace GameNS;

int main()
{
    try {
        unsigned nbDices{ 15 };
        Game game{ nbDices };
        game.enrol("Geronimo");
        game.enrol("Sitting Bull");
        game.enrol("Red hat");

        unsigned nbTurns{ 3 };
        game.setup(nbTurns);

        game.start();   // Geronimo won with 34 points
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}
