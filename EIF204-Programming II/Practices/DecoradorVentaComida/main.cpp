
//Nicole Araya Ballestero - Progra II

#include <iostream>
#include "VentaComida.h"
#include "Factura.h"
#include "Decorador.h"
#include "Hamburguesa.h"
#include "Bebida.h"
#include "PapasFritas.h"
#include "Tacos.h"

using namespace std;
int main()
{

 VentaComida* v= new Factura();

 v = new Bebida(new Hamburguesa(v));

cout<<"SIN IVA "<<v->toStringSINIVA()<<endl;
cout<<"CON IVA "<<v->toStringIVA()<<endl<<endl;



 VentaComida* v2= new Factura();

 v2 = new PapasFritas(new Bebida(new Hamburguesa(v2)));

cout<<"SIN IVA "<<v2->toStringSINIVA()<<endl;
cout<<"CON IVA "<<v2->toStringIVA()<<endl<<endl;



    return 0;
}
