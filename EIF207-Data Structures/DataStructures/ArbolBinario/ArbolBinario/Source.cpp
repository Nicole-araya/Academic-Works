#include <iostream>
#include "ArbolBinario.h"

int main() {

	ArbolBinario<int> A;

	if (A.vacio()) cout << "Esta vacio" << endl;

	A.insertar(new int(15));
	if (A.vacio()) cout << "Esta vacio" << endl;
	if (!A.vacio()) cout << "No esta vacio" << endl;


	return 0;
}