#include "usuarios.h"

usuario::usuario()
{
	ObjetoUsuarios.id = 0;
	ObjetoUsuarios.nombre = "";
	ObjetoUsuarios.apellido = "";
	ObjetoUsuarios.usuario = "";
	ObjetoUsuarios.password = "";
	ObjetoUsuarios.rol = 0;
	ObjetoUsuarios.date = "";
}

usuario::~usuario()
{
}

void usuario::setid()
{
	if (!VectorUsuarios.empty()) {
		ObjetoUsuarios.id = VectorUsuarios.back().id + 1;
	}
	else {
		ObjetoUsuarios.id = 1;
	}
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


	do {
		bool program = true;
		string nombre, apellido, usuario, password;
		int rol;

		cout << "Dame el Nombre del Empleado a registrar: ";
		cin >> nombre;
		cout << "Deme el apellido del Empleado a registrar: ";
		cin >> apellido;
		cout << "Deme el username del Empleado a registrar: ";
		cin >> usuario;
		cout << "Deme el password del Empleado a registrar: ";
		cin >> password;

		while (program)
		{
			cout << "Estos son los roles disponibles para el empleado: " << endl;
			cout << "1. Ventas" << endl;
			cout << "2. Administracion" << endl;
			cout << "3. Recursos Humanos" << endl;
			cout << "4. Admin" << endl;
			cout << "Ingrese la opcion deseada para el empleado a registrar: ";
			if (!(cin >> rol)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor ingrese un numero valido." << endl;
				continue;
			}
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
				cout << "Por favor ingrese una opcion valida\n" << endl;
				break;
			}
		}
		setnombre(nombre);
		setapellido(apellido);
		setusuario(usuario);
		setpassword(password);
		setrol(rol);
		setid();
		ObjetoUsuarios.date = getDateTime();


		ofstream SaveFile;
		try {
			SaveFile.open("usuarios.csv", fstream::app);
			if (!SaveFile) {
				throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
			}
			SaveFile << ObjetoUsuarios.id << "," << ObjetoUsuarios.nombre << "," << ObjetoUsuarios.apellido << "," << ObjetoUsuarios.usuario << "," << ObjetoUsuarios.password << "," << ObjetoUsuarios.rol << "," << ObjetoUsuarios.date << endl;
			SaveFile.close();
			cout << "Usuario registrado exitosamente." << endl;
		}
		catch (const std::exception& e) {
			cerr << "Ocurrio un error al escribir en usuarios.csv: " << e.what() << endl;
		}

		char respuesta;
		cout << "Desea realizar otra accion de registro (R) o regresar al menu de gestión (M)? (R/M): ";
		cin >> respuesta;
		if (respuesta == 'M' || respuesta == 'm') {
			return;
		}
	} while (true);
}

