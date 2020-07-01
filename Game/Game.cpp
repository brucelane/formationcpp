#include <iostream>
#include <ctime>
using namespace std;

using FaceValue = unsigned;

class Dice {
	FaceValue faceValue;
public:
	Dice() {
		srand((unsigned)time(0));
		roll();
	}
	void roll() {
		const FaceValue MIN_VALUE{ 1 };
		const FaceValue MAX_VALUE{ 6 };
		faceValue = MIN_VALUE + (rand() % MAX_VALUE);
	}
	void display() const { cout << faceValue << "\n"; }
	FaceValue getFaceValue() const { return faceValue; }
};
using CupContent = unsigned;
class Cup {
private:
	Dice d1, d2;
public:
	void roll() {
		d1.roll(); d2.roll();
	}
	void display() const {
		cout << "[" << d1.getFaceValue() << "," << d2.getFaceValue() << "]"  << endl;
	}
	CupContent getValue() const {
		return d1.getFaceValue() + d2.getFaceValue();
	}
};

int main()
{
	Cup cup;
	cup.roll();
	cup.display();
	cout << cup.getValue() << endl;
	/*Dice d;
	d.display();
	d.roll();
	d.display();
	d.roll();
	d.display();
	d.roll();
	d.display();
	d.roll();
	d.display();
	d.roll();
	d.display();
	cout << d.getFaceValue() << endl;*/
}
