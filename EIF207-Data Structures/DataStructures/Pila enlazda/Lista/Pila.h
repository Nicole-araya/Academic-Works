#pragma once
#include "Lista.h"

template<class T>
class Pila {
private:
	Lista<T>* S;
	int cantidad;

public:
	Pila();
	~Pila();
	void push(T* info);
	T* top();
	void pop();
	bool empty();
	int size();


};

template<class T>
 Pila<T>::Pila():S(new Lista<T>),cantidad(0) {
}

 template<class T>
 Pila<T>::~Pila() {
	 delete S;
 }


template<class T>
 void Pila<T>::push(T* info){
	 ++cantidad;
	 S->agregarIni(info);
	
}


template<class T>
 T* Pila<T>::top(){

	 if (empty()) {
		 cout << "Lista Vacia" << endl;
		 return NULL;
	 }

	return S->valorIni();
}

template<class T>
 void Pila<T>::pop(){
	 if (empty()) {
		 cout << "Lista Vacia" << endl;
	 }
	 else {
		 S->borrarIni();
		 cantidad--;
	 }
	
}

template<class T>
 bool Pila<T>::empty(){
	 return cantidad== 0;
}

template<class T>
int Pila<T>::size(){
	return cantidad;
}
