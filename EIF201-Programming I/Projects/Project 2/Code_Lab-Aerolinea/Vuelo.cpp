#include "Vuelo.h"

Vuelo::Vuelo(string cod, string fechSalida, string horaS, string horaL, string nomS, string nomL, Ruta* ruta, Piloto* pilo, Avion* avion) {

	codigo = cod;
	fechaSalida = fechSalida;
	horaSalida = horaS;
	horaLlegada = horaL;
	nombreAeropuertoSalida = nomS;
	nombreAeropuertoLlegada = nomL;
	this->ruta = ruta;
	piloto = pilo;
	this->avion = avion;

	pasajero = new ListaPasajero();
	copiloto = NULL;
	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
	

}

Vuelo::~Vuelo() {

	delete pasajero;
}

void Vuelo::setCodigo(int cod)
{
	codigo = cod;
}

void Vuelo::setFechaSalida(string fechSalida) {
	fechaSalida = fechSalida;
}
void Vuelo::setHoraSalida(string horaS) {
	horaSalida = horaS;
}
void Vuelo::setHoraLlegada(string horaL) {
	horaLlegada = horaL;
}
void Vuelo::setNombreAeropuertoSalida(string nomS) {
	nombreAeropuertoSalida = nomS;
}
void Vuelo::setNombreAeropuertoLlegada(string nomL) {
	nombreAeropuertoLlegada = nomL;
}
void Vuelo::setRuta(Ruta* ruta) {
	this->ruta = ruta;
}
void Vuelo::setPiloto(Piloto* pilo) {
	piloto = pilo;
}
void Vuelo::setAvion(Avion* avion) {
	this->avion = avion;
}
void Vuelo::setCopiloto(Piloto* copi)
{
	copiloto = copi;
}
void Vuelo::setSobrecargo1(Sobrecargo* s)
{
	s1 = s;
}
void Vuelo::setSobrecargo2(Sobrecargo* s)
{
	s2 = s;
}
void Vuelo::setSobrecargo3(Sobrecargo* s)
{
	s3 = s;
}
string Vuelo::getCodigo()
{
	return codigo;
}
string Vuelo::getFechaSalida() {
	return fechaSalida;
}
string Vuelo::getHoraSalida() {
	return horaSalida;
}
string Vuelo::getHoraLlegada() {
	return horaLlegada;
}
string Vuelo::getNombreAeropuertoSalida() {
	return nombreAeropuertoSalida;
}
string Vuelo::getNombreAeropuertoLlegada() {
	return nombreAeropuertoLlegada;
}

Ruta* Vuelo::getRuta()
{
	return ruta;
}
Piloto* Vuelo::getPiloto()
{
	return piloto;
}
Piloto* Vuelo::getCopiloto()
{
	return copiloto;
}
Avion* Vuelo::getAvion()
{
	return avion;
}

Sobrecargo* Vuelo::getSobrecargo1()
{
	return s1;
}

Sobrecargo* Vuelo::getSobrecargo2()
{
	return s2;
}

Sobrecargo* Vuelo::getSobrecargo3()
{
	return s3;
}


bool Vuelo::insertarPasajero(Pasajero* p) {

	int x=0;
	string y = " ";

	if (avion->asientosDisponibles() != 0) {  //Si hay asientos, entra, de lo contrario no

		if (pasajero->insertar(p)) {            //Inserta pasajero en la lista
			x = avion->insertarAsiento();       //Se elige su asiento

			auto s = std::to_string(x);         //Convierte en string el #

			if (x < (avion->getTamannio() / 2)) {        //Nombrando Asiento

				if (x < 10) {

					y = "A-00" + s;
				}
				else {

					if (x >= 10) {
						y = "A-0" + s;
					}
				}
			}
			else {
				if (x < 10) {

					y = "B-00" + s;
				}
				else {

					if (x >= 10) {
						y = "B-0" + s;
					}
				}
			}

			p->setNumAsiento(y);         //Y se le pasa a pasajero su Asiento 

			return true;
		}

	}

	return false;
}

bool Vuelo::compararSobrecargo(string id)  //Comparacion entre los 2 sobrecargos
{
	if (s1 != NULL && s2 != NULL) {  //Si encuentra que ya existe un sobrecargo igual al que se quiere ingresar retorna true

		if (s1->getID() == id) {
			return true;
		}
		if (s2->getID() == id) {
			return true;
		}
	}
	return false;

}

bool Vuelo::comparaSobrecargoVuelo(Sobrecargo* x, Sobrecargo* y, Sobrecargo* z)
{
	if (x != NULL && s1 == x) {   //Si existe algun sobrecargo repetido retorna true
		return true;
	}
	if (y != NULL && s2 == y) {   
		return true;
	}
	if (z != NULL && s3 == z) {   
		return true;
	}

	return false;
}

bool Vuelo::compararCopilotoVuelo( Piloto* c, Piloto* c2)
{
	if (copiloto == c || piloto == c2) {   //Si existe algun piloto repetido retorna true
		return true;
	}

	return false;
}

bool Vuelo::compararPilotoVuelo(Piloto* p)
{
	if (piloto == p) {   //Si existe algun sobrecargo repetido retorna true
		return true;
	}
	return false;
}

bool Vuelo::disponibilidad()
{
	if (avion->asientosDisponibles() != 0) {

		return true;
	}
	return false;
}


string Vuelo::MostrarTripulacion()
{
	stringstream s;

	s << "Piloto: " << piloto->getID() << ", " << piloto->getNombre() << endl;
	s<< "Copiloto: " <<copiloto->getID() << ", " << copiloto->getNombre() << endl;
	
	s << "Sobrecargo #1: " << s1->getID() << ", " << s1->getNombre() << endl;
	s << "Sobrecargo #2: " << s2->getID() << ", " << s2->getNombre() << endl;
	s << "Sobrecargo #3: " << s3->getID() << ", " << s3->getNombre() << endl;
	
	return s.str();
}

string Vuelo::capacidadYlistaPasajero()
{
	stringstream s;

	s << "**CAPACIDAD Y LISTA DE PASAJEROS**" << endl << endl;
	s << "Capacidad: " << avion->getTamannio() << endl;
	s << "Disponibles: " << avion->asientosDisponibles() << endl;
	s << "Ocupados: " << avion->getCantidad() << endl << endl;

	s << mostrarPasajeros() << endl << endl;

	return s.str();
}

string Vuelo::mostrarPasajeros() {

	stringstream s;
	s << "Lista de Pasajeros Registrados: " << endl;
	s << pasajero->toStringListaPasajero();

	return s.str();
}

string Vuelo::MostrarVueloSimple() {
	stringstream s;

	s << "Vuelo " << codigo << ", " << ruta->getLugarOrigen() << "-" << ruta->getLugardestino();
	
	return s.str();
}

string Vuelo::MostrarVueloDetallado() {
	stringstream s;

	s << "******* VUELO "<<codigo<<" *******" << endl << endl;
	s << "**Asientos Disponibles: " << avion->asientosDisponibles()<<endl;
	s << "RUTA" << endl;
	s << ruta->toStringRuta();
	s << "Avion: " << avion->getCodigo() << endl;
	s << "Piloto: " << piloto->getNombre() << endl;
	s << "Fecha de salida: " << fechaSalida << endl;
	s << "Hora de salida: " << horaSalida << endl;
	s << "Hora de llegada: " << horaLlegada << endl;
	s << "Nombre aeropuerto de salida: " << nombreAeropuertoSalida << endl;
	s << "Nombre aeropuerto de llegada: " << nombreAeropuertoLlegada << endl;


	return s.str();
}