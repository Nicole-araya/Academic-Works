#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
    list<Observa*>::iterator it;
    for (it = subscriptor.begin(); it != subscriptor.end(); it++) {

        subscriptor.erase(it);
    }
}

void Subject::agregarSubscriptor(Observa* ob){
	subscriptor.push_back(ob);
}

string Subject::tipoCliente(bool tipo) {

    Persona* p = NULL;
    Empresa* e=NULL;

    stringstream ss;
    list<Observa*>::iterator it;
    for(it = subscriptor.begin(); it != subscriptor.end(); it++) {

        if ((p = dynamic_cast<Persona*>(*it)) && tipo==true) {
           ss<< p->toString()<<endl;
        }
        if ((e = dynamic_cast<Empresa*>(*it)) && tipo==false) {
           ss<< e->toString()<<endl;
       }

    }
    return ss.str();
}

Observa* Subject::buscarSubscriptor(Observa* sub){
    list<Observa*>::iterator it;
    for (it = subscriptor.begin();it != subscriptor.end();it++) {

        if (*it == sub) {
            return *it;
        }
    }
    return NULL;
}

Observa* Subject::buscaPorID(string ID){
    list<Observa*>::iterator it;
    for(it = subscriptor.begin(); it != subscriptor.end(); it++) {

        Cliente* c = dynamic_cast<Cliente*>(*it);   //dymanic_cast para acceder a metodos de subscriptor
        if(c->getCedula() == ID){
            return c;
        }
    }
    return NULL;
}

void Subject::guardarSubscriptores(string nom)
{
    ofstream salida(nom);
    list<Observa*>::iterator it;
    for (it = subscriptor.begin(); it != subscriptor.end(); it++) {

        Cliente* c = dynamic_cast<Cliente*>(*it);
        GuardarDatos::guardarSubscriptor(salida, c);
    }
    salida.close();
}
