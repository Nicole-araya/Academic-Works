#include "Excepcion.h"

string Excepcion::notFound()
{
    return "No se encuentra la informacion para realizar la opcion!!\n";
}

string Excepcion::found()
{
    return "Ya se existe el cliente!\n";
}

string Excepcion::notLoad()
{
    return "No se pudo cargar la informacion\n";
}

string Excepcion::wrongOption()
{
    return "Opcion invalida!\n";
}
