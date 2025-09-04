#pragma once
#include "Nodo.h"

template<class T,class U>
class Iterador {
private:
    Nodo<T>* nodo;
public:

    void operator =(Nodo<T>*);
    void operator ++(Nodo<T>*);
    void operator --(Nodo<T>*);
    T operator *();
    bool operator ==(Nodo<T>*);
    bool operator !=(Nodo<T>*);
};

template<class T>
inline void Iterador<T>::operator =(Nodo<T>* n)
{
    nodo = n;
}

template<class T>
inline void Iterador<T>::operator ++(Nodo<T>* n)
{
    nodo = n->getSig();
}

template<class T>
inline void Iterador<T>::operator --(Nodo<T>* n)
{
    nodo = n->getAnter();
}

template<class T>
inline T Iterador<T>::operator *()
{
    return nodo->getInfo();
}

template<class T>
inline bool Iterador<T>::operator ==(Nodo<T>* n)
{
    return nodo = n;
}

template<class T>
inline bool Iterador<T>::operator !=(Nodo<T>*)
{
    return nodo != n;
}
