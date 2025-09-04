#include "ArbolBinario.h"

int main() {

	ArbolBinario<int>* a = new ArbolBinario<int>;
	cout << a->size() << endl;
	int n15 = 15;
	a->insertar(&n15);
	cout << a->size() << endl;
	a->insertar(new int(88));
	cout << a->size() << endl;
	a->insertar(new int(112));
	cout << a->size() << endl;
	int n53 = 53;
	a->insertar(&n53);
	cout << a->size() << endl;
	int n2 = 2;
	a->insertar(&n2);


	Nodo<int>* temp = a->buscar(new int(5));
	if (temp) {
		cout << "Se encontro!!" << endl;
	}
	else cout<<"NO se encontro..." << endl;

	 temp = a->buscar(&n15);
	if (temp) {
		cout << "Se encontro!!" << endl;
	}
	else cout << "NO se encontro..." << endl;


	if (a->isRoot(temp)) {
		cout << "El nodo con el valor " << *temp->getInfo() << " SI es raiz" << endl;
	}else cout << "El nodo con el valor " << *temp->getInfo() << " NO es raiz" << endl;

	if (a->isExternal(temp)) {
		cout << "El nodo con el valor " << *temp->getInfo() << " SI es hoja" << endl;
	}
	else cout << "El nodo con el valor " << *temp->getInfo() << " NO es hoja" << endl;

	delete a;
	return 0;
}