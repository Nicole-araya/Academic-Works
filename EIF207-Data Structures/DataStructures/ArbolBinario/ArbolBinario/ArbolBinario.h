#pragma once
#include "Nodo.h"

template <class T>
class ArbolBinario
{
private:
	Nodo<T>* raiz;

public:
	ArbolBinario();
	virtual ~ArbolBinario();
	bool vacio();
	void insertarNorm(T* info);
	void insertar(T* info);
	void insertaRecur(T* info,Nodo<T>* hoja);
	Nodo<T>* buscarRecur(T* info,Nodo<T>*leaf);
	Nodo<T>* buscar(T* info);
	void destruyeArbol(Nodo<T>* nodo);

};

template<class T>
inline ArbolBinario<T>::ArbolBinario()
{
	raiz = nullptr;
}

template<class T>
inline ArbolBinario<T>::~ArbolBinario()
{
	destruyeArbol(raiz);
}

template<class T>
inline bool ArbolBinario<T>::vacio()
{
	return raiz==nullptr;
}


template<class T>
inline void ArbolBinario<T>::insertarNorm(T* info)
{
	Nodo<T>* nuevo=new Nodo<T>;
	Nodo<T>* temp;
	temp = raiz;
	nuevo->setInfo(info);
	if (raiz == nullptr) {
		raiz = nuevo;
	}
	else {
		while (temp != nullptr) {

			if (temp->getInfo() > info) {
				if (temp->getLeft() == nullptr) {
					temp->setLeft(nuevo);
				}
				else temp = temp->getLeft();

			}
			else if (temp->getInfo() < info) {

				if (temp->getRight == nullptr) {
					temp->setRight(nuevo);
				}
				else temp = temp->getRight();

			}
			else return;
				
		}
 
	}
	
}

template<class T>
inline void ArbolBinario<T>::insertar(T* info)
{
	if (raiz != nullptr)
		insertaRecur(info, raiz);
	else {
		raiz = new Nodo<T>;
		raiz->setInfo(info);
	}
}

template<class T>
inline void ArbolBinario<T>::insertaRecur(T* info, Nodo<T>* hoja)
{
	if (info < hoja->getInfo()) {
		if (hoja->getLeft() != nullptr) {
			insertaRecur(info, hoja->getLeft());
		}
		else hoja->setLeft(new Nodo<T>(info, nullptr, nullptr));
	}
	else {
		if (info > hoja->getInfo()) {
			if (hoja->getRight() != nullptr) {
				insertaRecur(info, hoja->getRight());
			}
			else hoja->setRight(new Nodo<T>(info, nullptr, nullptr));
		}
	}
}

template<class T>
inline Nodo<T>* ArbolBinario<T>::buscarRecur(T* info, Nodo<T>* leaf)
{
	if (leaf != nullptr) {
		if (info == leaf->getInfo()) {
			return leaf;
		}
		if (info < leaf->getInfo()) 
			return buscarRecur(info, leaf->getLeft());
		else
			return buscarRecur(info, leaf->getRight());
	}
	return nullptr;
}

template<class T>
inline Nodo<T>* ArbolBinario<T>::buscar(T* info)
{
	return buscarRecur(info, raiz);
}

template<class T>
inline void ArbolBinario<T>::destruyeArbol(Nodo<T>* nodo)
{
	if (nodo != nullptr) {
		destruyeArbol(nodo->getLeft());
		destruyeArbol(nodo->getRight());
		delete nodo;
	}
}
