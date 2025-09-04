#include "Servicio.h"


 string Servicio::nombreDelGrupo(int num){

if(num==15) {return "Accionistas";}
 if(num==52){return "Socios";}
 if(num==55){return "Trabajadores";}
if(num==39){return "Clientes";}
if(num==33) {return "Competidores";}
 if(num==43){return "Contratistas";}
 if(num==37) {return "Medios de Comunicac";}
 if(num==11) {return "Black Rose";}

 }

 double Servicio::getPresupuesto(int num){

if(num==15) {return 33;}
 if(num==52){return 39;}
 if(num==55){return 15;}
if(num==39){return 14;}
if(num==33) {return 25;}
 if(num==43){return 60;}
 if(num==37){return 15;}
  if(num==11) {return 11;}
 }

 int Servicio::getActivPorAnio(int num){

 if(num==15) {return 30;}
 if(num==52){return 35;}
 if(num==55){return 16;}
if(num==39){return 11;}
if(num==33) {return 23;}
 if(num==43){return 42;}
 if(num==37) {return 18;}
  if(num==11) {return 11;}

 }

 int Servicio::getCantidadAsociados(int num){

if(num==15) {return 35;}
if(num==52){return 22;}
if(num==55){return 11;}
if(num==39){return 12;}
if(num==33) {return 7;}
if(num==43){return 44;}
if(num==37) {return 23;}
 if(num==11) {return 11;}
 }
