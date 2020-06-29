// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <array>
//
using namespace std;

using Dimension = int; // peut être changé en double
using Longueur = Dimension;
using Largeur = Dimension;
using Surface = Dimension;

enum class Couleur : int8_t { ROUGE = 1, VERT, ORANGE };
void f() {};
void f(int) {};
void f(float) {};
//byval in
/*void reset(int val) {
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
// en C moins lisible
void swap(int* a, int* b) {
	int c{ *a };
	*a = *b;
	*b = c;
}
// en C++ mieux avec refs que ptr du C
void swap(int& a, int& b) {
	int c{ a };
	a = b;
	b = c;
}*/
void reset(int* begin, int* end) {
	// surtout pas  ++ ou +1 on est sur des adr
	while (begin != end) {
		*begin = 0;
		++begin;
	}
}
void display(int* begin, int* end) {
	// surtout pas  ++ ou +1 on est sur des adr
	while (begin != end) {
		cout << *begin << ", ";
		++begin;
	}
	cout << endl;
}
unsigned nbNegatifs(int* begin, int* end) {
	// surtout pas  ++ ou +1 on est sur des adr
	unsigned cpt{ 0 };
	while (begin != end) {
		if (*begin < 0) { cpt++; };
		++begin;
	}
	cout << endl;
	return cpt;
}
unsigned count(int* begin, int* end, int value) {
	// surtout pas  ++ ou +1 on est sur des adr
	unsigned cpt{ 0 };
	while (begin != end) {
		if (*begin == value) { cpt++; };
		++begin;
	}
	cout << endl;
	return cpt;
}
int main()//int argc, char** argv
{
	//array<int, 10> tab;// utiliser au lieu tab[10]
	//tab.size();
	//int tab1[10]{ 12, 78, -12 };
	//display(begin(tab1), end(tab1));// end au lieu de tab + 10

	int tab[]{ 12, 3, 78, -12, 3, -2, 3 };
	for (int n : tab)
	{
		cout << n << endl;
	}
	unsigned cptNeg{};
	for (int n : tab)
	{
		if (n < 0) {
			cptNeg++;
		}
	}
	cout << "cptNeg:" << cptNeg << "\n";

	unsigned nbOccur{};
	const int value{ 3 };
	for (int n : tab)
	{
		if (n == value) { 
			nbOccur++;
		}
	}
	cout << "nbOccur:"  << nbOccur << "\n";


	cout << "Neg:" << nbNegatifs(begin(tab), end(tab)) << endl;
	cout << "Count:" << count(begin(tab), end(tab), 3) << endl; //2	


	display(tab, end(tab));// end au lieu de tab + 10
	//cout << tab[0] << endl; // nawak
	reset(tab, end(tab));
	//cout << tab[0] << endl; // 0
	display(tab, end(tab));


	// pour remplacer un switch à bannir
	/*std::map<int, std::string> dico{
		{0, "bonjour"},
		{1, "hi"},
		{2, "tag"},
	};
	int choix{ 2 };
	std::cout << dico[choix] << std::endl;
	// pour remplacer un switch


	int n{}; // 0 par défaut
	reset(n); // byval
	std::cout << " byval " << n << std::endl;
	riset(n); // byref
	std::cout << " byref " << n << std::endl;
	riset2(&n); // byref bof
	std::cout << " byref bof " << n << std::endl;
	getSurf(Longueur{ 12 }, Largeur{ 7 }); // clean
	int a{ };
	int b{ 1 };
	int max{ a > b ? a : b };

	if (a > 0 and b > 1) { // and et or supportés en c++
	}
	std::cout << a << " " << b << std::min<int>(a, b) << std::endl; // 0 1
	swap(a, b);
	swap(&a, &b);
	std::cout << a << " " << b << std::endl; // 1 0
	*/
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
