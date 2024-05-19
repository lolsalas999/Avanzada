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

string Cliente::gettime()
{
	// current date and time on the current system
	time_t now = time(0);

	// convert now to string form
	char* date_time = ctime(&now);
	string date = date_time;
	return date;
}

void Cliente::RegisterCliente()
{
	bool program = true;
	bool programb = true;
	bool repeat = false;
	ClientesObject.id = ClientesObject.id += 1;


	string name = "";
	while (program)
	{

		cout << "Deme el nombre del nuevo cliente: ";
		cin >> name;

		for (int i = 0; i < VectorClientes.size(); i++)
		{

			if (name == VectorClientes[i].name)
			{
				cout << "Por favor ingrese un nombre que sea diferente a " << VectorClientes[i].name << endl;
				repeat = true;
			}
		}
		if (repeat == true)
		{
			repeat = false;
			continue;
		}
		else
		{
			program = false;
		}

	}

	setname(name);
	getname();

	string RFC = "";
	program = true;
	while (program)
	{
		cout << "Deme el RFC del nuevo Cliente: ";
		cin >> RFC;
		for (int i = 0; i < VectorClientes.size(); i++)
		{
			if (RFC == VectorClientes[i].RFC)
			{
				cout << "Por favor ingrese un RFC que sea diferente a " << VectorClientes[i].RFC << endl;
				repeat = true;
			}
		}
		if (repeat == true)
		{
			repeat = false;
			continue;
		}
		else
		{
			program = false;
		}

	}
	setRFC(RFC);
	getRFC();

	//placeholder del id del regimen fiscal

	program = true;
	string direccion = "";
	while (program)
	{
		cout << "Deme la dirección del nuevo cliente: ";
		cin >> direccion;

		for (int i = 0; i < VectorClientes.size(); i++)
		{
			if (direccion == VectorClientes[i].direccion)
			{
				cout << "Por favor ingrese una direccion que sea diferente a " << VectorClientes[i].direccion << endl;
				repeat = true;
			}
		}
		if (repeat == true)
		{
			repeat = false;
			continue;
		}
		else
		{
			program = false;
		}
	}


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

	program = true;
	string zipcode = "";
	while (program)
	{
		cout << "Deme el código postal del nuevo cliente: ";
		cin >> zipcode;
		for (int i = 0; i < VectorClientes.size(); i++)
		{
			if (zipcode == VectorClientes[i].zipcode)
			{
				cout << "Por favor ingrese un codigo postal que sea diferente a " << VectorClientes[i].zipcode << endl;
				repeat = true;
			}
		}
		if (repeat == true)
		{
			repeat = false;
			continue;
		}
		else
		{
			program = false;
		}
	}

	setzipcode(zipcode);
	getzipcode();

	ClientesObject.date = gettime();

	ofstream SaveFile;
	try
	{
		SaveFile.open("clientes.csv", fstream::app);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el clientes.csv para escritura");
		}
		SaveFile.seekp(0, ios::end); // Mover el puntero al final del archivo
		SaveFile << endl;
		SaveFile << ClientesObject.id << "," << ClientesObject.name << "," << ClientesObject.RFC << "," << ClientesObject.fiscal_regimen_id << "," << ClientesObject.direccion << "," << ClientesObject.ciudad << "," << ClientesObject.estado << "," << ClientesObject.zipcode << "," << ClientesObject.date << endl;
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
		SaveFile << "Id,Nombre,RFC,Identificador de Regimen Fiscal,Direccion,Ciudad,Estado,Codigo Postal,Fecha Registro";
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
			templine = ModificaLinea(templine, 3, temporal);
			templine = ModificaLinea(templine, 4, temporal);
			templine = ModificaLinea(templine, 5, temporal);
			templine = ModificaLinea(templine, 6, temporal);
			templine = ModificaLinea(templine, 7, temporal);
			templine = ModificaLinea(templine, 8, temporal);
			templine = ModificaLinea(templine, 9, temporal);
			//Las almacena todas en un vector
			VectorClientes.push_back(temporal);
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

void Cliente::EditCliente()
{
	int count = 0;
	int acumid = 0;
	bool program = true;
	bool programb = true;
	bool programc = true;
	bool programd = true;
	bool repeat = false;
	bool found = false;
	bool notfound = false;
	int SearchOption;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Bienvenido a la seccion de modificado de datos del cliente. " << endl;
	cout << "Clientes Registrados actualmente: " << VectorClientes.size() << endl;
	cout << "Por favor seleccione el tipo de dato que quiere cambiar: " << endl;
	while (program)
	{
		programd = true;
		found = false;
		cout << "1. Nombre" << endl;
		cout << "2. RFC" << endl;
		cout << "3. Regimen Fiscal" << endl;
		cout << "4. Ciudad" << endl;
		cout << "5. Estado" << endl;
		cout << "6. Direccion" << endl;
		cout << "7. Codigo Postal" << endl;
		cout << "8. Regresar al menu principal" << endl;
		while (programd)
		{
			cout << "Ingrese su opcion deseada: ";
			cin >> SearchOption;
			if (cin.fail())
			{
				cout << "No puede ingresar una letra." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				programd = false;
			}
		}
		string searchname;
		string searchRFC;
		string searchciudad;
		string searchestado;
		string searchdireccion;
		string searchcodigopostal;
		int searchid;
		vector<int>storeids;
		switch (SearchOption)
		{
		case 1:
			programb = true;
			cout << "Dame el nombre a buscar: ";
			cin >> searchname;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (searchname == VectorClientes[i].name)
				{
					found = true;
					string newname;
					while (programb)
					{
						cout << "Deme el nuevo nombre: ";
						cin >> newname;
						for (int j = 0; j < VectorClientes.size(); j++)
						{
							if (newname == VectorClientes[j].name)
							{
								cout << "El nombre no se puede repetir, por favor ingrese un nombre diferente a: " << VectorClientes[j].name << endl;
								repeat = true;
							}
						}
						if (repeat == true)
						{
							repeat = false;
							continue;
						}
						else
						{
							programb = false;
						}

					}
					VectorClientes[i].name = newname;

				}

			}
			if (found == false)
			{
				cout << "No se encontro ese nombre en nuestra base de datos." << endl;
			}
			else
			{
				SobreEscribirCliente();
			}

			break;

		case 2:
			programb = true;
			cout << "Dame el RFC a buscar: ";
			cin >> searchRFC;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (searchRFC == VectorClientes[i].RFC)
				{
					found = true;
					string newRFC;
					while (programb)
					{
						cout << "Deme el nuevo RFC: ";
						cin >> newRFC;
						for (int j = 0; j < VectorClientes.size(); j++)
						{
							if (newRFC == VectorClientes[j].RFC)
							{
								cout << "El RFC no se puede repetir, por favor ingrese un RFC diferente a: " << VectorClientes[j].RFC << endl;
								repeat = true;
							}
						}
						if (repeat == true)
						{
							repeat = false;
							continue;
						}
						else
						{
							programb = false;
							break;
						}

					}
					VectorClientes[i].RFC = newRFC;
				}

			}
			if (found == false)
			{
				cout << "No se encontro ese RFC" << endl;
			}
			else
			{
				SobreEscribirCliente();
			}
			break;

		case 3:
			break;

		case 4:
			programb = true;
			programc = true;
			cout << "Deme la ciudad a buscar: " << endl;
			cin >> searchciudad;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (searchciudad == VectorClientes[i].ciudad)
				{
					found = true;
					count++;
					storeids.push_back(VectorClientes[i].id);
				}
			}
			if (count > 1)
			{
				cout << "Esta ciudad se repite " << count << " veces" << endl;
				cout << "Por favor escriba de que ID va a querer cambiar su ciudad: " << endl;
				for (int i = 0; i < storeids.size(); i++)
				{
					cout << "ID: " << storeids[i] << endl;
				}
				while (programc)
				{
					cout << "Por favor escriba su opción: ";
					cin >> searchid;
					for (int i = 0; i < storeids.size(); i++)
					{
						if (searchid == storeids[i])
						{
							string newcity;
							cout << "Escriba la nueva ciudad: ";
							cin >> newcity;
							for (int j = 0; j < VectorClientes.size(); j++)
							{
								if (VectorClientes[j].id == searchid)
								{
									cout << "Ok" << endl;
									VectorClientes[j].ciudad = newcity;
									found = true;
									programc = false;
									break;
								}

							}

						}
					}
				}
			}
			else if (count == 1)
			{
				programc = true;
				cout << "La ciudad solo existe una vez, se reemplazará la unica existencia." << endl;
				cout << storeids[0] << endl;
				string newcity;
				while (programc)
				{
					cout << "Escriba la nueva ciudad: ";
					cin >> newcity;
					for (int i = 0; i < VectorClientes.size(); i++)
					{
						if (VectorClientes[i].id == storeids[0])
						{
							VectorClientes[i].ciudad = newcity;
							programc = false;
							break;
						}
					}
				}

			}
			if (found == false)
			{
				cout << "No se encontro esa ciudad" << endl;
			}
			SobreEscribirCliente();
			break;
		case 5:
			programb = true;
			programc = true;
			cout << "Deme el estado a buscar: " << endl;
			cin >> searchestado;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (searchestado == VectorClientes[i].estado)
				{
					found = true;
					count++;
					storeids.push_back(VectorClientes[i].id);
				}
			}
			if (count > 1)
			{
				cout << "Este estado se repite " << count << " veces" << endl;
				cout << "Por favor escriba de que ID va a querer cambiar su Estado: " << endl;
				for (int i = 0; i < storeids.size(); i++)
				{
					cout << "ID: " << storeids[i] << endl;
				}
				while (programc)
				{
					cout << "Por favor escriba su opción: ";
					cin >> searchid;
					for (int i = 0; i < storeids.size(); i++)
					{
						if (searchid == storeids[i])
						{
							string newestado;
							cout << "Escriba el nuevo estado: ";
							cin >> newestado;
							for (int j = 0; j < VectorClientes.size(); j++)
							{
								if (VectorClientes[j].id == searchid)
								{
									cout << "Ok" << endl;
									VectorClientes[j].estado = newestado;
									found = true;
									programc = false;
									break;
								}

							}

						}
					}
				}
			}
			else if (count == 1)
			{
				programc = true;
				cout << "La ciudad solo existe una vez, se reemplazará la unica existencia." << endl;
				cout << storeids[0] << endl;
				string newestado;
				while (programc)
				{
					cout << "Escriba el nueva estado: ";
					cin >> newestado;
					for (int i = 0; i < VectorClientes.size(); i++)
					{
						if (VectorClientes[i].id == storeids[0])
						{
							VectorClientes[i].estado = newestado;
							programc = false;
							break;
						}
					}
				}

			}
			if (found == false)
			{
				cout << "No se encontro el estado" << endl;
			}
			SobreEscribirCliente();
			break;
		case 6:
			programb = true;
			cout << "Deme la direccion a buscar: ";
			cin >> searchdireccion;

			for (int i = 0; i < VectorClientes.size(); i++)
			{

				if (searchdireccion == VectorClientes[i].direccion)
				{

					found = true;
					string newdirection;

					while (programb)
					{
						cout << "Deme la nueva direccion: ";
						cin >> newdirection;

						for (int j = 0; j < VectorClientes.size(); j++)
						{
							if (newdirection == VectorClientes[j].direccion)
							{
								cout << "La direccion no se puede repetir, por favor ingrese una direccion diferente a: " << VectorClientes[j].direccion << endl;
								repeat = true;
							}
						}

						if (repeat == true)
						{
							repeat = false;
							continue;
						}

						else
						{
							programb = false;
						}

					}

					VectorClientes[i].direccion = newdirection;
				}
				if (found = false)
				{
					cout << "No se encontro esta direccion" << endl;
				}
				else
				{
					SobreEscribirCliente();
				}
			}



			break;
		case 7:

			programb = true;

			cout << "Deme el codigo postal a buscar: ";
			cin >> searchcodigopostal;

			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (searchcodigopostal == VectorClientes[i].zipcode)
				{
					found = true;
					string newcodigopostal;

					while (programb)
					{
						cout << "Deme el nuevo codigo postal: ";
						cin >> newcodigopostal;

						for (int j = 0; j < VectorClientes.size(); j++)
						{
							if (newcodigopostal == VectorClientes[j].zipcode)
							{
								cout << "El codigo postal no se puede repetir, por favor ingrese un codigo postal diferente a: " << VectorClientes[j].zipcode << endl;
								repeat = true;
							}
						}

						if (repeat == true)
						{
							repeat = false;
							continue;
						}

						else
						{
							programb = false;
						}

					}

					VectorClientes[i].zipcode = newcodigopostal;
				}

			}
			if (found == false)
			{
				cout << "No se encontro ese codigo postal" << endl;
			}
			else
			{
				SobreEscribirCliente();
			}

			break;

		case 8:

			program = false;
			cout << "Regresando al menu principal" << endl;
			break;

		default:
			cout << "Por favor ingrese una opcion valida" << endl;
		}
	}
}

