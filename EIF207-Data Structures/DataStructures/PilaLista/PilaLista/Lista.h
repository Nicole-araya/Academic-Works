#pragma once
#include <sstream>
#include <string>

#include "Nodo.h"

template<class T>
class Lista {             //LISTA SIMPLE
private:
    Nodo<T>* raiz;
public:
    Lista();
    ~Lista();
    T* valorIni();
    void agregarIni(T*);
    void borrarIni();
    string toString();

};

template<class T>
Lista<T>::Lista() {
    raiz = new Nodo<T>;

}

template<class T>
Lista<T>::~Lista() {
    Nodo<T>* aux=NULL;
    Nodo<T>* anterior=NULL;
    if (raiz->getSig() == nullptr) {
        delete raiz;
    }
    else {
        while (raiz->getSig() != nullptr) {
            aux = raiz;
            while (aux->getSig() != nullptr) {
                anterior = aux;
                aux = aux->getSig();
            }
            anterior->setSig(nullptr);
            delete aux;

        }
    }
}


template<class T>
T* Lista<T>::valorIni()
{
    Nodo<T>* temp = raiz;
    if (temp->getSig() != NULL) {
        temp = temp->getSig();
        return temp->getInfo();
    }

    return NULL;
}


template<class T>
void Lista<T>::agregarIni(T* valor) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->setInfo(valor);
    nuevo->setSig(raiz->getSig());
    raiz->setSig(nuevo);
   

}


template<class T>
void Lista<T>::borrarIni()
{
    Nodo<T>* temp = raiz;
    if (temp->getSig() != NULL) {

        temp = temp->getSig();
        raiz->setSig(temp->getSig());
        delete temp;
    }
}



template<class T>
string Lista<T>::toString() {
    Nodo<T>* temp = raiz;

    stringstream s;

    if (temp->getSig() == nullptr) {
        s << "Lista Vacia" << endl;
    }
    else {
        temp = temp->getSig();
        while (temp != nullptr) {
            s << temp->toString() << ", ";      
            temp = temp->getSig();
        }
        s << endl;
    }

    return s.str();
}