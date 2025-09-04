#include "Banco.h"

Banco::Banco()
{
   lc=new ListaCuenta();
}

Banco::~Banco()
{
   delete lc;
}


void Banco::ingresarCuenta(Cuenta* c){

 lc->agregar(c);
}





 void Banco::menu(){

int num;  float monto;
 int opcion;
Cuenta* c;
 try{

     cout<<"Ingrese su numero de cuenta: ";cin>>num; cout<<endl;

     if(c=lc->busqueda(num)){

 while(opcion != 4 ){

    cout<<" 1. Consultar Saldo"<<endl;
    cout<<" 2. Consignar "<<endl;
    cout<<" 3. Retirar "<<endl;
    cout<<" 4. Salir "<<endl;
    cout<<"---------------------"<<endl;
    cin>>opcion;

    if(!opcion){
        string a;
        throw a;
    }

     system("pause");
	system("cls");


    switch(opcion){

case 1:

cout<<c->toString();

    system("pause");
	system("cls");
    break;

case 2:
     cout<<" --Consignar-- "<<endl;
    cout<<"Ingrese el monto: "; cin>>monto;

    c->consignar(monto);

system("pause");
	system("cls");
    break;
case 3:
    cout<<" -- Retirar --"<<endl;
    cout<<"Ingrese el monto: "; cin>>monto;

    c->retirar(monto);

system("pause");
	system("cls");
    break;
case 4:

    cout<<"FIN DEL PROGRAMA"<<endl;
    system("pause");
	system("cls");
    break;

default:
    cout << "NO COINCIDE CON NINGUNA OPCION" << endl;

			system("pause");
			system("cls");

    }

 }

    system("pause");
	system("cls");

     } else throw;


 }
 catch(string a){

     cout<<"Ingreso letras"<<endl;

 }catch(...){
    cout<<"Error..."<<endl;
 }


 }
