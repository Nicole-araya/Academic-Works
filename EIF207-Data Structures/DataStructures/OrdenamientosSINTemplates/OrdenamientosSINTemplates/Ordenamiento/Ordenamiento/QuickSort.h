#pragma once
#include <iostream>
using namespace std;
class QuickSort
{
public:

	static void quickSort(int vec[],int size);

private:
	static void quickSortStep(int vec[],int a, int b);
};

