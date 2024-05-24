#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include "Presentacion.h"

using namespace std;

class Productos : public	Presentacion
{
public:
	Productos();
	~Productos();

	void setid(int);
	int getid();

	void setupc(string);
	string getupc();

	void setname(string);
	string getname();

	void setid_presentacion(int);
	int getid_presentacion();

	void setprice(float);
	float getprice();

	void setcost(float);
	float getcost();

	void sethas_iva(bool);
	bool gethas_iva();

	void setstock(int);
	int getstock();

	void registrarproducto();
	void archivoproductos();
	void leerproductos();

	vector<string> buscarproducto();
	void modificarproducto();

	bool checkvectorproductos();
	void ClearProductos();


private:
protected:

	struct infoProducto {
		int id;
		string UPC;
		string name;
		int id_presentacion;
		float price;
		float cost;
		bool has_iva;
		int stock;
	};
	infoProducto Producto;
	string ModificaLinea(string, int, infoProducto&);
	vector<infoProducto> VectorProductos;
};

