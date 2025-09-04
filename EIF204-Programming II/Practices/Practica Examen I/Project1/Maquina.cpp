#include "Maquina.h"

Maquina::Maquina(int tp)
{
    tamR = 2;
    tamP = tp;
    canR = 0;
    canP = 0;
    rec = new Recipiente * [tamR];

    for (int i = 0; i < tamR;i++) {
        rec[i] = NULL;
    }


    pro = new Producto * [tamP];
    for (int i = 0; i < tamP;i++) {
        pro[i] = NULL;
    }
}

Maquina::~Maquina()
{
    for (int i = 0; i < tamR;i++) {
        delete rec[i];
    }
    for (int i = 0; i < tamP;i++) {
        delete pro[i];
    }
    delete[] rec, pro;
}

void Maquina::ingresarProd(Producto* p) {

    if (canP < tamP) {
        pro[canP++] = p;
    }


}

string Maquina::imprimirProd() {
    stringstream s;

    for (int i = 0;i < canP;i++) {

        s << i << " " << pro[i]->toString() << endl;
    }

    return s.str();
}


bool Maquina::azucar(char l) {

    if (l == 'S' || l == 's') return true;

    else return false;

}


void Maquina::menu() {

    rec[0] = new Recibir("Alcancia");
    rec[0]->insertarDinero(new Quinientos(500, 1));
    rec[0]->insertarDinero(new Cien(100, 1));
    rec[0]->insertarDinero(new Cincuenta(50, 1));

    rec[1] = new Vuelto("Vueltos");
    rec[1]->insertarDinero(new Quinientos(500, 2));
    rec[1]->insertarDinero(new Cien(100, 4));
    rec[1]->insertarDinero(new Cincuenta(50, 4));

    ingresarProd(new Producto("Cafe Negro", 3, 550));
    ingresarProd(new Producto("Chocolate", 0, 450));
    ingresarProd(new Producto("Capuccino", 5, 650));


    int opcion = 1, c500=0, c100=0, c50=0; int monto = 0; int vuelto = 0;
    int opcion2; char l; char c;

    while (opcion != 0) {


        cout << imprimirProd();

        cout << "Elija el # de la bebida: "; cin >> opcion2;

        if (pro[opcion2]->disponible()== 0) { throw pro; }
        else {


            cout << endl << "Inserte la cantidad de monedas: " << endl;
            cout << " Cuantas de 500: "; cin >> c500;
            cout << endl << " Cuantas de 100: "; cin >> c100;
            cout << endl << " Cuantas de 50: "; cin >> c50;
            cout << "----------------" << endl;

            monto = c500*500 + c100*100 + c50*50;

            system("pause");
            system("cls");

            cout << " Desea azucar: S/N "; cin >> l;

            cout << endl << " Desea cancelar: S/N "; cin >> c;

            if (c == 'S') throw c;
            else {

                Vuelto* v = (Vuelto*)rec[1];  //DOWN CAST

                vuelto =   monto - (pro[opcion2]->getPrecio());

                v->darVuelto(vuelto);

                cout << " Dando vuelto...." << endl << " Su vuelto seria " << vuelto << endl;

                Recibir* r = (Recibir*)rec[0];  //DOWN CAST
                r->recibirDinero(pro[opcion2]->getPrecio());

                cout << "Preparando..." << endl;
                system("pause");
                system("cls");

                cout << "--LISTO--" << endl;
                cout << pro[opcion2]->toString();
                if (!azucar(l)) cout << "Sin azucar" << endl;
                else cout << "Con azucar" << endl;

                cout << "Desea salir: S/N ";cin >> c;  if(c=='S') opcion = 0;


            }
        }

    }

}