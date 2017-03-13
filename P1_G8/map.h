#pragma once

class Map {

public:

	char *map;



	Map(const int difficulty);

	void cellModify(int line, int row, char newelement);


	void operator<<(Map map);



};
