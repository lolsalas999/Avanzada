#include "cliente.h"

Cliente::Cliente()
{
	ClientesObject.id = 0;
	ClientesObject.name = "";
	ClientesObject.RFC = "";
	ClientesObject.fiscal_regimen_id = 0;
	ClientesObject.ciudad = "";
	ClientesObject.direccion = "";
	ClientesObject.estado = "";
	ClientesObject.zipcode = "";

}

Cliente::~Cliente()
{
}

void Cliente::setid(int a)
{
	ClientesObject.id = a;
}

int Cliente::getid()
{
	return ClientesObject.id;
}

void Cliente::setname(string b)
{
	ClientesObject.name = b;
}

string Cliente::getname()
{
	return ClientesObject.name;
}

void Cliente::setRFC(string c)
{
	ClientesObject.RFC = c;
}

string Cliente::getRFC()
{
	return ClientesObject.RFC;
}

void Cliente::setfiscalid(int d)
{
	ClientesObject.fiscal_regimen_id = d;
}

int Cliente::getfiscalid()
{
	return ClientesObject.fiscal_regimen_id;
}

void Cliente::setdireccion(string e)
{
	ClientesObject.direccion = e;
}

string Cliente::getdireccion()
{
	return ClientesObject.direccion;
}

void Cliente::setciudad(string f)
{
	ClientesObject.ciudad = f;
}

string Cliente::getciudad()
{
	return ClientesObject.ciudad;
}

void Cliente::setestado(string g)
{
	ClientesObject.estado = g;
}

string Cliente::getestado()
{
	return ClientesObject.estado;
}

void Cliente::setzipcode(string h)
{
	ClientesObject.zipcode = h;
}

string Cliente::getzipcode()
{
	return ClientesObject.zipcode;
}

void Cliente::RegisterCliente()
{
	ReadArchiveCliente();
	ClientesObject.id = ClientesObject.id += 1;

	string name = "";
	cout << "Deme el nombre del nuevo cliente: ";
	cin >> name;
	setname(name);
	getname();

	string RFC = "";
	cout << "Deme el RFC del nuevo Cliente: ";
	cin >> RFC;
	setRFC(RFC);
	getRFC();

	//placeholder del id del regimen fiscal

	string direccion = "";
	cout << "Deme la dirección del nuevo cliente: ";
	cin >> direccion;
	setdireccion(direccion);
	getdireccion();

	string ciudad = "";
	cout << "Deme la ciudad en la que se encuentra el nuevo cliente: ";
	cin >> ciudad;
	setciudad(ciudad);
	getciudad();

	string estado = "";
	cout << "Deme el estado en el que se encuentra el nuevo cliente: ";
	cin >> estado;
	setestado(estado);
	getestado();

	string zipcode = "";
	cout << "Deme el código postal del nuevo cliente: ";
	cin >> zipcode;
	setzipcode(zipcode);
	getzipcode();

	ofstream SaveFile;
	try
	{
		SaveFile.open("clientes.csv", fstream::app);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el clientes.csv para escritura");
		}
		SaveFile << ClientesObject.id << "," << ClientesObject.name << "," << ClientesObject.RFC << "," << ClientesObject.fiscal_regimen_id << "," << ClientesObject.direccion << "," << ClientesObject.ciudad << ","<<ClientesObject.estado<<";"<<ClientesObject.zipcode<< endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en clientes.csv" << e.what() << endl;
	}
	
}

void Cliente::CreateClientesArchive()
{
	ofstream SaveFile;
	try
	{
		SaveFile.open("clientes.csv", fstream::out);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el clientes.csv para escritura");
		}
		SaveFile << "Id,Nombre,RFC,Identificador de Regimen Fiscal,Direccion,Ciudad,Estado,Codigo Postal" << endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en clientes.csv" << e.what() << endl;
	}
}

void Cliente::ReadArchiveCliente()
{
	try
	{
		//Primero trata de abrir el archivo
		ifstream SaveFile;
		SaveFile.open("clientes.csv");
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el clientes.csv");
		}
		//Si se abre, se crean variables auxiliares
		string line;
		Clientes temporal;
		//Se usa el metodo modifica linea para leer cada linea del archivo
		while (getline(SaveFile, line))
		{
			Clientes temporal;
			string templine = line;
			templine = ModificaLinea(templine, 1, temporal);
			templine = ModificaLinea(templine, 2, temporal);
			templine = ModificaLinea(templine, 3, temporal);
			templine = ModificaLinea(templine, 4, temporal);
			templine = ModificaLinea(templine, 5, temporal);
			templine = ModificaLinea(templine, 6, temporal);
			templine = ModificaLinea(templine, 7, temporal);
			templine = ModificaLinea(templine, 8, temporal);
			//Las almacena todas en un vector
			VectorClientes.push_back(temporal);
		}
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al leer el archivo" << endl;
	}
	//Las desempaqueta para poder usar las variables mas facil
	for (int i = 0; i < VectorClientes.size(); i++)
	{
		ClientesObject.id = VectorClientes[i].id;
		ClientesObject.name = VectorClientes[i].name;
		ClientesObject.RFC = VectorClientes[i].RFC;
		ClientesObject.fiscal_regimen_id = VectorClientes[i].fiscal_regimen_id;
		ClientesObject.direccion = VectorClientes[i].direccion;
		ClientesObject.ciudad = VectorClientes[i].ciudad;
		ClientesObject.estado = VectorClientes[i].estado;
		ClientesObject.zipcode = VectorClientes[i].zipcode;
	}

}
string Cliente::ModificaLinea(string cadena, int elemento, Clientes& temporal)
{
	size_t pos = cadena.find(",");
	string value;
	if (pos != string::npos)
	{
		value = cadena.substr(0, pos);
		cadena = cadena.substr(pos + 1);
	}
	else
	{
		value = cadena;
	}
	switch (elemento)
	{
	case 1:
		temporal.id = stoi(value);
		break;
	case 2:
		temporal.name = value;
		break;
	case 3:
		temporal.RFC = value;
		break;
	case 4:
		temporal.fiscal_regimen_id = stoi(value);
		break;
	case 5:
		temporal.direccion = value;
		break;
	case 6:
		temporal.ciudad = value;
		break;
	case 7:
		temporal.estado = value;
		break;
	case 8:
		temporal.zipcode = value;
		break;
	}
	return cadena;
}

