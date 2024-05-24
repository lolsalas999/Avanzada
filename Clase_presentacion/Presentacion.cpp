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
	if (vectorpresentacionl.size() == 0)
	{
		id = 1;
	}
	else
	{
		id = PresentacionP.id + 1;
	}
	string name;
	cout << "Deme el nombre de la presentación del producto a registrar: ";
	cin >> name;
	setid(id);
	setname(name);
	ofstream SaveFile;
	try
	{
		SaveFile.open("presentacion.csv", fstream::app);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el presentacion.csv para escritura");
		}
		SaveFile.seekp(0, ios::end); // Mover el puntero al final del archivo
		SaveFile << endl;
		SaveFile << PresentacionP.id << "," << PresentacionP.name << endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en presentacion.csv" << e.what() << endl;
	}
}

void Presentacion::archivopresentacion()
{
	ofstream SaveFile;
	try
	{
		SaveFile.open("presentacion.csv", fstream::out);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el clientes.csv para escritura");
		}
		SaveFile << "Id,Presentacion";
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en clientes.csv" << e.what() << endl;
	}
}

void Presentacion::leerarchivopresentacion()
{
	try
	{
		//Primero trata de abrir el archivo
		ifstream SaveFile;
		SaveFile.open("presentacion.csv");
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el presentacion.csv");
		}
		//Si se abre, se crean variables auxiliares
		string line;
		PresentacionProduct temporal;
		string header;
		getline(SaveFile, header);
		//Se usa el metodo modifica linea para leer cada linea del archivo
		while (getline(SaveFile, line))
		{
			if (line.empty())
			{
				continue;
			}
			string templine = line;
			templine = ModificaLinea(templine, 1, temporal);
			templine = ModificaLinea(templine, 2, temporal);
			vectorpresentacionl.push_back(temporal);
		}
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al leer el archivo" << e.what() << endl;
	}
	//Las desempaqueta para poder usar las variables mas facil
	for (int i = 0; i < (VectorClientes.size()); i++)
	{
		cout << "ok" << endl;
		PresentacionP.id = vectorpresentacionl[i].id;
		PresentacionP.name = vectorpresentacionl[i].name;
	}
}

void Presentacion::clearpresentacion()
{
	vectorpresentacionl.clear();
}

bool Presentacion::checkvectorpresentacion()
{
	clearpresentacion();
	leerarchivopresentacion();
	if (vectorpresentacionl.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string Presentacion::ModificaLinea(string cadena, int elemento, PresentacionProduct& temporal)
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
	}
	return cadena;
}
