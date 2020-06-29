// Formation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <array>

using namespace std;

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
int main()
{
	int tab[]{ 12, 3, 78, -12, 3, -2, 3 };
	const int* iterator{ max_element(begin(tab), end(tab)) };
	int n{};
	//const val const ptr
	const int* const p{ &n };
	// ko *p = 99;
	// ko p = nullptr;
	
	cout << "iter:" << *iterator << "\n";




	return 0;
}
