#include"AViaje.h"

AViaje::AViaje(string nomE, string cedJ, string telCel) 
{
	nombEmpresa = nomE;
	ceduJuridica = cedJ;
	teleCelular = telCel;

}

AViaje::~AViaje() { }

string AViaje::getNombEmpresa() { 
	return nombEmpresa; }
string AViaje::getCeduJuridic() {
	return ceduJuridica;}
string AViaje::getTeleCelular() { 
	return teleCelular; }
void AViaje::setNombEmpresa(string nomE)  {
	nombEmpresa  = nomE;  }
void AViaje::setCeduJuridic(string cedJ)  { 
	ceduJuridica = cedJ;  }
void AViaje::setTeleCedular(string telCel){
	teleCelular  = telCel;}


string AViaje::toString() const{
	stringstream s;
	
	s << nombEmpresa << endl;
	s << "----------------------------" << endl;
	s << "Cedula Juridica: " << ceduJuridica << " Tel: " << teleCelular << endl;

	return s.str();
}

void AViaje::infoDelViaje(int cod) {

	Ruta* r = new Ruta();
	cout << nombEmpresa << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "Codigo: " << cod << " Destino: " << r->getDestino(cod) << " Costo: " << r->getCostoPasaje(cod) << " Horas: " << r->tiempoDeRuta(cod) << endl;

}