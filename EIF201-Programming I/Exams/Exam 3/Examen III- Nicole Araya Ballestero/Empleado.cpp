#include"Empleado.h"

Empleado::Empleado(int id, string nom, string cat, Fecha* fc): ID(id), nombre(nom), categoria(cat), fecha(fc){

}
Empleado::~Empleado()                {                  }
int Empleado::getID()                { return ID;       }
string Empleado::getNombre()         { return nombre;   }
string Empleado::getCategoria()      { return categoria;}
Fecha* Empleado::getFecha()          { return fecha;      }
void Empleado::setID(int id)         { ID = id;         }
void Empleado::setNombre(string nom) { nombre = nom;    }
void Empleado::setCategoria(string c){ categoria = c;   }
void Empleado::setFecha(Fecha* fc)   { fecha = fc;        }

double Empleado::salario()
{
	CategTrabajador c;
	double porcentaje = c.bonoBeneficio(categoria);
	
	return porcentaje;
}


bool Empleado::esIgualA(Empleado emp){

	return ID == emp.getID();
}



string Empleado::toString() const {
	stringstream s;

	s << "  -> " << ID << '\t' << nombre <<'\t'<< categoria<<'\t';

	if (fecha != NULL)
		s << fecha->toString();

	return s.str();
}

string Empleado::imprimirEmpleadoSalario()
{
	stringstream s;

	s << "  -> " << ID << '\t' << nombre << '\t' << categoria << '\t';
	s << "Salario: " << salario();

	return s.str();
	
}
