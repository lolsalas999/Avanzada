# Programa ERP - Sistema de Ventas
**Objetivo**: Desarrollar una aplicación basada en C++ que utilice interfaz de línea de comandos y archivos
CSV para la gestión de bases de datos. El programa funcionará como un sistema ERP básico diseñado
específicamente para la gestión de ventas, productos y roles de usuario.

**Integrantes** 
- Juan Pablo Ramírez Carlón (ID)
- Ricardo Zerón Del Valle (ID)
- Emilio Rendón Trias (0267019) 

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
`bool LeerArchivoUsuario();`, `bool AdministradorExiste();`, `void LimpiarPantalla();`, `void OrdenarUsuariosPorID();`, `UsuarioClear()` y `void ActualizarArchivoUsuario();` son funciones para el correcto funcionamiento del archivo de los usuarios. 
`ActualizarArchivoUsuario` se llama cada que el archivo se tenga que cambiar.


<ins>**CallLogin():**</ins>
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

<ins>**encriptar() & desencriptar():**</ins>

Función: encriptar
1. Definición de la funciónn
```cpp
string usuario::encriptar(string& password)
```
Esta línea define una función miembro encriptar de la clase usuario, que toma una referencia a una cadena password como parámetro y devuelve una cadena.

2. Copia de la contraseña:
```cpp
string encriptado = password;
```
Se crea una nueva cadena encriptado, inicializada con el valor de password.

3. Bucle de encriptación:
```cpp
for (size_t i = 0; i < encriptado.size(); ++i) {
    encriptado[i] += 3;
}
```
Un bucle for itera a través de cada carácter de la cadena encriptado.
Cada carácter se incrementa en 3 posiciones en la tabla ASCII, encriptando efectivamente la contraseña.

4. Devolución de la contraseña encriptada:

```cpp
return encriptado;
```
Se devuelve la cadena encriptada encriptado.

Función: desencriptar
1. Definición de la función:

```cpp
string usuario::desencriptar(string& password)
```
Esta línea define una función miembro desencriptar de la clase usuario, que toma una referencia a una cadena password como parámetro y devuelve una cadena.

2. Copia de la contraseña:

```cpp
string desencriptado = password;
```
Se crea una nueva cadena desencriptado, inicializada con el valor de password.


3. Bucle de desencriptación:

```cpp
for (size_t i = 0; i < desencriptado.size(); ++i) {
    desencriptado[i] -= 3;
}
```
Un bucle for itera a través de cada carácter de la cadena desencriptado.
Cada carácter se decrementa en 3 posiciones en la tabla ASCII, desencriptando efectivamente la contraseña.

4. Devolución de la contraseña desencriptada:

```cpp
return desencriptado;
```
Se devuelve la cadena desencriptada desencriptado.

- Función encriptar: Esta función toma una cadena de contraseña, desplaza cada carácter 3 posiciones en la tabla ASCII para encriptarla y devuelve la cadena encriptada.
- Función desencriptar: Esta función toma una cadena de contraseña encriptada, desplaza cada carácter 3 posiciones hacia atrás en la tabla ASCII para desencriptarla y devuelve la cadena desencriptada

## **Clase Clientes**:
### Funciones:
> `void setid(int);`
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
>
Hasta aqui son pares de getters y setters para todos los elementos se la estrutura en la clase. Con exepcion de el campo ` gettime` que funciona de la misma manera que `date` en la clase usuarios.

<ins>**void RegisterCliente();**</ins>

1. Definición de la función:

````cpp
void Cliente::RegisterCliente()
````
Esta línea define la función RegisterCliente de la clase Cliente.

2. Inicialización de variables:

