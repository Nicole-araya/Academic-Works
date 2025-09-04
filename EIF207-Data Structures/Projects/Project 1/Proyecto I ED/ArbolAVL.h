#pragma once
#include"NodoAVL.h"
#include<iostream>
#include "Heap.h"
using namespace std;

template<class T>
class ArbolAVL{
private:
	NodoAVL<T>* raiz;
	int cantNodos;

public:
	ArbolAVL();
	~ArbolAVL();
	NodoAVL<T>* getRoot();
	int getCantN();
	void setRoot(NodoAVL<T>* raiz);
	int height(NodoAVL<T>* nodo);

	void insertar(T* info, long long key = 0);

	NodoAVL<T>* balance(NodoAVL<T>* nodo);
	T* search(long long key);

	//Muestra;
	void show(NodoAVL<T>*);
	void inorder(NodoAVL<T>* nodo);
	void preorder(NodoAVL<T>* nodo);
	void postorder(NodoAVL<T>* nodo);
	Heap<T>* insertarHeap(Heap<T>* h);
	void saveData(string nom);
	bool isEmpty();

private:
	void guardarDatos(ofstream& salida, NodoAVL<T>* nodo);
	int difference(NodoAVL<T>* nodo);
	NodoAVL<T>* makeEmpty(NodoAVL<T>* t);
	NodoAVL<T>* rr_rotat(NodoAVL<T>* parent);
	NodoAVL<T>* ll_rotat(NodoAVL<T>* parent);
	NodoAVL<T>* lr_rotat(NodoAVL<T>* parent);
	NodoAVL<T>* rl_rotat(NodoAVL<T>* parent);
	NodoAVL<T>* insert(NodoAVL<T>* nodo, T* info, long long key);

	NodoAVL<T>* find(long long key, NodoAVL<T>* t);
	void insertHeap(NodoAVL<T>* nodo,Heap<T>* heap);

};

template<class T>
inline ArbolAVL<T>::ArbolAVL(){
	raiz = nullptr;
	cantNodos = 0;
}

