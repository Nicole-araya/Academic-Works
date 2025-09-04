#include "Ruta.h"

Ruta::Ruta(char m1, char m2, int c, int g, int cp, int a)
{
	maq1 = m1;
	maq2 = m2;
	concreto = c;
	gypsum = g;
	cambPiso = cp;
	adicional = a;
}

Ruta::~Ruta()
{
}

/*double Ruta::calcularPeso()
{
	int c, g, cp, a;
	c = concreto;
	g = gypsum;
	cp = cambPiso;
	a = adicional;
	double peso=0;
	while (c != 0) { peso += 2.5; c--; }
	while (g != 0) { peso += 1.5; g--; }
	while (cp != 0) { peso += 2; cp--; }
	while (a != 0) { adicional += 0.5; a--; }

	return peso;
}*/

double Ruta::calcularPeso( int v, int n, double p)
{
	if (v == 0) return p;
	(n == 1) ? p += 2.5: p;
	(n == 2) ? p += 1.5 : p;
	(n == 3) ? p += 2 : p;
	(n == 4) ? p += 0.5 : p;
	
	calcularPeso(--v, n, p);
}

double Ruta::calcular()
{
	double peso=0;
	return calcularPeso(concreto, 1, peso) + calcularPeso(gypsum, 2, peso) +
		calcularPeso(cambPiso, 3, peso) + calcularPeso(adicional, 4, peso);
}

void Ruta::guardar(ofstream& salida)
{
	salida <<maq1 << ",";
	salida << maq2 << ",";
	salida << calcular() << "\n";
}

string Ruta::toString()
{
	stringstream s;
	s << maq1 << "-" << maq2 << ", peso: " << calcular() << endl;
	return s.str();
}
