#include "Lista.h"
#include "Sort.h"

int main(){
	//pruebas
	Lista<int> lst, piko;
	lst.agregarFinal(new int(4));
	lst.agregarFinal(new int(3));
	lst.agregarFinal(new int(7));
	lst.agregarFinal(new int(1));
	lst.agregarFinal(new int(48));

	lst.agregarFinal(new int(9));
	lst.agregarFinal(new int(8));
	lst.agregarFinal(new int(34));
	lst.agregarFinal(new int(-91));
	lst.agregarFinal(new int(-1));

	Sort<int>::mergeSort(lst);
	cout << lst.toString()<<endl<<endl;


	piko.agregarIni(new int(1));
	piko.agregarIni(new int(31));
	piko.agregarIni(new int(194));
	piko.agregarIni(new int(12));
	piko.agregarIni(new int(193));
	piko.agregarIni(new int(11));
	piko.agregarIni(new int(173));
	piko.agregarFinal(new int(-91));
	piko.agregarIni(new int(193));
	piko.agregarIni(new int(91));
	piko.agregarFinal(new int(-41));

	Sort<int>::mergeSort(piko);
	cout << piko.toString() << endl << endl;

	return 0;
}