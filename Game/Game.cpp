#include <iostream>
#include <ctime>
#include <string>
using namespace std;

using Value = unsigned;
using FaceValue = Value;
using Score = unsigned;
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
		dice1.display();
		cout << " ";
		dice2.display();
		cout << " ]" << endl;
	}
	Value getValue() const {
		return dice1.getFaceValue() + dice2.getFaceValue();
	}
};
using Name = string;
class Player {
private:
	const Name name;
	Score score{ 0 };
public:
	Player(Name name) : name{ name } {
	}
	//void setScore(Score score) { this->score += score; }
	Score getScore() const { return this->score; }
	Name getName() const { return this->name; }
	void takeTurn(Cup cup) {
		cup.roll();
		Value value{ cup.getValue() };
		this->score += value;
		cout << cup.getValue() << " points pour" << this->name << endl;
		//this->setScore(cup.getValue());
	};
};
using Turns = unsigned;
class Game {
private:
	Turns turns;
	Player player1;
	Player player2;
	Cup cup;

public:
	Game(const Name& name1, const Name& name2) :
		player1{ name1 },
		player2{ name2 }
	{
	}
	void setup(Turns turns) {
		this->turns = turns;
	};
	void start() {
		for (unsigned turn{ 1 }; turn < this->turns; ++turn)
		{
			cout << "Tour " << turn << endl;
			player1.takeTurn(cup);
			player2.takeTurn(cup);

			//cout << "Gagnant tour " << turn << ": " << ((player1.getScore() > player2.getScore()) ? player1.GetName() : player2.GetName()) << endl;
		}
		const Player& winner{
			player1.getScore() > player2.getScore() ? player1 : player2
		};
		cout << "Gagnant: " << winner.getName() <<" " << winner.getScore() << endl;
			//cout << "Gagnant: " << ((player1.getScore() > player2.getScore()) ? player1.GetName() : player2.GetName()) << endl;
	};
};
int main()
{
	Game game{ "Sitting Bull" , "Geronimo" };
	Turns nbTurns{ 6 };
	game.setup(nbTurns);
	game.start();
	cout << "fin";
	/*Cup cup;
	cup.roll();
	cup.display();
	cout << cup.getValue() << " points" << endl;
	*/
}
