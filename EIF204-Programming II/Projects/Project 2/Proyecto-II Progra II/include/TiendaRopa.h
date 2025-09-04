#pragma once
#include "Excepcion.h"
#include "CargaArchivos.h"
#include "CatalogoEnLinea.h"
#include "GuardarDatos.h"
#define cls system("cls")
#define pause system("pause")
#include <string>
using namespace std;
class TiendaRopa{
private:

    int contador;    //contador para cod de trajes personalizados
    ContenedoraTrajesPersonalizados* trajePersonalizado;
    ContenedoraVentas* ventas;
    ContenedoraTrajes* trajes;
    CatalogoEnLinea* catalogo;

    TrajeAbstracto* crearTraje(bool codigo);
    void menuTiendaLinea(); 
    void menuAdministrador();
    void menuTiendaFisica(); 
 
public:

    TiendaRopa();
    ~TiendaRopa();
    void menuPrincipal();  

  
};

