#pragma once
#include "Subject.h"
#include "ContenedoraTrajes.h"
#include "ContenedoraVentas.h"
#include "ContenedoraTrajesPersonalizados.h"
#include "TrajeDeportivo.h"
#include "TrajeEjecutivo.h"
#include "TrajeTrabajo.h"
#include<fstream>
class CargaArchivos
{
public:
	static void cargarTrajes(string nom,ContenedoraTrajes* traje, ContenedoraTrajesPersonalizados* trajePer);
	static void cargarSubcriptores(string nom, Subject* subs);
	static void cargarVentas(string nom, ContenedoraVentas* venta, Subject* subs, ContenedoraTrajes* traje, ContenedoraTrajesPersonalizados* trajePer);
	void static crearArchivos(string, string, string);
};

