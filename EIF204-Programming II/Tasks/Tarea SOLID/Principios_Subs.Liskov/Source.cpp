#include "Metal.h"

int const tam = 3;

void imprimirSimbologia(Metal* m[]);

int main() {

	

	Metal* vec[tam];

	Metal *m = new Plata("Ag");
	Metal* m1 = new Oro("Au");
	Metal* m2 = new Hierro("Fe");

	vec[0] = m;
	vec[1] = m1;
	vec[2] = m2;


	//Princiopio de substitución de Liskov
	//Al poder llamar una clase hija como si fuera el padre y asi ejecutar el metodo deseado 

	imprimirSimbologia(vec);

	return 0;
}

void imprimirSimbologia(Metal* m[]) {

	for (int i=0; i < tam ; i++) {

		cout<<"Simbolo del metal: "<< m[i]->imprimirSimbolo() << endl;
	}

}