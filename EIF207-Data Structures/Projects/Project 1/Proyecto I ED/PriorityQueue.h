#pragma once
#include "Lista.h"

template<class T>
class PriorityQueue:public Lista<T>{
private:
	T elemento;

public:
	Lista<T> PQueueSort(Lista<T> l, PriorityQueue<T> p);
	void insert(T);
	T min();

};

template<class T>
inline Lista<T> PriorityQueue<T>::PQueueSort(Lista<T> l, PriorityQueue<T> p){
	while(!l.estaVacia()){
		elemento = l.valorFinal();
		l.borrarFinal();
		p.insert(elemento);
	}

	while(p.min()){
		elemento = p.min();
		p.borrarFinal();
		l.agregarFinal(elemento);

	}
	return l;
}

template<class T>
inline void PriorityQueue<T>::insert(T e){
	Nodo<T>* nodo = this->getRoot()->getSig();
	while(nodo->getSig() != nullptr && !this->estaVacia()){// a de Yukki
		if(nodo->getInfo() < e){
			break;

		} else if(nodo->getInfo() >= e){
			nodo = nodo->getSig();
		}
	}
	this->agregar(nodo, e);

}

template<class T>
inline T PriorityQueue<T>::min(){
	return this->valorFinal();
}
