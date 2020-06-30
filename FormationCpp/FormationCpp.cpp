// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <map>
#include <array>

using namespace std;
void display(const int* begin, const int* end) {
	// surtout pas  ++ ou +1 on est sur des adr
	while (begin != end) {
		cout << *begin << ", ";
		++begin;
	}
	cout << endl;
}
const int* max_element(const int* begin, const int* end) {	
	const int* itor{ begin };
	while (begin != end) {
		if (*begin > *itor) { 
			itor = begin; 
		};
		++begin;
	}
	return itor;
}
using func = int(*)(int, int); // avant C++11
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
void doIt(func f, int a, int b) {
	cout << f(a, b) << endl;
}
void doThis(int(*f)(int, int), int a, int b) {
	cout << f(a, b) << endl;
}
using Pred = bool(*)(int);
unsigned count_if(const int* begin, const int* end, Pred pred) {
	unsigned compteur{};
	while(begin != end) {
		if (pred(*begin)) {
			++compteur;
		}
		++begin;
	}
	return compteur;
}
bool isNegatif(int n) { return n < 0; }
bool isPositif(int n) { return n >= 0; }

int somme(initializer_list<int> liste) {
	int resultat{};
	for (int n : liste) {
		resultat += n;
	}
	return resultat;
}

int main()
{
	cout << somme({ 12, 78 }) << endl;
	cout << somme({ 12, 78, 890 }) << endl;

	//int tab[]{ 12, 3, 78, -12, 3, -2, 3 };
	int tab[10];
	//generate(begin(tab), end(tab), rand);
	generate(begin(tab), end(tab), [] {return (rand() % 10) - 5; });
	cout << all_of(cbegin(tab), cend(tab), [](int n) {return n > 0; }) << endl;
	cout << count_if(cbegin(tab), cend(tab), isNegatif) << endl;
	cout << count_if(cbegin(tab), cend(tab), isPositif) << endl;
	// lambda
	cout << 
		count_if(
			cbegin(tab), 
			cend(tab), 
			[](int n) {return n >= 0;}
		) << endl;
	// cbegin lecture seule begin écriture
	cout << *find_if(cbegin(tab), cend(tab), [](int n) {return n < 0; }) << endl;

	sort(begin(tab), end(tab));
	display(begin(tab), end(tab));
	const int* iterator{ max_element(begin(tab), end(tab)) };
	int n{};
	//const val const ptr
	const int* const p{ &n };
	// ko *p = 99;
	// ko p = nullptr;
	int tabio[20];
	iota(begin(tabio), end(tabio), 87);
	cout << "iter:" << *iterator << "\n";
	display(begin(tabio), end(tabio));
	for (int n : tabio) {} // pas de modif des elements
	for (int& n : tabio) {} // modif des elements

//inutile func a{ add };
	//inutile func s{ sub };
	doIt(add, 3, 7);
	doIt(sub, 3, 7);
	return 0;
}
