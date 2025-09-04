//Progra II - Nicole Araya Ballestero
#include <iostream>
#include "Maquina.h"

using namespace std;

int main()
{
   Maquina* m= new Maquina(5);

try{

   m->menu();

}

catch (int a){

cout<<"No hay vuelto, cancelando orden..."<<endl;
}

catch(Producto* p){

cout<<"No hay mas producto"<<endl;

}

catch(char a){

cout<<"Cancelando..."<<endl;

}
catch(...){
cout<<"ERROR"<<endl;
}
    return 0;
}
