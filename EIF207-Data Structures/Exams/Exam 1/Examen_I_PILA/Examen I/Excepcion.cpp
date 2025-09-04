#include "Excepcion.h"

string Excepcion::torreVacia()
{
    return "Opcion Invalida, la torre esta vacia...\n";
}

string Excepcion::contraIncorrecta()
{
    return "Contrasenia Incorrecta!\n";
}

string Excepcion::opcionIncorrecta()
{
    return "No existe la opcion\n";
}

string Excepcion::movimientoInvalido()
{
    return "Movimiento Invalido!\n";
}
