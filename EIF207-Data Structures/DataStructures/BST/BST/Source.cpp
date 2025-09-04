#include "ArbolBinario.h"

int main() {
	ArbolBinario<int> a;
	int *n12 = new int(12);
	int* n1 = new int(1);
	int *n52 = new int(52);
	int *n33 = new int(33);
	int* n85 = new int(85);
	a.insert(12,n12);
	a.insert(1, n1);
	a.insert(52,n52);
	a.insert(85, n85);
	a.insert(33,n33);

	a.display();
	a.remove(12);
	a.display();
	a.remove(52);
	a.display();
	a.remove(33);
	a.display();

	return 0;
}