#pragma once
#include <iostream>

using namespace std;

template<class T>
class Nodo {

private:
	int key;
	T* info;
	Nodo<T>* left;
	Nodo<T>* right;

public:
	Nodo(int k = 0, T* info = nullptr, Nodo<T>* l = nullptr, Nodo<T>* r = nullptr);
	virtual ~Nodo();
	int getKey();
	Nodo<T>* getLeft();
	Nodo<T>* getRight();
	T* getInfo();
	void setKey(int k);
	void setNodoLeft(Nodo<T>* l);
	void setNodoRight(Nodo<T>* r);
	void setInfo(T* i);
};

template<class T>
inline Nodo<T>::Nodo(int k, T* info, Nodo<T>* l, Nodo<T>* r) {
	key = k;
	left = l;
	right = r;
	this->info = info;
}


template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline int Nodo<T>::getKey()
{
	return key;
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
inline T* Nodo<T>::getInfo()
{
	return this->info;
}

template<class T>
inline void Nodo<T>::setKey(int k)
{
	key = k; 
}

template<class T>
inline void Nodo<T>::setNodoLeft(Nodo<T>* l)
{
	left = l;
}

template<class T>
inline void Nodo<T>::setNodoRight(Nodo<T>* r)
{
	right = r;
}

template<class T>
inline void Nodo<T>::setInfo(T* i)
{
	info = i;
}
