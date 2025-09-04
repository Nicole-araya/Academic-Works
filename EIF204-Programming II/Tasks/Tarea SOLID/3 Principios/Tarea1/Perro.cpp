
#include "Perro.h"

/*principio de responsabilidad unica
cada metodo tiene una sola funcion*

*de funcionalidad, no de programacion
*/
Perro::Perro(string nombre){
    this->nombre=nombre;
}

string Perro::caracteristica(){
    return "tiene 4 patas porque es un perro";
}

void Perro::setNombre(string nombre2){
    this->nombre=nombre2;
}

string Perro::ladrar(){
    return "guau guau";
}

string Perro::correr() {
    return "tuki tuki tuki *corre*";
}

/*===============================Otras Clases=====================================*/

string chihuahua::caracteristica(){
    return "Ta chikito";
}

string husky::caracteristica(){
    return "Ta grandote";
}

string shibaInu::caracteristica(){
    return "creo que es japones, seguro habla coreano";
}

string perroEx::carracteristica(){
    return "Es extraterreste asi que come cabras";
}

string perroEx::comerse3Cabras(){
    return "*Se come tres cabras*";
}
