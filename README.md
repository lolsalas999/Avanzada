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
	cout << "Acceso denegado. Solo los usuarios con rol administrativo pueden registrar nuevos usuarios." << endl;
	return;
}
```
Lo primero es checar si el usurio que esta realizando la tarea tiene los permisos de registrar nuevos usuarios, si no se les niega seguir.

```cpp
	cout << "Dame el Nombre del Empleado a registrar: ";
	cin >> nombre;
	cout << "Deme el apellido del Empleado a registrar: ";
	cin >> apellido;
	cout << "Deme el username del Empleado a registrar: ";
	cin >> usuario;
	cout << "Deme el password del Empleado a registrar: ";
	cin >> password;
```
Luego se pide que ingresen los datos del usuario a registrar.

```cpp
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
```
Finalmente se assigna un rol dentrop del sitema y este se pasa a un swich el numero leido en el bloque anterior donsde se assinga el rol y se rompe el while donde esta el bloque para assegurarnos que no se salten pasos del ingreso de archivos.


>`void VerUsuarios();`
`void gestionarUsuarios();`
`bool LeerArchivoUsuario();`
`void ActualizarArchivoUsuario();`
`bool AdministradorExiste();`
`string getDateTime();`
`void LimpiarPantalla();`
`void OrdenarUsuariosPorID();`
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



