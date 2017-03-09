#include "DynArray.hh"

int main(void) {

	DynArray pere;

	DynArray joan(static_cast<size_t>(12),2);

	std::cout << joan[11]<< std::endl;

	if (pere == joan)
		std::cout << "si";
	else
		std::cout << "no";
}