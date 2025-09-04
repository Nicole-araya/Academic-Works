#pragma once
#include "Observa.h"
class Cliente :
    public Observa
{
protected:
    string cedula;
    string nombre;
    string correo;
    double pagoSubscripcion;
    string ciudad;
    string pais;

public:

    Cliente(string cedula, string nom, string correo, double pago, string ciudad, string pais);
    ~Cliente();

    string getCiudad();
    string getPais();
    string getNombre();
    string getCedula();
    string getCorreo();
    double getPagoSubs();
    virtual void actualizar(bool)=0;
    virtual string toString() = 0;
};

