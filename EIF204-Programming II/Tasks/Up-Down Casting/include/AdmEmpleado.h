#ifndef ADMEMPLEADO_H
#define ADMEMPLEADO_H
#include "Empleado.h"
#include "Vendedor.h"
#include"Gerente.h"
#include"Cajero.h"

class AdmEmpleado
{
    public:
        AdmEmpleado();
        virtual ~AdmEmpleado();
        void mostrarInfo(Empleado* );
        void mostrarInfoDC(Empleado*);


};

#endif // ADMEMPLEADO_H
