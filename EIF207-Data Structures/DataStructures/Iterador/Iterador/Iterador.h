#pragma once
#include "Nodo.h"
using namespace std;

template<class T>
class Iterador {
private:
    Nodo<T>* cursor;
    Nodo<T>* Lisraiz; //esto se pone porque es lista doble enlazada, si no no
public:
    Iterador(Nodo<T>* nodo, Nodo<T>* raiz);
    bool isEmpty();
    T* next();

};

template<class T>
inline Iterador<T>::Iterador(Nodo<T>* nodo, Nodo<T>* raiz)
{
    cursor = nodo;
    Lisraiz = raiz;
}

template<class T>
inline bool Iterador<T>::isEmpty()
{
    return (cursor == NULL);
}

template<class T>
inline T* Iterador<T>::next()
{
    T* aux;
    if (!isEmpty()) {
        aux = cursor->getInfo();

        //ESTA PARTE ES XQ ES LISTA DOBLE ENLAZADA
        if (cursor->getSig()->getInfo() != Lisraiz->getInfo()) {
            cursor = cursor->getSig();
        } else { cursor = nullptr; }
        //--------
       // cursor =cursor->getSig(); SI FUERA Normal
        return aux;
    }
    return nullptr;
}