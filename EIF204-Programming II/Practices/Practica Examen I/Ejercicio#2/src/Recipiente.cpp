#include "Recipiente.h"

Recipiente::Recipiente(string nom)
{
    nombre = nom;
    tam = 3;
    can = 0;

    v = new Dinero * [tam];

    for (int i = 0; i < tam;i++) {
        v[i] = NULL;
    }
}

Recipiente::~Recipiente()
{
    for (int i = 0; i < tam;i++) {
        delete v[i];
    }
    delete[] v;
}

/////////////////////////////////////////


Vuelto::Vuelto(string nom) :Recipiente(nom) {


}

Vuelto:: ~Vuelto() {}

void  Vuelto::insertarDinero(Dinero* d) {

    if (can < tam) {
        v[can++] = d;
    }
}



Dinero* Vuelto::buscar(int valor) {

    for (int i = 0;i < can;i++) {

        if (v[i]->getValor() == valor) {

            return v[i];
        }
    }
    return NULL;
}

void Vuelto::darVuelto(int monto) {

    if (monto != 0) {
        int aux1 = buscar(500)->getcan(); int aux2 = buscar(100)->getcan(); int aux3 = buscar(50)->getcan();

        while (!(monto - 500 < 0) && aux1 != 0) {

            aux1--;
            monto -= 500;  // monto = monto - 500;
        }
        while (!(monto - 100 < 0) && aux2 != 0) {

            aux2--;
            monto -= 100;
        }
        while (!(monto - 50 < 0) && aux3 != 0) {

            aux3--;
            monto -= 50;
        }

        if (monto == 0) {

            buscar(500)->setCan(aux1);
            buscar(100)->setCan(aux2);
            buscar(50)->setCan(aux3);


        }
        else {
            throw monto;
        }
    }
}

///////////////////////////////////////////////////


Recibir::Recibir(string nom) :Recipiente(nom) {



}
Recibir:: ~Recibir() {}

void  Recibir::insertarDinero(Dinero* d) {

    if (can < tam) {
        v[can++] = d;
    }
}




Dinero* Recibir::buscar(int valor) {

    for (int i = 0;i < can;i++) {

        if (v[i]->getValor() == valor) {

            return v[i];
        }
    }

    return NULL;
}


void Recibir::recibirDinero(int monto) {
    int aux1 = buscar(500)->getcan(); int aux2 = buscar(100)->getcan(); int aux3 = buscar(50)->getcan();
    while (!(monto - 500 < 0)) {

        buscar(500)->setCan(aux1++);
        monto -= 500;
    }
    while (!(monto - 100 < 0)) {

        buscar(100)->setCan(aux2++);
        monto -= 100;
    }
    while (!(monto - 50 < 0)) {

        buscar(50)->setCan(aux3++);
        monto -= 50;
    }

}
