#include "ListaTiquete.h"

ListaTiquete::ListaTiquete()
{
    primero = NULL;
    actual = NULL;
}

ListaTiquete::~ListaTiquete()
{
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }
}

void ListaTiquete::agregar(Tiquete* t)
{
    actual = primero;

    if (primero == NULL) {
        primero = new NodoTiquete(t, NULL);

    }
    else {
        while (actual->getSig() != NULL) {
            actual = actual->getSig();
        }
        actual->setSig(new NodoTiquete(t, NULL));

    }
}

string ListaTiquete::toString()
{
    actual = primero;
    stringstream s;
    while (actual != NULL) {
        s << actual->toStringNodoTiquete() << endl;
        actual = actual->getSig();
    }
    return s.str();
}

bool ListaTiquete::estaVacia()
{
    return primero == NULL ? true : false;;
}

Tiquete* ListaTiquete::busqueda(string id)
{
    actual = primero;
    if (estaVacia()) {
        return NULL;
    }
    else {
        while (actual != nullptr) {
            if (actual->getTiquete()->getIdentificador() == id) {
                return actual->getTiquete();
            }
            actual = actual->getSig();
        }
        return NULL;
    }
}

void ListaTiquete::guardar(string nom)
{
    ofstream salida(nom);

    actual = primero;
    while (actual != NULL) {

        TiquteBDatos::guardar(salida,actual->getTiquete());

        actual = actual->getSig();
    }
    salida.close();
}








