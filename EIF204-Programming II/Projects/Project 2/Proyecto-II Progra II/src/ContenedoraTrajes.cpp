#include "ContenedoraTrajes.h"

ContenedoraTrajes::~ContenedoraTrajes()
{
    list<TrajeAbstracto*>::iterator it;
    for (it = traje.begin(); it != traje.end(); it++) {
            traje.erase(it);
    }
}

bool ContenedoraTrajes::ingresaTraje(TrajeAbstracto* t)
{
    if(t) {
        traje.push_back(t); 

        return true;
    }

    return false;
}

bool ContenedoraTrajes::eliminaTraje(TrajeAbstracto* t){
    list<TrajeAbstracto*>::iterator it;
    for(it = traje.begin(); it != traje.end(); it++) {

        if(*it == t) {
            traje.erase(it);
            return true;
        }
    }
    return false;
}

TrajeAbstracto* ContenedoraTrajes::buscarTraje(TrajeAbstracto* t){
    list<TrajeAbstracto*>::iterator it;
    for (it = traje.begin(); it != traje.end(); it++) {

        if (*it == t) {
            return *it;
        }
    }
    return NULL;
}

TrajeAbstracto* ContenedoraTrajes::buscaPorCod(string codigo){
    list<TrajeAbstracto*>::iterator it;
    for(it = traje.begin(); it != traje.end(); it++) {
        
        if((*it)->getCodigo()==codigo){
            return *it;
        }
    }
    return NULL;
}

string ContenedoraTrajes::toString(){
    stringstream ss;

    list<TrajeAbstracto*>::iterator it;
    ss << "--->> Trajes Disponibles <<----" << endl;
    ss << "===============================" << endl << endl;
    for(it = traje.begin(); it != traje.end(); it++) {

        ss << ">>>>" << (*it)->toString() << endl << endl;
        

    }
    return ss.str();
}

void ContenedoraTrajes::guardarDatos(string nombre)
{
    ofstream salida(nombre);

    list<TrajeAbstracto*>::iterator it;
    for (it = traje.begin(); it != traje.end(); it++) {

        GuardarDatos::guardarTraje(salida, *it);
    }
    salida.close();
}
