#pragma once
#include "HashNode.h"

template <typename K,typename V>
class HashMap {
	HashNode<K, V>** arr;
	int capacity;
	int size;
public:
	HashMap();
	int hashCode(K key);
	void insertNode(K key, V value);
	V deleteNode(int key);
	V get(int key);
	int sizeofMap();
	bool isEmpty();
	string display();
};

template<typename K, typename V>
inline HashMap<K, V>::HashMap()
{
	capacity = 20;
	size = 0;
	arr = new HashNode<K, V>*[capacity];
	for (int i = 0;i < capacity; i++)
	{
		arr[i] = nullptr;
	}
}

template<typename K, typename V>
inline int HashMap<K, V>::hashCode(K key)
{
	return (key%capacity);
}

template<typename K, typename V>
inline void HashMap<K, V>::insertNode(K key, V value)
{
	HashNode<K, V>* temp = new HashNode<K, V>(key, value);
	int hashIndex = hashCode(key);
	while (arr[hashIndex]!=nullptr&&arr[hashIndex]->getKey() !=key
		&& arr[hashIndex]->getKey() != -1)
	{
		hashIndex++;
		hashIndex %= capacity;
	}
	if (arr[hashIndex] == nullptr || arr[hashIndex]->getKey() != -1)
		size++;

	arr[hashIndex] = temp;
}

template<typename K, typename V>
inline V HashMap<K, V>::deleteNode(int key)
{
	int hashIndex = hashCode(key);
	while (arr[hashIndex] != nullptr) {
		if (arr[hashIndex]->getKey() == key) {
			HashNode<K, V>* temp = arr[hashIndex];
			arr[hashIndex] = new HashNode<K, V>(-1, -1);
			size--;
			return temp->getValue();
		}
		hashIndex++;
		hashIndex %= capacity;
		}
	return NULL;
}

template<typename K, typename V>
inline V HashMap<K, V>::get(int key)
{
	int hashIndex = hashCode(key);
	
	while (arr[hashIndex] != nullptr) {
		int counter = 0;
		if (counter++ > capacity)
			return NULL;
		if (arr[hashIndex]->getKey() == key)
			return arr[hashIndex]->getValue();
		hashIndex++;
		hashIndex %= capacity;
	}
	return NULL;
}

template<typename K, typename V>
inline int HashMap<K, V>::sizeofMap()
{
	return size;
}

template<typename K, typename V>
inline bool HashMap<K, V>::isEmpty()
{
	return size==0;
}

template<typename K, typename V>
inline string HashMap<K, V>::display()
{
	stringstream s;
	for (int i = 0; i < capacity; i++) {
		if (arr[i] != nullptr && arr[i]->getKey() != -1)
			s << "Key= " << arr[i]->getKey()
			<< " Value= " << arr[i]->getValue() << endl;
	}
	return s.str();
}
