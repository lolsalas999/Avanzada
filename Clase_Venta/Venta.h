#pragma once
#include <iostream>
#include <string>
#include <ctime>   // For time()
#pragma warning(disable : 4996) //more reaserch necessary
using namespace std;
class Venta
{
public:
	Venta();
	~Venta();
	void setIdVenta(int id);
	int getIdVenta();
	void setIdCliente(int id);
	int getIdCliente();
	void setIdEmpleado(int id);
	int getIdEmpleado();
	void setTotalAmount(float total);
	float getTotalAmount();
	char* getDateTime();

private:


protected:
	int idVenta;
	int idCliente;
	int idEmpleado;
	float total_amount;
	char* date_time;
};

