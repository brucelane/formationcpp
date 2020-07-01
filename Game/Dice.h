#pragma once
#include "types.h"


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
	void display() const { cout << faceValue; }
	FaceValue getFaceValue() const { return faceValue; }
};