void Cliente::BorrarCliente()
{
	bool confirmation = false;
	bool error = true;
	bool found = false;
	bool notfound = false;
	int searchopc;
	int Elimopc = 0;
	while (error)
	{
		cout << "Ingrese el id del cliente a borrar, actualmente hay " << VectorClientes.size() << " IDS registrados: ";
		cin >> searchopc;
		if (cin.fail()) {
			cout << "Error! Por favor ingrese un numero y no un hilo" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			error = false;
		}
	}

	for (int i = 0; i < VectorClientes.size(); i++)
	{
		if (VectorClientes[i].id == searchopc)
		{
			found = true;
		}
		else
		{
			notfound = true;
		}

	}

	if (found == true)
	{
		confirmation = true;
	}
	if (found == false && notfound == true)
	{
		cout << "No tenemos ese id en nuestra base de datos." << endl;
	}

	while (confirmation)
	{

		error = true;
		cout << "Estas seguro que lo quieres borrar? " << endl;
		cout << "1. Si" << endl;
		cout << "2. No" << endl;
		while (error)
		{
			cout << "Digite su opcion: ";
			cin >> Elimopc;
			if (cin.fail())
			{
				cout << "Error! Por favor ingrese un numero y no una letra!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				error = false;
			}
		}

		switch (Elimopc)
		{
		case 1:
			cout << "De acuerdo, se eliminó el id " << searchopc << endl;
			if (VectorClientes.size() == 1)
			{
				CreateClientesArchive();
			}
			else
			{
				for (int i = 0; i < VectorClientes.size(); i++)
				{
					if (VectorClientes[i].id == searchopc)
					{
						VectorClientes.erase(VectorClientes.begin() + i);
						SobreEscribirCliente();
					}
				}
			}
			confirmation = false;

			break;
		case 2:
			cout << "De acuerdo no se eliminará nada." << endl;
			confirmation = false;
			break;
		default:
			cout << "Ingrese una opción valida" << endl;
		}
	}


}

