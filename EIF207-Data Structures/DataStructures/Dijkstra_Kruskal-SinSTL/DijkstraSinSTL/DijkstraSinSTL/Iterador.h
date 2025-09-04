#pragma once
#include "Nodo.h"
#include <xkeycheck.h>
using namespace std;

template<class T>
class Iterador {
private:
    Nodo<T>* cursor;
    Nodo<T>* Lisraiz; //esto se pone porque es lista doble enlazada, si no no
public:
    Iterador(Nodo<T>* nodo, Nodo<T>* raiz);
    bool isEmpty();
    void next();
    T* Cursor();
    Nodo<T>* getCursor();

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
inline void Iterador<T>::next()
{
    if (!isEmpty()) {

        if (cursor->getSig()->getInfo() != Lisraiz->getInfo()) { cursor = cursor->getSig(); }
        else { cursor = nullptr; }
    }
}

template<class T>
inline T* Iterador<T>:: Cursor()
{
    return (cursor->getInfo());
}

template<class T>
inline Nodo<T>* Iterador<T>::getCursor()
{
    return cursor;
}





