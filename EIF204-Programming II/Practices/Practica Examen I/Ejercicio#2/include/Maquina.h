#ifndef MAQUINA_H
#define MAQUINA_H
#include "Recipiente.h"
#include "Producto.h"

class Maquina
{
    public:
        Maquina(int);
        virtual ~Maquina();
        void ingresarProd(Producto*);
        void menu();
        string imprimirProd();
        bool azucar(char);

    private:
        Recipiente** rec;
        Producto** pro;
        int tamR;
        int tamP;
        int canR;
        int canP;


};

#endif // MAQUINA_H
