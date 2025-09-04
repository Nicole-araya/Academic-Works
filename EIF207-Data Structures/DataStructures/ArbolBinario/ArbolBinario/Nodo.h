#pragma once
using namespace std;

template <class T> 
class Nodo
{
private:
	T* info;
	Nodo* left;
	Nodo* right;

public:
	Nodo(T* info = nullptr, Nodo* l=__nullptr, Nodo* r=__nullptr);
	~Nodo();
	T* getInfo();
	Nodo* getLeft();
	Nodo* getRight();
	void setInfo(T* info);
	void setLeft(Nodo<T>* l);
	void setRight(Nodo<T>* r);
	bool isExternal();
	bool isInternal();


};

template<class T>
inline Nodo<T>::Nodo(T* info, Nodo* l, Nodo* r):info(info),left(l),right(r)
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
inline void Nodo<T>::setLeft(Nodo<T>* l)
{
	left = l;
}

template<class T>
inline void Nodo<T>::setRight(Nodo<T>* r)
{
	right = r;
}

template<class T>
inline bool Nodo<T>::isExternal()
{
	return (getLeft()==nullptr && getRight()==nullptr);
}

template<class T>
inline bool Nodo<T>::isInternal()
{
	return (getLeft() != nullptr or getRight() != nullptr);
}
