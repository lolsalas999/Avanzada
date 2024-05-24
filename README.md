# Programa ERP - Sistema de Ventas
**Objetivo**: Desarrollar una aplicación basada en C++ que utilice interfaz de línea de comandos y archivos
CSV para la gestión de bases de datos. El programa funcionará como un sistema ERP básico diseñado
específicamente para la gestión de ventas, productos y roles de usuario.

## **Clase Usuario**:
### Funciones:
>`usuario();`
`void setid();`
`int getid();`
`void setnombre(string);`
`string getnombre();`
`void setapellido(string);`
`string getapellido();`
`void setusuario(string);`
`string getusuario();`
`void setpassword(string);`
`string getpassword();`
`void setrol(int);`
`int getrol();`
>
Hasta aqui son pares de getters y setters para todos los elementod se la estrutura siguiente. Con exepcion de el campo `date` que funciona de otra manera y sera explicado por separado.

```cpp
struct UsuariosRegistrados
{
    int id;
    string nombre;
    string apellido;
    string usuario;
    string password;
    int rol;
    string date;
};
```


>
`void RegistrarUsuario(UsuariosRegistrados&);`
`void EditarUsuario(UsuariosRegistrados&);`
`void EliminarUsuarios(UsuariosRegistrados&);`
`bool IniciarSesion(UsuariosRegistrados&);`
>
Estas funciones trabajan con un vector de tipo `<UsuariosRegistrados>`  con el nombre `VectorUsuarios` para cumplir las funciones y guardar los mismos en el archivo scv.

<ins>**Registrar usuario:**</ins>
```cpp
if (usuarioActual.rol != 4) {
	cout << "Acceso denegado. Solo los usuarios con rol administrativo
	pueden registrar nuevos usuarios." << endl;
	return;
}
```
Lo primero es checar si el usurio que esta realizando la tarea tiene los permisos de registrar nuevos usuarios, si no se les niega seguir.

```cpp
//ejemplo:
	cout << "Dame el Nombre del Empleado a registrar: ";
	cin >> nombre;
```
Luego se pide que ingresen los datos del usuario a registrar.

```cpp
	cout << "Estos son los roles disponibles para el empleado: " << endl;
cout << "1. Ventas" << endl;
cout << "2. Administracion" << endl;
cout << "3. Recursos Humanos" << endl;
cout << "4. Admin" << endl;
cout << "Ingrese la opcion deseada para el empleado a registrar: ";
```
Finalmente se assigna un rol dentrop del sitema y este se pasa a un swich el numero leido en el bloque anterior donsde se assinga el rol y se rompe el while donde esta el bloque para assegurarnos que no se salten pasos del ingreso de archivos.


`void VerUsuarios();`
Preimero presenta la funcion presenta la opcion de filtrar o no los usuarios que se mostraran:
```cpp
cout << "Desea filtrar la lista de usuarios? (1: Si, 2: No): ";
if (!(cin >> filtro) || (filtro != 1 && filtro != 2)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor ingrese un número valido (1 o 2)." << endl;
```
Este código solicita al usuario seleccionar un criterio de filtro (1, 2 o 3) y valida la entrada para asegurarse de que sea un número válido dentro del rango especificado. Si el usuario ingresa un valor inválido, se le pide que intente de nuevo hasta que proporcione una entrada correcta.
```cpp
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
```

`string getDateTime();` funciona de la siguiente manera:
```cpp
// current date and time on the current system
time_t now = time(0);
// convert now to string form
char* date_time = ctime(&now);
string date = date_time;
return date;
```
Utilizando `#include <ctime>` `#pragma warning(disable : 4996)` respectivamente son la libreria que se utiliza ara las funciones time y la indicacion al sistema de ignorar el error 4996 puesto que el mismo solo cumple la funcion de informar al usuario que la funcion que esta usando podria etar depreciada. `time(0)` nos devuelve el tiempo actual en segundo lo cual es luego pasado a un string por medio de ctime(&now) que nos devuelve un puntero al string en la forma: `diaDeLaSemana mes Dia horas:minutos:segundos Año.` esta string se deposita en una variable de tipo string para ser mas facil de utilizar.
```cpp
 // current date and time on the current system
 time_t now = time(0);

 // convert now to string form
 char* date_time = ctime(&now);
 string date = date_time;
 return date;
```
`bool LeerArchivoUsuario();`, `bool AdministradorExiste();`, `void LimpiarPantalla();`, `void OrdenarUsuariosPorID();`, `UsuarioClear()` y `void ActualizarArchivoUsuario();` son funciones para el correcto funcionamiento del arcivio de los usuarios. 
`ActualizarArchivoUsuario` se llama cada que el archivo se tenga que cambiar.


### `CallLogin()`
1. Verificación de existencia del archivo usuarios.csv:

```cpp
if (!ifstream("usuarios.csv")) {
```
Se utiliza ifstream para comprobar si el archivo usuarios.csv existe. Si no existe, se ejecuta el bloque de código dentro del if.

2. Mensaje de creación de cuenta de administrador:
```cpp
cout << "Primera vez iniciando el programa. Creando cuenta de administrador por defecto..." << endl;
```
Se muestra un mensaje indicando que se creará una cuenta de administrador por defecto.

