/*

Estructuras de Datos - Proyecto II

Estudiantes:
		Esteban Mojica González
		Nicole Araya Ballestero
*/


#include <iostream>
#include "Excepcion.h"
#include <random>
#include <ctime>
#include <string>
#include "Node.h"
#include "TwoFour.h"
int main(){

	TwoFour* theTree = new TwoFour();
	int n = 0;
	char choice;
	int value;
	Node* present;
	Node* del;
	Node* found;

	while(true){
		random_device device;
		mt19937 generador(device());
		uniform_real_distribution<> distribucion(0.0, 1.0);

		double random;
		clock_t startTime = 0, endTime = 0;
		int operation = 0;
		int searchCount = 0;
		int insertCount = 0;
		int deleteCount = 0;
		double tiempo = 0;

		try {
			cout << "***** ARBOL 2 - 4 *****\n";
			cout << "\n1. Insert n random Integers" << endl;
			cout << "2. Perform 2n operations with probability\n3. Print In Order";
			cout << "\n4. View Tree level by level\n5. Insert an element\n6. Delete an element";
			cout << "\n7. Find an element\n8. Quit" << endl;
			cout << "---------------------------------\n";
			cout << "Opcion ";
			cin >> choice;

			system("pause");
			system("cls");

			switch(choice){
				case '1':
					cout << "---Insert n random Integers---" << endl;
					cout << "Enter the value of n ";
					cin >> n;
					for(int a = 1; a < n + 1; a++){
						present = theTree->find(a);
						if(present == nullptr){
							theTree->insert(a);
						}
					}
					cout << "Valores ingresados!!\n\n";
					break;

				case '2':
					cout << "---Perform 2n operations with probability---\n";
					cout << "Enter the value of n ";
					cin >> n;
					
					startTime = clock();

					while(operation < (2 * n)){

						uniform_int_distribution<> distribucion2(0, n);
						random = (distribucion(generador));
						if(random < 0.4){

							int x = distribucion2(generador);
							present = theTree->find(x);
							if(present == nullptr){
								theTree->insert(x);
							}
							operation++;
							insertCount++;
						}

						random = distribucion(generador);
						if(random < 0.25){
							int x = distribucion2(generador);
							del = theTree->find(x);
							if(del != nullptr){
								theTree->deleteN(del, x);
							}
							operation++;
							deleteCount++;
						}

						random = distribucion(generador);
						if(random < 0.35){
							int x = distribucion2(generador);
							theTree->find(x);
							operation++;
							searchCount++;
						}
					}
					endTime = clock();
					tiempo = (endTime - startTime) / (double)CLOCKS_PER_SEC;

					cout << "\n\nTotal No. of search operations performed :"
						<< searchCount;
					cout << "\nTotal No. of delete operations performed :"
						<< deleteCount;
					cout << "\nTotal No. of insert operations performed :"
						<< insertCount;
					cout << "\nTotal Time Taken:" << tiempo << " nanoseconds\n\n";

					break;

				case '3':
					cout << "---Print In Order---\n";
					cout << "In Order: ";
					theTree->displayTree(1);
					cout << endl;
					break;

				case '4':
					cout << "---View Tree level by level---\n";
					cout << "Tree: \n";
					theTree->displayTree(0);
					break;

				case '5':
					cout << "---Insert an element---\n";
					cout <<"Enter value to insert: ";
					cin >> value;
					present = theTree->find(value);
					if(present != nullptr){
						throw present;  //si no es NULL, existe
					} else{
						theTree->insert(value);
						cout << "\nValor ingresado!!\n\n";
					}
					break;

				case '6':
					cout << "---Delete an element---\n";
					cout << "Enter value to delete: ";
					cin >> value;

					del = theTree->find(value);
					if(del != nullptr){
						if(theTree->deleteN(del, value) != nullptr)
							cout << "Deleted " << value << endl<<endl;
						else{
							throw false; // si no se elimino da false
						}
					}
					else
						throw del; // si es null no encontro el valor
					break;

				case '7':
					cout << "---Find an element---\n" << endl;
					cout << "Enter value to find: ";
					cin >> value;
					found = theTree->find(value);
					if (found != nullptr)
						cout << "\nFound " << value<<endl<<endl;
					else
						throw found; // si es null no lo encontro
					break;

				case '8':
					cout << "***Quit***" << endl;
					cout << "\nThank you!!!\n\n";
					system("pause");
					system("cls");
					exit(0);
					break;

				default:
					throw choice;
					system("cls");
			}
		} catch(Node* node){
			if (node!=NULL) {
				cout << Excepcion::found();
			}
			else {
				cout<<Excepcion::notFound();
			}

		} catch(char x){
			cout << Excepcion::wrongOption();
		}
		catch (bool y) {
			cout << Excepcion::notDeleted();
		}

		system("pause");
		system("cls");
	}
}