#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include <ctime>
#include "usuarios.h"
#pragma warning(disable : 4996) //more reaserch necessary

using namespace std;

class Cliente : public usuario
{
public:
	Cliente();
	~Cliente();

	void setid(int);
	int getid();

	void setname(string);
	string getname();

	void setRFC(string);
	string getRFC();

	void setfiscalid(int);
	int getfiscalid();

	void setdireccion(string);
	string getdireccion();

	void setciudad(string);
	string getciudad();

	void setestado(string);
	string getestado();

	void setzipcode(string);
	string getzipcode();

	string gettime();


	void RegisterCliente();
	void CreateClientesArchive();
	void ReadArchiveCliente();
	void EditCliente();
	void BorrarCliente();
	void SobreEscribirCliente();
	void BusquedaCliente();
	int VectorSize();
	void Clear();
	void CrearReporteArchivo();
	void RegistrarReporteCliente(string, string);
	bool checkvectorclientes();
	void LimpiarPantalla();

private:
protected:

	struct Clientes
	{
		int id;
		string name;
		string RFC;
		int fiscal_regimen_id;
		string direccion;
		string ciudad;
		string estado;
		string zipcode;
		string date;
	};
	Clientes ClientesObject;
	string ModificaLinea(string, int, Clientes&);
	vector<Clientes> VectorClientes;
};
