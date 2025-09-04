#pragma once
#include "Nodo.h"

template <class T>
class ArbolBinario
{
private:
	Nodo<T>* raiz;
	int cant;

protected:

	void insertaRecur(T* info, Nodo<T>* hoja);
	void destruyeArbol(Nodo<T>* nodo);
	Nodo<T>* buscarRecur(T* info, Nodo<T>* leaf);

public:
	ArbolBinario();
	virtual ~ArbolBinario();
	int getCan() const;
	void setCan(int can);
	int size();
	bool vacio();
	bool isRoot(Nodo<T>* nodo);
	bool isExternal(Nodo<T>* nodo);

	void insertar(T* info);
	Nodo<T>* buscar(T* info);
	void preOrden(Nodo<T>* t);
	
};

template<class T>
inline ArbolBinario<T>::ArbolBinario()
{
	raiz = nullptr;
	cant = 0;
}

template<class T>
inline ArbolBinario<T>::~ArbolBinario()
{
	destruyeArbol(raiz);
}

template<class T>
inline int ArbolBinario<T>::getCan() const
{
	return cant;
}

template<class T>
inline void ArbolBinario<T>::setCan(int can)
{
	cant = can;
}

template<class T>
inline int ArbolBinario<T>::size()
{
	return getCan();
}

template<class T>
inline bool ArbolBinario<T>::vacio()
{
	return raiz==nullptr;
}

template<class T>
inline bool ArbolBinario<T>::isRoot(Nodo<T>* nodo)
{
	return (nodo->getParent()==nullptr);
}

template<class T>
inline bool ArbolBinario<T>::isExternal(Nodo<T>* nodo)  //para ver si es hoja
{
	return (nodo->getLeft()==nullptr && nodo->getRight()==nullptr);
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
	setCan(getCan() + 1);
}

template<class T>
inline void ArbolBinario<T>::insertaRecur(T* info, Nodo<T>* nodo)
{
	if (info < nodo->getInfo()) {
		if (nodo->getLeft() != nullptr) {
			insertaRecur(info, nodo->getLeft());
		}
		else nodo->setLeft(new Nodo<T>(info,nodo, nullptr, nullptr));
	}
	else {
		if (info >= nodo->getInfo()) {
			if (nodo->getRight() != nullptr) {
				insertaRecur(info, nodo->getRight());
			}
			else nodo->setRight(new Nodo<T>(info,nodo, nullptr, nullptr));
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
inline void ArbolBinario<T>::preOrden(Nodo<T>* t)
{
	if (t != nullptr) {
		cout << t->getInfo() << " - ";
		preOrden(t->getLeft());
		preOrden(t->getRight());
	}
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
