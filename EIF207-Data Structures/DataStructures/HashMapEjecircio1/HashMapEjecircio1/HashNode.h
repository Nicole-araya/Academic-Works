#pragma once
#include <sstream>
using namespace std;

const int SIZE = 101;  //siempre es un valor primo porque tiene menos coliciones

template <typename K, typename V>
class HashNode {

private:

	K key;
	V value;
	HashNode* next; //siguiente en el value con la misma llave

public:
	HashNode(const K& key, const V& value);
	K getKey()const;
	V getValue()const;
	void setValue(V v);
	HashNode* getNext()const;
	void setNext(HashNode* next);


};

template<typename K, typename V>
inline HashNode<K, V>::HashNode(const K& key, const V& value) :key(key), value(value), next(nullptr) {}

template<typename K, typename V>
inline K HashNode<K, V>::getKey()const
{
	return key;
}

template<typename K, typename V>
inline V HashNode<K, V>::getValue()const
{
	return value;
}

template<typename K, typename V>
inline void HashNode<K, V>::setValue(V v)
{
	value = v;
}

template<typename K, typename V>
inline HashNode<K, V>* HashNode<K, V>::getNext()const
{
	return next;
}

template<typename K, typename V>
inline void HashNode<K, V>::setNext(HashNode* next)
{
	this->next = next;
}