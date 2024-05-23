#include "cliente.h";
#include "usuarios.h";
#include "Venta.h";

using namespace std;

int main()
{
    Cliente Pruebas;
    Productos PruebaProductos;
    Venta PruebaVenta;
    Presentacion PruebaPresentacion;
    usuario PruebaUsuario;
    bool program = true;
    int opc = 0;
    int role = 0;
    string useractual;

    while (program) {
        program = PruebaUsuario.CallLogin(useractual, role);
        if (!program) {
            break;
        }
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

        cout << "------WALMAR------" << endl;
        cout << "1. Acceso a Usuarios" << endl;
        cout << "2. Acceso a Clientes" << endl;
        cout << "3. Acceso a Ventas" << endl;
        cout << "4. Acceso a Productos" << endl;
        cout << "A que seccion quiere ingresar: ";
        cin >> opc;
        switch (opc) {
        case 1:
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
                break;
            case 2:
                PruebaUsuario.EditarUsuario(role, useractual);
                break;
            case 3:
                PruebaUsuario.VerUsuarios();
                break;
            case 4:
                PruebaUsuario.EliminarUsuarios(role, useractual);
                break;
            case 5:
                break;
            default:
                cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                break;
            }
            break;
        case 2:
            break;
        default:
            cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
            break;
        }
    }


    //	cout << "1. Register Cliente" << endl;
    //	cout << "2. Edit Cliente" << endl;
    //	cout << "3.Busqueda Cliente" << endl;
    //	cout << "4. Eliminar Cliente" << endl;
    //	cout << "5. Registrar Producto" << endl;
    //	cout << "6. Realizar Venta" << endl;
    //	cout << "7. Registrar Presentacion" << endl;
    //	cout << "8. Terminar" << endl;
    //	cout << "Digite su opcion deseada: ";
    //	while (fail)
    //	{
    //		cin >> opc;
    //		if (cin.fail()) 
    //		{
    //			cout << "Error! Por favor no ingrese una letra!" << endl;
    //			cin.clear();
    //			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //		}
    //		else 
    //		{
    //			fail = false;
    //		}
    //	}
    //	switch (opc)
    //	{
    //	case 1:
    //		Pruebas.RegisterCliente();
    //		break;
    //	case 2:
    //		Pruebas.EditCliente();
    //		break;
    //	case 3:
    //		Pruebas.BusquedaCliente();
    //		break;
    //	case 4:
    //		Pruebas.BorrarCliente();
    //		break;
    //	case 5:
    //		PruebaProductos.registrarproducto();
    //		break;
    //	case 6:
    //		PruebaVenta.registrarVenta();
    //		break;
    //	case 7:
    //		PruebaPresentacion.registrarpresentacion();
    //		break;
    //	case 8:
    //		program = false;
    //		break;
    //	default:
    //		cout << "Ingrese una opcion valida" << endl;
    //		break;
    //	}
    //}
}