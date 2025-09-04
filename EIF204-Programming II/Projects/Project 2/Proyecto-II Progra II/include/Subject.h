#pragma once
#include <list>
#include "Cliente.h"
#include "GuardarDatos.h"
class Subject
{
protected:
	list <Observa*> subscriptor;

public:

	Subject();
	~Subject();
	void agregarSubscriptor(Observa* sub);
	string tipoCliente(bool);
	Observa* buscarSubscriptor(Observa* sub);
	Observa* buscaPorID(string ID);
	void guardarSubscriptores(string nom);
};

