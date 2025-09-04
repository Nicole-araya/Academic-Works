//ejemplo agenda de contactos
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "windows.h"

using namespace std;

typedef struct {
	char nom[25];
	int edad;
	char tel[15];
	char dir[35];
}Contacto;

/*Funciones de Archivo*/
void Crear(void);
void Listar(void);
void Agregar(void);
void Modificar(void);
void Borrar(void);
void Encontrar(void);

/*Nombre del Archivo a guardar*/
char nombre_fichero[] = "agenda.dat";

FILE *abrir_fichero_b(char cadena[], int metodo);

int main(){
	FILE *fp;
	int opc;
	char cad[3];

	fp = abrir_fichero_b(nombre_fichero,0);
	if( fp ){
		fclose(fp);
	}
	else
	{
		cout<<"Error (NO ABIERTO)"<<endl;
		cout<<"Presiona cualquier tecla para continuar y Crear el Archivo"<<endl;
		fp = abrir_fichero_b(nombre_fichero,1);
		fclose(fp);
		getch();
	}

	do{
		system("color 1f");
		system("cls");
		cout<<"1. Crear Archivo (Cuidado, elimina lo que ya se tiene en el Archivo)"<<endl;
		cout<<"2. Agregar\n3. Eliminar\n4. Listar\n5. Buscar\n6. Modificar\n7. Salir"<<endl;
		cout<<"Digite la opcion que desea: "<<endl;

		opc = atoi(gets(cad));
		while(opc<0 || opc>7) /*Limitando la entrada de las opciones*/
			opc = atoi(gets(cad));
		//clrscr();
		switch(opc)
		{
		case 1:
				Crear();
				break;
		case 2:
				Agregar();
				break;
		case 3:
				Borrar();
				break;
		case 4:
				Listar();
				break;
		case 5:
				Encontrar();
				break;
		case 6:
				 Modificar();
				break;

		}

		/*Solo parar cuando sea una de las opciones*/
		if(opc<7){
			cout<<"\nPresiona Cualquier Tecla para Regresar al Menu"<<endl;
			getch();
		}


	}while(opc!=7);

}



// FUNCION PARA CREAR UN ARCHIVO
/*****************************************************************
Funcion que sirve para borrar todo el Contenido del Archivo Binario*/
void Crear(void){
   FILE *fp;

   fp = abrir_fichero_b(nombre_fichero,0);
   if(fp)
   {
		cout<<"\n Error de apertura del archivo agenda.txt\n";
        fclose(fp);
   }
}


/********************************************************
Funcion que sirve para imprimir todos los  un registros del Archivo Binario*/
void Listar(void){
   FILE *fp;
   int i=1;
   Contacto aux;
	fp = abrir_fichero_b(nombre_fichero,0);
   if(!(fp))
   	cout<<"\n Error de apertura del archivo agenda.txt\n";
   else{
      cout<<"\n U S U A R I O S  E N  L A  A G E N D A"<<endl;
      cout<<"---------------------------------------------------------------"<<endl;
      while ((fread(&aux, sizeof(aux), 1, fp))!=0){
		cout<<"Datos del Contacto "<<i<<endl;
		cout<<"Nombre: "<<aux.nom<<endl;
		cout<<"Edad: "<<aux.edad<<endl;
		cout<<"Telefono: "<<aux.tel<<endl;
		cout<<"Direccion: "<<aux.dir<<endl;
		i++;
      }
      cout<<"---------------------------------------------------------------"<<endl;
      fclose(fp);
   }
}

/********************************************************
Funcion que sirve para agregar un registro dentro del Archivo Binario*/
void Agregar(void){
   FILE *fp;
   Contacto aux;
   char cad[3];

   cout<<"\n Agregando un Contacto Nuevo al archivo binario agenda.dat"<<endl;
   fp=abrir_fichero_b(nombre_fichero,2);
   if(!(fp))
		cout<<"Error de apuertura del archivo agenda.dat"<<endl;
   else{
		/*Introduciendo los Datos del contacto*/
		cout<<"Digite el nombre del contacto: "<<endl;
		cin>>aux.nom;
		cout<<"Digite la Edad de "<<aux.nom<<" :"<<endl;
		cin>>cad;
		aux.edad=atoi(cad);
		cout<<"Digite el telefono de "<<aux.nom<<": "<<endl;
		cin>>aux.tel;
		cout<<"Digite la direccion de "<<aux.nom<<" :"<<endl;
		cin>>aux.dir;

		fwrite(&aux, sizeof(aux), 1, fp);
		fclose(fp);
   }
}


