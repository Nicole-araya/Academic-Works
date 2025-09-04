#include"CategTrabajador.h"

string CategTrabajador::tipoDeTrabajador(string str) {
	if (str == "001") return "Malo";
	if (str == "002") return "Aceptable";
	if (str == "003") return "Muy bueno";
	if (str == "004") return "Excelente";
	return "";
}

double CategTrabajador::bonoBeneficio(string str) {
	if (str == "001") return 0.0;
	if (str == "002") return 0.1;
	if (str == "003") return 0.2;
	if (str == "004") return 0.3;
	return 0;
}