
#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
//using std::map;

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
	void Reparer() {} // v.GetMoteur().Reparer non!
	void Casser() {}
	~Moteur() { cout << "Destructeur Moteur" << endl; }
};
class Clim {
private:
public:
	Clim() {};
};
using Prix = double;
class Voiture {
private:
	Prix prix;
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
	Voiture(Couleur couleur, Cylindree cylindree, bool presenceClim, Prix prix) :
		couleur{ couleur },
		moteur(cylindree),
		pClim{ presenceClim ? new Clim : nullptr},
		prix {prix} 
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
	void Reparer() { /*moteur.Reparer();*/ }
	friend class Garagiste;

};
class Garagiste {
public:
	void reparer(Voiture& v) {
		v.Reparer();
	}
};


double mySqrt(double d) /*noexcept(true)*/ {
	if (d <= 0) throw exception{ "Valeur non positive" };
	return sqrt(d);
}
class A {
public:
	A() { cout << "ctor A" << endl; }
	A(int n) { cout << "ctor 1" << endl; }
	A(int n, double d) { cout << "ctor 1" << endl; }
	A(const initializer_list<int>& liste) { cout << "ctor 2" << endl; }
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
class Point {
	int x;
	int y;
public:
	Point(int x, int y) : x{ x }, y{ y } {}
	Point operator + (const Point& other) const {
		return Point{ this->x + other.x,this->y + other.y };
	}
	Point operator - (const Point& other) const {
		//Point copy{ *this }; copy -= other; return copy;
		return Point{ *this } -= other; // copie utilise -= operateur
		//return Point{ this->x - other.x,this->y - other.y };
	}
	Point operator -= (const Point& other) {
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Point operator * (int n) const {
		return Point{ x * n, y * n }; // this facultatif
	}
	Point& operator *= (int n) {
		this->x -= n;
		this->y -= n;
		return *this;
	}
	friend ostream& operator << (ostream& o, const Point& pt) {
		return o << "(" << pt.x << ", " << pt.y << ")";
	}
};
// utiliser set pour remplacer map dans vd? multiset si doublons

using Code = string;
using Titre = string;
using Auteur = string;
using Duree = unsigned;

class Texture {
private:
	const Titre titre;
protected: // pas accessible, que des sous-classes dérivées
	//Texture() = default;
	Texture(const Titre& titre) :
		titre{ titre }
	{};
	string name{ "" };
	virtual void afficher(ostream &o) const noexcept = 0 {
		o << titre << ", ";
	};
public:
	friend ostream& operator<< (ostream& o, const Texture& tex) {
		tex.afficher(o);
		return o;
	}
	virtual ~Texture() { cout << "dtor tex" << endl; };
};	

enum class Genre {WAVE, LINEIN};
class TAudio : public Texture {
	const Duree duree;
	const Auteur auteur;
	const Genre genre;
	//void doIt() override { name = ""; };
	void afficher(ostream& o) const noexcept override {
		Texture::afficher(o);
		static const map<Genre, string> g { {Genre::WAVE, "wave"}, { Genre::LINEIN, "mic in" }};
		o << auteur << g.at(genre) << duree;
	};
public:
	TAudio(const Titre& titre, const Auteur& auteur, const Duree& duree, const Genre& genre ) : 
		Texture{ titre }, 
		duree{ duree },
		genre{ genre } {}
	
	~TAudio() { cout << "dtor TAudio" << endl; };
};

class TImage : public Texture {
	const Code code;
	void afficher(ostream& o) const noexcept override {
		Texture::afficher(o);
		o << code ;
	};
public:
	TImage(const Titre& titre, const Code& code) : 
		Texture{ titre }, 
		code{ code } {}
	//void doIt() override { name = ""; };

	~TImage() { cout << "dtor TImage" << endl; };
};
int main()
{
	// ctor protected impossible Texture ta{};
	TAudio ta{ Titre {"song"}, Code {"c99"}, Duree{330}, Genre::WAVE };
	//ta.afficher(cout);
	TImage ti{ Titre {"jpg"}, Auteur {"bl"} };
	//ti.afficher(cout);
	Texture& t{ ti };
	//t.afficher(cout);
	cout << ta << endl << ti << endl << t << endl;

	Texture* l{ new TImage { Titre {"jpg"}, Auteur {"bl"} } };
	//l->afficher(cout);
	delete l;
/*	map <int, string> dico {
		{1, "one"},
		{2, "two"}
	};
	int n;
	cout << "chiffre? => ";
	cin >> n;
	dico["t"] = 20;
	dico["tu"] = 2;
	for (const auto& paire : dico) {
		cout << paire.first << "" << paire.second << endl;
	}
	for (const pair<string,unsigned>& paire : dico) {
		cout << paire.first << "" << paire.second << endl;
	}
	auto n{ 123.34 };
	cout << typeid(n).name()  << endl;
		Point p1{ 2, 3 };
	cout << "p:" << p1 << endl;
	ofstream{ "p.txt" } << p1 << "\n"; // fopen à bannir

	ostringstream oss;
	oss << p1 << "ok\n";
	cout << oss.str() << endl; // ou socket si besoin
	// pas de try catch possible, trop ancien C
	ifstream ifs{ "input.txt" };
	if (!ifs.good()) {
		cout << "inexistant" << endl;
	}

	Point p2{ 4, 5 };
	Point p3{ p1 + p2 };
	Point p4{ p1 - p2 };
	Point p5{ p1 * 3 };
	p5 -= p2;
	p2 *= 5;
	int tab[3];//tab[3]=12 pas d'exception ça plante... ne plus utiliser  les tableaux []
	// lol p5.operator+(p2);
	cout << "fin" << endl;
	try
		{
			array<int, 3> tab; //classe
			tab.at(3) = 12;
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}


		deque<int> c(23, 789); //val 1,2,3 (23, 789) taille, val 1
		cout << c.size() << " c " << c[0] << endl;
		deque<int> collection{ 23, 789 }; //val 1,2,3 (23, 789) taille, val 1
		cout << collection.size() << " c " << collection[0] << endl;

		list<int> l{ 26, 76 };
		vector<int> vec{ cbegin(l),cend(l) };
		vector<int>::iterator itor{ begin(vec) };
		cout << *itor << endl;
		++itor;
		cout << *itor << endl;

		vector<A> v;
		//v.push_back(A{123}); non car ctor par copie
		v.emplace_back(123, 56.32); //economique

		vector<int> v;
		for (int i{ 0 }; i < 16; ++i) {
			v.push_back(i);
			cout << v.size() << " c " << v.capacity() << endl;
		}


		v.reserve(100);
		v.size();
		v.push_back(v.size());
		v.push_back(123);
		v.push_back(v.size());
		v.push_back(v.capacity());

		for (int n : v) cout << n ;

		cout << "A a1(12) "  << endl;
		A a1(12);
		cout << "A a2{ 21 } " << endl;
		A a2{ 21 };
		cout << "string(60, 61) " << string(60, 61) << endl;
		cout << "string{ 60, 61 } "  << string{ 60, 61 } << endl;
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

