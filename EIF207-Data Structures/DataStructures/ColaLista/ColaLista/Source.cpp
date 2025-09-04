
#include "Cola.h"

int main() {
	Cola<string> * cola=new Cola<string>;
	cola->enqueue(new string("Hola"));

	cout << cola->size() << endl;
	cola->enqueue(new string("como estas"));
	cout << *cola->front()<<endl;
	cola->enqueue(new string(":)"));
	cola->dequeue();
	cola->dequeue();
	cout << *cola->front()<<endl;
	

	return 0;
}