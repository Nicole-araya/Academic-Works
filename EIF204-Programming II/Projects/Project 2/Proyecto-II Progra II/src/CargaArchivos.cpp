#include "CargaArchivos.h"

void CargaArchivos::cargarTrajes(string nom, ContenedoraTrajes* Ctraje, ContenedoraTrajesPersonalizados* trajePer)
{
	string cod, precio, medida, color, boolOpc, descrip; 
	TrajeAbstracto* traje = NULL;
	CamisaAbstracta* camisa; PantalonAbstracto* panta;
	ZapatoAbstracto* zap;

	ifstream entrada(nom);
	if (!entrada) {

		throw entrada;
		entrada.close();
		return;
	}

	while (!entrada.eof()) {

		getline(entrada, cod, '\t');
		getline(entrada, precio, '\t');
		getline(entrada, medida, '\t');

		if (!cod.empty() && !precio.empty() && !medida.empty())
		{
			double x = stoi(precio);
			//Para saber cual traje se crea nos guiaremos por el codigo dado
			if (cod[0] == 'D') {

				traje = new TrajeDeportivo(cod, medida);
			}
			if (cod[0] == 'E') {

				traje = new TrajeEjecutivo(cod, medida);
			}
			if (cod[0] == 'T') {

				traje = new TrajeTrabajo(cod, medida);
			}

			traje->setPrecio(x);

			//Crear camisa
			getline(entrada, color, '\t');
			getline(entrada, precio, '\t');
			getline(entrada, boolOpc, '\t');

			if (!color.empty() && !precio.empty() && !boolOpc.empty())
			{
				bool y = stoi(boolOpc);
				double num = stoi(precio);

				camisa = traje->crearCamisa(color, y);
				camisa->setPrecio(num);
			}

			//Crear panta
			getline(entrada, color, '\t');
			getline(entrada, precio, '\t');
			getline(entrada, boolOpc, '\t');

			if (!color.empty() && !precio.empty() && !boolOpc.empty())
			{
				bool y = stoi(boolOpc);
				double num = stoi(precio);

				panta = traje->crearPantalon(color, y);
				panta->setPrecio(num);
			}

			//Crear zapatos
			getline(entrada, color, '\t');
			getline(entrada, precio, '\t');
			getline(entrada, boolOpc, '\n');

			if (!color.empty() && !precio.empty() && !boolOpc.empty())
			{
				bool y = stoi(boolOpc);
				double num = stoi(precio);

				zap = traje->crearZapatos(color, y);
				zap->setPrecio(num);
			}
			// agregar traje 
			if (cod[1] == 'P') {
				trajePer->ingresaTraje(traje);
			}
			else {
				Ctraje->ingresaTraje(traje);
			}
		}
	}
	
	entrada.close();
}

void CargaArchivos::cargarSubcriptores(string nom, Subject* subs)
{
	string id, nomb,correo,pago,pais,ciudad, nac,frec, inicial;

	ifstream entrada(nom);

	if (!entrada) {

		throw entrada;
		entrada.close();
		return;
	}

	while (!entrada.eof()) {

		getline(entrada, inicial, '\t');
		if (!inicial.empty() && inicial == "P")
		{
			getline(entrada, nac, '\t');
			getline(entrada, id, '\t');
			getline(entrada, nomb, '\t');
			getline(entrada, correo, '\t');
			getline(entrada, pago, '\t');
			getline(entrada, pais, '\t');
			getline(entrada, ciudad, '\n');

			double x = stoi(pago);

			subs->agregarSubscriptor(new Persona(id, nomb, correo, x, ciudad, pais, nac));
		}

		if (!inicial.empty() && inicial == "E")
		{
			getline(entrada, frec, '\t');
			getline(entrada, id, '\t');
			getline(entrada, nomb, '\t');
			getline(entrada, correo, '\t');
			getline(entrada, pago, '\t');
			getline(entrada, pais, '\t');
			getline(entrada, ciudad, '\n');

			double z = stoi(pago);
			bool y = stoi(frec);

			subs->agregarSubscriptor(new Empresa(id, nomb, correo, z, ciudad, pais, y));
		}

	}
	entrada.close();
}

void CargaArchivos::cargarVentas(string nom, ContenedoraVentas* ventas, Subject* subs, ContenedoraTrajes* traje, ContenedoraTrajesPersonalizados* trajePer)
{
	string cod, fecha, envio, id;
	Observa* observa; TrajeAbstracto* trajeAb; Venta* venta; Cliente* cliente;
	
	ifstream entrada(nom);

	if (!entrada) {

		throw entrada;
		entrada.close();
	}


	while (!entrada.eof()) {

		getline(entrada, fecha, '\t');
		getline(entrada, envio, '\t');
		getline(entrada, id, '\t');
		getline(entrada, cod, '\n');

		if (!fecha.empty() && !envio.empty() && !id.empty() && !cod.empty()) {

			double x = stoi(envio);
			
			if (id != "000") {
				observa = subs->buscaPorID(id);
				cliente = dynamic_cast<Cliente*>(observa);
			}
			else {
				cliente = NULL;
			}
			
			if (cod[1] != 'P') {
				trajeAb = traje->buscaPorCod(cod);
				venta = new Venta(cliente, trajeAb, fecha);
			}
			else {
				trajeAb = trajePer->buscaPorCod(cod);
				venta = new Venta(cliente, trajeAb, fecha);
			}

			venta->setPrecioEnvio(x);
			ventas->agregaVenta(venta);

		}

	}
	entrada.close();

}

void CargaArchivos::crearArchivos(string nomT, string nomC, string nomV)
{
	ofstream fAux;
	fAux.open(nomT, ios::out | ios::app);
	fAux.close();
	ofstream fAux2;
	fAux2.open(nomC, ios::out | ios::app);
	fAux2.close();
	ofstream fAux3;
	fAux3.open(nomV, ios::out | ios::app);
	fAux3.close();
}
