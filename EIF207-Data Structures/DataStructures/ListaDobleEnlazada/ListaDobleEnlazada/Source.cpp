
#include "Lista.h"


int main() {

	Lista<int>* p = new Lista<int>;
	p->agregarFinal(new int(12));
	p->agregarFinal(new int(2));
	p->agregarFinal(new int(33));
	p->agregarFinal(new int(4));

	cout << p->toString()<<endl;

	p->borrarIni();
	cout << p->toString() << endl;

	return 0;
}