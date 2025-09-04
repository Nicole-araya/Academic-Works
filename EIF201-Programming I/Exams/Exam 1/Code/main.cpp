#include "Control.h"

int main() {

	Control* c = new Control();

	c->menu();

	c->~Control();

	delete c;

	return 0;



}