#include "OrdenamientoSeleccion.h"

void OrdenamientoSeleccion::selectionSort(int vec[],int n)
{
	int minIDX,j,i;
	//se mueve de 1 en 1 el arreglo
	for ( i = 0; i < n - 1; i++) {
		//valor minimo en el vec sin orden
		minIDX = i;
		for ( j = i + 1; j < n; j++) {
			if (vec[j] < vec[minIDX]){  
				minIDX = j;
			//Permutacion de los elementos
				int tmp = vec[i];
				vec[i] = vec[minIDX];
				vec[minIDX] = tmp;
			}
			
		}
	}

}
