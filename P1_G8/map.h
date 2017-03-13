#pragma once
#include "Input.h"

class Map {

public:

	char **map; // doble punter que apunta la matriu

	const int mapproportion = 5; // ratio de tamany del mapa segons la dificultat [1,5]

	int mapsize; // llargada del mapa.

	Map(const int &difficulty);

	void cellModify(const int &line, const int &row, const char &newelement);


	void operator<<(Map map);



};

class Player {

public:

	int x, y;

	int puntuacio;

	Player(Map mapa,int spawnrange);

	void  movement(Map mapa);


};

class Coinmanager {

public:
	int coinnum;

	const int coinproportion = 10; // proporcio de monedes segons la grandaria del mapa ( 100/3 , 100/13)

	Coinmanager(int coinproportion,Map mapa);

};
