
#include"Habitacion.h"
using namespace std;

class ContenedorM {
  private:
	Habitacion* mat[4][6];      
	int filas;
	int colum;

  public:

	ContenedorM();
	virtual ~ContenedorM();
	void imprimeContenedor();
	bool establecerEstadoDeHabitacion(int,int,char);
	Habitacion* obtenerHabitacion(int, int);
	double calculoAPagarPorHabitacion(int, int);
	double obtenerRecaudoDiarioTotal();
};
