#include "ArchivosAerolinea.h"

bool ArchivosAerolinea::verificarUsuarioAdmi(string x, string y)  //VERIFICAR SI INGRESO BIEN LOS DATOS PARA ENTRAR EN ADMINISTRADOR
{
	ifstream f_admi("Administrador.txt");
	string usuario, contra;
	
	while (f_admi.good()) {
		getline(f_admi, usuario, '\t');
		getline(f_admi, contra, '\n');

		if (!usuario.empty() && !contra.empty())
		{
			if (usuario == x && contra == y) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	f_admi.close();
}



void ArchivosAerolinea::cargarDatos(ListaAvion* la, ListaRuta* lr, ListaPiloto* lp, ListaSobrecargo* ls)
{
	string cod, categ, tam, origen, destino, duracion, cant, precio, nom, id, edad, correo, sexo, titulo, telf, grado;

	ifstream entradaA("ListaAvion.txt");
	
	if (!entradaA) {

		cout << "ERROR... (no se puede abrir el archivo Avion)" << endl;
		entradaA.close();
		return;
	}

	while (!entradaA.eof()) {
	
		getline(entradaA, cod, '\t');
		getline(entradaA, categ, '\t');
		getline(entradaA, tam, '*');

		if (!cod.empty() && !categ.empty() && !tam.empty())
		{
			int num = stoi(tam);
			la->insertar(new Avion(cod, categ, num));
		}

	} 
	entradaA.close();

	//-----------------------------------------------------------------------

	ifstream entradaR("ListaRuta.txt");
	

	if (!entradaR) {

		cout << "ERROR... (no se puede abrir el archivo Ruta)" << endl;
		entradaR.close();
		return;
	}

	while (!entradaR.eof()) {

		

		getline(entradaR, cod, '\t');
		getline(entradaR, origen, '\t');
		getline(entradaR, destino, '\t');
		getline(entradaR, duracion, '\t');
		getline(entradaR, cant, '\t');
		getline(entradaR, precio, '*');

		if (!cod.empty() && !origen.empty() && !destino.empty() && !duracion.empty() && !cant.empty() && !precio.empty())
		{
			int num = stoi(cant);
			double num2 = stoi(precio);

			lr->insertar(new Ruta(cod, origen, destino, duracion, num, num2));
		}
	}
	entradaR.close();

	//-----------------------------------------------------------------------

	ifstream entradaP("ListaPiloto.txt");
	

	if (!entradaP) {

		cout << "ERROR... (no se puede abrir el archivo Piloto)" << endl;
		entradaP.close();
		return;
	}

	while (!entradaP.eof()) {

		

		getline(entradaP, nom, '\t');
		getline(entradaP, id, '\t');
		getline(entradaP, edad, '\t');
		getline(entradaP, correo,'\t');
		getline(entradaP, sexo, '*');

		if (!nom.empty() && !id.empty() && !edad.empty() && !correo.empty() && !sexo.empty())
		{
			int num = stoi(edad);
			char letra = sexo[0];
			
			lp->insertar(new Piloto(nom, id, num, correo, letra));
		}
	}
	entradaP.close();

	//-----------------------------------------------------------------------

	ifstream entradaS("ListaSobrecargo.txt");
	
	if (!entradaS) {

		cout << "ERROR... (no se puede abrir el archivo Sobrecargo)" << endl;
		entradaS.close();
		return;
	}

	while (!entradaS.eof()) {

		getline(entradaS, nom, '\t');
		getline(entradaS, id, '\t');
		getline(entradaS, edad, '\t');
		getline(entradaS, titulo, '\t');
		getline(entradaS, telf, '\t');
		getline(entradaS, grado, '*');

		if (!nom.empty() && !id.empty() && !edad.empty() && !titulo.empty() && !telf.empty() && !grado.empty())
		{
			int num = stoi(edad);
			int num2 = stoi(grado);

			ls->insertar(new Sobrecargo(nom, id, num, titulo, telf, num2));
		}
		
	}
	entradaS.close();

}
