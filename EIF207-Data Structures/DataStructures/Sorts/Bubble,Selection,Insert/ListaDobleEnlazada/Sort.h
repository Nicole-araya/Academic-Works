#pragma once
#include "Lista.h"

template <class T>
class Sort{
public: 
	typedef typename Nodo<T> Iter;

	static void insertionSortAsc(Lista<T> A);
	static void bubleSort(Lista<T> lst);
	static void selectionSort(Lista<T> vec);

};

template <class T>
inline void Sort<T>::insertionSortAsc(Lista<T> A){
	Iter* actual = A.root()->getSig();

	for (int i = 1, n=A.size(); i < n; i++) {
		Iter* jota = actual->getAnter();

		while ((actual != A.end()) && (*jota->getInfo() > *jota->getSig()->getInfo())){

			A.swap(jota, jota->getSig());
			if(jota == A.root()){
				break;
			}

			jota = jota->getAnter();
		} 

		actual = actual->getSig();

	}
}

template <class T>
inline void Sort<T>::bubleSort(Lista<T> vec){
	Iter* scc;
	Iter* jota;

	for (int i = 0,n=vec.size(); i < n; i++){		
		 jota = vec.root()->getSig();

		for (int j = 1; j < n - i; j++, jota=jota->getSig()) {

			scc = jota->getAnter();

			if (*scc->getInfo() > *scc->getSig()->getInfo()){
				jota=vec.swap(scc, scc->getSig());

			}
		}

	}
}


template <class T>
void Sort<T>::selectionSort(Lista<T> vec){
	Iter* idei = vec.root();
	Iter* jota=nullptr;

	Iter* minVal = jota;

	
	for (int i = 0, n=vec.size(); idei != vec.end()->getAnter(); i++, idei=idei->getSig()) {
		//valor minimo en el vec sin orden
		minVal = idei;

		jota = idei->getSig();
		for (int j = i + 1,n = vec.size(); j < n; j++) {
			

			if (*jota->getInfo() < *minVal->getInfo()) {
				minVal = jota;

			}
			jota = jota->getSig();
		}
		idei = vec.swap(minVal, idei);
	}
}