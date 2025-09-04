#pragma once

template <class G>
class Vertice{
private:
	int key;
	G info;
public:
	Vertice(int key=0);
	Vertice(G info, int key);
	int getKey();
	G getInfo();
};

template<class G>
inline Vertice<G>::Vertice(int key){
	this->key = key;
	info = key;
}

template<class G>
inline Vertice<G>::Vertice(G info, int key){
	this->info = info;
	this->key = key;
}

template<class G>
inline int Vertice<G>::getKey(){
	return key;
}

template<class G>
inline G Vertice<G>::getInfo(){
	return info;
}
