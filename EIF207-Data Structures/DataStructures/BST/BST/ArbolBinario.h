#pragma once
#include "Nodo.h"


template <class T>
class ArbolBinario {

private:
	
	Nodo<T>* root;
	
	Nodo<T>* makeEmpty(Nodo<T>* t);
	Nodo<T>* insert(int k,T* info, Nodo<T>* t);
	Nodo<T>* finMin(Nodo<T>* t);
	Nodo<T>* finMax(Nodo<T>* t);
	Nodo<T>* remove(int k, Nodo<T>* t);
	void inorder(Nodo<T>* t);
	Nodo<T>* find(int k, Nodo<T>* t);

public:

	ArbolBinario();
	virtual ~ArbolBinario();
	void insert(int k, T* info);
	void remove(int k);
	void display();
	void search(int k);
};

template<class T>
inline ArbolBinario<T>::ArbolBinario()
{
	root = nullptr;
}

template<class T>
inline ArbolBinario<T>::~ArbolBinario()
{
	root = makeEmpty(root);
}

template<class T>
inline void ArbolBinario<T>::insert(int k,T* info)
{
	root = insert(k,info, root);
}

template<class T>
inline void ArbolBinario<T>::remove(int k)
{
	root = remove(k, root);
}

template<class T>
inline void ArbolBinario<T>::display()
{
	inorder(root);
	cout << endl;
}

template<class T>
inline void ArbolBinario<T>::search(int k)
{
	root = find(k, root);
}

template<class T>
inline Nodo<T>* ArbolBinario<T>::makeEmpty(Nodo<T>* t)
{
	if (t == nullptr) 
		return nullptr;
	{
		makeEmpty(t->getLeft());
		makeEmpty(t->getRight());
		delete t;
	}

	return nullptr;
}

template<class T>
inline Nodo<T>* ArbolBinario<T>::insert(int x, T* info, Nodo<T>* t)
{
	if (t == nullptr) {
		t = new Nodo<T>(x, info);
	}
	else if (x < t->getKey())
		t->setNodoLeft(insert(x, info, t->getLeft()));
	else if (x > t->getKey())
		t->setNodoRight(insert(x, info, t->getRight()));

	return t;
}


template<class T>
inline Nodo<T>* ArbolBinario<T>::finMin(Nodo<T>* t)
{
	if (t == nullptr)
		return nullptr;
	else if (t->getLeft() == nullptr)
		return t;
	else
		return finMin(t->getLeft());
}

template<class T>
inline Nodo<T>* ArbolBinario<T>::finMax(Nodo<T>* t)
{
	if (t == nullptr)
		return nullptr;
	else if (t->getRight() == nullptr)
		return t;
	else
		return finMin(t->getRight());
}


template<class T>
inline Nodo<T>* ArbolBinario<T>::remove(int k, Nodo<T>* t)
{
	Nodo<T>* temp;
	if (t == nullptr) {
		return nullptr;
	}
	else if (k < t->getKey()) {
		t->setNodoLeft(remove(k, t->getLeft()));
	}
	else if (k > t->getKey()) {
		t->setNodoRight(remove(k, t->getRight()));
	}
	else if (t->getLeft() && t->getRight()) {
		temp = finMin(t->getRight());
		t->setKey(temp->getKey()); t->setInfo(temp->getInfo());
		t->setNodoRight(remove(t->getKey(), t->getRight()));
	}
	else {

		temp = t;
		if (t->getLeft() == nullptr) {
			t = t->getRight();
		}
		else if (t->getRight() == nullptr)
			t = t->getLeft();
		delete temp;
	}
	return t;
}

template<class T>
inline void ArbolBinario<T>::inorder(Nodo<T>* t)
{
	if (t == nullptr)
		return;
	inorder(t->getLeft());
	cout << *t->getInfo() << " ";
	inorder(t->getRight());
}

template<class T>
inline Nodo<T>* ArbolBinario<T>::find(int x, Nodo<T>* t)
{
	if (t == nullptr) return nullptr;

	else if (x < t->getKey())
		return find(t->getLeft());
	else if (x > t ->getKey())
		return fin(t->getRight());
	else return t;
}



