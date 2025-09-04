#pragma once
#include <list>
#include <iostream>
using namespace std;
class MergeSort
{
public:
	static void mergeSort(list<int>& S);
	static void merge(list<int>& S1, list<int>& S2, list<int>& S);
};

