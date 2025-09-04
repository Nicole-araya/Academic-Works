#include"Departamento.h"

Departamento::Departamento(int val){
	codigo = 0;
	descripcion = "";

	//----------------

	tam = val;
	can = 0;
	vec = new Empleado * [val];
	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

Departamento::~Departamento(){
	for (int i = 0; i < tam; i++)
		delete vec[i];
	delete[] vec;
}

bool Departamento::ingresaEmpleado(Empleado* e){
	
	if (buscar(e->getID()) != NULL) {    // NO SE REPITA
		return false;
	}
	
	if (can < tam) {
		vec[can++] = e;
		return true;
	}
	else
		return false;
}

Empleado* Departamento::buscar(int id)
{
	for (int i = 0;i < can;i++) {

		if (vec[i]->getID() == id) {
			return vec[i];
		}
	}

	return NULL;
}

string Departamento::toString() const{
	stringstream s;
	s << "--> Descripcion del departamento: " << descripcion << endl
	  << "--> El codigo del departamento: " << codigo << endl
	  << "-------------Listado de Empleados------------" << endl;
	for (int i = 0; i < can; i++)
		s << vec[i]->toString() << endl;
	return s.str();
}

void Departamento::setDescripcion(string desc) { descripcion = desc; }

string Departamento::getDescripcion() { return descripcion; }

void Departamento::setCodigo(int cod) { codigo = cod; }

int Departamento::getCan()
{
	return can;
}

int  Departamento::getCodigo() { return codigo; }




bool Departamento::empleadoYaExiste(int id) {
	
	if (buscar(id) == NULL) {
		return false;
	}

	return true;
}

string Departamento::reportarEmpleados()
{
	stringstream s;
	double total = 0;

	for (int i = 0; i < can; i++) {
		s << vec[i]->imprimirEmpleadoSalario() << endl;
		total = total + vec[i]->salario();

	}
	s << "Salario total: " << total << endl;

	return s.str();
}

string Departamento::reportarMismoDia(Fecha* f)
{
	stringstream s;

	for (int i = 0; i < can; i++) {
	
		if (vec[i]->getFecha() == f) {

			s << vec[i]->toString();

		}

	}

	return s.str();
}

void Departamento::EliminarPuesto(Empleado* e)
{

	//ELIMINAR

	if (vec[can - 1]->getID() ==e->getID()) { // si fuera el ultimo
		delete vec[can - 1];
		vec[can - 1] = NULL;
		can--;
	}
	else {	// si estuviera en otra posicion

		int pos = -1;
		for (int i = 0; i < can; i++)
		{
			if (e->getID() == vec[i]->getID()) { pos = i; }
		}

		if (pos == -1) { return ; }

		delete vec[pos];
		for (int j = pos; j < can - 1; j++)   // hacemos el corrimiento
		{
			vec[j] = vec[j + 1];
		}
		vec[can - 1] = NULL;
		can--;
	}

	
}

string Departamento::imprimirEmpleados()
{
	stringstream s;
	
	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}

	return s.str();
}


string Departamento::reporteSalario()
{
	stringstream s;

	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << " Salario: " << vec[i]->salario();
	}

	return s.str();
}

double Departamento::sumaSalario()
{
	double total = 0;
	for (int i = 0; i < can; i++) {
		total = total + vec[i]->salario();
	}

	return total;
}

Empleado* Departamento::mayorSalario()
{
	Empleado* e = NULL;
	int aux;
	for (int i = 0; i < can; i++) {

		for (int j = 1;j < can;j++) {

			if (vec[i]->salario() > vec[j]->salario()) {

				e = vec[i];
				
			}
			else {

				e = vec[j];
				aux =i;
				i = j;
				j = i;
			}

		}

	}

	return e;
}


