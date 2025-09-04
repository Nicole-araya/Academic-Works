#include "Inserccion.h"

void Inserccion::inserccionSortAsc(int A[], int n)
{
	for (int i = 0; i < n; i++) {
		int cur = A[i]; //valor actual a insertar
		int j = i - 1; //se inicia con el valor anterior
		while ((j >= 0) && (A[j] > cur)) {
			A[j + 1] = A[j]; // mueve A[j] a la derecha
			j--;
		} A[j + 1] = cur; //lugra correcto de cur
	}
}
