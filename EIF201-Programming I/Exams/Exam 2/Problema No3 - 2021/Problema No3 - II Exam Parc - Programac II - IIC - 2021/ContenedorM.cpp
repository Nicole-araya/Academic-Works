#include"ContenedorM.h"

ContenedorM::ContenedorM(){

	filas = 4;
	colum = 6;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < colum; j++)
		{
			mat[i][j] = new Habitacion();
		}
	}
	
}

ContenedorM::~ContenedorM(){
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < colum; j++)
			delete mat[i][j];
}

void ContenedorM::imprimeContenedor(){


	for (int i = 0; i < filas; i++) {

		cout << endl;
		cout << "Piso: " << i << endl;

		for (int j = 0; j < colum; j++) {

			mat[i][j]->setNumHabitacion(j );

			cout << mat[i][j]->toString() << endl;
			cout << endl;

		}
	}

}


bool ContenedorM::establecerEstadoDeHabitacion(int num, int num2, char est){
	
	Habitacion* h = obtenerHabitacion(num, num2);

	if (h) {


		mat[num][num2]->setEstado(est);
				return true;

	}
	else {
		return false;
	}

	
}

Habitacion* ContenedorM::obtenerHabitacion(int i, int j){
	if (i >= 0 && i < filas && j >= 0 && j < colum) {
		return mat[i][j];
	}
	else
		return NULL;
}

double ContenedorM::calculoAPagarPorHabitacion(int i, int j) {
	
	if (mat[i][j]->getDesc() == false) {

		return ((2 * 20000) + (3 * 15000));
	}
	else {

		return ((2 * 20000) + (0.50 * (3 * 15000)));
	}



}

double ContenedorM::obtenerRecaudoDiarioTotal(){
	
	double total = 0;

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < colum; j++) {


			if (mat[i][j]->getEstado() == 'O' || 'o') {


				total = total + calculoAPagarPorHabitacion(i,j);
			}

		}
	}

	return total;

}