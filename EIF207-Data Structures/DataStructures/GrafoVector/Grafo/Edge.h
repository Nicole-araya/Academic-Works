#pragma once
#include <iostream>
using namespace std;

template<class T>
class Edge{
private:
	T* firstVertex;
	T* secondVertex;

public:
	Edge(T* FV=nullptr, T* SV= nullptr);
	Edge(T FV, T SV);
	T* getFirst();
	T* getSecond();
	bool operator==(Edge<T> ed);

};

template<class T>
inline Edge<T>::Edge(T* FV, T* SV){
	firstVertex = FV;
	secondVertex = SV;
}

template<class T>
inline Edge<T>::Edge(T FV, T SV){
	firstVertex = new T(FV);
	secondVertex = new T(SV);
}

template<class T>
T* Edge<T>::getFirst()
{
	return firstVertex;
}

template<class T>
T* Edge<T>::getSecond()
{
	return secondVertex;
}

template<class T>
inline bool Edge<T>::operator==(Edge<T> ed){
	
	return this->firstVertex == ed.firstVertex && this->secondVertex == ed.secondVertex;
}
