#include "Excepcion.h"

string Excepcion::notFound()
{
    return "\nNo existe lo ingresado\n";
}

string Excepcion::found()
{
    return "\n¡Ya existe!\n";
}

string Excepcion::notDeleted()
{
    return "\nNo se pudo eliminar\n";
}

string Excepcion::wrongOption()
{
    return "\nOpcion invalida!\n";
}