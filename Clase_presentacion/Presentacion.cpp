#include "Presentacion.h"

Presentacion::Presentacion()
{
	PresentacionP.id = 0;
	PresentacionP.name = "";
}

Presentacion::~Presentacion()
{

}

void Presentacion::setid(int a)
{
	PresentacionP.id = a;
}

int Presentacion::getid()
{
	return PresentacionP.id;
}

void Presentacion::setname(string b)
{
	PresentacionP.name = b;
}

string Presentacion::getname()
{
	return PresentacionP.name;
}

void Presentacion::registrarpresentacion()
{
	int id;
	cout << "Deme el id de la presentación del producto a registrar: ";
	cin >> id;
	string name;
	cout << "Deme el nombre de la presentación del producto a registrar: ";
	cin >> name;

	setid(id);
	setname(name);
}