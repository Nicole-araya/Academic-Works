#include "HashMap.h"
#include <iostream>

int main() {

	HashMap<int, int>* h = new HashMap <int, int > ;
	h->insertNode(1, 12);
	h->insertNode(3, 2);
	h->insertNode(21, 12);
	h->insertNode(4, 4);
	cout << h->display() << endl;
	cout << "Tamannio: " << h->sizeofMap() << endl;
	cout << "Se borro el valor: " << h->deleteNode(21) << endl;
	cout<< "Tamannio: " << h->sizeofMap()<<endl;

	if (h->isEmpty() ) {
		cout << "Esta Vacio!\n";
	}
	else {
		cout << "NO esta vacio!\n";
	}


	if (h->get(21) == NULL) {
		cout << "NO existe!\n";
	}
	else {
		cout << "Existe!\n";
	}



	return 0;
}