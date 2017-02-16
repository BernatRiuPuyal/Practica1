#include <string>
#include <ctime>
#include <iostream>

enum EnemyType { zombie, vampire, ghost, witch };

std::string namelist[10] = { "Pere","Mascu", "Joan","Animal","Flapa","Salvatge","AlextheKiller","Pruna","Dinosaure","EOF"};

struct Enemy {
	std::string name;
	int health;
};

bool operator==(Enemy a, Enemy b) {
		return (a.health == b.health && a.name == b.name);
}

Enemy CreateRandomEnemy(void) {
	Enemy a;
	a.health = rand() % 91 + 10;
	a.name = namelist[rand() % 10];
	return a;
	};


