#include "ListaSimple.h"

// Constructor de copia
ListaSimple::ListaSimple(const ListaSimple& obj) {
	if (obj.inicio == nullptr)
		inicio = nullptr;
	else {
		inicio = new Nodo(obj.inicio->valor);
		iterador tmp = inicio;
		iterador tmp_obj = obj.inicio->next;
		while (tmp_obj != nullptr) {
			tmp->next = new Nodo(tmp_obj->valor);
			tmp = tmp->next;
			tmp_obj = tmp_obj->next;
		}
	}
}

// Inserta un nuevo elemento en la lista enlazada
// Inserción al final de la lista
// Se hace el paso de parámetro por referencia (actual) por si es necesario modificar
// la dirección de memoria de inicio
void ListaSimple::Insertar(int val) {
	Nodo* nuevo;

	nuevo = new Nodo(val);

	if (inicio == nullptr)
		inicio = nuevo;
	else {
		Nodo* tmp = inicio;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
	}
}

// Elimina el nodo especificado de la lista enlazada - (el apuntador)
// Se hace el paso de parámetro por referencia (actual) por si es necesario modificar
// la dirección de memoria de inicio
void ListaSimple::Eliminar(int val) {
	// No hay nada que borrar si la lista enlazada está vacía
	// o el puntero es NULL
	if (inicio == nullptr)
		return;

	// Caso #1: El elemento a borrar es el primero de la lista enlazada
	if (inicio->valor == val) {
		Nodo* tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
	// Caso #2: El elemento se encuentra en alguna otra posición de la lista
	else {
		Nodo* tmp = inicio;
		Nodo* tmp2 = tmp->next;
		while (tmp2 != nullptr) {
			if (tmp2->valor == val) {
				tmp->next = tmp2->next;
				delete tmp2;
				return;
			}
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
}

// Elimina un nodo de la lista en la posición especificada
// Requiere que se pase por parámetro el inicio de la lista
void ListaSimple::EliminarEnPos(size_t pos) {
	if (pos <= 0 || inicio == nullptr)
		return;

	Nodo* tmp = inicio;
	Nodo* tmp2 = nullptr;

	// Si es la primera posición
	if (pos == 1) {
		Nodo* tmp = inicio;
		inicio = inicio->next;
		delete tmp;
		return;
	}

	// Para cualquier otro caso
	for (size_t i = 1; i < pos; ++i) {
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp == nullptr)
			return;
	}

	if (tmp2 != nullptr) {
		tmp2->next = tmp->next;
		delete tmp;
		tmp = nullptr;
	}
}

// Borra completamente la lista
void ListaSimple::BorrarLista() {
	Nodo* tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
}