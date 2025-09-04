#include "Controlador.h"

Controlador::Controlador(){
	
    movimientos = 0;
    disco = canDISCO;
	minMovimienos = 0;
}

void Controlador::insertarTorre1()
{
    for (int h = 0; h <= disco-1; h++) {
        torre1.enqueue(new float(pow((h + 9),(h + 1) ) * (h + 4)));
    }
}


void Controlador::imprimirSolucion(int disco, int t1, int t2, int t3, bool flag){

	//Por se cola y entrar por debajo, y la comparacion ser si es mayor que el que se tiene, por lo que no tiene complejidad en su recursividad

	if(disco == 1){
		if(flag){ cout << "Disco de la torre " << t1 << " a torre " << t3 << endl; }
        
		minMovimienos++;

	}else{
		imprimirSolucion(disco - 1, t1, t2, t3,flag);
		if (flag) { cout << "Disco de la torre " << t1 << " a torre " << t3 << endl; }
		minMovimienos++;
		
    }
	
}

bool Controlador::comparaTop(Cola<float>& n1, Cola<float>& n2)
{
	if (n2.empty()) return false;
	return *n1.front() < *n2.front();  //n1 es el que entra, Comparo alrevez del metodo de la pila, por lo que entra si el numero es mayor al que se tiene por ser cola

}



void Controlador::menuJuego() {
	int opcion = 0; float* x, * y = NULL;  bool compara = false;
	insertarTorre1(); 
	while (opcion != 7) {

		if (torre1.empty() && torre2.empty()) {       //PARA GANAR Y TERMINAR EL JUEGO
			cout << "WIN! WIN! WIN!" << endl;
			system("pause");
			system("cls");
			opcion = 7;
		}

		cout << torre1.imprimir()<<"1\n" << endl << torre2.imprimir() << "2\n" << endl << torre3.imprimir() << "3\n" << endl;
		cout << "Cantidad de movimientos realizados " <<movimientos<< endl;

		cout << " -----------------------------------" << endl;
		cout << " 1. De la torre 1 a la torre 2 " << endl;
		cout << " 2. De la torre 1 a la torre 3 " << endl;
		cout << " 3. De la torre 2 a la torre 1 " << endl;
		cout << " 4. De la torre 2 a la torre 3 " << endl;
		cout << " 5. De la torre 3 a la torre 1 " << endl;
		cout << " 6. De la torre 3 a la torre 2 " << endl;
		cout << " 7. Reiniciar el Juego" << endl;
		cout << "--------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: ";
		cin >> opcion;

		system("pause");
		system("cls");

		try {
			switch (opcion) {

			case 1:

				if (torre1.empty()) throw y;
				if (comparaTop(torre1, torre2)) throw compara;  //NO entra si el numero no es mayor al que se tiene por ser cola

				x = torre1.front();
				torre2.enqueue(new float(*x));   //ingresa por debajo
				torre1.dequeue();
				movimientos++;

				break;

			case 2:

				if (torre1.empty()) throw y;
				if (comparaTop(torre1, torre3)) throw compara;
				x = torre1.front();
				torre3.enqueue(new float(*x));
				torre1.dequeue();
				movimientos++;

				break;

			case 3:
				if (torre2.empty()) throw y;
				if (comparaTop(torre2, torre1)) throw compara;
				x = torre2.front();
				torre1.enqueue(new float(*x));
				torre2.dequeue();
				movimientos++;

				break;

			case 4:

				if (torre2.empty()) throw y;
				if (comparaTop(torre2, torre3)) throw compara;
				x = torre2.front();
				torre3.enqueue(new float(*x));
				torre2.dequeue();
				movimientos++;

				break;
			case 5:
				if (torre3.empty()) throw y;
				if (comparaTop(torre3, torre1)) throw compara;
				x = torre3.front();
				torre1.enqueue(new float(*x));
				torre3.dequeue();
				movimientos++;

				break;
			case 6:
				if (torre3.empty()) throw y;
				if (comparaTop(torre3, torre2)) throw compara;
				x = torre3.front();
				torre2.enqueue(new float(*x));
				torre3.dequeue();
				movimientos++;

				break;

			case 7:
				torre1.makeEmpty();
				torre2.makeEmpty();
				torre3.makeEmpty();
				system("cls");

				break;
			default:

				cin.clear();
				throw opcion;
				system("pause");
				system("cls");

			}
		}
		catch (float* x) {
			if (x == NULL) {
				cout << Excepcion::torreVacia();
				system("pause");
				system("cls");
			}
			
		}
		catch (bool y) {
			if (y == false) {
				cout << Excepcion::movimientoInvalido();
				system("pause");
				system("cls");
			}
		}
		catch (int num) {
			cin.ignore();
			cout << Excepcion::opcionIncorrecta();
			system("pause");
			system("cls");
		}

	}
}

void Controlador::menuPrincipal()
{
	int opcion = 0; string contra;
	while (opcion != 4) {

		cout << " ------MENU PRINCIPAL---------" << endl;
		cout << " 1. Ingresar al Juego " << endl;
		cout << " 2. Mostrar el minimo numero de movimientos para ganar" << endl;
		cout << " 3. Mostrar el algoritmo completo paso a paso de la solucion " << endl;
		cout << " 4. Salir " << endl;
		cout << "-------------------------------" << endl;
		cout << " Ingrese la opcion a realizar: ";
		cin >> opcion;

		system("pause");
		system("cls");
		try {
			switch (opcion) {

			case 1:
				menuJuego();
				break;

			case 2:
				imprimirSolucion(disco, 1, 2, 3,0);
				cout << "Minimo de movientos ..."<< minMovimienos << endl;
				minMovimienos = 0;
				system("pause");
				system("cls");
				break;

			case 3:
				cout << "-- Mostrar el algoritmo completo paso a paso de la solución --" << endl;
				cout << " Ingrese la contrasenia : "; cin >> contra;

				if (contra != "123") throw contra;

				imprimirSolucion(disco, 1, 2, 3);
				minMovimienos = 0;
				system("pause");
				system("cls");

				break;

			case 4:

				cout << "Saliendo..." << endl;
				system("pause");
				break;

			default:

				cin.clear();
				throw opcion;
				system("pause");
				system("cls");

			}
		}
		catch (string x) {
			cout << Excepcion::contraIncorrecta();
			system("pause");
			system("cls");
		}
		catch (int num) {
			cin.ignore();
			cout << Excepcion::opcionIncorrecta();
			system("pause");
			system("cls");
		}
	}
}
