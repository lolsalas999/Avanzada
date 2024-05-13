#include "usuarios.h"

usuario::usuario()
{
	ObjetoUsuarios.id = 0;
	ObjetoUsuarios.nombre = "";
	ObjetoUsuarios.apellido = "";
	ObjetoUsuarios.usuario = "";
	ObjetoUsuarios.password = "";
	ObjetoUsuarios.rol = 0;
}

usuario::~usuario()
{
}

void usuario::setid(int b)
{
	ObjetoUsuarios.id = b;
}

int usuario::getid()
{
	return ObjetoUsuarios.id;
}

void usuario::setnombre(string a)
{
	ObjetoUsuarios.nombre = a;
}

string usuario::getnombre()
{
	return ObjetoUsuarios.nombre;
}

void usuario::setapellido(string c)
{
	ObjetoUsuarios.apellido = c;
}

string usuario::getapellido()
{
	return ObjetoUsuarios.apellido;
}

void usuario::setusuario(string d)
{
	ObjetoUsuarios.usuario = d;
}

string usuario::getusuario()
{
	return ObjetoUsuarios.usuario;
}

void usuario::setpassword(string e)
{
	ObjetoUsuarios.password = e;
}

string usuario::getpassword()
{
	return ObjetoUsuarios.password;
}

void usuario::setrol(int f)
{
	ObjetoUsuarios.rol = f;
}

int usuario::getrol()
{
	return ObjetoUsuarios.rol;
}

void usuario::RegistrarUsuario()
{
	bool program = true;
	string nombre;
	cout << "Dame el Nombre del Empleado a registrar: ";
	cin >> nombre;
	//Placeholder id 
	string apellido;
	cout << "Deme el apellido del Empleado a registrar: ";
	cin >> apellido;
	string usuario;
	cout << "Deme el username del Empleado a registrar: ";
	cin >> usuario;
	string password;
	cout << "Deme el password del Empleado a registrar: ";
	cin >> password;
	int rol;
	cout << "Estos son los roles disponibles para el empleado: " << endl;
	cout << "1. Ventas" << endl;
	cout << "2. Administración" << endl;
	cout << "3. Recursos Humanos" << endl;
	cout << "4. Admin" << endl;
	while (program) 
	{
		cout << "Ingrese la opción deseada para el empleado a registrar: ";
		cin >> rol;
		switch (rol) 
		{
		case 1:
			rol = 1;
			program = false;
			break;
		case 2:
			rol = 2;
			program = false;
			break;
		case 3:
			rol = 3;
			program = false;
			break;
		case 4:
			rol = 4;
			program = false;
			break;
		default:
			cout << "Por favor ingrese una opción valida\n" << endl;
			break;
		}
	}
	setnombre(nombre);
	setapellido(apellido);
	setusuario(usuario);
	setpassword(password);
	setrol(rol);
	getnombre();
	getapellido();
	getusuario();
	getpassword();
	getrol();

	ofstream SaveFile;
	try
	{
		SaveFile.open("usuarios.csv", fstream::app);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
		}
		SaveFile << ObjetoUsuarios.id<< ","<<ObjetoUsuarios.nombre<<","<<ObjetoUsuarios.apellido<<","<<ObjetoUsuarios.usuario<<","<<ObjetoUsuarios.password<<","<<ObjetoUsuarios.rol << endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en usuarios.csv" << e.what() << endl;
	}

}

void usuario::creararchivousuarios()
{
	ofstream SaveFile;
	try
	{
		SaveFile.open("usuarios.csv", fstream::out);
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
		}
		SaveFile << "Id,Nombre,Apellido,Usuario,Password,Rol" << endl;
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al escribir en usuarios.csv" << e.what() << endl;
	}
}

void usuario::LeerArchivoUsuario()
{
	try
	{
		//Primero trata de abrir el archivo
		ifstream SaveFile;
		SaveFile.open("usuarios.csv");
		if (!SaveFile)
		{
			throw std::runtime_error("No se pudo abrir el usuarios.csv");
		}
		//Si se abre, se crean variables auxiliares
		string line;
		UsuariosRegistrados temporal;
		//Se usa el metodo modifica linea para leer cada linea del archivo
		while (getline(SaveFile, line))
		{
			UsuariosRegistrados temporal;
			string templine = line;
			templine = ModificaLinea(templine, 1, temporal);
			templine = ModificaLinea(templine, 2, temporal);
			templine = ModificaLinea(templine, 3, temporal);
			templine = ModificaLinea(templine, 4, temporal);
			templine = ModificaLinea(templine, 5, temporal);
			templine = ModificaLinea(templine, 6, temporal);
			//Las almacena todas en un vector
			VectorUsuarios.push_back(temporal);
		}
		SaveFile.close();
	}
	catch (const std::exception& e)
	{
		cerr << "Ocurrio un error al leer el archivo" << endl;
	}
	//Las desempaqueta para poder usar las variables mas facil
	for (int i = 0; i < VectorUsuarios.size(); i++)
	{
		ObjetoUsuarios.id = VectorUsuarios[i].id;
		ObjetoUsuarios.nombre = VectorUsuarios[i].nombre;
		ObjetoUsuarios.apellido = VectorUsuarios[i].apellido;
		ObjetoUsuarios.usuario = VectorUsuarios[i].usuario;
		ObjetoUsuarios.password = VectorUsuarios[i].password;
		ObjetoUsuarios.rol = VectorUsuarios[i].rol;
	}
}

string usuario::ModificaLinea(string cadena, int elemento, UsuariosRegistrados& temporal)
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
		temporal.nombre = value;
		break;
	case 3:
		temporal.apellido = value;
		break;
	case 4:
		temporal.usuario = stoi(value);
		break;
	case 5:
		temporal.password = value;
		break;
	case 6:
		temporal.rol = stoi(value);
		break;
	}
	return cadena;
}



 
