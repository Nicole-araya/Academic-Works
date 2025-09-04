#pragma once
#include "Lista.h"

template <class T>
class Sort{
public: 
	typedef typename Nodo<T> Iter;
	static void quickSort(Lista<T> lst);
	//static void selectionSort(Lista<T> vec);

private:
	typedef typename Lista<T>::Iterador Iterador;
	static void quickSortStep(Lista<T> lst, Iterador begin, Iterador fin);
};

template<class T>
inline void Sort<T>::quickSort(Lista<T> lst){
	if(lst.size() <= 1) return;
	quickSortStep(lst, Iterador(lst.root()), Iterador(lst.end()->getAnter()).i(lst.size()-1));
}

template<class T>
inline void Sort<T>::quickSortStep(Lista<T> lst, Iterador a, Iterador b){
	T pivot = *a.valor;
	Iterador r(b.nd);
	Iterador l(a.nd);

	int i=a.indice, j=b.indice;
	while(i<j){
		while(!(* l.valor > pivot) && i<j) l++, i++;//not mayor == <=
		while(*r.valor > pivot && r.nd != l.nd)r--, j--;

		if(i<j){ //swap
			l.swap(r);
		}
	}

	l.i(i);
	r.i(j);

	if(pivot > *r.valor) r++;

	lst.agregar(r.nd, new T(*a.valor));
	a++;
	lst.borrar(a.nd->getAnter());

	if(a.indice < j - 1) quickSortStep(lst, a, Iterador(r.nd->getAnter()).i(r.indice-1));
	if(j < b.indice) quickSortStep(lst, Iterador(r.nd).i(r.indice), b);
}
