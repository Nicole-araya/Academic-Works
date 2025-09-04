#include"Vendedor.h"

Vendedor::Vendedor(int id, string nom, string cat,Fecha* fc, double cuo, double totVen, double porcCom)
 :Empleado(id,nom,cat,fc), cuota(cuo), totalVentas(totVen), porcentajeComision(porcCom) {
}

Vendedor::~Vendedor(){}
double Vendedor::getCuota()                    { return cuota;             }
double Vendedor::getTotalVentas()              { return totalVentas;       }
double Vendedor::getPorcentajeComision()       { return porcentajeComision;}
void Vendedor::setCuota(double cuo)            { cuota = cuo;              }
void Vendedor::setTotalVentas(double tV)       { totalVentas = tV;         }
void Vendedor::setPorcentajeComision(double pC){ porcentajeComision = pC;  }


double Vendedor::salario()
{
	double base = 320000;
	double bono = Empleado::salario();
	if (totalVentas > cuota) {

		return (base * porcentajeComision) * bono;

	}
	else {
		return base * bono;
	}
	
}

string Vendedor::toString() const              {
	
	stringstream s;
	s << Empleado::toString() << '\t' << cuota << '\t' << totalVentas << '\t' << porcentajeComision;
	return s.str();
}

string Vendedor::imprimirEmpleadoSalario()
{
	stringstream s;

	s << "  -> " << ID << '\t' << nombre << '\t' << categoria << '\t';
	s << "Salario: " << salario();
	return s.str();

}