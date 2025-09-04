#include "Piloto.h"

Piloto::Piloto(string nom, string id, int edad, string correo, char sex):Tripulante(nom,id,edad) {

	this->correo = correo;
	sexo = sex;
}

Piloto::~Piloto() {

}

void Piloto::setCorreo(string correo) {
	this->correo = correo;
}
void Piloto::setSexo(char sex) {
	sexo = sex;
}
string Piloto::getCorreo() {
	return correo;
}
char Piloto::getSexo() {
	return sexo;
}

void Piloto::guardar(ofstream& salida)
{
	salida << nombre << "\t";
	salida << id << "\t";
	salida << edad << "\t";
	salida << correo << "\t";
	salida << sexo << "*";

}

string Piloto::toStringPiloto() {
	stringstream s;

	s << Tripulante::toString();
	s << " " << correo << " Sexo: " << sexo << endl<<endl;

	return s.str();
}