#include"Supervisor.h"


Supervisor::Supervisor(int id, string nom, string cat, Fecha* fc, double cuo, double totVen, double porcCom, double porcRec)
:Vendedor(id,nom,cat, fc, cuo, totVen, porcCom), porcentajeRecargo(porcRec){

}

Supervisor::~Supervisor(){}
double Supervisor::getPorcentRecargo() { return porcentajeRecargo; }
void Supervisor::setPorcentRecargo(double porcRec) { porcentajeRecargo = porcRec; }





double Supervisor::salario()
{
	double salario = Vendedor::salario();

	return salario * porcentajeRecargo;
}

string Supervisor::toString() const    {
	stringstream s;
	s << Vendedor::toString() <<'\t'<< porcentajeRecargo << endl;
	return s.str();
}

string Supervisor::imprimirEmpleadoSalario()
{
	stringstream s;

	s << "  -> " << ID << '\t' << nombre << '\t' << categoria << '\t';
	s << "Salario: " << salario();

	return s.str();

}