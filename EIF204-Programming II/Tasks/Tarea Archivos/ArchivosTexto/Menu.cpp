#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::opciones() {
    string nom, contenido;

    int opcion;
    do {
        system("cls");
        cout << "Menu principal" << endl;
        cout << "========================" << endl;
        cout << "[1]Crear archivo de texto" << endl;
        cout << "[2]Abrir archivo de texto" << endl;
        cout << "[3]Modificar archivo de texto" << endl;
        cout << "[0]Salir del programa" << endl;
        cout << "========================" << endl;
        cout << "Ingresa la opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 0:
            break;
        case 1:
        {

            cout << "Ingresa el nombre del archivo a crear(sin el .txt): ";
            cin.ignore();
            getline(cin, nom);
            cout << "Ingresa el contenido del archivo: ";
            getline(cin, contenido);

            nom += ".txt";
            Archivo* a = new Archivo(nom);


           ArchivoGuardar::guardar(a,contenido);

            system("pause");
            break;
        }
        case 2:
        {
            cout << "Ingresa el nombre del archivo que quieres leer(sin el .txt): ";
            cin.ignore();
            getline(cin, nom);
            nom += ".txt";

            try {
                ArchivoLeer::leerArchivo(nom);
            }
            catch (ifstream& e) {

                cout << "Error al ingresar" << endl;
            }

            system("pause");
            break;
        }
        case 3:
        {
            cout << "Ingresa el nombre del archivo que quieres modificar(sin el .txt): ";
            cin.ignore();
            getline(cin, nom);
            nom += ".txt";
            cout << "Ingresa el NUEVO contenido del archivo: ";
            getline(cin, contenido);
            
            ArchivoModificar::modificar(nom, contenido);

            cout << "El archivo ha sido modificado correctamente" << endl;
            system("pause");
            break;
        }
        default:
            cout << "\nEl numero de opcion escrito no es valido\n" << endl;
            system("pause");
        }
    } while (opcion != 0);




}
