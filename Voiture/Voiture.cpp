
#include <iostream>

using namespace std;

using Vitesse = int;
using Acceleration = Vitesse;
using Deceleration = Vitesse;
// Ctrl+D Dupliquer la selection
enum class Couleur { ROUGE, VERT, POURPRE };
enum class Cylindree { CC_200, CC_250, CC_500, CC_2000, CC_4200 };

class Moteur {
	const Cylindree cylindree;
public:
	Moteur(Cylindree cylindree) :
		cylindree{ cylindree }
	{
	}
};

class Voiture {
private:
	Couleur couleur;
	Moteur moteur;
	const Vitesse VITESSE_MAXIMUM = 129;
	Vitesse vitesse{ 0 };
	void SetVitesse(Vitesse vitesse) {
		if (vitesse < VITESSE_MAXIMUM) {
			this->vitesse = vitesse;
			cout << "Vitesse: " << vitesse << endl;
		}
	}

public:
	Voiture(Couleur couleur, Cylindree cylindree) :
		couleur{ couleur },
		moteur(cylindree)
	{
	}
	void demarrer(Vitesse vitesse) {
		this->SetVitesse(vitesse);

	}
	void accelerer(Acceleration acceleration) {
		this->SetVitesse(vitesse + acceleration);
	}
	void ralentir(Deceleration deceleration) {
		this->SetVitesse(vitesse + deceleration);
	}
	void stopper() {
		this->SetVitesse(0);
	}
};

int main()
{
	Voiture v1{ Couleur::ROUGE, Cylindree::CC_2000 };
	v1.demarrer(Vitesse{ 30 });
	v1.accelerer(Acceleration{ 15 });
	v1.ralentir(Deceleration{ 30 });
	v1.stopper();

	string s; // creation objet
	s = "t"; // puis init
	string s2{ "r" }; // mieux pour performance
}

