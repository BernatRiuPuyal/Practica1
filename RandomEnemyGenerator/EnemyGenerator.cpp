#include <string>
#include <ctime>
#include <iostream>
#include "Circle.h"

enum class EnemyType { zombie, vampire, ghost, witch, MAX }; // class per a mes encapsulasció més sexy
const int MAX_ENEMIES{ 5 };
std::string namelist[10] = { "Pere","Mascu", "Joan","Animal","Flapa","Salvatge","AlextheKiller","Pruna","Dinosaure","EOF"};
Enemy enemies[MAX_ENEMIES];
struct Enemy {
	EnemyType type;
	std::string name;
	int health;


	std::string getEnemyTypeString() {
		switch (type) {
		case EnemyType::zombie:		return "Zombie";	break;
		case EnemyType::vampire:	return "Vampire";	break;
		case EnemyType::ghost:		return "Ghost";		break;
		case EnemyType::witch:		return "Witch";		break;
	}
}
};

bool operator==(const Enemy &a,const  Enemy &b) { // const: per a deixar clar que no canviarem el valor &: per a passar-lo per referència (pots passar unicament la direcció
		return (a.health == b.health && a.name == b.name);
}
void enemyCreator(Enemy enemies[]) {
	int i = 0;

	while (i < MAX_ENEMIES) {
		enemies[i] = CreateRandomEnemy();
		int j = i - 1;
		while (j >= 0) {
			if (enemies[i] == enemies[j]) {
				--i;
				break;
			}
		}


	}


}



Enemy CreateRandomEnemy(void) {
	const int MAX_LIFE{ 100 }; // declaracio de forma sexy
	Enemy a;
	/*a.health = rand() % 91 + 10;
	a.name = namelist[rand() % 10];
	return a;*/

	return Enemy{ static_cast<EnemyType> (rand() % static_cast<int>(EnemyType::MAX)), namelist[rand() % (sizeof namelist / sizeof std::string],rand() % MAX_LIFE }; // satanas i tal 
	};


int main(void) {
	srand(time(nullptr));
	enemyCreator(enemies);
	for (auto &enemici : enemies) {
		std::cout << enemici.name << "is a " << enemici.getEnemyTypeString() << "whose life is" << enemici.health << std::endl;
	}
	Circle c1(2.0 , 3.0, 4.0); // inicialització de la classe
	std::cout << c1.Area();

	Circle *c2
		c2 = new  Circle(1.0, 2.0, 3.0); 
	std::cout << c2->Area();
	delete c2;

}

Circle::Circle(float a, float b, float r) : coorX{ a }, coorY{ b }, radio{ r } {} // constructor

Circle:: ~Circle() { // destructor



}

float Circle::GetRadio() { // fuincions?
	return radio;
}
float Circle::Area() {
	return 3.14 * radio * radio;
}


