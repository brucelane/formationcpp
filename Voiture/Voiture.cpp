
#include <iostream>

using namespace std;

using Vitesse = int;
using Acceleration = Vitesse;
using Deceleration = Vitesse;
// Ctrl+D Dupliquer la selection
class Voiture {
	const Vitesse VITESSE_MAXIMUM = 129;
private:
	Vitesse vitesse{0};
	void SetVitesse(Vitesse vitesse) {
		if (vitesse < VITESSE_MAXIMUM) {
			this->vitesse = vitesse;
			cout << "Vitesse: " << vitesse << endl;
		}
	}

public:
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
	Voiture v1;
	v1.demarrer(Vitesse{ 30 });
	v1.accelerer(Acceleration{ 15 });
	v1.ralentir(Deceleration{ 30 });
	v1.stopper();


}

