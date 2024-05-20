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
`void VerUsuarios();`
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



