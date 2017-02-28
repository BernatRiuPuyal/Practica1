#include <iostream>
#include <string>
#include <ctime>

enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX };

class Zombie;
/*
std::ostream& operator<< (std::ostream &os, const Weapon &weapon) {

	switch (weapon) {
	case::Weapon::GUN: return os << "gun";
	case::Weapon::SOTGUN: return os << "gun";
	case::Weapon::GUN: return os << "gun";
	case::Weapon::GUN: return os << "gun";
	case::Weapon::GUN: return os << "gun";
	}




}

*/







class Player {
public:
	// atributos
	

	Weapon weapon;

	float precision;

	int life;

	
	Player():
		weapon(static_cast <Weapon>(rand() % static_cast<int>(Weapon::MAX))),
		precision((rand() % 10)/ 10.f), // posem .f per indicar que es float, ja que si posem .0 es de tips double
		life(rand() % 100) // constructor
	{			}

	Player(const Weapon &t_weapon, const float &t_precision, const int &t_life) { // overloading constructor
		weapon = t_weapon;
		precision = t_precision;
		life = t_life;
	}

	//metodos
	void attack(Zombie &);

	bool isalive() {

		return (life > 0);
	}


};

class Zombie {
	public: // es privada per defecte
		// atributos
		int distanceToPlayer;

		float speed;

		float damage;

		int life;
		//metodos
		
		void attack(Player &jugador) {
			
			if (distanceToPlayer <= 0) {
				jugador.life -= damage;
			}
			else {
				distanceToPlayer--;
			}
		}
		bool isAlive() {
			return (life > 0);
		}

		Zombie() :distanceToPlayer(20 + (rand() % 1800)/10 ), speed((rand() % 200)/10), damage((rand() % 200)/10), life(rand() % 100)
		{}
};

void Player::attack(Zombie &atacat) {

	atacat.life -= static_cast <int>(static_cast <int>(weapon) * precision);
}

int main(void) {
	srand(time(nullptr));
	int zombiobjectiu;
	const int tamanyhorda = 10;
	Player jugadore; // es declara i s'inicialitza amb el constructor

	Zombie horda[tamanyhorda];

	bool zombiesAreAlive = true;

	do { 
		std::cout < "Quin zombie ataques:";
		std::cin > zombiobjectiu;
		jugadore.attack();





		for (int c = 0; c < tamanyhorda && zombiesAreAlive == false; c++) {
			zombiesAreAlive = false;
			if (horda[c].isAlive) {
				zombiesAreAlive = true;
			}
		}
		


	} while (jugadore.isalive() && zombiesAreAlive);



}



