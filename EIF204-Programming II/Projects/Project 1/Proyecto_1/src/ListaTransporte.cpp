#include "ListaTransporte.h"

ListaTransporte::ListaTransporte()
{
    primero=NULL;
    actual = NULL;
}

ListaTransporte::~ListaTransporte()
{
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSig();
        delete actual;
    }
}

void ListaTransporte::agregar(Transporte* t)
{
    actual = primero;

    if (primero == NULL) {
        primero = new NodoTransporte(t, NULL);
       
    }
    else {
        while (actual->getSig() != NULL) {
            actual = actual->getSig();
        }
        actual->setSig(new NodoTransporte(t, NULL));
     
    }
}

string ListaTransporte::toString()
{
    actual = primero;
    stringstream s;
    while (actual != NULL) {
        s << actual->toStringNodoTransporte();
        actual = actual->getSig();
    }
    return s.str();
}

bool ListaTransporte::estaVacia()
{
    return primero == NULL ? true : false;;
}

Transporte* ListaTransporte::busqueda(string id)
{
    actual = primero;
    if (estaVacia()) {
        return NULL;
    }
    else {
        while (actual != NULL) {
            if (actual->getTransporte()->getIdentificador() == id) {
                return actual->getTransporte();
            }
            actual = actual->getSig();
        }
       return NULL;
    } 
}

void ListaTransporte::restriccion(int max)
{
    actual = primero;
    
    while (actual != NULL) {
    RestriccionTransporte* t= dynamic_cast<RestriccionTransporte*>(actual->getTransporte());

             if (t) {
                         t->setPorcentaje(max);
                         t->getTamDisponible();
                 }
             actual = actual->getSig();

    }
}

int ListaTransporte::contarCapacidad() 
{
    actual = primero;
    int contador = 0;

    while (actual != NULL) {
        RestriccionTransporte* t = dynamic_cast<RestriccionTransporte*>(actual->getTransporte());

        if (t) {
            contador +=t->getTamDisponible(); 
            actual = actual->getSig();
        }
    }
    return contador;
}

int ListaTransporte::contadorOcupados()
{
    actual = primero;
    int contador = 0;

    while (actual != NULL) {

        contador += actual->getTransporte()->getCan();
        actual = actual->getSig();

    }
    return contador;
    
}


Transporte* ListaTransporte::reservar()
{
    actual = primero;

    while (actual != NULL) {

        if (actual->getTransporte()->reservar()) { return actual->getTransporte(); }

        actual=actual->getSig();

    }
    return NULL;
}

void ListaTransporte::archivoGuarda(string nom)
{
        ofstream salida(nom);
        actual = primero;
        while (actual != NULL) {

            RestriccionTransporte* t = dynamic_cast<RestriccionTransporte*>(actual->getTransporte());

            if (t) {
               
                TransporteBDatos::guardar(salida,t);
            }

            actual = actual->getSig();
        }
        salida.close();
 
}

void ListaTransporte::datosGuardar(ofstream& salida)
{

    actual = primero;
    while (actual != NULL) {

        salida << actual->getTransporte()->getIdentificador()<<'\n';

        actual = actual->getSig();
    }

}