void Cliente::SobreEscribirCliente()
{

	ofstream SaveFile;
	try
	{

		SaveFile.open("clientes.csv", fstream::out);
		if (!SaveFile)

		{
			throw std::runtime_error("No se pudo abrir el clientes.csv para escritura");
		}

		SaveFile << "Id,Nombre,RFC,Identificador de Regimen Fiscal,Direccion,Ciudad,Estado,Codigo Postal,Fecha Vencimiento" << endl;

		for (int i = 0; i < VectorClientes.size(); i++)
		{
			SaveFile << VectorClientes[i].id << "," << VectorClientes[i].name << "," << VectorClientes[i].RFC << "," << VectorClientes[i].fiscal_regimen_id << "," << VectorClientes[i].direccion << "," << VectorClientes[i].ciudad << "," << VectorClientes[i].estado << "," << VectorClientes[i].zipcode << "," << VectorClientes[i].date << endl;
		}

		SaveFile.close();
	}

	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en clientes.csv" << e.what() << endl;
	}

}

void Cliente::BusquedaCliente()
{
	bool program = true;
	bool found = false;
	bool notfound = false;
	bool error = true;
	int searchopc = 0;
	int idopc;
	string stringopc;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Bienvenido a la busqueda de Clientes, seleccione el criterio por el cual quiere buscar." << endl;
	cout << "1. Busqueda por id" << endl;
	cout << "2. Busqueda por nombre" << endl;
	cout << "3. Busqueda por ciudad" << endl;
	cout << "4. Busqueda por estado" << endl;
	while (program)
	{
		while (error)
		{
			cout << "Por favor digite la opcion deseada: ";
			cin >> searchopc;
			if (cin.fail())
			{
				cout << "Por favor ingrese un numero y no una letra" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				error = false;
			}
		}
		switch (searchopc)
		{
		case 1:
			error = true;
			while (error)
			{
				cout << "Deme el id a buscar: ";
				cin >> idopc;
				if (cin.fail())
				{
					cout << "Error! Ingrese un numero y no una letra!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
				{
					error = false;
				}
			}

			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (VectorClientes[i].id == idopc)
				{
					found = true;
					cout << "Esta es la informacion relacionada con el id " << idopc << endl;
					cout << "Id: " << VectorClientes[i].id << endl;
					cout << "Nombre: " << VectorClientes[i].name << endl;
					cout << "RFC: " << VectorClientes[i].RFC << endl;
					cout << "Regimen Fiscal: " << VectorClientes[i].fiscal_regimen_id << endl;
					cout << "Direccion: " << VectorClientes[i].direccion << endl;
					cout << "Ciudad: " << VectorClientes[i].ciudad << endl;
					cout << "Estado: " << VectorClientes[i].estado << endl;
					cout << "Codigo Postal: " << VectorClientes[i].zipcode << endl;
					cout << "Fecha: " << VectorClientes[i].date << endl;
					cout << '\n' << endl;
				}
				else
				{
					notfound = true;
				}
			}
			if (notfound == true && found == false)
			{
				cout << "No se encontro ese id en nuestra base de datos, regresando al menu principal." << endl;
			}
			program = false;
			break;
		case 2:
			cout << "Deme el nombre a buscar: ";
			cin >> stringopc;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (VectorClientes[i].name == stringopc)
				{
					found = true;
					cout << "Esta es la informacion relacionada con el nombre " << stringopc << endl;
					cout << "Id: " << VectorClientes[i].id << endl;
					cout << "Nombre: " << VectorClientes[i].name << endl;
					cout << "RFC: " << VectorClientes[i].RFC << endl;
					cout << "Regimen Fiscal: " << VectorClientes[i].fiscal_regimen_id << endl;
					cout << "Direccion: " << VectorClientes[i].direccion << endl;
					cout << "Ciudad: " << VectorClientes[i].ciudad << endl;
					cout << "Estado: " << VectorClientes[i].estado << endl;
					cout << "Codigo Postal: " << VectorClientes[i].zipcode << endl;
					cout << "Fecha: " << VectorClientes[i].date << endl;
					cout << '\n' << endl;
				}
				else
				{
					notfound = true;
				}
			}
			if (notfound == true && found == false)
			{
				cout << "No se encontro ese nombre en nuestra base de datos, regresando al menu principal." << endl;
			}
			program = false;
			break;
		case 3:
			cout << "Deme la ciudad a buscar: ";
			cin >> stringopc;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (VectorClientes[i].ciudad == stringopc)
				{
					found = true;
					cout << "Esta es la informacion relacionada con la ciudad " << stringopc << endl;
					cout << "Id: " << VectorClientes[i].id << endl;
					cout << "Nombre: " << VectorClientes[i].name << endl;
					cout << "RFC: " << VectorClientes[i].RFC << endl;
					cout << "Regimen Fiscal: " << VectorClientes[i].fiscal_regimen_id << endl;
					cout << "Direccion: " << VectorClientes[i].direccion << endl;
					cout << "Ciudad: " << VectorClientes[i].ciudad << endl;
					cout << "Estado: " << VectorClientes[i].estado << endl;
					cout << "Codigo Postal: " << VectorClientes[i].zipcode << endl;
					cout << "Fecha: " << VectorClientes[i].date << endl;
					cout << '\n' << endl;
				}
				else
				{
					notfound = true;
				}
			}
			if (notfound == true && found == false)
			{
				cout << "No se encontro esa ciudad en nuestra base de datos, regresando al menu principal." << endl;
			}
			program = false;
			break;
		case 4:
			cout << "Deme el estado a buscar: ";
			cin >> stringopc;
			for (int i = 0; i < VectorClientes.size(); i++)
			{
				if (VectorClientes[i].estado == stringopc)
				{
					found = true;
					cout << "Esta es la informacion relacionada con el estado " << stringopc << endl;
					cout << "Id: " << VectorClientes[i].id << endl;
					cout << "Nombre: " << VectorClientes[i].name << endl;
					cout << "RFC: " << VectorClientes[i].RFC << endl;
					cout << "Regimen Fiscal: " << VectorClientes[i].fiscal_regimen_id << endl;
					cout << "Direccion: " << VectorClientes[i].direccion << endl;
					cout << "Ciudad: " << VectorClientes[i].ciudad << endl;
					cout << "Estado: " << VectorClientes[i].estado << endl;
					cout << "Codigo Postal: " << VectorClientes[i].zipcode << endl;
					cout << "Fecha: " << VectorClientes[i].date << endl;
					cout << '\n' << endl;
				}
				else
				{
					notfound = true;
				}
			}
			if (notfound == true && found == false)
			{
				cout << "No se encontro ese estado en nuestra base de datos, regresando al menu principal." << endl;
			}
			program = false;
			break;
		default:
			cout << "Escriba una opcion valida del menu" << endl;
		}
	}
}

int Cliente::VectorSize()
{
	int a = 0;
	a = VectorClientes.size();
	return a;
}

void Cliente::Clear()
{
	VectorClientes.clear();
}

void Cliente::CrearReporteArchivo()
{
	ofstream SaveFile;
	try
	{
		SaveFile.open("reporteusuarios.txt", fstream::out);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el reportesusuarios.txt para escritura");
		}
		SaveFile << endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en reporteusuarios.txt" << e.what() << endl;
	}
}

void Cliente::RegistrarReporteCliente(string usuario, string accion)
{
	ofstream SaveFile;
	try
	{
		SaveFile.open("reporteusuarios.txt", fstream::app);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el reportesusuarios.txt para escritura");
		}
		SaveFile << endl;
		SaveFile << "El usuario " << usuario << "hizo " << accion << endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en reporteusuarios.txt" << e.what() << endl;
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
	case 9:
		temporal.date = value;
		break;
	}
	return cadena;
}
