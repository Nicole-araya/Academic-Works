#include"ContenedorL.h"


ContenedorL::ContenedorL() {

	primero = NULL;
	actual = NULL;

}

ContenedorL::~ContenedorL() {
	
}

string ContenedorL::toString() {  
	stringstream s;
	
	if (estaVacia() != true) {
		actual = primero;

		while (actual != NULL) {

			s << actual->toString();

			actual = actual->getSiguiente();
		}
	}
	else {
		s << "LISTA VACIA" << endl;
	}
	return s.str();
}

bool ContenedorL::estaVacia() {  
	
	if (primero == NULL) {
		return true;
	}
	return false;
}

void ContenedorL::ingresarProducto(Producto* pro){
	
	actual = primero;

	if (primero == NULL) {

		primero = new Nodo(pro, NULL);
	}
	else {

		while (actual->getSiguiente() != NULL) {

			actual = actual->getSiguiente();

		}

		actual->setSiguiente(new Nodo(pro, NULL));

	}



}




/*bool ContenedorL::compararaListasIguales(ContenedorL* contPtr2) {
	

	actual = primero;
	contPtr2->actual = contPtr2->primero;

	while (actual != NULL ) {


				if (actual->getProducto()->esIgualA(*contPtr2->actual->getProducto()) ) {

					contPtr2->actual = contPtr2->actual->getSiguiente();
				}
				

		

			return false;
		
	}

}*/





