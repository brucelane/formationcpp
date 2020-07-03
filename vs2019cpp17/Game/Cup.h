#pragma once
#include "Dice.h"


using std::endl;

namespace Agaz {
	class Cup {
	private:
		vector<Dice> dices; // nb de dés frozen
		
	public:
		Cup(unsigned nbDices) : dices(nbDices) {
			static const unsigned MIN_NB_DICES{ 1 };
			static const unsigned MAX_NB_DICES{ 10 };
			if (nbDices < MIN_NB_DICES or nbDices > MAX_NB_DICES) {
				throw exception{ "invalid number of dices" };
			}
		} // frozen ()oui {} non!
		void roll() {
			for (Dice& dice : dices) {// ERR & obligatoire grace au delete du ctor de copie
				dice.roll();
			}

		}
		/* << void display() const noexcept {
			//enlever cette dépendance cout << "[" << d1.getFaceValue() << "," << d2.getFaceValue() << "]"  << endl;
			cout << "[ ";
			for (const Dice& dice : dices) {// ERR & obligatoire grace au delete du ctor de copie
				cout << " " << dice.getFaceValue();
			}
			cout << " ]" << endl;
		}*/
		Value getValue() const noexcept {
			Value value{ 0 };
			for (const Dice& dice : dices) {// ERR
				value += dice.getFaceValue();
			}
			return value;
		}
		friend ostream& operator<< (ostream& o, const Cup& cup) {
			o << "[ ";
			for (const Dice& dice : cup.dices)
				o << dice << " ";
			return o << "]";
		}
		
	};
}