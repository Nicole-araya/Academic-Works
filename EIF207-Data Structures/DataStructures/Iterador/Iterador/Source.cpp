#include "Lista.h"
#include <iostream>
int main() {

	Lista<int>* lis = new Lista<int>;
	lis->agregarFinal(new int(22));
	lis->agregarFinal(new int(2));
	lis->agregarFinal(new int(4));
	lis->agregarFinal(new int(10));

	int aux;
	Iterador<int>* it = lis->iterador();
	while (!(it->isEmpty())) {
		aux = *it->next();
		cout << aux<<endl;
	}

	return 0;
}