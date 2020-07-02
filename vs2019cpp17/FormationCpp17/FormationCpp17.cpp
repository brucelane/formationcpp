
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
		cout << "Constructeur Moteur" << endl;
	}
	~Moteur() { cout << "Destructeur Moteur" << endl; }
};


class Voiture {
private:
	static inline Vitesse vitesseMax{ 129 };

	const Couleur couleur;
	const Moteur moteur;
	//const Vitesse VITESSE_MAXIMUM =
	Vitesse vitesse{ 0 };
	void SetVitesse(Vitesse vitesse) {
		if (vitesse < getVitesseMax()) {
			this->vitesse = vitesse;
			cout << "Vitesse: " << vitesse << endl;
		}
	}

public:
	Voiture(Couleur couleur, Cylindree cylindree) :
		couleur{ couleur },
		moteur(cylindree)
	{
		cout << "Constructeur Voiture" << endl;
	}
	static Vitesse getVitesseMax() {
		return vitesseMax;
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
	~Voiture() { cout << "Destructeur Voiture" << endl; }
};
double mySqrt(double d) /*noexcept(true)*/ {
	if (d <= 0) throw exception{ "Valeur non positive" };
	return sqrt(d);
}
class A {
public:
	A() { cout << "ctor" << endl; }
	~A() { cout << "dtor" << endl; }
	void doIt() const { cout << "doit" << endl; }
};
void f(const A& a) {
	a.doIt();
}
// global data segment
A globalA;

int main()
{
	cout << "1" << endl;
	A{}.doIt();
	cout << "2" << endl;
	f(A{});
	cout << "3" << endl;
	for (int n{ 0 };n < 3; ++n)
	{
		double d;
		cout << "nombre?" << endl;
			cin >> d;
			try
			{
				cout << mySqrt(d) << endl;
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
			}
	}
	
	
		Voiture v1{ Couleur::ROUGE, Cylindree::CC_2000 };
		v1.demarrer(Vitesse{ 30 });
		v1.accelerer(Acceleration{ 15 });
		v1.ralentir(Deceleration{ 30 });
		v1.stopper();

		string s; // creation objet
		s = "t"; // puis init
		string s2{ "r" }; // mieux pour performance
	
	cout << Voiture::getVitesseMax() << endl;
}

