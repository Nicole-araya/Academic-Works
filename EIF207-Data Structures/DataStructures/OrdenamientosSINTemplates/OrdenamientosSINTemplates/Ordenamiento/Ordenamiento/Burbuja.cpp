#include "Burbuja.h"

void Burbuja::bubleSort(int vec[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			int prec =vec[j-1]; 
			int succ = vec[j];
			if (prec > succ) {
				int tmp = vec[j - 1];
				vec[j - 1] = vec[j];
				vec[j] = tmp;
			}
		}
	}
}
