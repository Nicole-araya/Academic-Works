#include "Menu.h"

Menu::Menu()
{
	arbol = new ArbolAVL<Cliente>();
	
	heap = new Heap<Cliente>(TAM_HEAP);  
}

Menu::~Menu()
{
	delete arbol, heap;
}

void Menu::menu()
{
	int opcion = 0; string id, nom; long long x,ced; Cliente* c; int ni, em, adul,cat; bool arch = true;
	int sizeTotal = 0;
	stringstream idk;
		

		while (opcion != 7) {
			try {

				if (arch) { Archivo::cargarDatos(arbol, "DatosBancoUno.txt");  arch = false; }


				cout << " ------MENU PRINCIPAL---------" << endl;
				cout << " 1. Encolar todos los clientes " << endl;
				cout << " 2. Encolar un cliente" << endl;
				cout << " 3. Atender los siguientes 5 clientes " << endl;
				cout << " 4. Mostrar el siguiente cliente a ser atendido " << endl;
				cout << " 5. Simulacion de Atencion de Clientes " << endl;
				cout << " 6. Agregar un Cliente Nuevo " << endl;
				cout << " 7. Salir " << endl;
				cout << "-------------------------------" << endl;
				cout << " Ingrese la opcion a realizar: ";
				cin >> opcion;

				system("pause");
				system("cls");
				switch (opcion) {

				case 1:
					if (arbol->isEmpty()) throw arbol;
					cout << "Encolando todos los clientes..." << endl;
					arbol->insertarHeap(heap);
					system("pause");
					system("cls");
					break;
				case 2:
					cout << " ---Encolando un cliente---" << endl;
					cout << "Ingrese el ID: "; cin >> ced;
					system("cls");
					
					c = NULL;
					c = arbol->search(ced);
					if (c == NULL) throw c;
					else {
						heap->insertKey(c);
						cout << "Ingreso exitoso!!" << endl;
					}

					system("pause");
					system("cls");
					break;

				case 3:

					cout << " Atender los siguientes 5 clientes " << endl;
					cout << "-----------------------------------" << endl;
					if (heap->isEmpty()) throw heap; //esta vacio

					for (int i = 0, j = heap->size(); i < 5 && i < j; i++) {

						cout << *heap->getMax();
						heap->deleteKey(0);

					}

					system("pause");
					system("cls");
					break;

				case 4:
					if (heap->isEmpty()) throw heap; //esta vacio

					cout << "**Siguiente cliente a ser atendido: " << *heap->getMax() << endl;

					system("pause");
					system("cls");
					break;

				case 5:
					cout << "---Simulacion de Atencion de Clientes---" << endl;
					cout << "----------------------------------------" << endl;

					if (heap->isEmpty()) throw heap; //esta vacio

					sizeTotal = heap->size();
					for (int i = 0; i < sizeTotal; i++) {

						cout << *heap->getMax();
						heap->deleteKey(0);
					}
					sizeTotal = heap->size();
					system("pause");
					system("cls");
					break;

				case 6:
					cout << "---Agregar un Cliente Nuevo-----" << endl;
					cout << "\nIngrese la id: "; cin >> ced;
					c = NULL;
					
					c = arbol->search(ced);
					if (c != NULL) throw c;      //Ya existe este cliente

					cout << "Ingrese el nombre: "; cin.ignore();getline(cin, nom);   

					cout << "Ingresa con un ninio\nIngrese 0.No 1.Si: "; cin >> ni;  ni == 0 || ni== 1 ?  ni :throw ni;
					cout << "Esta embarazada \nIngrese 0.No 1.Si: "; cin >> em;  em == 0 || em == 1 ?  em :throw em;
					cout << "Es adulto mayor\nIngrese 0.No 1.Si: "; cin >> adul; adul == 0 || adul == 1 ?  adul :throw adul;
					cout << "Ingresa la categoria\n1.Premiun 2.Oro 3.Normal: "; cin >> cat; cat != 1 && cat != 2 && cat != 3 ? throw cat: cat;
					
					idk << ced;
					idk >> id;
					c = new Cliente(nom, id, ni, em, adul, cat);
					arbol->insertar(c,ced);
					cout << "\nIngreso exitoso!!" << endl;

					system("pause");
					system("cls");
					break;
				case 7:
					arbol->saveData("DatosBancoUno.txt");
					cout << "Saliendo..." << endl;
					system("pause");
					break;
				default:

					cin.clear();
					throw opcion;
					break;

				}
			}
			catch (int num) {

				cin.clear(); cin.ignore();
				cout << Excepcion::wrongOption();
				system("pause");
				system("cls");
			}
			catch (fstream& f) {

				cout << Excepcion::notLoad();
				f.close();
				system("pause");
				system("cls");
			}
			catch (Cliente* c) {
				if (c)
					cout << Excepcion::found();
				else
					cout << Excepcion::notFound();
					
				system("pause");
				system("cls");
			}
			catch (ArbolAVL<Cliente>* a) {
				cout << Excepcion::notFound();
				system("pause");
				system("cls");
			}
			catch (Heap<Cliente>* h) {
				cout << Excepcion::notFound();
				system("pause");
				system("cls");
			}
			catch (bool op) {
				cin.ignore();
				cout << Excepcion::wrongOption();
				
				system("pause");
				system("cls");
			}
		}
}
