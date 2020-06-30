// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <algorithm>
#include <numeric>
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
int main()
{
	//inutile func a{ add };
	//inutile func s{ sub };
	doIt(add, 3, 7);
	doIt(sub, 3, 7);

	int tab[]{ 12, 3, 78, -12, 3, -2, 3 };
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


	return 0;
}
