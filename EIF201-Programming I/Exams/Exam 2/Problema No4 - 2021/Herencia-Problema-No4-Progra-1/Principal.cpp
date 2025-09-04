
#include"Estudiante.h"
#include"ProfUniversitario.h"
#include"AdmUniversitario.h"

int main() {
    cout << "---------------Creacion de 3 objetos------------------" << endl;
    cout << endl<<endl;



    cout << "1- Creacion de un Estudiante..." << endl;

   Persona* p = new Estudiante("Nicole","111","Sistemas",20);


    cout << "2- Creacion de un Profesor Universitario...." << endl;

    int can = 0;
    cout << "Cuantos hijos tiene: " << endl;  cin >> can;

    Trabajador* t = new ProfUniversitario ("MARIA","111",can,true,"A");

    int edad = 0;

    while(can!=0){

        cout << "Ingrese la edad de su hijo: " << endl; cin >> edad;
        t->llenarVecDeEdades(edad);
        can--;
    }
    

    cout << "3- Creacion de un Administrador Universitario...." << endl;
  
    cout << "Cuantos hijos tiene: " << endl;  cin >> can;

    Trabajador* t2 = new AdmUniversitario("CARLOS", "222", can, "Contador", 5);

    while (can != 0) {

        cout << "Ingrese la edad de su hijo: " << endl; cin >> edad;
        t2->llenarVecDeEdades(edad);
        can--;
    }

    system("cls");
    



    cout << "------------------------------------------------------" << endl;
    cout << endl;
    cout << "--------------IMPRESION DE UNIVERSITARIOS-------------" << endl;
    cout << endl;
    cout << "Impresion de un Estudiante..." << endl;
    
    cout<<p->toString();
    cout << endl << endl;

    cout << "Impresion de un profesor universitario...." << endl;
    cout << t->toString();
    cout << endl << endl;


    cout << "Impresion de un administrador universitario..." << endl;
    cout << t2->toString();
    cout << endl << endl;


    cout << "Eliminar personas universitarias..." << endl;
  
    delete p, t, t2;


    system("pause");
    return 0;
}