template<class T>
inline ArbolAVL<T>::~ArbolAVL()
{
	raiz = makeEmpty(raiz);
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::makeEmpty(NodoAVL<T>* t)
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
inline NodoAVL<T>* ArbolAVL<T>::getRoot(){
	return raiz;
}

template<class T>
inline int ArbolAVL<T>::getCantN(){
	return this->cantNodos;
}

template<class T>
inline void ArbolAVL<T>::setRoot(NodoAVL<T>* raiz){ this->raiz = raiz; }

template<class T>
inline int ArbolAVL<T>::height(NodoAVL<T>* nodo){
	int h=0;
	if(nodo!= nullptr){
		int l_height = height(nodo->getLeft());
		int r_height = height(nodo->getRight());
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

template<class T>
inline int ArbolAVL<T>::difference(NodoAVL<T>* nodo){
	int l_height = height(nodo->getLeft());
	int r_height = height(nodo->getRight());
	int b_factor = l_height - r_height;
	return b_factor;
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::rr_rotat(NodoAVL<T>* parent){
	NodoAVL<T>* t;
	t = parent->getRight();
	parent->setR(t->getLeft());
	t->setL(parent);
	return t;
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::ll_rotat(NodoAVL<T>* parent){
	NodoAVL<T>* t;
	t = parent->getLeft();
	parent->setL(t->getRight());
	t->setR(parent);
	return t;
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::lr_rotat(NodoAVL<T>* parent){
	NodoAVL<T>* t;
	t = parent->getLeft();
	parent->setL(rr_rotat(t));
	return ll_rotat(parent);
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::rl_rotat(NodoAVL<T>* parent){
	NodoAVL<T>* t;
	t = parent->getRight();
	parent->setR(ll_rotat(t));
	return rr_rotat(parent);
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::balance(NodoAVL<T>* nodo){
	int bal_factor = difference(nodo);

	if (bal_factor > 1) {
		if(difference(nodo->getLeft()) > 0) {
			nodo = ll_rotat(nodo);

		}else {
			nodo = lr_rotat(nodo);
		}
	}else if (bal_factor < -1) {
		if(difference(nodo->getRight()) > 0) {
			nodo = rl_rotat(nodo);
		}else {
			nodo = rr_rotat(nodo);
		}
	}
	return nodo;
}

template<class T>
inline T* ArbolAVL<T>::search(long long key){
	NodoAVL<T>* nodo=NULL;
	if (isEmpty()) return NULL;

	 nodo=find(key, raiz);
	 if (nodo) return nodo->getInfo();
	 else return NULL;
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::insert(NodoAVL<T>* nodo, T* info, long long key) {//key por si la usamos
	if(nodo == raiz && raiz==nullptr){
		raiz = new NodoAVL<T>;
		raiz->setInfo(info);
		raiz->setKey(key);
		return raiz;

	}if(nodo == nullptr) {
		nodo = new NodoAVL<T>;
		nodo->setInfo(info);
		nodo->setKey(key);
		return nodo;

	}else if(key<nodo->getKey()) {
		nodo->setL(insert(nodo->getLeft(), info, key));
		
		nodo = balance(nodo);

	}else if(key >= nodo->getKey()) {
		nodo->setR(insert(nodo->getRight(), info, key));

		nodo = balance(nodo);
	}
	return nodo;
}

template<class T>
inline NodoAVL<T>* ArbolAVL<T>::find(long long key, NodoAVL<T>* t){
	if(t == nullptr) return nullptr;

	else if(key < t->getKey())
		return find(key,t->getLeft());
	else if(key > t->getKey())
		return find(key, t->getRight());
	else return t;
}


template<class T>
inline void ArbolAVL<T>::insertar(T* info, long long key){
	this->raiz=insert(raiz, info, key);
	cantNodos++;
}

template<class T>
inline void ArbolAVL<T>::show(NodoAVL<T>* nodo){  //Eliminamos el int y el for para " "
	int i;
	if(nodo != nullptr){
		show(nodo->getRight());
		cout << " ";

		/*if (nodo == raiz) {
			cout << endl << endl<<endl << endl<< "Root-> "<<endl<<endl;
		}*/

		cout << *nodo->getInfo();
		show(nodo->getLeft());
	}
}

template<class T>
inline void ArbolAVL<T>::inorder(NodoAVL<T>* nodo){
	if(nodo == nullptr){ return; }

	inorder(nodo->getLeft());
	cout << *nodo->getInfo()<<"	";
	inorder(nodo->getRight());
}

template<class T>
inline void ArbolAVL<T>::preorder(NodoAVL<T>* nodo){
	if(nodo == nullptr){ return; }

	cout << *nodo->getInfo() << "	";
	preorder(nodo->getLeft());
	preorder(nodo->getRight());
}

template<class T>
inline void ArbolAVL<T>::postorder(NodoAVL<T>* nodo){
	if(nodo == nullptr){ return; }

	postorder(nodo->getLeft());
	postorder(nodo->getRight());
	cout << *nodo->getInfo() << "	";
}

template<class T>
inline void ArbolAVL<T>::insertHeap(NodoAVL<T>* nodo, Heap<T>* heap)
{
	if (nodo == nullptr) { return; }

	heap->insertKey(nodo->getInfo());
	
	insertHeap(nodo->getLeft(),heap);
	
	insertHeap(nodo->getRight(), heap);
}

template<class T>
inline Heap<T>* ArbolAVL<T>::insertarHeap(Heap<T>* h)
{
	insertHeap(raiz, h);
	return h;
}

template<class T>
inline void ArbolAVL<T>::saveData(string nom)
{ ofstream salida(nom);
	guardarDatos(salida, raiz);
	salida.close();
}

template<class T>
inline bool ArbolAVL<T>::isEmpty()
{
	return raiz==NULL;
}

template<class T>
inline void ArbolAVL<T>::guardarDatos(ofstream& salida, NodoAVL<T>* nodo)
{
	if (nodo == nullptr) { return;  }

	guardarDatos(salida,nodo->getLeft());
	nodo->getInfo()->guardar(salida);
	guardarDatos(salida,nodo->getRight());

	
}
