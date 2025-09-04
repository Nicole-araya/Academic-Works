#pragma once
#include "Subject.h"
#include "ContenedoraTrajes.h"
class CatalogoEnLinea :
    public Subject{
private:
    ContenedoraTrajes* trajes;

public:
    CatalogoEnLinea(ContenedoraTrajes*);
    ~CatalogoEnLinea();
    void notificar(bool);

    string toString();
};

