// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
//using namespace std;

using Dimension = int; // peut être changé en double
using Longueur = Dimension;
using Largeur = Dimension;
using Surface = Dimension;

enum class Couleur : int8_t { ROUGE = 1, VERT, ORANGE };
void f() {};
void f(int) {};
void f(float) {};
//byval in
void reset(int val) {
	val = 99;
}
//byref in out
void riset(int& val) {
	val = 99;
}
//byref in out bof
void riset2(int* val) {
	*val = 3;
}
Surface getSurf(Longueur lng, Largeur lar = 10) {
	return lng * lar;
}
// en C++
void swap(int& a, int& b) {
	int c{ a };
	a = b;
	b = c;
}
// en C moins lisible
void swap(int* a, int* b) {
	int c{ *a };
	*a = *b;
	*b = c;
}
int main()//int argc, char** argv
{
	int n{};
	reset(n); // byval
	std::cout << " byval " << n << std::endl;
	riset(n); // byref
	std::cout << " byref " << n << std::endl;
	riset2(&n); // byref bof
	std::cout << " byref bof " << n << std::endl;
	getSurf(Longueur{ 12 }, Largeur{ 7 }); // clean
	int a{ };
	int b{ 1 };
	std::cout << a << " " << b << std::endl; // 0 1
	swap(a, b);
	swap(&a, &b);
	std::cout << a << " " << b << std::endl; // 1 0 
	/* args
	std::cout << argc << " args " << std::endl;
	//std::cout << argv[0] << " argv0 " << std::endl;

	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	int tab[]{ 3, 78, 9 };
	int* debut{ tab };
	std::cout << *debut << std::endl; //1st

	char chaine[]{ 'h', 'i' };*/

	/* types et ptr
	Couleur c{ Couleur::VERT };
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
