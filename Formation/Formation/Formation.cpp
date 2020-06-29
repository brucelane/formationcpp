// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
//using namespace std;

using Dimension = int; // peut être changer en double
Dimension Longueur;
Dimension Largeur;

enum class Couleur: int8_t { ROUGE = 1, VERT, ORANGE };
void f() {};
void f(int) {};
void f(float) {};
int main()
{
	Couleur c{ Couleur::VERT };
	std::string s{ "chaine" };
	Largeur = 3;
	long long ll{ 67'000'000LL };
	int n{ 0b001 }, i{ 4 };
	bool b{ 1 };
	int* p = {&n};
	
	std::cin >> i;
	if (b) {
		std::cout << b << "vrai" << p << i << std::endl;
	}
	else {
		std::cout << b << "faux" << std::endl;
	}
}
