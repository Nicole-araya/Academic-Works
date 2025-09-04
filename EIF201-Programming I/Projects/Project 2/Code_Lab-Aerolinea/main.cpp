#include "Aerolinea.h"

int main() {

	Aerolinea* ae = new Aerolinea();
		
	ae->menu();


	system("pause");
	system("cls");

	delete ae;

	return 0;
}