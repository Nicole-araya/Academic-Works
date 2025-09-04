#include "Carro.h"


int main() {


	Tesla* t = new Tesla(4,"Motor Electrico");
	Hyundai* t2 = new Hyundai(4, "Motor Gas");

	t->imprimirInfo();
	t2->imprimirInfo();

	return 0;
}