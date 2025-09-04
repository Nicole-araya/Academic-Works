#pragma once
#include "ListaQQ.h"
#include <iostream>
using namespace std;

template<class E>
class Cola{
private:

	Lista<E>* l;
	int cantidad;

public:
	Cola();
	~Cola();

	int size();
	bool empty();
	void enqueue(E* info);
	void dequeue();
	E* front();
	void makeEmpty();
	string imprimir();
	//string toString();
};

template<class E>
Cola<E>::Cola():l(new Lista<E>), cantidad(0) {
}


template<class E>
int Cola<E>::size(){
	return cantidad+1;
}

template<class E>
bool Cola<E>::empty(){
	return (cantidad == 0);
}

template<class E>
 Cola<E>::~Cola(){
	delete l;
}

template<class E>
void Cola<E>::enqueue(E* info){
	l->agregarFinal( info);
	cantidad++;
}

template<class E>
 void Cola<E>::dequeue(){
	if(!empty()){
		l->borrarIni();
		cantidad--;
		return;
	}
}

template<class E>
E* Cola<E>::front(){
	if (!empty()) {
		return l->valorIni();
	}
}

template<class E>
inline void Cola<E>::makeEmpty(){
	if(empty()){
		return;
	} else{

		l->borrarIni();
		cantidad--;
		makeEmpty();
	}
}

template<class E>
inline string Cola<E>::imprimir(){
	return l->toString();
}
