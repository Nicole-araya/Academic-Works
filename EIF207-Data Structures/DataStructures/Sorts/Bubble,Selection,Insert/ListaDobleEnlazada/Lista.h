#pragma once
#include <sstream>
#include <string>

#include "Nodo.h"

template<class T>
class Lista {
private:
    Nodo<T>* raiz;
    Nodo<T>* aux;
    int siz;
public:
    Lista();
    ~Lista();
    bool estaVacia();
    int size();
    Nodo<T>* root();
    Nodo<T>* end();

    T* valorIni();
    T* valorFinal();
    void agregar( Nodo<T>*,T*);
    void agregarIni(T*);
    void agregarFinal(T*);
    void borrar(Nodo<T>*);
    void borrarIni();
    void borrarFinal();
    string toString();

    Nodo<T>* swap(Nodo<T>* ref, Nodo<T>* act);
    
};

template<class T>
Lista<T>::Lista() {
    raiz = new Nodo<T>;
    aux = new Nodo<T>;
    raiz->setSig(aux);
    aux->setAnter(raiz);
    siz = 0;
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
bool Lista<T>::estaVacia() {
    return (raiz->getSig() == aux);
}

template<class T>
inline int Lista<T>::size(){
    return siz;
}

template<class T>
inline Nodo<T>* Lista<T>::root(){
    return raiz->getSig();
}

template<class T>
inline Nodo<T>* Lista<T>::end(){
    return aux;
}

template<class T>
T* Lista<T>::valorIni(){
    Nodo<T>* temp = raiz->getSig();
    if (temp == NULL) {
        return NULL;
    }

    return temp->getInfo();
}

template<class T>
T* Lista<T>::valorFinal(){
    Nodo<T>* temp = aux->getSig();
    if (temp == NULL) {
        return NULL;
    }

    return temp->getInfo();
}

template<class T>
void Lista<T>::agregar(Nodo<T>* ref,T* valor){
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->setInfo(valor);
    nuevo->setSig(ref);
    nuevo->setAnter(ref->getAnter());
    ref->getAnter()->setSig(nuevo);
    ref->setAnter(nuevo);
    siz++;
}


template<class T>
void Lista<T>::agregarIni(T* valor) {
    agregar(raiz->getSig(), valor);

}

template<class T>
void Lista<T>::agregarFinal(T* valor) {
    agregar(aux, valor);
}


template<class T>
void Lista<T>::borrar(Nodo<T>* ref) {
    Nodo<T>* ant = ref->getAnter();
    Nodo<T>* sig = ref->getSig();
    ant->setSig(sig);
    sig->setAnter(ant);
    delete ref;
    siz--;
}

template<class T>
void Lista<T>::borrarIni(){
    borrar(raiz->getSig());
}

template<class T>
void Lista<T>::borrarFinal(){
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
            s << *temp->getInfo() << ", ";      /// no hago uso del toString de nodo porque son int
            temp = temp->getSig();
        }
        s << endl;
    }

    return s.str();
}

template<class T>
inline Nodo<T>* Lista<T>::swap(Nodo<T>* ref, Nodo<T>* act) {

    T* aux = act->getInfo();
    act->setInfo(ref->getInfo());
    ref->setInfo(aux);
    return act;

}
