#include "HashMap.h"
#include <iostream>

int main() {

	HashMap<int, int>* h = new HashMap<int, int>;
	h->insertNode(1, 2);
	h->insertNode(2, 311);
	h->insertNode(13, 33);
	cout << h->display();
	cout << "Tamannio: " << h->sizeofMap() << endl;
	cout << "Borrar llave 2 que contien a " << h->deleteNode(2) << endl;
	cout << "Tamannio: " << h->sizeofMap() << endl;

	if (h->isEmpty())
		cout << "Esta vacio el hash!!\n";
	else
		cout << "NO esta vacio el hash!!\n";

	if (h->get(2) == NULL) {
		cout << "NO existe la llave!!\n";
	}
	else {
		cout << "Existe la llave!!\n";
	}

	if (h->get(13) == NULL) {
		cout << "NO existe la llave!!\n";
	}
	else {
	cout << "Existe la llave!!\n";
	}

	return 0;
}