````cpp
bool program = true;
bool repeat = false;
ClientesObject.id = ClientesObject.id += 1;`
````
- Se inicializan las variables program y repeat como booleanas.
- Se incrementa el ID del cliente.

3. Entrada y verificación del nombre del cliente:

````cpp
string name = "";
while (program)
{
    cout << "Deme el nombre del nuevo cliente: ";
    cin.ignore();
    getline(cin, name);

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
````
- Solicita al usuario el nombre del nuevo cliente.
- Verifica que el nombre no esté ya en uso en VectorClientes.
- Si el nombre está en uso, solicita otro nombre.
- Si no está en uso, establece el nombre del cliente.

4. Entrada y verificación del RFC:

````cpp
string RFC = "";
program = true;
while (program)
{
    cout << "Deme el RFC del nuevo Cliente: ";
    getline(cin, RFC);
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
````
- Solicita al usuario el RFC del nuevo cliente.
- Verifica que el RFC no esté ya en uso en VectorClientes.
- Si el RFC está en uso, solicita otro RFC.
- Si no está en uso, establece el RFC del cliente.

5. Entrada y verificación de la dirección:
````cpp
string direccion = "";
program = true;
while (program)
{
    cout << "Deme la dirección del nuevo cliente: ";
    getline(cin, direccion);
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
````
- Solicita al usuario la dirección del nuevo cliente.
- Verifica que la dirección no esté ya en uso en VectorClientes.
- Si la dirección está en uso, solicita otra dirección.
- Si no está en uso, establece la dirección del cliente.
  
6. Entrada de la ciudad y el estado:

````cpp
string ciudad = "";
cout << "Deme la ciudad en la que se encuentra el nuevo cliente: ";
getline(cin, ciudad);
setciudad(ciudad);
getciudad();

string estado = "";
cout << "Deme el estado en el que se encuentra el nuevo cliente: ";
getline(cin, estado);
setestado(estado);
getestado();
````
- Solicita al usuario la ciudad y el estado del nuevo cliente.
- Establece la ciudad y el estado del cliente.

5. Entrada y verificación del código postal:

```` cpp
program = true;
string zipcode = "";
while (program)
{
    cout << "Deme el código postal del nuevo cliente: ";
    getline(cin, zipcode);
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
````
- Solicita al usuario el código postal del nuevo cliente.
- Verifica que el código postal no esté ya en uso en VectorClientes.
- Si el código postal está en uso, solicita otro código postal.
- Si no está en uso, establece el código postal del cliente.

7. Guardar los datos del cliente en un archivo CSV:

````cpp
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
````
- Establece la fecha y hora actual para el objeto ClientesObject.
- Intenta abrir el archivo clientes.csv en modo de anexado (append).
- Si no se puede abrir el archivo, lanza una excepción.
- Escribe los datos del cliente en el archivo y cierra el archivo.

8. Solicitar si se quiere registrar otro cliente o regresar al área de clientes:

````cpp
char respuesta;
cout << "Desea registrar otro cliente (S) o regresar al área de clientes (R)? (S/R): ";
cin >> respuesta;
if (respuesta == 'R' || respuesta == 'r')
{
    LimpiarPantalla();
    return;
}
LimpiarPantalla();
````
- Solicita al usuario si desea registrar otro cliente o regresar al área de clientes.
- Si la respuesta es R o r, limpia la pantalla y retorna.
- De lo contrario, limpia la pantalla y permite registrar otro cliente.

Este código define una función RegisterCliente que permite registrar un nuevo cliente. Solicita al usuario los detalles del cliente, verifica que los datos no estén duplicados, y guarda la información en un archivo CSV. Al final, permite al usuario decidir si desea registrar otro cliente o regresar al área de clientes.

>`void CreateClientesArchive();`
`void ReadArchiveCliente();`
`void EditCliente();`
`void BorrarCliente();`
`void SobreEscribirCliente();`
`void BusquedaCliente();`
`int VectorSize();`
`void Clear();`
>
son funciones para el correcto funcionamiento del archivo de los clientes. 

<ins>**void CrearReporteArchivo(); & void RegistrarReporteCliente(string, string):**</ins>

Función: CrearReporteArchivo
1. Definición de la función:

````cpp
void Cliente::CrearReporteArchivo()
````
Esta línea define la función CrearReporteArchivo de la clase Cliente.

2. Apertura del archivo para escritura:

````cpp
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
````
- Se crea un objeto ofstream llamado SaveFile para manejar las operaciones de salida de archivos.
- En un bloque try, se intenta abrir el archivo reporteusuarios.txt en modo de salida (escritura).
- Si el archivo no se puede abrir, se lanza una excepción.
- Si el archivo se abre correctamente, se escribe una línea vacía y se cierra el archivo.
- En el bloque catch, se captura cualquier excepción lanzada y se muestra un mensaje de error en cerr.

Función: RegistrarReporteCliente

1. Definición de la función:

````cpp
void Cliente::RegistrarReporteCliente(string usuario, string accion)
````
Esta línea define la función RegistrarReporteCliente de la clase Cliente, que toma dos parámetros: usuario y accion, ambos de tipo string.

2. Apertura del archivo para anexar datos:

````cpp
ofstream SaveFile;
try
{
    SaveFile.open("reporteusuarios.txt", fstream::app);
    if (!SaveFile)
    {
        throw std::runtime_error("No se pudo abrir el reportesusuarios.txt para escritura");
    }
    SaveFile << endl;
    SaveFile << "El usuario " << usuario << " hizo " << accion << endl;
    SaveFile.close();
}
catch (const std::exception& e)
{
    cerr << "Ocurrio un error al escribir en reporteusuarios.txt" << e.what() << endl;
}
````
- Se crea un objeto ofstream llamado SaveFile para manejar las operaciones de salida de archivos.
- En un bloque try, se intenta abrir el archivo reporteusuarios.txt en modo de anexado (append).
- Si el archivo no se puede abrir, se lanza una excepción.
- Si el archivo se abre correctamente, se escribe una línea vacía y luego se registra la acción del usuario en el formato: "El usuario [usuario] hizo [acción]".
- Se cierra el archivo.
- En el bloque catch, se captura cualquier excepción lanzada y se muestra un mensaje de error en cerr.

Función CrearReporteArchivo: Esta función crea (o limpia) un archivo llamado reporteusuarios.txt. Si el archivo no se puede abrir, se muestra un mensaje de error.
Función RegistrarReporteCliente: Esta función agrega una entrada en reporteusuarios.txt que registra una acción realizada por un usuario. Si el archivo no se puede abrir, se muestra un mensaje de error.
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
>
Hasta aqui son pares de getters y setters para todos los elementod se la estrutura en la clase. 

>`void registrarproducto();`
`void archivoproductos();`
`void leerproductos();`
`vector<string> buscarproducto(string);`
`void modificarproducto(string);`
`void ClearProductos();`
>
son funciones para el correcto funcionamiento del archivo de los productos. 

## **Clase Presentacion**:
### Funciones:
> `Presentacion();`
`void setid(int);`
`int getid();`
`void setname(string);`
`string getname();`
>
Hasta aqui son pares de getters y setters para todos los elementod se la estrutura siguiente. 

<ins>**void registrarpresentacion();**</ins>

1. Definición de la función:

````cpp
void Presentacion::registrarpresentacion()
````
Esta línea define la función registrarpresentacion de la clase Presentacion.

2. Asignación del ID:

````cpp

int id;
if (vectorpresentacionl.size() == 0)
{
    id = 1;
}
else
{
    id = PresentacionP.id + 1;
}
````
Si el vector vectorpresentacionl está vacío, asigna id a 1.
Si el vector no está vacío, asigna id al siguiente valor después del último ID registrado (PresentacionP.id + 1).

3. Entrada del nombre de la presentación:
````cpp
string name;
cout << "Deme el nombre de la presentación del producto a registrar: ";
cin.ignore();
getline(cin, name);
````
Solicita al usuario el nombre de la presentación del producto y lo almacena en la variable name.

4. Asignación del ID y el nombre:

````cpp
Copy code
setid(id);
setname(name);
LimpiarPantalla();
````
Asigna el ID y el nombre utilizando las funciones setid y setname.
Limpia la pantalla.

5. Guardado de los datos en un archivo CSV:

````cpp
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
````
- Intenta abrir el archivo presentacion.csv en modo de anexado.
- Si el archivo no se puede abrir, lanza una excepción.
- Si se abre correctamente, mueve el puntero al final del archivo y agrega una nueva línea con el ID y el nombre de la presentación.
- Cierra el archivo.

Función registrarpresentacion: Esta función registra una nueva presentación de producto. Solicita el nombre de la presentación, asigna un ID único, guarda los datos en un archivo CSV, y maneja cualquier excepción que ocurra durante el proceso de escritura en el archivo.

<ins>**void archivopresentacion();**</ins>

1. Definición de la función:

````cpp
void Presentacion::archivopresentacion()
````
Esta línea define la función archivopresentacion de la clase Presentacion.

2. Creación del archivo CSV con encabezado:

````cpp
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
````
- Intenta abrir el archivo presentacion.csv en modo de salida (escritura).
- Si el archivo no se puede abrir, lanza una excepción.
- Si se abre correctamente, escribe el encabezado "Id,Presentacion" en el archivo.
- Cierra el archivo.
Función archivopresentacion: Esta función crea un archivo CSV con el encabezado "Id,Presentacion" para registrar presentaciones de productos. Maneja cualquier excepción que ocurra durante el proceso de creación del archivo.

`void leerarchivopresentacion();`
`void clearpresentacion();`
son funciones para el correcto funcionamiento del archivo de las precentaciones. 

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
>
Hasta aqui son pares de getters y setters para todos los elementod se la estrutura siguiente. Con exepcion de el campo `DateTime` que funciona de la misma manera que fue explicada en la clase cliente.

<ins>**void registrarVenta();**</ins>

1. Definición de la función:

````cpp
void Venta::registrarVenta()
````
Esta línea define la función registrarVenta de la clase Venta.

2. Preparación para el registro de ventas:

````cpp
LimpiarPantalla();
ClearProductos();
clearventas();
VectorUsuarios.clear();
leerVentas();
ReadArchiveCliente();
LeerArchivoUsuario();
leerproductos();
````
Estas líneas llaman a varias funciones para limpiar datos previos y leer archivos necesarios para el proceso de ventas.

3. Inicialización de variables:

````cpp
char seguir = 's';
bool program = true;
bool found = false;
bool notfound = false;
if (VectorVentas.size() == 0)
{
    venta.id = 1;
}
else
{
    venta.id = venta.id + 1;
}
````
Se inicializan varias variables y se establece el ID de la venta.

4. Proceso de registro de ventas:

````cpp
do {
    cout << "\n==================== Registro de Ventas ====================\n";
    int idCliente = 0;
    while (program)
    {
        cout << "Ingrese el id del cliente: ";
        cin >> idCliente;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < VectorClientes.size(); i++)
        {
            if (VectorClientes[i].id == idCliente)
            {
                found = true;
            }
            else {
                notfound = true;
            }
        }
        if (found == true)
        {
            program = false;
        }
        else if (found == false && notfound == true)
        {
            cout << "No tenemos ese id en nuestra base de datos, por favor ingrese uno que si existe." << endl;
        }
    }
}
````
Se solicita y verifica el ID del cliente.

5. Establecer el ID del cliente:

````cpp
setIdCliente(idCliente);
program = true;
int idEmpleado = 0;

found = false;
notfound = false;

while (program)
{
    cout << "Ingrese el id del Empleado: ";
    cin >> idEmpleado;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < VectorUsuarios.size(); i++)
    {
        if (VectorUsuarios[i].id == idEmpleado)
        {
            found = true;
        }
        else
        {
            notfound = true;
        }
        if (found == true)
        {
            program = false;
        }
        else if (found == false && notfound == true)
        {
            cout << "No tenemos ese id en nuestra base de datos, por favor ingrese uno que si existe." << endl;
        }
    }
}
````
Se solicita y verifica el ID del empleado.

6. Establecer el ID del empleado:

````cpp
setIdEmpleado(idEmpleado);

program = true;
found = false;
notfound = false;
int idsearch;
float priceperunit;
int nameindex;

while (program)
{
    cout << "Ingrese el id del producto a comprar: ";
    cin >> idsearch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < VectorProductos.size(); i++)
    {
        if (VectorProductos[i].id == idsearch)
        {
            found = true;
            priceperunit = VectorProductos[i].price;
            setppu(priceperunit);
            nameindex = i;
        }
        else
        {
            notfound = true;
        }
        if (found == true)
        {
            program = false;
        }
        else if (found == false && notfound == true)
        {
            cout << "No tenemos ese id en nuestra base de datos, por favor ingrese uno que si existe." << endl;
        }
    }

}
````
Se solicita y verifica el ID del producto.

7. Establecer el ID del producto:

````cpp
setidproducto(idsearch);

cout << "El precio por unidad de este producto es: " << priceperunit << endl;

int cant = 0;
program = true;
bool cancelled = false;;

while (program)
{
    cout << "Ingrese la cantidad de productos que desea comprar: ";
    cin >> cant;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (VectorProductos[nameindex].stock < cant || cant <= 0)
    {
        cout << "No tenemos suficiente stock para completar esta venta, cancelando la venta." << endl;
        cancelled = true;
        program = false;
        break;
    }
    else
    {
        VectorProductos[nameindex].stock = VectorProductos[nameindex].stock - cant;
        program = false;
        setcant(cant);
        continue;
    }

}
````
Se solicita la cantidad de productos a comprar y se verifica si hay suficiente stock.

8. Calcular el total y registrar la venta:

````cpp
float total = 0;
if (cancelled == true)
{
    cout << "Venta cancelada" << endl;
}
else {
    total = priceperunit * cant;
    cout << "El total a pagar sera de: " << total << endl;

    setTotalAmount(total);

    venta.date = getDateTime();

    ofstream SaveFile("Ventas.csv", fstream::app);
    if (SaveFile.is_open()) {
        SaveFile << endl;
        SaveFile << venta.id << "," << venta.id_Cliente << "," << venta.id_Empleado << ","
            << venta.idproducto << "," << venta.cant << "," << venta.ppu << "," << venta.total << "," << venta.date << "\n";
        SaveFile.close();
        cout << "Venta registrada con exito.\n";
    }
    else {
        cerr << "Error al abrir el archivo para escritura.\n";
    }
    SaveFile;
    try
    {

        SaveFile.open("Productos.csv", fstream::out);
        if (!SaveFile)

        {
            throw std::runtime_error("No se pudo abrir el Productos.csv para escritura");
        }

        SaveFile << "Id,UPC,Nombre,Id_presentacion,Precio,Costo,IVA,Stock" << endl;

        for (int i = 0; i < VectorProductos.size(); i++)
        {
            SaveFile << VectorProductos[i].id << "," << VectorProductos[i].UPC << "," << VectorProductos[i].name << "," << VectorProductos[i].id_presentacion << "," << VectorProductos[i].price << "," << VectorProductos[i].cost << "," << VectorProductos[i].has_iva << "," << VectorProductos[i].stock << endl;
        }
        SaveFile.close();
    }

    catch (const std::exception& e)
    {
        cerr << "Ocurrio un error al escribir en clientes.csv" << e.what() << endl;
    }

}

cout << "\nDesea registrar otra venta? (s/n): ";
cin >> seguir;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
````

`void archivoVenta();`
`void leerVentas();`
`void clearventas();`

son funciones para el correcto funcionamiento del archivo de las ventas. 
