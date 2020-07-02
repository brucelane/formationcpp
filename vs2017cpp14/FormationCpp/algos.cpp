#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

using namespace std;

void reset(int* begin, int* end) {
  while (begin != end) {
    *begin = 0;
    ++begin;
  }
}

void display(const int* begin, const int* end) {
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
  cout << "\n";
}

unsigned nbNégatifs (const int* begin, const int* end) {
  unsigned compteur{};
  while (begin != end) {
    if (*begin < 0) ++compteur;
    ++begin;
  }
  return compteur;
}

unsigned count (const int* begin, const int* end, int value) {
  unsigned compteur{};
  while (begin != end) {
    if (*begin == value) ++compteur;
    ++begin;
  }
  return compteur;
}

const int* max_element(const int* begin, const int* end) {  
  
  const int* itor{ begin };
  while (begin != end) {
    if (*begin > *itor)
      itor = begin;
    ++begin;
  }
  return itor;

}

int main(){

  int tab[]{ 56, 78, -34, -4567, 89, 123 };

  const int* iterator{ std::max_element(cbegin(tab), cend(tab)) };
  cout << *iterator << endl;   // 89


  for (int n : tab) {
    cout << n << " ";
  }
  cout << endl;

  unsigned compteurNégatifs{};
  for (int n : tab) {
    if (n < 0)
      ++compteurNégatifs;
  }
 
  cout << compteurNégatifs << "\n";

  unsigned nbOccurences{};
  const int value{ 3 };
  for (int n : tab) {
    if (n == value)
      ++nbOccurences;
  }
  cout << nbOccurences << "\n";

  cout << nbNégatifs(begin(tab), end(tab)) << endl;
  cout << std::count(begin(tab), end(tab), 3) << endl;

  display(begin(tab) + 2, end(tab) - 2);
  reset(begin(tab), end(tab));



  display(begin(tab), end(tab));
}

