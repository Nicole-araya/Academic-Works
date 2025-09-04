#include "ListaCuenta.h"

ListaCuenta::ListaCuenta()
{
    primero = NULL;
	actual = NULL;
}

ListaCuenta::~ListaCuenta()
{
    while (primero != NULL) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}

void ListaCuenta::agregar(Cuenta* c) {
	actual = primero;

	if (primero == NULL) {
		primero = new Nodo(c, NULL);
		return ;
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new Nodo(c, NULL));
		return ;
	}

}


 bool ListaCuenta::estaVacia(){

 if(primero==NULL){
    return true;
 } else return false;
 }

  Cuenta* ListaCuenta::busqueda(int num){
  actual = primero;

	while (actual != NULL) {

		if (actual->getCuenta()->getNumCuenta() == num) {

			return actual->getCuenta();
		}
		actual = actual->getSig();

	}
	return NULL;
  }

