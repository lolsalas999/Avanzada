#include "cliente.h"
#include "usuarios.h"
#include "Venta.h"
#include "reporte_inventario.h"

using namespace std;

void ReporteUsuarios(vector<string> a, vector<string> b);
void Limpiarpantalla();

int main()
{
    Cliente Pruebas;
    Productos PruebaProductos;
    Venta PruebaVenta;
    Presentacion PruebaPresentacion;
    usuario PruebaUsuario;
    ReporteInventario PruebaReporte;
    bool program = true;
    bool programb = true;
    int opc = 0;
    int role = 0;
    string useractual;
    bool check = false;
    vector<string>vectoru;
    vector<string>acciones;

    //Solo se realiza un inicio de sesi�n al principio 
    program = PruebaUsuario.CallLogin(useractual, role);
    if (!program) {
        return 0;
    }

    do {
        programb = true;
        Pruebas.Clear();
        PruebaProductos.ClearProductos();
        PruebaVenta.clearventas();
        PruebaPresentacion.clearpresentacion();
        PruebaUsuario.UsuarioClear();
        Pruebas.ReadArchiveCliente();
        PruebaProductos.leerproductos();
        PruebaVenta.leerVentas();
        PruebaPresentacion.leerarchivopresentacion();
        PruebaUsuario.LeerArchivoUsuario();
        Limpiarpantalla();
        cout << "------WALMAR------" << endl;
        cout << "1. Acceso a Usuarios" << endl;
        cout << "2. Acceso a Clientes" << endl;
        cout << "3. Acceso a Ventas" << endl;
        cout << "4. Acceso a Productos" << endl;
        cout << "5. Ver movimentos" << endl;
        cout << "6. Salir" << endl;
        cout << "A que seccion quiere ingresar: ";
        cin >> opc;
        switch (opc) {
        case 1:
            while (programb)
            {
                Limpiarpantalla();
                cout << "Bienvenido al area de usuarios" << endl;
                cout << "1. Registrar Usuario" << endl;
                cout << "2. Editar Usuario" << endl;
                cout << "3. Ver Usuario" << endl;
                cout << "4. Eliminar Usuario" << endl;
                cout << "5. Salir al menu principal" << endl;
                cout << "Que funcion quiere usar: ";
                cin >> opc;
                switch (opc) {
                case 1:
                    PruebaUsuario.RegistrarUsuario(role, useractual);
                    vectoru.push_back(useractual);
                    acciones.push_back("registro un usuario");
                    break;
                case 2:
                    check = PruebaUsuario.checkvectoruser();
                    if (check == false)
                    {
                        cout << "Por favor registra a un usuario antes" << endl;
                        break;
                    }
                    PruebaUsuario.EditarUsuario(role, useractual);
                    vectoru.push_back(useractual);
                    acciones.push_back("edito un usuario");
                    break;
                case 3:
                    check = PruebaUsuario.checkvectoruser();
                    if (check == false)
                    {
                        cout << "Por favor registra a un usuario antes" << endl;
                        break;
                    }

                    PruebaUsuario.VerUsuarios();
                    vectoru.push_back(useractual);
                    acciones.push_back("vio un usuario");
                    break;
                case 4:
                    check = PruebaUsuario.checkvectoruser();
                    if (check == false)
                    {
                        cout << "Por favor registra a un usuario antes" << endl;
                        break;
                    }
                    PruebaUsuario.EliminarUsuarios(role, useractual);
                    vectoru.push_back(useractual);
                    acciones.push_back("elmino un usuario");
                    break;
                case 5:
                    cout << "Regresando al menu principal" << endl;
                    programb = false;
                    break;
                default:
                    cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                    break;
                }
            }
            break;
        case 2:
            while (programb)
            {
                Limpiarpantalla();
                cout << "Bienvenido al area de clientes" << endl;
                cout << "1. Registrar Cliente" << endl;
                cout << "2. Editar Cliente" << endl;
                cout << "3. Eliminar Cliente" << endl;
                cout << "4. Busqueda Cliente" << endl;
                cout << "5. Salir al menu principal" << endl;
                cout << "Que funcion quiere usar: ";
                cin >> opc;
                switch (opc) {
                case 1:
                    if (role == 4 || role == 2)
                    {
                        Pruebas.RegisterCliente();
                        vectoru.push_back(useractual);
                        acciones.push_back("registro un cliente");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funcion" << endl;
                    }
                    break;
                case 2:
                    check = Pruebas.checkvectorclientes();
                    if (check == false)
                    {
                        cout << "Primero registre un cliente para poder usar esta funcion" << endl;
                        break;
                    }
                    if (role == 4 || role == 2)
                    {
                        Pruebas.EditCliente();
                        vectoru.push_back(useractual);
                        acciones.push_back("edito un cliente");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 3:
                    check = Pruebas.checkvectorclientes();
                    if (check == false)
                    {
                        cout << "Primero registre un cliente para poder usar esta funci�n" << endl;
                        break;
                    }
                    if (role == 4 || role == 2)
                    {
                        Pruebas.BorrarCliente();
                        vectoru.push_back(useractual);
                        acciones.push_back("borro un cliente");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 4:
                    check = Pruebas.checkvectorclientes();
                    if (check == false)
                    {
                        cout << "Primero registre un cliente para poder usar esta funci�n" << endl;
                        break;
                    }
                    if (role == 4 || role == 2)
                    {
                        Pruebas.BusquedaCliente();
                        cout << "Presione cualquier tecla para regresar al menu de clientes..." << endl;
                        cin.ignore();
                        cin.get();
                        vectoru.push_back(useractual);
                        acciones.push_back("busco un cliente");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 5:
                    cout << "Regresando al menu principal" << endl;
                    programb = false;
                    break;
                default:
                    cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                    break;
                }
            }
            break;
        case 3:
            while (programb)
            {
                Limpiarpantalla();
                cout << "Bienvenido al area de ventas" << endl;
                cout << "1. Registrar Venta" << endl;
                cout << "2. Ver Venta" << endl;
                cout << "3. Reporte Productos Vendidos" << endl;
                cout << "4. Salir al menu principal" << endl;
                cout << "Que funcion quiere usar: ";
                cin >> opc;
                switch (opc) {
                case 1:
                    if (role == 4 || role == 1)
                    {
                        PruebaVenta.registrarVenta();
                        vectoru.push_back(useractual);
                        acciones.push_back("realizo una venta");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 2:
                    if (role == 4 || role == 1)
                    {
                        PruebaVenta.verventas();
                        vectoru.push_back(useractual);
                        acciones.push_back("vio las ventas");

                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 3:
                    if (role == 4 || role == 1)
                    {
                        PruebaReporte.GenerarReporteMovimiento();
                        cout << "Presione Enter para continuar" << endl;
                        cin.ignore();
                        cin.get();
                    }
                    break;
                case 4:
                    cout << "Regresando al menu principal" << endl;
                    programb = false;
                    break;
                default:
                    cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                    break;
                }
            }
            break;
        case 4:
            while (programb)
            {
                Limpiarpantalla();
                cout << "Bienvenido al area de productos" << endl;
                cout << "1. Registrar Producto" << endl;
                cout << "2. Buscar Producto" << endl;
                cout << "3. Modificar Producto Cliente" << endl;
                cout << "4. Registrar Presentacion" << endl;
                cout << "5. Ver Inventario" << endl;
                cout << "6. Salir al menu principal" << endl;
                cout << "Que funcion quiere usar: ";
                cin >> opc;
                switch (opc) {
                case 1:
                    check = PruebaPresentacion.checkvectorpresentacion();
                    if (check == false)
                    {
                        cout << "Necesitas registrar una presentacion para poder registrar un producto" << endl;
                        break;
                    }

                    if (role == 4 || role == 2)
                    {
                        PruebaProductos.registrarproducto();
                        vectoru.push_back(useractual);
                        acciones.push_back("registro un producto");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 2:
                    check = PruebaProductos.checkvectorproductos();
                    if (check == false)
                    {
                        cout << "Necesitas al menos un producto registrado" << endl;
                        break;
                    }

                    if (role == 4 || role == 2)
                    {
                        vectoru.push_back(useractual);
                        acciones.push_back("busco un producto");
						vector<string> busqueda = PruebaProductos.buscarproducto();
						cout << "=====Producto=====" << endl;
						cout << "ID: " << busqueda[0] << endl;
						cout << "UPC: " << busqueda[1] << endl;
						cout << "Nombre: " << busqueda[2] << endl;
						cout << "ID Presentacion: " << busqueda[3] << endl;
						cout << "Precio: " << busqueda[4] << endl;
						cout << "Costo: " << busqueda[5] << endl;
						cout << "IVA: " << busqueda[6] << endl;
						cout << "Stock: " << busqueda[7] << endl;
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 3:
                    check = PruebaProductos.checkvectorproductos();
                    if (check == false)
                    {
                        cout << "Necesitas al menos un producto registrado" << endl;
                        break;
                    }
                    if (role == 4 || role == 2)
                    {
                        vectoru.push_back(useractual);
                        acciones.push_back("modifico un producto");
						PruebaProductos.modificarproducto();
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 4:
                    if (role == 4 || role == 2)
                    {
                        PruebaPresentacion.registrarpresentacion();
                        vectoru.push_back(useractual);
                        acciones.push_back("registro una presentacion");
                    }
                    else
                    {
                        cout << "Acceso denegado, no tiene permiso para ver esta funci�n" << endl;
                    }
                    break;
                case 5:
                    if (role == 4 || role == 2)
                    {
                        PruebaReporte.GenerarReporteInventario();
                        cout << "Presione Enter para continuar" << endl;
                        cin.ignore();
                        cin.get();
                    }
                    else
                    {
                        cout << "Usted no tiene permiso para usar esta funci�n" << endl;
                    }
                    break;
                case 6:
                    cout << "Regresando al menu principal" << endl;
                    programb = false;
                    break;
                default:
                    cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                    break;
                }
            }
            break;
        case 5:
            if (role == 4)
            {
                ReporteUsuarios(vectoru, acciones);
                cout << "Presione enter para continuar" << endl;
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "No tiene permiso para usar esta funci�n";
            }
            break;
        case 6:
            cout << "Saliendo del programa..." << endl;
            return 0;
        default:
            cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
            break;
        }
    } while (program);


    return 0;
}

void ReporteUsuarios(vector<string> a, vector<string> b)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << "El usuario " << a[i] << " llevo a cabo la acci�n de " << b[i] << endl;
    }
}

void Limpiarpantalla()
{
    system("cls");
}