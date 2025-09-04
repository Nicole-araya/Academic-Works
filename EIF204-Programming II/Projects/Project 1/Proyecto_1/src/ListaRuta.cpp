#include "ListaRuta.h"

ListaRuta::ListaRuta()
{
    primero = NULL;
    actual = NULL;
}

ListaRuta::~ListaRuta()
{
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }
}

void ListaRuta::agregar(Ruta* r)
{
    actual = primero;

    if (primero == NULL) {
        primero = new NodoRuta(r, NULL);

    }
    else {
        while (actual->getSig() != NULL) {
            actual = actual->getSig();
        }
        actual->setSig(new NodoRuta(r, NULL));

    }
}

string ListaRuta::toString()
{
    actual = primero;
    stringstream s;
    while (actual != NULL) {
        s << actual->toStringNodoRuta() << endl;
        actual = actual->getSig();
    }
    return s.str();
}

bool ListaRuta::estaVacia()
{
    return primero == NULL ? true : false;;
}

string ListaRuta::imprimirRutaBus()
{
    actual = primero;
    stringstream s;
    while (actual != NULL) {
        s << "Ruta ";
        s << actual->toStringNodoRuta() << endl;
        s << actual->getRuta()->imprimirBuses() << endl;
        actual = actual->getSig();
    }
    return s.str();
}

Ruta* ListaRuta::busqueda(string id)
{
    actual = primero;
    if (estaVacia()) {
        return NULL;
    }
    else {
        while (actual != nullptr) {
            if (actual->getRuta()->getIdentificador() == id) {
                return actual->getRuta();
            }
            actual = actual->getSig();
        }
        return NULL;
    }
}

bool ListaRuta::busquedaTransporte(string cod)
{
    actual = primero;
    string aux;

    while (actual != NULL) {

        if (actual->getRuta()->getLista()->busqueda(cod)) {
            return true;
        }

        actual = actual->getSig();
    }

    return false;
}

string ListaRuta::disponibilidadRutas()
{
    actual = primero;
    stringstream s;

    while (actual != NULL) {

        s << actual->toStringNodoRuta() << " Disponibilidad actual: "
            << RutaReservar::porcentajedisponibilidad(actual->getRuta())<<"%" << endl;

        actual = actual->getSig();
    }

    return s.str();
}

void ListaRuta::guardar(string nom,string nomB)
{
    ofstream salida(nom);

    actual = primero;
    while (actual != NULL) {

        RutaBDatos::guardarRuta(salida, actual->getRuta());
        actual = actual->getSig();
    }
    salida.close();


    ofstream salida2(nomB);
    actual = primero;
    while (actual != NULL) {

        RutaBDatos::guardarRTransporte(salida2, actual->getRuta());
        actual = actual->getSig();
    }
    salida2.close();

}


