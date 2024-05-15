#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // For time()
#include <fstream>
#include <ostream>
#include <stdexcept>
#pragma warning(disable : 4996) //more reaserch necessary
using namespace std;
class Venta
{
public:
	Venta();
	~Venta();
	int getIdVenta();
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


private:


protected:
	int idVenta;
	static int unique_id;
	int idCliente;
	int idEmpleado;
	float total_amount;
	string date_time;


	struct infoVenta {
		int id;
		int id_Cliente;
		int id_Empleado;
		float total;
		string date;
	};
	infoVenta venta;
	string ModificaLinea(string, int, infoVenta&);
	vector<infoVenta> VectorVentas;
};