void usuario::EditarUsuario(UsuariosRegistrados& usuarioActual)
{


	do {
		try {
			LeerArchivoUsuario();
			int idBuscar, indice = -1;
			cout << "Ingrese el ID del usuario que desea editar: ";
			if (!(cin >> idBuscar)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor ingrese un numero valido para el ID." << endl;
				return;
			}

			for (int i = 0; i < VectorUsuarios.size(); i++) {
				if (VectorUsuarios[i].id == idBuscar) {
					indice = i;
					break;
				}
			}

			if (indice == -1) {
				cout << "Usuario no encontrado." << endl;
				return;
			}

			int opc;
			cout << "1. Nombre" << endl;
			cout << "2. Apellido" << endl;
			cout << "3. Nombre de usuario" << endl;
			cout << "4. Contrasena" << endl;
			cout << "5. Rol" << endl;
			cout << "Seleccione el campo que desea editar: ";
			cin >> opc;

			string nuevoValor;
			int nuevoValorInt;

			switch (opc) {
			case 1:
				cout << "Ingrese el nuevo nombre: ";
				cin >> nuevoValor;
				VectorUsuarios[indice].nombre = nuevoValor;
				break;
			case 2:
				cout << "Ingrese el nuevo apellido: ";
				cin >> nuevoValor;
				VectorUsuarios[indice].apellido = nuevoValor;
				break;
			case 3:
				cout << "Ingrese el nuevo nombre de usuario: ";
				cin >> nuevoValor;
				VectorUsuarios[indice].usuario = nuevoValor;
				break;
			case 4:
				cout << "Ingrese la nueva contrasena: ";
				cin >> nuevoValor;
				VectorUsuarios[indice].password = nuevoValor;
				break;
			case 5:
				cout << "Ingrese el nuevo rol (1-Ventas, 2-Administracion, 3-Recursos Humanos, 4-Admin): ";
				if (!(cin >> nuevoValorInt)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Por favor ingrese un numero valido para el rol." << endl;
					return;
				}
				VectorUsuarios[indice].rol = nuevoValorInt;
				break;
			default:
				cout << "Opcion no valida." << endl;
				return;
			}
			ActualizarArchivoUsuario();
			cout << "Usuario editado exitosamente." << endl;
		}
		catch (const std::exception& e) {
			cerr << "Error al editar usuario: " << e.what() << endl;
		}

		char respuesta;
		cout << "Desea realizar otra accion de edición (E) o regresar al menu de gestion (M)? (E/M): ";
		cin >> respuesta;
		if (respuesta == 'M' || respuesta == 'm') {
			return;
		}
	} while (true);
}

