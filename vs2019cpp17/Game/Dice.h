#pragma once
#include "types.h"

namespace Agaz {

	



	class Dice {
		FaceValue faceValue;
	public:
		Dice() {

			roll();
		}
		void roll() noexcept {
			static Random random;
			const FaceValue MIN_VALUE{ 1 };
			const FaceValue MAX_VALUE{ 6 };
			faceValue = random.nextValue(MIN_VALUE, MAX_VALUE);
		}
		void display() const noexcept { cout << faceValue; }
		FaceValue getFaceValue() const noexcept { return faceValue; }
	};
}