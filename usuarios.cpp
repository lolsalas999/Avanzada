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
	int id;
	cout << "Deme el id del Empleado a registrar: ";
	cin >> id;
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
	setid(id);
	setusuario(usuario);
	setpassword(password);
	setrol(rol);
	getnombre();
	getapellido();
	getid();
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



 