/********************************************************
Funcion que sirve para Modificar un registro dentro del Archivo Binario*/
void Modificar(void){
   FILE *fp;
   Contacto aux;
   int n;
   char cadena[25],cad[2];
	fp=abrir_fichero_b(nombre_fichero,3);
   if(!(fp))
   	cout<<"\n Error de apuertura del archivo agenda.txt"<<endl;
   else{
		cout<<"Como se llama el contacto que quieres Modificar: "<<endl;
		cin>>cadena;

		/*Buscando el Contacto dentro del Archivo*/
      while ((n=fread(&aux, sizeof(aux), 1, fp))!=0 && stricmp(aux.nom,cadena)!=0); //stricmp devuelve 0 si las cadenas son iguales
      if (n==0)
         cout<<"No existe el contacto llamado: "<<cadena<<endl;
      else{
         cout<<"\n Contacto encontrado....!!!"<<endl;
         cout<<"Nombre: "<<aux.nom<<endl;
         cout<<"Edad: "<<aux.edad<<endl;
         cout<<"Telefono: "<<aux.tel<<endl;
         cout<<"Direccion: "<<aux.dir<<endl;

         cout<<"\n CAMBIANDO VALORES "<<endl;

        cout<<"Dame el nombre nuevo del contacto: "<<endl;
		cin>>aux.nom;
		cout<<"Dame la nueva Edad del contacto: "<<endl;
		cin>>cad;
		aux.edad=atoi(cad);
		cout<<"Dame el nuevo telefono del contacto: "<<endl;
		cin>>aux.tel;
		cout<<"Dame la nueva direccion del contacto: "<<endl;
		cin>>aux.dir;



         cout<<"\n GRABANDO Y CERRANDO ARCHIVO "<<endl;
         fseek(fp,-1*sizeof(aux),SEEK_CUR);
         fwrite(&aux, sizeof(aux), 1, fp);
      }
      fclose(fp);   //Cerramos el archivo
   }
}

/********************************************************
Funcion que sirve para borrar un registro dentro del Archivo Binario*/
void Borrar(void){
   FILE *fp,*fd;
   Contacto	aux;
   int encontrado=0;
	char cadena[25];

   cout<<"Introduce el nombre del contacto a borrar: "<<endl;
   cin>>cadena;

   cout<<"\n BORRANDO REGISTROS  "<<endl;
   fp=abrir_fichero_b(nombre_fichero,0);
   if(!(fp))
   	cout<<"\n Error de apuertura del archivo agenda.txt"<<endl;
   else{
		fd=abrir_fichero_b("paso.$$$",1);
      if(!(fd))
         cout<<"\n Error Imposible crear archivo auxiliar"<<endl;
      else{
         while ((fread(&aux, sizeof(aux), 1, fp))!=0)
            if(stricmp(aux.nom,cadena)!=0)
              fwrite(&aux, sizeof(aux), 1, fd);
            else
              encontrado=1;
         fclose(fd);
      }
      fclose(fp);
      if(encontrado){
         system("del agenda.txt");
         system("ren paso.$$$ agenda.txt");
         cout<<"\n Registro BORRADO con Exito!!!"<<endl;
      }
      else{
         system("del paso.$$$");
         cout<<"\n El Registro NO SE ENCONTRO, no fue borrado!!!"<<endl;
      }
   }
}

/******************************************
Funcion para encontrar un contacto e imprimir sus datos*/
void Encontrar(void){
	FILE *fp;
	Contacto aux;
	int n;
	char cadena[25];

	cout<<"Introduce el nombre del contacto que buscas: "<<endl;
	cin>>cadena;

	cout<<"\n Buscando a un contacto  "<<endl;
	fp=abrir_fichero_b(nombre_fichero,0);
	if(!(fp))
		cout<<"\n Error de apuertura del archivo agenda.txt"<<endl;
	else{
		while ((n=fread(&aux, sizeof(aux), 1, fp))!=0 && stricmp(aux.nom,cadena)!=0);
      if (n==0)
         cout<<"No existe el cuate llamado:"<<cadena<<endl;
      else{
         cout<<"\n contacto encontrado....!!!"<<endl;
		 cout<<"Nombre: "<<aux.nom<<endl;
		 cout<<"Edad: "<<aux.edad<<endl;
		 cout<<"Telefono: "<<aux.tel<<endl;
		 cout<<"Direccion: "<<aux.dir<<endl;

		/* getch();*/

		}
	}


}

/*************************************************
Funcion que Carga el Archivo y regresa un apuntador con que se va ha manejar el Archivo
Recibe: 	El nombre del Archivo , Y el método con que se va abrir el Archivo
		Un Apuntador tipo Archivo, 0 - Solo Lectura , 1 - Para crearlo de nuevo desde cero,
		2 - Anhadir Informacion, 3 - para Lectura y Escritura.
 Regresa:	El apuntador de Tipo FILE, con el cual se abrio*/
FILE *abrir_fichero_b(char cadena[], int metodo){
	FILE *x;
	switch(metodo){
		case 0:
			x = fopen(cadena,"rb");
			break;
		case 1:
			x = fopen(cadena,"wb");
			break;
		case 2:
			x = fopen(cadena,"ab");
			break;
		case 3:
			x = fopen(cadena,"r+b");
			break;
	}
	return x;
}

