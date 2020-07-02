#pragma once

#include <iostream>
#include <ctime>
#include <string>

using std::string; // only needed
using std::cout;
using std::endl;
using std::exception;

namespace Agaz {
	using Value = unsigned;
	using FaceValue = Value;
	using Score = unsigned;
	using Name = string;
	using Turns = unsigned;

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
}