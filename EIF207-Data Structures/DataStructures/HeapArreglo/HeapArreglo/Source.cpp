#include "Heap.h"


int main() {

	Heap<int> h(50);
	h.insertKey(3);
	h.insertKey(8);
	h.insertKey(10);
	h.insertKey(1);
	h.insertKey(50);
	h.insertKey(3);
	h.insertKey(8);
	h.insertKey(10);
	h.insertKey(19);
	h.insertKey(50);
	h.insertKey(3);
	h.insertKey(8);
	h.insertKey(10);
	h.insertKey(19);
	h.insertKey(50);

	for (int i = 0; i < 20; i++) {
cout << h.getMin() << "\n";
	h.deleteKey(0);

	}

	


/*h.decreaseKey(5, 25);   // intercambia el valor de 50 a un numero que sea menor a el

	cout << h.extracMin() << " ";
	
	cout << h.extracMin() << " ";
	cout << h.getMin() << "	";
	
	*/

	return 0;
}