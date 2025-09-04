#include"Cajero.h"


Cajero::Cajero(int id, string nom, string cat, Fecha* fc, int hT, double sXh)
	:Empleado(id,nom,cat,fc),horasTrabajadas(hT), salarioXhora(sXh){
}


Cajero::~Cajero(){ }
int Cajero::getHorasTrabajadas()        { return horasTrabajadas; }
double Cajero::getSalarioXHora()        { return salarioXhora;    }
void Cajero::setHorasTrabajadas(int hT) { horasTrabajadas = hT;   }
void Cajero::setSalarioXHora(double sXh){ salarioXhora = sXh;     }
double Cajero::salario()
{
	int extra = 0;
	int horaT = 0;
	double bono = Empleado::salario();

	if (horasTrabajadas > 48) {

		extra = horasTrabajadas - 48;
		horaT = horasTrabajadas - extra;


		return (horaT * salarioXhora + (extra * (9000 * 2))) * bono;

	}
	else {

		return (horasTrabajadas * salarioXhora) * bono;
	}
}
string Cajero::toString() const         { stringstream s;
  s << Empleado::toString() << '\t' << horasTrabajadas << '\t' << salarioXhora ;
	return s.str();
}

string Cajero::imprimirEmpleadoSalario()
{
	stringstream s;

	s << "  -> " << ID << '\t' << nombre << '\t' << categoria << '\t';
	s << "Salario: " << salario();

	return s.str();

}