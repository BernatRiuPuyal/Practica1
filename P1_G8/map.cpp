#include "map.h"
#include "Input.h"
#include <iostream>
#include <conio.h>


Map::Map(const int &difficulty)
{
	mapsize = difficulty * mapproportion;
	map = new char*[mapsize];

	for (int c = 0; c < mapsize;c++) {
		map[c] = new char[mapsize];
	}

}
void Map::cellModify(const int &line, const int &row,const char &newelement) {

	map[line][row] = newelement;


}

void operator<<(Map map){

}

Player::Player(Map mapa,int spawnrange) {
	do {
		x = (mapa.mapsize / 2) + rand() % mapa.mapsize / spawnrange - mapa.mapsize / 2 * spawnrange;
		y = (mapa.mapsize/ 2) + rand() % mapa.mapsize/spawnrange - mapa.mapsize/ 2*spawnrange;
	} while ( mapa.map[x][y] != '$');
	mapa.cellModify(x, y, '@');

}
void Player::movement(Map mapa) {
	char entrada;
	if (_kbhit()) {
		entrada = _getch();
		mapa.cellModify(x,y,'.');
		switch (entrada) {

		case 'a':
		case 'A':
			x--;	break;
		case 'd':
		case 'D':
			x++;	break;
		case 'w':
		case 'W':
			y++;	break;
		case 's':
		case 'S':
			y--;	break;
		}
		mapa.cellModify(x, y, '@');
		}
	
}

Coinmanager::Coinmanager(int coinproportion,Map mapa) {

	coinnum = mapa.mapsize*mapa.mapsize / coinproportion;

	for (int c = 0; c < coinnum; c++) {
		int x;
		int y;
		do {
			x = rand() % mapa.mapsize;
			y = rand() % mapa.mapsize;
			
		} while (mapa.map[x][y] != '.');
		mapa.map[x][y];
	}
 }
