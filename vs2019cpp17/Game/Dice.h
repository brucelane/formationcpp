#pragma once
#include "types.h"

namespace Agaz {

	
	class Random {
	public:
		Random()
		{
			cout << "Random ctor, seed generation" << endl;
			srand((unsigned)time(0));
			//lire Settings.json!
		}
		Value nextValue(Value minValue, Value maxValue) const noexcept {
			return minValue + (rand() % maxValue);
		};
		~Random()
		{
			cout << "Random dtor " << endl;
		}
	};

	class Dice {
		FaceValue faceValue;
	public:
		Dice() {

			roll();
		}
		void roll() noexcept {
			static Random random; // possible de créer la classe Random ici si seulement utilisée ici
			const FaceValue MIN_VALUE{ 1 };
			const FaceValue MAX_VALUE{ 6 };
			faceValue = random.nextValue(MIN_VALUE, MAX_VALUE);
		}
		void display() const noexcept { cout << faceValue; }
		FaceValue getFaceValue() const noexcept { return faceValue; }
	};
}