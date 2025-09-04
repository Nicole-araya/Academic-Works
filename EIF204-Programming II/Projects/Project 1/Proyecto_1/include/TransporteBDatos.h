#pragma once
#include "RestriccionTransporte.h"
#include <fstream>

class TransporteBDatos
{
public:

	static void guardar(ofstream&, RestriccionTransporte*);


};

