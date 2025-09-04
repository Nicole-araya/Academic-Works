#pragma once
#include "CamisaAbstracta.h"
class MangaLarga : public CamisaAbstracta{


public:

	MangaLarga(string, double, string, bool);
	~MangaLarga();
	string toString();
};

