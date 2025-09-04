#pragma once
#include<sstream>
using namespace std;

template<typename K,typename V>
class HashNode {

private:

	V value;
	K key;

public:
	HashNode(K key,V value);
	V getValue();
	K getKey();
	void setValue(V value);
	void setKey(K key);


};

template<typename K, typename V>
inline HashNode<K, V>::HashNode(K key, V value):key(key),value(value)
{
}

template<typename K, typename V>
inline V HashNode<K, V>::getValue()
{
	return value;
}

template<typename K, typename V>
inline K HashNode<K, V>::getKey()
{
	return key;
}

template<typename K, typename V>
inline void HashNode<K, V>::setValue(V value)
{
	this->value = value;
}

template<typename K, typename V>
inline void HashNode<K, V>::setKey(K key)
{
	this->key = key;
}