void usuario::VerUsuarios()
{
	do {
		try {
			LeerArchivoUsuario();
			int filtro;
			string busqueda;
			int rolBusqueda;

			while (true) {
				cout << "Desea filtrar la lista de usuarios? (1: Si, 2: No): ";
				if (!(cin >> filtro) || (filtro != 1 && filtro != 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Por favor ingrese un número valido (1 o 2)." << endl;
				}
				else {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}

			if (filtro == 1) {
				while (true) {
					cout << "Seleccione el criterio de filtro:" << endl;
					cout << "1. Por Rol" << endl;
					cout << "2. Por Nombre de Usuario" << endl;
					cout << "3. Por Nombre" << endl;
					cout << "Ingrese su opcion: ";
					if (!(cin >> filtro) || (filtro < 1 || filtro > 3)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Por favor ingrese un numero valido (1, 2 o 3)." << endl;
					}
					else {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (filtro) {
				case 1:
					while (true) {
						cout << "Ingrese el rol a buscar (1-Ventas, 2-Administracion, 3-Recursos Humanos, 4-Admin): ";
						if (!(cin >> rolBusqueda) || (rolBusqueda < 1 || rolBusqueda > 4)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Por favor ingrese un numero valido para el rol (1-4)." << endl;
						}
						else {
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							break;
						}
					}
					cout << "Filtrando usuarios por rol: " << rolBusqueda << endl;
					break;
				case 2:
					cout << "Ingrese el nombre de usuario a buscar: ";
					getline(cin, busqueda);
					cout << "Filtrando usuarios por nombre de usuario: " << busqueda << endl;
					break;
				case 3:
					cout << "Ingrese el nombre a buscar: ";
					getline(cin, busqueda);
					cout << "Filtrando usuarios por nombre: " << busqueda << endl;
					break;
				default:
					cout << "Opcion no valida. Mostrando todos los usuarios." << endl;
					filtro = 0;
					break;
				}
			}
			else {
				filtro = 0;
			}

			cout << "Lista de Usuarios:" << endl;
			for (int i = 0; i < VectorUsuarios.size(); i++) {
				bool mostrar = false;
				if (filtro == 0) {
					mostrar = true;
				}
				else if (filtro == 1 && VectorUsuarios[i].rol == rolBusqueda) {
					mostrar = true;
				}
				else if (filtro == 2 && VectorUsuarios[i].usuario == busqueda) {
					mostrar = true;
				}
				else if (filtro == 3 && VectorUsuarios[i].nombre == busqueda) {
					mostrar = true;
				}

				if (mostrar) {
					cout << "ID: " << VectorUsuarios[i].id << ", Nombre: " << VectorUsuarios[i].nombre << ", Apellido: " << VectorUsuarios[i].apellido
						<< ", Usuario: " << VectorUsuarios[i].usuario << ", Rol: " << VectorUsuarios[i].rol << ", Fecha: " << VectorUsuarios[i].date << endl;
				}
			}
		}
		catch (const std::exception& e) {
			cerr << "Error al ver usuarios: " << e.what() << endl;
		}

		char respuesta;
		cout << "Desea realizar otra acción de visualizacion (V) o regresar al menu de gestion (M)? (V/M): ";
		cin >> respuesta;
		if (respuesta == 'M' || respuesta == 'm') {
			return;
		}
	} while (true);
}

void usuario::EliminarUsuarios(UsuariosRegistrados& usuarioActual)
{
	if (usuarioActual.rol != 4) {
		cout << "Acceso denegado. Solo los usuarios con rol administrativo pueden eliminar usuarios." << endl;
		return;
	}

	do {
		try {
			LeerArchivoUsuario();
			int idBuscar;
			cout << "Ingrese el ID del usuario que desea eliminar: ";
			if (!(cin >> idBuscar)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor ingrese un numero valido para el ID." << endl;
				return;
			}

			int indice = -1;
			for (int i = 0; i < VectorUsuarios.size(); i++) {
				if (VectorUsuarios[i].id == idBuscar) {
					indice = i;
					break;
				}
			}

			if (indice == -1) {
				cout << "Usuario no encontrado." << endl;
				return;
			}

			cout << "Usuario a eliminar:" << endl;
			cout << "ID: " << VectorUsuarios[indice].id << ", Nombre: " << VectorUsuarios[indice].nombre << ", Apellido: " << VectorUsuarios[indice].apellido
				<< ", Usuario: " << VectorUsuarios[indice].usuario << ", Rol: " << VectorUsuarios[indice].rol << ", Fecha: " << VectorUsuarios[indice].date << endl;

			char confirmacion;
			cout << "Esta seguro que desea eliminar este usuario? (S/N): ";
			cin >> confirmacion;

			if (confirmacion == 'S' || confirmacion == 's') {
				VectorUsuarios.erase(VectorUsuarios.begin() + indice);
				ActualizarArchivoUsuario();
				cout << "Usuario eliminado exitosamente." << endl;
			}
			else {
				cout << "Eliminacion cancelada." << endl;
			}
		}
		catch (const std::exception& e) {
			cerr << "Error al eliminar usuario: " << e.what() << endl;
		}

		char respuesta;
		cout << "Desea realizar otra acción de eliminación (L) o regresar al menu de gestión (M)? (L/M): ";
		cin >> respuesta;
		if (respuesta == 'M' || respuesta == 'm') {
			return;
		}
	} while (true);
}

void usuario::gestionarUsuarios()
{
	string xd;
	if (!ifstream("usuarios.csv")) {
		cout << "Primera vez iniciando el programa. Creando cuenta de administrador por defecto..." << endl;
		setnombre("admin");
		setapellido("admin");
		setusuario("admin");
		setpassword("admin");
		setrol(4);
		setid();
		ObjetoUsuarios.date = getDateTime();

		VectorUsuarios.push_back(ObjetoUsuarios);

		ofstream SaveFile;
		try {
			SaveFile.open("usuarios.csv", fstream::out);
			if (!SaveFile) {
				throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
			}
			SaveFile << "Id,Nombre,Apellido,Usuario,Password,Rol,Fecha" << endl;
			SaveFile << ObjetoUsuarios.id << "," << ObjetoUsuarios.nombre << "," << ObjetoUsuarios.apellido << "," << ObjetoUsuarios.usuario << "," << ObjetoUsuarios.password << "," << ObjetoUsuarios.rol << "," << ObjetoUsuarios.date << endl;
			SaveFile.close();
			cout << "Cuenta de administrador creada exitosamente." << endl;
			cout << "Usuario: admin" << endl;
			cout << "Contrasena: admin" << endl;
		}
		catch (const std::exception& e) {
			cerr << "Ocurrio un error al escribir en usuarios.csv: " << e.what() << endl;
		}
	}
	else {
		LeerArchivoUsuario();
	}

	UsuariosRegistrados usuarioActual;
	if (!IniciarSesion(usuarioActual, xd)) {
		cout << "Nombre de usuario o contrasena incorrectos. Saliendo del programa..." << endl;
		return;
	}

	int opc;
	bool continuar = true;

	while (continuar) {
		LeerArchivoUsuario();
		cout << "Bienvenido al sistema de gestion de usuarios" << endl;
		cout << "1. Registrar nuevo usuario" << endl;
		cout << "2. Editar usuario existente" << endl;
		cout << "3. Ver todos los usuarios" << endl;
		cout << "4. Eliminar usuario" << endl;
		cout << "5. Salir" << endl;
		cout << "Por favor, elija una opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			RegistrarUsuario();
			break;
		case 2:
			EditarUsuario(usuarioActual);
			break;
		case 3:
			VerUsuarios();
			break;
		case 4:
			EliminarUsuarios(usuarioActual);
			break;
		case 5:
			continuar = false;
			cout << "Saliendo del sistema de gestión de usuarios..." << endl;
			break;
		default:
			cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
			break;
		}
	}
}

bool usuario::LeerArchivoUsuario()
{
	VectorUsuarios.clear();
	try {
		ifstream SaveFile("usuarios.csv");
		if (!SaveFile) {
			return false;
		}
		string line;
		UsuariosRegistrados temporal;
		string header;
		getline(SaveFile, header);
		while (getline(SaveFile, line)) {
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
			VectorUsuarios.push_back(temporal);
		}
		SaveFile.close();
		OrdenarUsuariosPorID();
		return true;
	}
	catch (const std::exception& e) {
		cerr << "Ocurrio un error al leer el archivo: " << e.what() << endl;
		return false;
	}
	for (int i = 0; i < (VectorUsuarios.size()); i++)
	{
		ObjetoUsuarios.id = VectorUsuarios[i].id;
		ObjetoUsuarios.nombre = VectorUsuarios[i].nombre;
		ObjetoUsuarios.apellido = VectorUsuarios[i].apellido;
		ObjetoUsuarios.usuario = VectorUsuarios[i].usuario;
		ObjetoUsuarios.password = VectorUsuarios[i].password;
		ObjetoUsuarios.rol = VectorUsuarios[i].rol;
		ObjetoUsuarios.date = VectorUsuarios[i].date;
	}
}

void usuario::ActualizarArchivoUsuario()
{
	ofstream SaveFile("usuarios.csv");
	SaveFile << "Id,Nombre,Apellido,Usuario,Password,Rol,Fecha" << endl;

	//Ciclo for para sobreescribir todo el archivo
	for (int i = 0; i < VectorUsuarios.size(); i++) {
		SaveFile << VectorUsuarios[i].id << ","
			<< VectorUsuarios[i].nombre << ","
			<< VectorUsuarios[i].apellido << ","
			<< VectorUsuarios[i].usuario << ","
			<< VectorUsuarios[i].password << ","
			<< VectorUsuarios[i].rol << ","
			<< VectorUsuarios[i].date << endl;
	}
	SaveFile.close();
}

bool usuario::IniciarSesion(UsuariosRegistrados& usuarioActual, string& user)
{
	string username, password;
	int intentos = 0;
	const int maxIntentos = 4;

	while (intentos < maxIntentos) {
		cout << "----------------------------------------" << endl;
		cout << "Bienvenido al menu de inicio de sesion" << endl;
		cout << "----------------------------------------" << endl;

		cout << "Ingrese su nombre de usuario: ";
		cin >> username;
		cout << "Ingrese su contrasena: ";
		cin >> password;

		for (int i = 0; i < VectorUsuarios.size(); i++) {
			if (VectorUsuarios[i].usuario == username && VectorUsuarios[i].password == password) {
				usuarioActual = VectorUsuarios[i];
				cout << "----------------------------------------" << endl;
				cout << "Inicio de sesion exitoso. Bienvenido, " << usuarioActual.nombre << "." << endl;
				cout << "----------------------------------------" << endl;
				user = username;
				return true;
			}
		}

		intentos++;
		cout << "----------------------------------------" << endl;
		cout << "Nombre de usuario o contrasena incorrectos. Intente de nuevo." << endl;
		cout << "Intentos restantes: " << maxIntentos - intentos << endl;

		if (intentos == maxIntentos - 1) {
			cout << "----------------------------------------" << endl;
			cout << "Advertencia: Si falla el proximo intento, el programa se cerrara por seguridad." << endl;
		}

		cout << "----------------------------------------" << endl;
	}

	cout << "Demasiados intentos fallidos. El programa se cerrara por seguridad." << endl;
	return false;
}

bool usuario::AdministradorExiste()
{
	LeerArchivoUsuario();
	for (int i = 0; i < VectorUsuarios.size(); i++) {
		if (VectorUsuarios[i].rol == 4) {
			return true;
		}
	}
	return false;
}

string usuario::getDateTime()
{
	// current date and time on the current system
	time_t now = time(0);
	// convert now to string form
	char* date_time = ctime(&now);
	string date = date_time;
	return date;
}

void usuario::LimpiarPantalla()
{
	system("cls");
}

void usuario::OrdenarUsuariosPorID()
{
	for (size_t i = 0; i < VectorUsuarios.size() - 1; ++i) {
		for (size_t j = 0; j < VectorUsuarios.size() - i - 1; ++j) {
			if (VectorUsuarios[j].id > VectorUsuarios[j + 1].id) {
				// Intercambiar los elementos manualmente
				UsuariosRegistrados temp = VectorUsuarios[j];
				VectorUsuarios[j] = VectorUsuarios[j + 1];
				VectorUsuarios[j + 1] = temp;
			}
		}
	}
}

void usuario::UsuarioClear()
{
	VectorUsuarios.clear();
}

bool usuario::CallLogin(string& user)
{
	if (!ifstream("usuarios.csv")) {
		cout << "Primera vez iniciando el programa. Creando cuenta de administrador por defecto..." << endl;
		setnombre("admin");
		setapellido("admin");
		setusuario("admin");
		setpassword("admin");
		setrol(4);
		setid();
		ObjetoUsuarios.date = getDateTime();

		VectorUsuarios.push_back(ObjetoUsuarios);

		ofstream SaveFile;
		try {
			SaveFile.open("usuarios.csv", fstream::out);
			if (!SaveFile) {
				throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
			}
			SaveFile << "Id,Nombre,Apellido,Usuario,Password,Rol,Fecha" << endl;
			SaveFile << ObjetoUsuarios.id << "," << ObjetoUsuarios.nombre << "," << ObjetoUsuarios.apellido << "," << ObjetoUsuarios.usuario << "," << ObjetoUsuarios.password << "," << ObjetoUsuarios.rol << "," << ObjetoUsuarios.date << endl;
			SaveFile.close();
			cout << "Cuenta de administrador creada exitosamente." << endl;
			cout << "Usuario: admin" << endl;
			cout << "Contrasena: admin" << endl;
		}
		catch (const std::exception& e) {
			cerr << "Ocurrio un error al escribir en usuarios.csv: " << e.what() << endl;
		}
	}
	else {
		LeerArchivoUsuario();
	}

	UsuariosRegistrados usuarioActual;
	if (!IniciarSesion(usuarioActual, user)) {
		cout << "Nombre de usuario o contrasena incorrectos. Saliendo del programa..." << endl;
		return false;
	}
}

int usuario::GetRole(string user)
{
	int a = 0;
	LeerArchivoUsuario();
	for (int i = 0; i < VectorUsuarios.size(); i++)
	{
		if (user == VectorUsuarios[i].usuario)
		{
			a = VectorUsuarios[i].rol;
		}
	}
	return a;
}

void usuario::callRegister()
{
	RegistrarUsuario();
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
		temporal.usuario = value;
		break;
	case 5:
		temporal.password = value;
		break;
	case 6:
		temporal.rol = stoi(value);
		break;
	case 7:
		temporal.date = value;
		break;
	}
	return cadena;
}