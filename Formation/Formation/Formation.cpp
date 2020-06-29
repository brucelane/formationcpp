// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

using Dimension = int; // peut être changer en double
Dimension Longueur;
Dimension Largeur;

enum class Couleur: int8_t { ROUGE = 1, VERT, ORANGE };
int main()
{
	Couleur c{ Couleur::VERT };
	string s{ "chaine" };
	Largeur = 3;
	long long ll{ 67LL };
	int n{};
	bool b{ 1 };
	int p = n;
	if (b) {
		std::cout << b << "vrai" << endl;
	}
	else {
		std::cout << b << "faux" << endl;
	}
}
