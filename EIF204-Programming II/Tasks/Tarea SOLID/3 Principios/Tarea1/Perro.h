#pragma once
#include<iostream>

using namespace std;

class Perro{
private:

    string nombre;

public:    
    Perro(string="-");

    string caracteristica();
    
    void setNombre(string);
    
    string ladrar();
    string correr();
};
/*========================================================================*/

/*
Principio abierto/cerrado
se pueden crear nuevos metodos u objetos
sin necesidad de editar los ya existentes
*/

class chihuahua: public Perro{
public:
    chihuahua(string n):Perro(n){};
    string caracteristica();

};

class husky: public Perro{
public:
    husky(string n):Perro(n){};
    string caracteristica();

};
class shibaInu: public Perro{
public:
    shibaInu(string n):Perro(n){};
    string caracteristica();
};


class perroEx:public Perro{
public:
    perroEx(string n):Perro(n){};
    string carracteristica();

    //principio de inversion de dependencia
    //La clase Perro(padre) no depende de perroEx(hija)
    string comerse3Cabras();
};