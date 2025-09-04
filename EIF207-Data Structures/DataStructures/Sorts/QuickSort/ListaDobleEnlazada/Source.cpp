#include "Lista.h"
#include "Sort.h"

int main(){
	Lista<int> idk;
	idk.agregarFinal(new int(76));
	idk.agregarFinal(new int(23));
	idk.agregarFinal(new int(250));
	idk.agregarFinal(new int(1004));
	idk.agregarFinal(new int(-20));
	idk.agregarFinal(new int(334));
	idk.agregarFinal(new int(34));
	idk.agregarFinal(new int(136));
	idk.agregarFinal(new int(303));
	idk.agregarFinal(new int(1452));

	Sort<int>::quickSort(idk);
	cout << idk.toString();

	return 0;
}