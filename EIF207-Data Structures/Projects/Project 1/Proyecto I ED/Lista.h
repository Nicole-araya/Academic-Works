#pragma once
#include <sstream>
#include <string>

#include "Nodo.h"

template<class T>
class Lista{
private:
    Nodo<T>* raiz;
    Nodo<T>* aux;
public:
    Lista();
    ~Lista();
    Nodo<T>* getRoot();
    bool estaVacia();
    T valorIni();
    T valorFinal();
    void agregar( Nodo<T>*,T);
    void agregarIni(const T&);
    void agregarFinal(const T&);
    void borrar(Nodo<T>*);
    void borrarIni();
    void borrarFinal();
    string toString();
};

template<class T>
Lista<T>::Lista() {
    raiz = new Nodo<T>;
    aux = new Nodo<T>;
    raiz->setSig(aux);
    aux->setAnter(raiz);
}

template<class T>
Lista<T>::~Lista() {
    Nodo<T>* anterior = nullptr;
    if (raiz->getSig() == nullptr) {
        delete raiz;
    }
    else {
        while (aux->getSig() != nullptr) {
            aux = raiz->getSig();
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
inline Nodo<T>* Lista<T>::getRoot(){
    return raiz;
}

template<class T>
bool Lista<T>::estaVacia() {
    return (raiz->getSig() == aux);
}

template<class T>
T Lista<T>::valorIni()
{
    Nodo<T>* temp = raiz->getSig();
    
    if (temp == NULL) {
        return NULL;
    }

    return temp->getInfo();
}

template<class T>
T Lista<T>::valorFinal(){

    Nodo<T>* temp = aux->getAnter();
    if (temp == NULL) {
        return NULL;
    }

    return temp->getInfo();
}

template<class T>
void Lista<T>::agregar(Nodo<T>* ref,T valor){
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->setInfo(valor);
    nuevo->setSig(ref);
    nuevo->setAnter(ref->getAnter());
    ref->getAnter()->setSig(nuevo);
    ref->setAnter(nuevo);
}


template<class T>
void Lista<T>::agregarIni(const T& valor) {
    agregar(raiz->getSig(), valor);
}

template<class T>
void Lista<T>::agregarFinal(const T& valor) {
    agregar(aux, valor);
}


template<class T>
void Lista<T>::borrar(Nodo<T>* ref) {
    Nodo<T>* ant = ref->getAnter();
    Nodo<T>* sig = ref->getSig();
    ant->setSig(sig);
    sig->setAnter(ant);
    //ref = new Nodo<T>();
    //ref->~Nodo();
    delete ref;
}

template<class T>
void Lista<T>::borrarIni()
{
    borrar(raiz->getSig());
}

template<class T>
void Lista<T>::borrarFinal()
{
    borrar(aux->getAnter());
}


template<class T>
string Lista<T>::toString() {
    Nodo<T>* temp = raiz->getSig();

    stringstream s;

    if (temp == aux) {
        s << "Lista Vacia" << endl;
    }
    else {
        while (temp != aux) {
            s << temp->getInfo() << ", ";      /// no hago uso del toString de nodo porque son int
            temp = temp->getSig();
        }
        s << endl;
    }

    return s.str();
}