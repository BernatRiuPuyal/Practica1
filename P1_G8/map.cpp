#include "map.h"
#include "Input.h"


Map::Map(const int difficulty)
{
	
	map = new char[difficulty * 5][difficulty*10];


}
void Map::cellModify(int line, int row, char newelement) {

	map[line][row] = newelement;


}
