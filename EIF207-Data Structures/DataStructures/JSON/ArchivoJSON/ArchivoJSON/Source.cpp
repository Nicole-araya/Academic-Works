#include "Persona.h"
#include <fstream>
#include <json/json.h>

int main() {


	Persona* p1 = new Persona(111, "Nicole", "Santa");
	Persona* p2 = new Persona(222, "Yuki-chan", "San Rafael");
	Persona* p3 = new Persona(333, "Sofi", "Mercedes");

	Json::StreamWriterBuilder builder;

	builder["commentStyle"] = "None";
	builder["indentation"] = "	";
	unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());  //creo un puntero para escribir

	ofstream salida ("Prueba.txt");  //guardar

	Json::Value event;
	Json::Value arreglo(Json::arrayValue);


	string valor = "Nombre"; // para ver que hay 2 maneras de ingresar etiquetas

	event["Id"] = p1->getID();
	event[valor] = p1->getNombre();
	event["Direccion"] = p1->getDireccion();

	arreglo.append(event);

	event["Id"] = p2->getID();
	event[valor] = p2->getNombre();
	event["Direccion"] = p2->getDireccion();

	arreglo.append(event);

	event["Id"] = p3->getID();
	event[valor] = p3->getNombre();
	event["Direccion"] = p3->getDireccion();

	arreglo.append(event);


	writer->write(arreglo, &salida);
	salida.close();



	ifstream entrada("Prueba.txt"); //lectura

	Persona temporal;

	Json::Value objeto;
	Json::Reader reader;

	reader.parse(entrada, objeto);

	for (int i = 0; i < objeto.size(); i++) {
		temporal.setID(objeto[i]["Id"].asInt());
		temporal.setNombre(objeto[i]["Nombre"].asString());
		temporal.setDireccion(objeto[i]["Direccion"].asString());
		cout << temporal.toString() << endl;
	}

	delete p1, p2, p3;
	return 0;
}