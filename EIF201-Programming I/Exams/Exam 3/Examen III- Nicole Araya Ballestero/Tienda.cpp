#include"Tienda.h"


Tienda::Tienda(int tama){
	nombreTienda = "----------Tienda Programacion UNO-------------" ;
	cedulaJuridica = "COD-213444-KDWZ";
	//-------------------------------------------------------------
	tam = tama;
	can = 0;
	vec = new Departamento * [tama];
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}    
Tienda::~Tienda(){
	for (int i = 0; i < tam; i++)
		delete vec[i];
	delete[] vec;
}
void Tienda::setNombreTienda(string nom) { nombreTienda = nom; }

void Tienda::setCeduJuridica(string cJ) { cedulaJuridica = cJ; }

string Tienda::getNombreTienda()   { return nombreTienda;   }

string Tienda::getCedulaJuridica() { return cedulaJuridica; }

int Tienda::getCantidad() { return can; }

int Tienda::getTamanio()  { return tam; }

bool   Tienda::ingresaDepartamento(Departamento* d){

	if (buscar(d->getCodigo()) != NULL) {  //NO SE REPITA
		return false;
	}

	if (can < tam) {
		vec[can++] = d;
		return true;
	}
	else
		return false;
}

Departamento* Tienda::buscar(int cod)
{
	for (int i = 0;i < can;i++) {

		if (vec[i]->getCodigo() == cod) {
			return vec[i];
		}
	}

	return NULL;
}

string Tienda::toString() const{
	stringstream s;
	s << "-----------Listado de Departamentos------------" << endl;
	for (int i = 0; i < can; i++)
		s << vec[i]->toString() << endl;
	return s.str();
}

bool Tienda::tiendaYaExiste(int cod){

	if (buscar(cod) == NULL) {
		return false;
	}

	return true;
}

Empleado* Tienda::buscarEmpleado(int id)
{
	Empleado* e = NULL;

	for (int i = 0;i < can;i++) {

		if (vec[i]->buscar(id)!=NULL) {

			e = vec[i]->buscar(id);

			return e;
		}
		

	}

	return NULL;

}

string Tienda::imprimirEmpleadosT()
{
	int can2 = 0;

	stringstream s;

	s << "-----------Listado de Empleados------------" << endl;
	for (int i = 0; i < can; i++) {

		s << vec[i]->imprimirEmpleados();

		can2 = can2 + vec[i]->getCan();
	}

	s << "Cantidad de Empleados en Tienda: " << can2 << endl;

	return s.str();
}

string Tienda::imprimirMismoDia(Fecha* f)
{
	stringstream s;

	for (int i = 0; i < can; i++) {

		s << vec[i]->reportarMismoDia(f);

	}

	return s.str();
}

string Tienda::imprimirSalario()
{
	double total = 0;

	stringstream s;

	for (int i = 0; i < can; i++) {

		s << vec[i]->reporteSalario();

		total = total + vec[i]->sumaSalario();
	}
	
	s << "\nSalario total: " << total << endl;

	return s.str();
}

string Tienda::imprimirMayorSalario()
{
	stringstream s;

		Empleado* e;
		int aux;
		for (int i = 0; i < can; i++) {

			for (int j = 1;j < can;j++) {

				if (vec[i]->mayorSalario()->salario() > vec[j]->mayorSalario()->salario()) {

					e = vec[i]->mayorSalario();

				}
				else {

					e = vec[j]->mayorSalario();
					aux = j;
					i = j;
					j = aux + 1;;
				}

			}
		}

		//s << e->toString();


	return s.str();
}


