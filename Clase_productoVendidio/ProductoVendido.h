#pragma once
#include <iostream>
#include <string>

using namespace std;
class ProductoVendido
{
public:
	ProductoVendido();
	~ProductoVendido();
	void setId(int i);
	int getId();
	void setIdSale(int id);
	int getIdSale();
	void setIdProduct(int id);
	int getIdProduct();
	void setQuantity(int q);
	int getQuantity();
	void setSalePricePerUnit(float price);
	float getSalePricePerUnit();

private:

protected:
	int id;
	int id_sale;
	int id_product;
	int quantity;
	float sale_price_per_unit;
};
