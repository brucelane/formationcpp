
#include <iostream>
#include <string>

using namespace std;

using Rayon = double;
using Surface = double;
using Vitesse = int;
using Acceleration = Vitesse;
using Deceleration = Vitesse;
// Ctrl+D Dupliquer la selection
enum class Couleur { ROUGE, VERT, POURPRE };
using Filename = string;
const double PI{ 3.14159 };
class Shader {
	const Filename filename;
	Rayon rayon;
public:
	Shader(Filename filename, Rayon rayon) :
		filename{ filename },
		rayon { rayon }
	{
		cout << "Constructeur Shader" << endl;
	}
	// mutator
	void setRayon(Rayon rayon) {
		this->rayon = rayon;
	}
	Surface getSurface() const {
		// erreur mutation if (rayon = 0) return 0; protction avec const
		return (rayon == 0) ? 0 : 4.0 / 3 * PI*pow(rayon, 3);
	}
	~Shader() { cout << "Destructeur Shader" << endl; }
};

class Fbo {
private:
	const Couleur couleur;
	const Shader shader;
	const Vitesse VITESSE_MAXIMUM = 129;
	Vitesse vitesse{ 0 };
	void SetVitesse(Vitesse vitesse) {
		if (vitesse < VITESSE_MAXIMUM) {
			this->vitesse = vitesse;
			cout << "Vitesse: " << vitesse << endl;
		}
	}

public:
	Fbo(Couleur couleur, Filename filename) :
		couleur{ couleur },
		shader(filename, Rayon{ 10 })
	{
		cout << "Constructeur Fbo" << endl;
	}
	// inspecteur accesseur
	int getqq() const {
		return 3;
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
	~Fbo() { cout << "Destructeur Fbo" << endl; }
};

class A {
public:
	A() = default;// plus clair que {}
	//A(const A& src) { cout << "copie\n"; }
	A(const A& src) = delete; // pour interdire copie
};


int main()
{
	A a;
	// impossible A a2{ a };
	{
		const Fbo mix{ Couleur::ROUGE, "0.glsl" };
		/* ko car const pour cette instance
		v1.demarrer(Vitesse{ 30 });
		v1.accelerer(Acceleration{ 15 });
		v1.ralentir(Deceleration{ 30 });
		v1.stopper();*/

		string s; // creation objet
		s = "t"; // puis init
		string s2{ "r" }; // mieux pour performance
	}
	cout << "Fin " << endl;
}

