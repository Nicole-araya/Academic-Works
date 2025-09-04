#include "Inserccion.h"
#include "Burbuja.h"
#include "OrdenamientoSeleccion.h"
#include "MergeSort.h"
#include "QuickSort.h"
int main() {

	int vec[10] = { 1,5,9,8,3,15,7,2,32,1};

	/*Inserccion::inserccionSortAsc(vec, 10);

	for (int i = 0; i < 10; i++) {
		cout << vec[i]<<'\t';
	}*/

	/*Burbuja::bubleSort(vec, 10);
	for (int i = 0; i < 10; i++) {
		cout << vec[i] << '\t';
	}*/

	/*OrdenamientoSeleccion::selectionSort(vec, 10);
	for (int i = 0; i < 10; i++) {
		cout << vec[i] << '\t';
	}*/


	//CON STL :C

	list<int> lista = { 1,5,9,8,3,15,7,2,32,1 };
	list<int>::iterator it;

	MergeSort::mergeSort(lista);
	for (it = lista.begin(); it != lista.end();it++) {
		cout << *it << '\t';
	}
	
	/*QuickSort::quickSort(vec, 10);
	for (int i = 0; i < 10; i++) {
		cout << vec[i] << '\t';
	}
	*/
	return 0;
}