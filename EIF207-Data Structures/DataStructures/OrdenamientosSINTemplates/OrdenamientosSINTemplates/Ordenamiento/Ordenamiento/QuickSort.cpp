#include "QuickSort.h"

void QuickSort::quickSort(int vec[], int size) 
{
	if (size <= 1)return;
	quickSortStep(vec, 0, size - 1);
}

void QuickSort::quickSortStep(int vec[], int a, int b)
{
	if (a >= b) return;
	int pivot = vec[b];
	int l = a;
	int r = b - 1;
	while (l <= r) {
		while (l <= r && !(pivot < vec[l]))l++;
		while (r >= l && !(vec[r] < pivot)) r--;

		if (l < r) { //swap
			int tmp = vec[l];
			vec[l] = vec[r];
			vec[r] = tmp;
		}
	}
	//swap
	int tmp = vec[l];
	vec[l] = vec[b];
	vec[b] = tmp;

	quickSortStep(vec, a, l - 1);
	quickSortStep(vec, l + 1, b);
}
