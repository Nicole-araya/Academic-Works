#include<iostream>
#include "Perro.h"

using namespace std;

int main(){
    husky yuki("yuki");
    chihuahua garbanzo("garbazo");
    perroEx luiso("Luiso");

    cout << yuki.caracteristica() << endl;
    cout << garbanzo.ladrar() << endl;
    cout << luiso.comerse3Cabras()<<endl;

    system("pause");
    return 0;
}

