#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // For time()
#include <fstream>
#include <ostream>
#include <stdexcept>
#include "Producto.h"
#pragma warning(disable : 4996) //more reaserch necessary
using namespace std;
class Venta : public Productos
{
public:
	Venta();
	~Venta();
	int getIdVenta();
	int getcant();
	int getppu();
	void setcant(int);
	void setppu(int);
	void setidproducto(int);
	int getidproducto();
	void setIdCliente(int id);
	int getIdCliente();
	void setIdEmpleado(int id);
	int getIdEmpleado();
	void setTotalAmount(float total);
	float getTotalAmount();
	string getDateTime();
	void registrarVenta();
	void archivoVenta();
	void leerVentas();

	void clearventas();

private:
protected:

	int idVenta;
	int unique_id;
	int idCliente;
	int idEmpleado;
	float total_amount;
	string date_time;

	struct infoVenta {
		int id;
		int id_Cliente;
		int id_Empleado;
		int idproducto;
		int cant;
		int ppu;
		float total;
		string date;
	};
	infoVenta venta;
	string ModificaLinea(string, int, infoVenta&);
	vector<infoVenta> VectorVentas;
};



