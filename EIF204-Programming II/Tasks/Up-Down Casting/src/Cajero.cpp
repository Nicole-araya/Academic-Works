 #include "Cajero.h"

 Cajero::Cajero(string n,string i,int s,int ca): Empleado(n,i), Salario(s){

 numCaja=ca;

 }

 Cajero::~Cajero(){}

void  Cajero::setNumCaja(int ca){ numCaja=ca;
 }
int  Cajero::getNumCaja(){ return numCaja;}

string  Cajero::toString(){
stringstream s;

        s<<Empleado::toString();
        s<<"Numero de caja: "<<numCaja<<endl;
        s<<"Salario: "<<Salario::getSalario()<<endl;
        return s.str();

}
