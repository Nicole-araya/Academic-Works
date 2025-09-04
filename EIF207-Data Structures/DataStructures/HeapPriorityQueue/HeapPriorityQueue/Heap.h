#pragma once
#include <iostream>
using namespace std;
template <class T>
class Heap
{
private:
	T* harr; //puntero al arreglo de elementos en el heap
	int capacity; //tamanio maximo posible del heap
	int heap_size; //tamanio actual del heap

public:
	Heap(int cap);
	~Heap();
	void MinHeapify(int i);
	int parent(int i);
	int left(int i);
	int righ(int i);
	T getMin();
	T extracMin();
	void decreaseKey(int i,T new_val);
	void deleteKey(int i);
	void insertKey(T k);
};

template <class T>
void swap(T* x, T* y);

template<class T>
inline Heap<T>::Heap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new T[cap];
}

template<class T>
inline Heap<T>::~Heap()
{
}

template<class T>
inline void Heap<T>::MinHeapify(int i)
{
	int l = left(i);
	int r = righ(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
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
inline T Heap<T>::getMin()
{
	return harr[0];
}

template<class T>
inline T Heap<T>::extracMin()
{
	if (heap_size <= 0) {
		return INT_MAX;
	}if (heap_size == 1) {
		heap_size--;
		return harr[0];
	}
	T root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}

template<class T>
inline void Heap<T>::decreaseKey(int i,T new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

template<class T>
inline void Heap<T>::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extracMin();
}

template<class T>
inline void Heap<T>::insertKey(T k)
{
	if (heap_size == capacity) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

template<class T>
inline void swap(T* x, T* y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}
