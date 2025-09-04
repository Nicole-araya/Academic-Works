#include "CatalogoEnLinea.h"

CatalogoEnLinea::CatalogoEnLinea(ContenedoraTrajes* ct)
{
    trajes = ct;
}

CatalogoEnLinea::~CatalogoEnLinea()
{
    
}

void CatalogoEnLinea::notificar(bool mensaje)
{
    for (Observa* ob : subscriptor) {
        ob->actualizar(mensaje);       // si mensaje es true se ingreso un traje, si es false se elimino un traje
    }
}


string CatalogoEnLinea::toString(){
    stringstream ss;

    list<TrajeAbstracto*>::iterator it;
    ss << "     CATALOGO EN LINEA   " << endl;
    ss << "----------------------------" << endl;
    ss << trajes->toString()<<endl;
    return ss.str();
}
