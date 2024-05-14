#include "ProductoVendido.h"

ProductoVendido::ProductoVendido()
{
	id = unique_id++;
}

ProductoVendido::~ProductoVendido()
{
}

int ProductoVendido::getId()
{
	return id;
}

void ProductoVendido::setIdSale(int id)
{
	id_sale = id;
}

int ProductoVendido::getIdSale()
{
	return id_sale;
}

void ProductoVendido::setIdProduct(int id)
{
	id_product = id;
}

int ProductoVendido::getIdProduct()
{
	return id_product;
}

void ProductoVendido::setQuantity(int q)
{
	quantity = q;
}

int ProductoVendido::getQuantity()
{
	return quantity;
}

void ProductoVendido::setSalePricePerUnit(float price)
{
	sale_price_per_unit = price;

}

float ProductoVendido::getSalePricePerUnit()
{
	return sale_price_per_unit;
}
