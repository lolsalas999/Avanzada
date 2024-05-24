#pragma once
#include "Venta.h"
#include "Producto.h"
using namespace std;
class ProductoVendido
{
public:
	ProductoVendido();
	~ProductoVendido();
	int getId();

	void setIdSale(int id);
	int getIdSale();

	void setIdProduct(int id);
	int getIdProduct();

	void setQuantity(int q);
	int getQuantity();

	void setSalePricePerUnit(float price);
	float getSalePricePerUnit();

	void registrarProductoVendido(Venta venta, Productos p);
	void leerProductosVendios();
	void archivoProductosVendios();

private:

protected:
	int id;
	static int unique_id;
	int id_sale;
	int id_product;
	int quantity;
	float sale_price_per_unit;

	struct infoProductoVendido {
		int id;
		int id_venta;
		int id_producto;
		int cantidad;
		float ppu;
	};
	infoProductoVendido productoVendido;
	string ModificaLinea(string, int, infoProductoVendido&);
	vector<infoProductoVendido> VectorVendidos;
};
