#pragma once
#include "AplicacionADN.h"
#include <iostream>
using namespace std;

// Las interfaces de usuario son clases de servicio.

class InterfazUsuario {
     public:
           static int menu();
       static void ventanaCargarPacientes(AplicacionADN*);
	   static void ventanaCargaEnfermedades(AplicacionADN*);
	    static void ventanaParaEncabezadoAnalisis1();
	    static void ventanaParaEncabezadoAnalisis2();
	    static void ventanaParaEncabezadoAnalisis3();
};

int InterfazUsuario::menu() {
	int op;
	system("cls");
	cout << "------ Creacion de una Aplicacion ADN-----" << endl;
	cout << "                                          " << endl;
	cout << "-------------------MENU-------------------" << endl;
	cout << "   1- Cargar Datos de pacientes           " << endl;
	cout << "   2- Cargar Datos de enfermedades        " << endl;
	cout << "   3- Procesar el analisis No.1           " << endl;
	cout << "   4- Procesar el analisis No.2           " << endl;
	cout << "   5- Procesar el analisis No.3           " << endl;
	cout << "   6- Salir                               " << endl;
	cout << "------------------------------------------" << endl;
	cout << "Digite la opcion...";
	cin >> op;
	return op;
}

void InterfazUsuario::ventanaCargarPacientes(AplicacionADN* Co) {
	Co->cargarPacientes();
	cout << "Datos cargados.." << endl;
}

void InterfazUsuario::ventanaCargaEnfermedades(AplicacionADN* Co) {
	Co->cargarEnfermedades();
	cout << "Datos cargados.." << endl;
}

void InterfazUsuario::ventanaParaEncabezadoAnalisis1(){
    cout << "----------------------------------------------" << endl;
    cout << "----SISTEMA DE ANALISIS DE DATOS MOLECULAR----" << endl;
    cout << "----------------ANALISIS NO.1-----------------" << endl;
    cout << "-------------LISTADO DE PACIENTES-------------" << endl;
    cout << "-------CON ENFERMEDADES SUSCEPTIBLES DE ------" << endl;
    cout << "-----------------DESARROLLO-------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
}


void InterfazUsuario::ventanaParaEncabezadoAnalisis2(){
   cout << "----------------------------------------------" << endl;
   cout << "----SISTEMA DE ANALISIS DE DATOS MOLECULAR----" << endl;
   cout << "----------------ANALISIS NO.2-----------------" << endl;
   cout << "----------------------------------------------" << endl;
   cout << "---------BASE NITROGENADA POR PACIENTE--------" << endl;
   cout << "----------------------------------------------" << endl;
   cout << endl;
}

void InterfazUsuario::ventanaParaEncabezadoAnalisis3() {
	cout << "----------------------------------------------" << endl;
	cout << "----SISTEMA DE ANALISIS DE DATOS MOLECULAR----" << endl;
	cout << "----------------ANALISIS NO.3-----------------" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "-----CONCORDANCIA ENFERMEDAD POR PACIENTE-----" << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
}
