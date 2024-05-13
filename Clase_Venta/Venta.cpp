#include "Venta.h"

Venta::Venta()
{
	idVenta = unique_id++;
}

Venta::~Venta()
{
}

int Venta::getIdVenta()
{
	return idVenta;
}

void Venta::setIdCliente(int id)
{
	idCliente = id;
}

int Venta::getIdCliente()
{
	return idCliente;
}

void Venta::setIdEmpleado(int id)
{
	idEmpleado = id;
}

int Venta::getIdEmpleado()
{
	return idEmpleado;
}

void Venta::setTotalAmount(float total)
{
	total_amount = total;
}

float Venta::getTotalAmount()
{
	return total_amount;
}

char* Venta::getDateTime()
{
	// current date and time on the current system
	time_t now = time(0);

	// convert now to string form
	char* date_time = ctime(&now);
	return date_time;
}
