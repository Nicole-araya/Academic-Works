#pragma once
#include <iostream>
#include <sstream>
using namespace std;
template <class  T>

class Nodo{

    private:
        T* info;
        Nodo<T>* sig;
    public:
        Nodo();
        ~Nodo();
        void setInfo(T*);
        T* getInfo();
        void setSig(Nodo<T>*);
        Nodo<T>* getSig();
        string toString();



};

template<class T>
Nodo<T>::Nodo() {
    info = NULL;
    this->sig = nullptr;

}

template<class T>
void Nodo<T>::setInfo(T* info) {
    this->info = info;
}

template<class T>
T* Nodo<T>::getInfo() {
    return info;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* sig) {
    this->sig = sig;
}


template<class T>
Nodo<T>* Nodo<T>::getSig() {
    return sig;
}



template<class T>
string Nodo<T>::toString() {
    return getInfo()->toString();
}

template<class T>
Nodo<T>::~Nodo(){
    delete info;
}



