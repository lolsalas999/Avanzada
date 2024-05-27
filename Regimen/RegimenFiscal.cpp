#include "RegimenFiscal.h"

Regimen::Regimen()
{
}

Regimen::~Regimen()
{
}

void Regimen::LeerArchivoRegimen()
{
	try
	{
		//Primero trata de abrir el archivo
		ifstream SaveFile;
		SaveFile.open("regimen.csv");
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el regimen.csv");
		}
		//Si se abre, se crean variables auxiliares
		string line;
		RegimenFiscal temporal;
		string header;
		getline(SaveFile, header);
		//Se usa el metodo modifica linea para leer cada linea del archivo
		while (getline(SaveFile, line))
		{
			if (line.empty())
			{
				continue;
			}
			RegimenFiscal temporal;
			string templine = line;
			templine = ModificaLinea(templine, 1, temporal);
			templine = ModificaLinea(templine, 2, temporal);
			templine = ModificaLinea(templine, 3, temporal);
			//Las almacena todas en un vector
			VectorRegimen.push_back(temporal);
		}
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al leer el archivo" << e.what() << endl;
	}
	//Las desempaqueta para poder usar las variables mas facil
	for (int i = 0; i < VectorRegimen.size(); i++)
	{
		ObjetoRegimen.id = VectorRegimen[i].id;
		ObjetoRegimen.code = VectorRegimen[i].code;
		ObjetoRegimen.descripcion = VectorRegimen[i].descripcion;

	}
}


string Regimen::ModificaLinea(string cadena, int elemento, RegimenFiscal& temporal)
{
	{
		size_t pos = cadena.find(',');
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
			temporal.code = stoi(value);
			break;
		case 3:
			temporal.descripcion = value;
			break;
		}
		return cadena;
	}
}