3. Configuración de datos del administrador:
```cpp
setnombre("admin");
setapellido("admin");
setusuario("admin");
setpassword("admin");
setrol(4);
setid();
ObjetoUsuarios.date = getDateTime();
```
Se establecen los valores por defecto para la cuenta de administrador utilizando varias funciones set.

4. Agregar el objeto de usuario al vector:
```cpp
VectorUsuarios.push_back(ObjetoUsuarios);
```
Se añade el objeto ObjetoUsuarios al vector VectorUsuarios.

5. Apertura del archivo `usuarios.csv` para escritura:
```cpp
ofstream SaveFile;
try {
    SaveFile.open("usuarios.csv", fstream::out);
    if (!SaveFile) {
        throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
    }
```
Se intenta abrir el archivo `usuarios.csv` en modo escritura. Si falla, se lanza una excepción.

6. Escritura de datos en el archivo:

```cpp
SaveFile << "Id,Nombre,Apellido,Usuario,Password,Rol,Fecha" << endl;
SaveFile << ObjetoUsuarios.id << "," << ObjetoUsuarios.nombre << "," << ObjetoUsuarios.apellido << "," << ObjetoUsuarios.usuario << "," << ObjetoUsuarios.password << "," << ObjetoUsuarios.rol << "," << ObjetoUsuarios.date << endl;
SaveFile.close();
```
Se escribe la cabecera y los datos del administrador en el archivo `usuarios.csv`.

7. Mensajes de confirmación:
```cpp
cout << "Cuenta de administrador creada exitosamente." << endl;
cout << "Usuario: admin" << endl;
cout << "Contrasena: admin" << endl;
```
Se muestran mensajes confirmando la creación exitosa de la cuenta de administrador y proporcionando las credenciales.

8. Manejo de excepciones:
```cpp
catch (const std::exception& e) {
    cerr << "Ocurrio un error al escribir en usuarios.csv: " << e.what() << endl;
}
```
Si ocurre una excepción al escribir en el archivo, se muestra un mensaje de error.

9. Lectura del archivo si ya existe:
```cpp
else {
    LeerArchivoUsuario();
}
```
Si el archivo `usuarios.csv` ya existe, se llama a la función `LeerArchivoUsuario()`.

10. Inicio de sesión:

```cpp
return IniciarSesion(useractual, rol);
```
Finalmente, se llama a la función IniciarSesion con los parámetros useractual y rol.

Este código verifica si el archivo usuarios.csv existe. Si no existe, crea una cuenta de administrador por defecto con las credenciales admin y guarda estos datos en el archivo usuarios.csv. Si el archivo ya existe, simplemente lee los datos de usuarios desde el archivo. Luego, procede a iniciar sesión con las credenciales actuales del usuario.

>
`CallLogin()`
`encriptar()`
`desencriptar`
>

## **Clase Clientes**:
### Funciones:
> `Cliente();`
`void setid(int);`
`int getid();`
`void setname(string);`
`string getname();`
`void setRFC(string);`
`string getRFC();`
`void setfiscalid(int);`
`int getfiscalid();`
`void setdireccion(string);`
`string getdireccion();`
`void setciudad(string);`
`string getciudad();`
`void setestado(string);`
`string getestado();`
`void setzipcode(string);`
`string getzipcode();`
`string gettime();`
`void RegisterCliente();`
`void CreateClientesArchive();`
`void ReadArchiveCliente();`
`void EditCliente();`
`void BorrarCliente();`
`void SobreEscribirCliente();`
`void BusquedaCliente();`
`int VectorSize();`
`void Clear();`
`void CrearReporteArchivo();`
`void RegistrarReporteCliente(string, string);`
>


## **Clase Producto**:
### Funciones:
> `Productos();`
`void setid(int);`
`int getid();`
`void setupc(string);`
`string getupc();`
`void setname(string);`
`string getname();`
`void setid_presentacion(int);`
`int getid_presentacion();`
`void setprice(float);`
`float getprice();`
`void setcost(float);`
`float getcost();`
`void sethas_iva(bool);`
`bool gethas_iva();`
`void setstock(int);`
`int getstock();`
`void registrarproducto();`
`void archivoproductos();`
`void leerproductos();`
`vector<string> buscarproducto(string);`
`void modificarproducto(string);`
`void ClearProductos();`
>

## **Clase Presentacion**:
### Funciones:
> `Presentacion();`
`void setid(int);`
`int getid();`
`void setname(string);`
`string getname();`
`void registrarpresentacion();`
`void archivopresentacion();`
`void leerarchivopresentacion();`
`void clearpresentacion();`
>


## **Clase Venta**:
### Funciones:
> `Venta();`
`int getIdVenta();`
`int getcant();`
`int getppu();`
`void setcant(int);`
`void setppu(int);`
`void setidproducto(int);`
`int getidproducto();`
`void setIdCliente(int id);`
`int getIdCliente();`
`void setIdEmpleado(int id);`
`int getIdEmpleado();`
`void setTotalAmount(float total);`
`float getTotalAmount();`
`string getDateTime();`
`void registrarVenta();`
`void archivoVenta();`
`void leerVentas();`
`void clearventas();`
>


