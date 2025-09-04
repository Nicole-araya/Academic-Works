#pragma once
#include "Lista.h"

template <class T>
class Sort{
public: 

	static void mergeSort(Lista<T> S);
	static void merge(Lista<T>& S1, Lista<T>& S2, Lista<T>& S);

	

};

template<class T>
inline void Sort<T>::mergeSort(Lista<T> S)
{
	
	//typedef typename Iterador<T> itor; //secuencia de elementos
	int n = S.size();
	if (n <= 1) return;
	Lista<T> S1, S2;
	Iterador<T>* itor = S.begin();
	for (int i = 0; i < n / 2; i++) {
		S1.agregarIni(new int(*itor->Cursor())); itor->next();
	}
	for (int i = n / 2; i < n; i++) {
		S2.agregarIni(new int(*itor->Cursor())); itor->next();
	}

	S.clear(); // borra los numeros
	mergeSort(S1);
	mergeSort(S2);
	
	merge(S1, S2, S);
	
}

template<class T>
inline void Sort<T>::merge(Lista<T>& S1, Lista<T>& S2, Lista<T>& S)
{
	Iterador<T>* itor = S1.begin();
	Iterador<T>* itor2 = S2.begin();
	while (!(itor->isEmpty()) && !(itor2->isEmpty()) && itor->getCursor() != S1.end() && itor2->getCursor() != S2.end()) {
		if ( *itor->Cursor() < *itor2->Cursor()) { 
			S.agregarFinal(new int(*itor->Cursor())); itor->next();
		}
		else { S.agregarFinal(new int(*itor2->Cursor())); itor2->next();
		}
	}
	
	while (!(itor->isEmpty()) && itor->getCursor() != S1.end())
	{
		S.agregarFinal(new int(*itor->Cursor())); itor->next();
	}

	while (!(itor2->isEmpty()) && itor2->getCursor() != S2.end())
	{
		S.agregarFinal(new int(*itor2->Cursor())); itor2->next();
	}

}


