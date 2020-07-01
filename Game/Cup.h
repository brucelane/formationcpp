#pragma once
#include "Dice.h"

class Cup {
private:
	Dice dice1;
	Dice dice2;
public:
	void roll() {
		dice1.roll(); dice2.roll();
	}
	void display() const {
		//enlever cette dépendance cout << "[" << d1.getFaceValue() << "," << d2.getFaceValue() << "]"  << endl;
		cout << "[ ";
		dice1.getFaceValue();
		cout << " ";
		dice2.display();
		cout << " ]" << endl;
	}
	Value getValue() const {
		return dice1.getFaceValue() + dice2.getFaceValue();
	}
};
