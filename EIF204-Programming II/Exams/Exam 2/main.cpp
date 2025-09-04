#include <iostream>
#include "Region.h"
#include "Zona.h"
#include "Coordinador.h"
#include "Grupo.h"
#include "Servicio.h"
using namespace std;

int main()
{
cout << "---------------------------------------------------" << endl;
cout << " II Examen de Progra-2 - Ejercicio " << endl;
cout << " Prueba y ejecución del Programa " << endl;
cout << " Nombre:Nicole Araya Ballestero Id 4 0250 0623" << endl;
cout << "---------------------------------------------------" << endl;
 cout << "Los siguientes puntos, se realizan con base en la figura del enunciado.";
cout << "1- Creación de 7 Grupos de Interés (10 pts)........" << endl;

Region* g1= new Grupo("g1","Zona Nicoya",15);
Region* g2= new Grupo("g2","Zona Santa Cruz",52);
Region* g3= new Grupo("g3","Zona sarapiqui",55);
Region* g4= new Grupo("g4","Zona perez zeldon",39);
Region* g5= new Grupo("g5","Zona Nacional",33);
Region* g6= new Grupo("g6","Zona Golfito",43);
Region* g7= new Grupo("g7","Zona sarapiqui",37);

cout << "2- Creación de 9 Coordinadores (10 pts).." << endl;

Coordinador* c1=new Coordinador("Juana","111",30);
Coordinador* c2=new Coordinador("Jose","222",40);
Coordinador* c3=new Coordinador("Manuel","333",33);
Coordinador* c4=new Coordinador("Esteban","444",41);
Coordinador* c5=new Coordinador("Rosa","555",35);
Coordinador* c6=new Coordinador("Maria","666",38);
Coordinador* c7=new Coordinador("Jesus","777",32);
Coordinador* c8=new Coordinador("Mauricio","888",43);
Coordinador* c9=new Coordinador("Guadalupe","999",45);

cout << "3- Creación de 9 Zonas... (10 pts)......." << endl;

Region* z1=new Zona(c1,"Zona Nacional");
Region* z2=new Zona(c2,"Zona Chorotega");
Region* z3=new Zona(c3,"Zona Nicoya");
Region* z4=new Zona(c4,"Zona Santa Cruz");
Region* z5=new Zona(c5,"Zona Huetar-Norte");
Region* z6=new Zona(c6,"Zona sarapiqui");
Region* z7=new Zona(c7,"Zona Brunca");
Region* z8=new Zona(c8,"Zona perez zeldon");
Region* z9=new Zona(c9,"Zona Golfito");


cout << "4- Ingreso de Zonas y Grupos dentro de sus respectivas Zonas." << endl;
cout << " (20 pts).." << endl;

z1->agregarRegion(g5);
z1->agregarRegion(g1);
z1->agregarRegion(g2);
z1->agregarRegion(g3);
z1->agregarRegion(g4);
z1->agregarRegion(g6);
z1->agregarRegion(g7);

z2->agregarRegion(g1);
z2->agregarRegion(g2);

z3->agregarRegion(g1);

z4->agregarRegion(g2);

z5->agregarRegion(g3);
z5->agregarRegion(g7);

z6->agregarRegion(g3);
z6->agregarRegion(g7);

z7->agregarRegion(g4);
z7->agregarRegion(g6);

z8->agregarRegion(g4);
z8->agregarRegion(g6);

z9->agregarRegion(g6);


cout <<endl<<endl<< "5- Imprimir presupuesto asignado a cada una de las siguientes Zonas "
 << " (10 pts). " << endl;

cout << " A la Zona Nacional /n ";

cout<<"Presupuesto: "<<z1->getPresupuesto()<<endl<<endl;

cout << " A la Zona Chorotega.....";
cout<<"Presupuesto: "<<z2->getPresupuesto()<<endl<<endl;

cout << " A la Zona Huetar Norte ";
cout<<"Presupuesto: "<<z5->getPresupuesto()<<endl<<endl;

cout << " A la Zona Perez Zeledon.";
cout<<"Presupuesto: "<<z8->getPresupuesto()<<endl<<endl;

cout << " A la Zona Brunca........";
cout<<"Presupuesto: "<<z7->getPresupuesto()<<endl<<endl<<endl;

cout << "6- Imprimir cantidad de actividades realizadas en cada una de las "
 << "siguientes Zonas. (10 pts)." << endl;

 cout << " En la Zona Nacional.......";
 cout<<"Cantidad Actividades: "<<z1->getCantActivds()<<endl<<endl;

cout << " En la Zona Chorotega......";
cout<<"Cantidad Actividades: "<<z2->getCantActivds()<<endl<<endl;

cout << " En la Zona Huetar Norte...";
cout<<"Cantidad Actividades: "<<z5->getCantActivds()<<endl<<endl;

cout << " En la Zona Perez Zeledon..";
cout<<"Cantidad Actividades: "<<z8->getCantActivds()<<endl<<endl;

cout << " En la Zona Brunca.........";
cout<<"Cantidad Actividades: "<<z7->getCantActivds()<<endl<<endl<<endl;

cout << "7- Utilizar algún grupo para construir uno nuevo e imprimirlo..(10 pts)" ;
cout << "El grupo a utilizar es el que se encuentra en Golfito." << endl;

Region* g= new Grupo("g00","Zona Golfito",11);
cout<<g->toString()<<endl;
//SE AGREGO A LA ZONA GOLFITO UN NUEVO GRUPO
z9->agregarRegion(g);
cout<<z9->toString()<<endl<<endl;

cout <<endl<< "8- Imprimir toda la zona de la Región Nacional. (10 pts)" << endl;
cout<<z1->toString()<<endl;

cout <<endl<<endl<< "9- Pasar o reproducir toda la REGION NACIONAL EN OTRA NUEVA e Imprimirla."
 << " (10 pts) ";

Region* z=new Zona(new Coordinador("Marly","123",36),"Zona Pais");

z->agregarRegion(z1);

cout<<z->toString()<<endl;

  return 0;
}
