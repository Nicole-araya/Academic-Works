#pragma once
#include <iostream>
using namespace std;

template <class T> 
class Nodo
{
private:
	T* info;
	Nodo* parent;
	Nodo* left;
	Nodo* right;

public:
	Nodo(T* info = nullptr, Nodo<T>* p = __nullptr, Nodo<T>* l=__nullptr, Nodo<T>* r=__nullptr);
	~Nodo();
	T* getInfo();
	Nodo<T>* getParent();
	Nodo<T>* getLeft();
	Nodo<T>* getRight();
	void setInfo(T* info);
	void setParent(Nodo<T>* p);
	void setLeft(Nodo<T>* l);
	void setRight(Nodo<T>* r);

};

template<class T>
inline Nodo<T>::Nodo(T* info, Nodo<T>* p, Nodo<T>* l, Nodo<T>* r):info(info),left(l),right(r),parent(p)
{
}

template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline T* Nodo<T>::getInfo()
{
	return info;
}

template<class T>
inline Nodo<T>* Nodo<T>::getParent()
{
	return parent;
}

template<class T>
inline Nodo<T>* Nodo<T>::getLeft()
{
	return left;
}

template<class T>
inline Nodo<T>* Nodo<T>::getRight()
{
	return right;
}

template<class T>
inline void Nodo<T>::setInfo(T* info)
{
	this->info = info;
}

template<class T>
inline void Nodo<T>::setParent(Nodo<T>* p)
{
	parent = p;
}

template<class T>
inline void Nodo<T>::setLeft(Nodo<T>* l)
{
	left = l;
}

template<class T>
inline void Nodo<T>::setRight(Nodo<T>* r)
{
	right = r;
}

