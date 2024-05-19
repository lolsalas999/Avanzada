#include "Venta.h"

Venta::Venta()
{
    venta.id = 0;
    venta.id_Cliente = 0;
    venta.id_Empleado = 0;
    venta.idproducto = 0;
    venta.cant = 0;
    venta.ppu = 0;
    venta.total = 0;
    venta.date = "";
}

Venta::~Venta()
{
}

int Venta::getIdVenta()
{
    return venta.id;
}

int Venta::getcant()
{
    return venta.cant;
}

int Venta::getppu()
{
    return venta.ppu;
}

void Venta::setcant(int cant)
{
    venta.cant = cant;
}

void Venta::setppu(int ppu)
{
    venta.ppu = ppu;
}

void Venta::setidproducto(int id)
{
    venta.idproducto = id;
}

int Venta::getidproducto()
{
    return venta.idproducto;
}

void Venta::setIdCliente(int id)
{
    venta.id_Cliente = id;
}

int Venta::getIdCliente()
{
    return venta.id_Cliente;
}

void Venta::setIdEmpleado(int id)
{
    venta.id_Empleado = id;
}

int Venta::getIdEmpleado()
{
    return venta.id_Empleado;
}

void Venta::setTotalAmount(float total)
{
    venta.total = total;
}

float Venta::getTotalAmount()
{
    return venta.total;
}

string Venta::getDateTime()
{
    // current date and time on the current system
    time_t now = time(0);

    // convert now to string form
    char* date_time = ctime(&now);
    string date = date_time;
    return date;
}

void Venta::registrarVenta()
{
    Clear();
    ClearProductos();
    clearventas();
    VectorUsuarios.clear();
    leerVentas();
    ReadArchiveCliente();
    LeerArchivoUsuario();
    leerproductos();
    char seguir = 's';
    bool program = true;
    bool found = false;
    bool notfound = false;

    do {
        cout << "\n==================== Registro de Ventas ====================\n";
        cout << VectorVentas.size() << endl;
        if (VectorVentas.size() == 0)
        {
            venta.id = 1;
        }
        else
        {
            venta.id = venta.id + 1;
        }

        int idCliente;
        while (program)
        {
            cout << "Ingrese el id del cliente: ";
            cin >> idCliente;
            for (int i = 0; i < VectorClientes.size(); i++)
            {
                if (VectorClientes[i].id == idCliente)
                {
                    cout << "ok" << endl;
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

        setIdCliente(idCliente);
        program = true;
        int idEmpleado;

        found = false;
        notfound = false;

        while (program)
        {
            cout << "Ingrese el id del Empleado: ";
            cin >> idEmpleado;
            for (int i = 0; i < VectorUsuarios.size(); i++)
            {
                cout << VectorUsuarios[i].id << endl;
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
        setidproducto(idsearch);

        cout << "El precio por unidad de este producto es: " << priceperunit << endl;

        int cant;
        program = true;
        bool cancelled = false;;

        while (program)
        {
            cout << "Ingrese la cantidad de productos que desea comprar: ";
            cin >> cant;


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

        float total;
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

                for (int i = 0; i < VectorClientes.size(); i++)
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

    } while (seguir == 's' || seguir == 'S');
}

void Venta::archivoVenta()
{
    ofstream SaveFile;
    try
    {
        SaveFile.open("Ventas.csv", fstream::out);
        if (!SaveFile)
        {
            throw std::runtime_error("No se pudo abrir el Ventas.csv para escritura");
        }
        SaveFile << "Id,Id_cliente,Id_empleado,Id_Producto,Cantidad,Precio por unidad,Total,Fecha" << endl;
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrio un error al escribir en Ventas.csv" << e.what() << endl;
    }
}

void Venta::leerVentas()
{
    try
    {
        ifstream SaveFile;
        SaveFile.open("Ventas.csv");
        if (!SaveFile)
        {
            throw std::runtime_error("No se pudo abrir Ventas.csv");
        }
        string line;
        getline(SaveFile, line); // Omito la primera línea que es el encabezado

        while (getline(SaveFile, line))
        {
            if (line.empty()) continue;// Para evadir las líneas blancas que se crean

            infoVenta temporal;
            string templine = line;
            templine = ModificaLinea(templine, 1, temporal);
            templine = ModificaLinea(templine, 2, temporal);
            templine = ModificaLinea(templine, 3, temporal);
            templine = ModificaLinea(templine, 4, temporal);
            templine = ModificaLinea(templine, 5, temporal);
            templine = ModificaLinea(templine, 6, temporal);
            templine = ModificaLinea(templine, 7, temporal);
            templine = ModificaLinea(templine, 8, temporal);
            VectorVentas.push_back(temporal);
        }
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrió un error al leer el archivo o no hay un archivo creado todavía: " << e.what() << endl;
    }
    for (int i = 0; i < VectorVentas.size(); i++)
    {
        venta.id = VectorVentas[i].id;
        venta.id_Cliente = VectorVentas[i].id_Cliente;
        venta.id_Empleado = VectorVentas[i].id_Empleado;
        venta.idproducto = VectorVentas[i].idproducto;
        venta.cant = VectorVentas[i].cant;
        venta.ppu = VectorVentas[i].ppu;
        venta.total = VectorVentas[i].total;
        venta.date = VectorVentas[i].date;

    }
    //Para probar si está leyendo el archivo correctamente, implemento este ciclo for.
    for (int i = 0; i < VectorVentas.size(); i++)
    {
        cout << "ID: " << VectorVentas[i].id
            << ", ID Cliente: " << VectorVentas[i].id_Cliente
            << ", ID Empleado: " << VectorVentas[i].id_Empleado
            << ", ID producto: " << VectorVentas[i].idproducto
            << ", Cantidada: " << VectorVentas[i].cant
            << ", Precio por unidad: " << VectorVentas[i].ppu
            << ", Total: " << VectorVentas[i].total
            << ", Fecha: " << VectorVentas[i].date << endl;

    }
}

void Venta::clearventas()
{
    VectorVentas.clear();
}

string Venta::ModificaLinea(string cadena, int elemento, infoVenta& temporal)
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
        cadena = "";
    }
    try {
        switch (elemento)
        {
        case 1:
            temporal.id = stoi(value);
            break;
        case 2:
            temporal.id_Cliente = stoi(value);
            break;
        case 3:
            temporal.id_Empleado = stoi(value);
            break;
        case 4:
            temporal.idproducto = stof(value);
            break;
        case 5:
            temporal.cant = stoi(value);
            break;
        case 6:
            temporal.ppu = stoi(value);
            break;
        case 7:
            temporal.total = stoi(value);
            break;
        case 8:
            temporal.date = value;
            break;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error al convertir el valor '" << value << "' en el campo " << elemento << ": " << e.what() << endl;
    }
    return cadena;
}
