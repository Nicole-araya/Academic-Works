#pragma once
template<class T>
class NodoAVL{
private:
	long long key;
	T* info;
	NodoAVL<T>* left;
	NodoAVL<T>* right;
public:
	NodoAVL();

	T* getInfo();
	void setInfo(T* info);

	long long getKey();
	void setKey(long long key);
	NodoAVL<T>* getRight();
	NodoAVL<T>* getLeft();

	void setR(NodoAVL<T>* R);
	void setL(NodoAVL<T>* L);
};

template<class T>
inline NodoAVL<T>::NodoAVL(){
	left = nullptr;
	right = nullptr;
	info = nullptr;
	key = 0;
}

template<class T>
inline T* NodoAVL<T>::getInfo(){

	return info;
}

template<class T>
inline void NodoAVL<T>::setInfo(T* info){
	this->info = info;
}

template<class T>
inline long long NodoAVL<T>::getKey(){ 
	return key; 
}

template<class T>
inline void NodoAVL<T>::setKey(long long key){ this->key = key; }

template<class T>
inline NodoAVL<T>* NodoAVL<T>::getRight(){
	return right;
}

template<class T>
inline NodoAVL<T>* NodoAVL<T>::getLeft(){
	return left;
}

template<class T>
inline void NodoAVL<T>::setR(NodoAVL<T>* R){
	this->right = R;
}

template<class T>
inline void NodoAVL<T>::setL(NodoAVL<T>* L){
	this->left = L;
}
