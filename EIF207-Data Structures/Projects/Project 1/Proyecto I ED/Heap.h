#pragma once
#include <iostream>
using namespace std;
template <class T>
class Heap
{
private:
	T** harr; //puntero al arreglo de elementos en el heap
	int capacity; //tamanio maximo posible del heap
	int heap_size; //tamanio actual del heap

public:
	Heap(int cap);
	~Heap();
	int maxCapacity();
	int size();
	void MaxHeapify(int i);
	int parent(int i);
	int left(int i);
	int righ(int i);
	T* getMax();
	T* extracMax();
	void decreaseKey(int i,T* new_val);
	void deleteKey(int i);
	void insertKey(T* k);
	bool isEmpty();

	

};
template<class T>
void swap(T* x, T* y);

template<class T>
inline Heap<T>::Heap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new T*[cap];

	for (int i = 0; i < capacity; i++) {
		harr[i] = NULL;
	}
}

template<class T>
inline Heap<T>::~Heap()
{
	for (int i = 0; i < capacity; i++) {
		delete harr[i];
	}
	delete[] harr;
}

template<class T>
inline int Heap<T>::maxCapacity(){
	return capacity;
}

template<class T>
inline int Heap<T>::size()
{
	return heap_size;
}

template<class T>
inline void Heap<T>::MaxHeapify(int i){
	int l = left(i);
	int r = righ(i);
	int biggest = i;
	if (l < heap_size && *harr[l] > *harr[i])
		biggest = l;
	if (r < heap_size && *harr[r] > *harr[biggest])
		biggest = r;
	if (biggest != i) {

		T* child = harr[i];
		T* pp = harr[biggest];

		swap(harr[i], harr[parent(i)]);
		harr[i] = pp;
		harr[biggest] = child;
		MaxHeapify(biggest);
	}
}

template<class T>
inline int Heap<T>::parent(int i)
{
	return (i-1)/2;
}

template<class T>
inline int Heap<T>::left(int i)
{
	return (2*i + 1);
}

template<class T>
inline int Heap<T>::righ(int i)
{
	return (2*i + 2);
}

template<class T>
inline T* Heap<T>::getMax()
{
	return harr[0];
}

template<class T>
inline T* Heap<T>::extracMax()
{
	if (heap_size <= 0) {
		return  NULL;      
	}if (heap_size == 1) {
		heap_size--;
		return harr[0];
	}
	T* root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MaxHeapify(0);

	return root;
}

template<class T>
inline void Heap<T>::decreaseKey(int i,T* new_val)
{
	harr[i] = new_val;
	while (i != 0 && *harr[parent(i)] < *harr[i]) {

		T* child = harr[i];
		T* pp = harr[parent(i)];

		swap(harr[i], harr[parent(i)]);
		harr[i] = pp;
		harr[parent(i)] = child;

		i = parent(i);
	}
}

template<class T>
inline void Heap<T>::deleteKey(int i)
{
	T* c = new T();
	c->setInfluencia(INT_MAX);
	decreaseKey(i, c);
	extracMax();
}

template<class T>
inline void Heap<T>::insertKey(T* k)
{
	if (heap_size == capacity) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	heap_size++;
	int i = heap_size-1;
	harr[i] = k;

	while (i != 0 && *harr[parent(i)] < *harr[i]) {
	
		T* child = harr[i];
		T* pp = harr[parent(i)];

		swap(harr[i], harr[parent(i)]);

		harr[i] = pp;
		harr[parent(i)] = child;


		i = parent(i);
	}
}

template<class T>
inline bool Heap<T>::isEmpty()
{
	return heap_size==0;
}

template<class T>
inline void swap(T* x, T* y){

	T *temp = x;
	x = y;
	y = temp;
}
