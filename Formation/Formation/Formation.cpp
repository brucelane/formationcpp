// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
//using namespace std;

using Dimension = int; // peut être changer en double
Dimension Longueur;
Dimension Largeur;

enum class Couleur : int8_t { ROUGE = 1, VERT, ORANGE };
void f() {};
void f(int) {};
void f(float) {};
int main(int argc, char** argv)
{
	std::cout << argc << " args " << std::endl;
	//std::cout << argv[0] << " argv0 " << std::endl;

	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] <<  std::endl;
	}
	/*Couleur c{ Couleur::VERT };
	std::string s{ "chaine" };
	Largeur = 3;
	long long ll{ 67'000'000LL };
	int n{ 0b001 }, i{ 4 };
	bool b{ 1 };
	int* p = { &i };
	int* adresse{ nullptr }; // ne jamais utiliser NULL
	p = &n;
	if (p != nullptr) {
		*p = 99;
	}
	//std::cin >> i;
	if (b) {
		std::cout << b << " vrai p " << p << " *p " << *p << " i " << i << " " << typeid(nullptr).name() << " " << typeid(c).name() << " " << typeid(p).name() << std::endl;
	}
	else {
		std::cout << b << " faux " << std::endl;
	}*/
	return 0;
}
