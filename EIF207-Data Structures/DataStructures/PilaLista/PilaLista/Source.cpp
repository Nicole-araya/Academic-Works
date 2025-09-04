#include "Pila.h"

int main() {

	Pila<int> *list=new Pila<int>;
	
	list->push(new int(2));
	cout << list->size() << endl;
	cout << *list->top()<<endl;

	list->push(new int(3));
	cout << *list->top() << endl;
	list->pop();

	cout << *list->top() << endl;

	list->push(new int(4));
	cout << *list->top() << endl;
	list->push(new int(6));
	cout<<*list->top() << endl;

	delete list;

	return 0;
}