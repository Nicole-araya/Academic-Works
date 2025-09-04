#include "Avion.h"

Avion::Avion(string cod, string categ,int tam){
	codigo = cod;
	categoria = categ;
	tamannio = tam;
	cantidad = 0;

	asiento = new int*[tamannio];

	for (int i = 0;i < tamannio;i++) {
		asiento[i] = NULL;
	}

}

Avion::~Avion() {
	for (int i = 0;i < tamannio;i++) {
		delete asiento[i];
	}
	delete[] asiento;
}

void Avion::setTamannio(int tam)
{
	tamannio = tam;
}

void Avion::setCodigo(string cod) {
	codigo = cod;
}
void Avion::setCategoria(string categ) {
	categoria = categ;
}
string Avion::getCodigo() {
	return codigo;
}
string Avion::getCategoria() {
	return categoria;
}

int Avion::getTamannio()
{
	return tamannio;
}

int Avion::getCantidad()
{
	return cantidad;
}

int Avion::insertarAsiento() {
	
	int* x = new int(1);  //PARA INSERTAR QUE ESTA OCUPADO USARE EL # 1;

	if (cantidad < tamannio) {

		asiento[cantidad++] = x;
		
		return cantidad;  //Sera el numero del asiento
	}

	return -1; //Si no se inserto devolvera un -1

}

int Avion::asientosDisponibles() {
	return tamannio - cantidad;
}

void Avion::guardar(ofstream& salida)
{
	salida << codigo << "\t";
	salida << categoria << "\t";
	salida << tamannio << "*";
}


string Avion::toStringAvion() {
	stringstream s;

	s << codigo << " " << categoria << endl;

	return s.str();
}