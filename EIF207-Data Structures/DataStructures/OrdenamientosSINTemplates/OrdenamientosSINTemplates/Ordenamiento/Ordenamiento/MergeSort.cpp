#include "MergeSort.h"

void MergeSort::mergeSort(list<int>& S)
{
	typedef typename list<int>::iterator itor; //secuencia de elementos
	int n = S.size();
	if (n <= 1) return;
	list<int> S1, S2;
	itor p = S.begin();
	for (int i = 0; i < n / 2; i++)
		S1.push_back(*p++);
	for (int i = n / 2; i < n; i++)
		S2.push_back(*p++);
	S.clear();
	mergeSort(S1);
	mergeSort(S2);
	merge(S1, S2, S);
}

void MergeSort::merge(list<int>& S1, list<int>& S2, list<int>& S)
{
	typedef typename list<int>::iterator itor;
	itor p1 = S1.begin();
	itor p2 = S2.begin();
	while (p1 != S1.end() && p2 != S2.end()) {
		if (*p1 < *p2) S.push_back(*p1++);
		else S.push_back(*p2++);
	}while (p1 != S1.end())
		S.push_back(*p1++);
	while (p2 != S2.end())
		S.push_back(*p2++);
}
