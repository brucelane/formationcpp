#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main()
{

  map<int, string> dico {
    {0, "bonjour"},
    {1, "hello"},
    {2, "guten tag"},
    {3, "hola"}
  };

  int choix{2};

  cout << dico[choix] << endl;

  //switch (choix) {
  //  case 0:
  //    cout << "bonjour\n";
  //    break;

  //  case 1:
  //    cout << "hello\n";
  //    break;

  //  case 2:
  //    cout << "guten tag\n";
  //    break;

  //  default:
  //    cout << "renouveller votre choix\n";
  //    break;
  //}

  cout << "sortie\n";
}

