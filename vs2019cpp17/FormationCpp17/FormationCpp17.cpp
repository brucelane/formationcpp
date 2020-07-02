
#include <iostream>
#include <memory>
#include <vector>
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
class Clim {
private:
public:
	Clim() {};
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
	Clim* pClim;
public:
	Voiture(Couleur couleur, Cylindree cylindree, bool presenceClim) :
		couleur{ couleur },
		moteur(cylindree),
		pClim{ presenceClim ? new Clim : nullptr }
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
	~Voiture() {
		delete pClim;
		cout << "Destructeur Voiture" << endl;
	}
};
double mySqrt(double d) /*noexcept(true)*/ {
	if (d <= 0) throw exception{ "Valeur non positive" };
	return sqrt(d);
}
class A {
public:
	A() { cout << "ctor A" << endl; }
	~A() { cout << "dtor A" << endl; }
	void doIt() const { cout << "doit A\n" << endl; }
};
void f(const A& a) {
	a.doIt();
}
// global data segment
A globalA;

class Conteneur {
	//A* a = nullptr;
	unique_ptr<A> a;
public:
	Conteneur(bool presenceA) {
		//if (presenceA) a = new A;
		if (presenceA) a.reset(new A);
		cout << "ctor Conteneur" << endl;
	}
	void start() const {
		if (a != nullptr) a->doIt();
	}
	~Conteneur() { cout << "dtor Conteneur" << endl; }

};

int main()
{
	vector<int> v;
	v.reserve(100);
	v.size();
	v.push_back(v.size());
	v.push_back(123);
	v.push_back(v.size());
	v.push_back(v.capacity());

	for (int n : v) cout << n << endl;

	Conteneur c{ true };
	unique_ptr<Conteneur> cnt{ new Conteneur(true) };

	shared_ptr<A> up{ new A }; // weak-ptr ptr sur qq chose qui n'existe pitet plus ?
	{
		shared_ptr<A> up1{ up };
		cout << "0" << endl;
	}
	cout << "1" << endl;
	shared_ptr<A> up2{ up };
	cout << "2" << endl;
	/*


	A* pA{ new A[1] };
		pA[0].doIt();
		delete [] pA;

		{
			A tab[1];
			tab[0].doIt();
		}

		A* a{ new A{} }; // c++ c os gest mémoire, couteux
		a->doIt();
		exec(a);

		A* a2{ a }; // ptr sur même objet sur le tas(heap)
		cout << a << " a a2 " << a2 << endl;


		A aa;
		A* pAA{ &aa };
		cout << "0" << endl;
		cout << "1" << endl;
		A{}.doIt(); // sur la pile, anonyme
		cout << "2" << endl;
		f(A{});
		cout << "3" << endl;
		for (int n{ 0 }; n < 3; ++n)
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

		cout << Voiture::getVitesseMax() << endl;*/
		// meme ptr! ne pas faire delete a2;

}

