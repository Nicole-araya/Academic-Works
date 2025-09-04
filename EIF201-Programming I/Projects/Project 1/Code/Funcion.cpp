#include "Funcion.h" 

Funcion::Funcion(string fec, string hor, Sala* s , Pelicula* p ) {

	fecha = fec;
	hora = hor;
	sala = s;
	pelicula = p;

}

Funcion::~Funcion() {

}

void Funcion::setFecha(string fech) {
	fecha = fech;
}
void Funcion::setHora(string hora) {
	this->hora = hora;
}
void Funcion::setSala(Sala* s) {
	sala = s;
}
void Funcion::setPelicula(Pelicula* p) {
	pelicula = p;
}

string Funcion::getFecha() {
	return fecha;
}
string Funcion::getHora() {
	return hora;
}
Sala* Funcion::getSala() {
	return sala;
}
Pelicula* Funcion::getPelicula() {
	return pelicula;
}


string Funcion::toString() {
	stringstream s;

	s << "    Funcion         " << endl;
	s << "---------------------------" << endl;
	s << "Fecha: " << fecha << " Hora: " << hora << endl;
	s << "Sala: " << sala->getTipo()<<endl;
	s << "---------------------------" << endl;
	s  << pelicula->toString() << endl;
	

	return s.str();
}
