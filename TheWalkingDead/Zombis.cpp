#include <iostream>
#include <string>
#include <ctime>

enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX };

class Zombie;


class Player {
public:
	// atributos
	

	Weapon weapon;

	float precision;

	int life;

	//metodos
	void attack(Zombie &);
	
	bool isalive() {
		
		return (life > 0);
	}

	Player():weapon(static_cast <Weapon>(rand() % static_cast<int>(Weapon::MAX))),precision(rand() % 1),life(rand() % 100) // constructor
	{		
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

	atacat.life -= static_cast <float>(weapon) * precision;
}

int main(void) {
	srand(time(nullptr));
	int zombiobjectiu;
	const int tamanyhorda = 10;
	Player jugadore;

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



