#include "Venta.h"

Venta::Venta()
{
	venta.id = 0;
    venta.id_Cliente = 0;
	venta.id_Empleado = 0;
	venta.total = 0.0;
	venta.date = "";
}

Venta::~Venta()
{
}

int Venta::getIdVenta()
{
	return venta.id;
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
	leerVentas();
    char seguir = 's';
    do {
        cout << "\n==================== Registro de Ventas ====================\n";
		venta.id = unique_id++;

        int idCliente;
        cout << "Ingrese el id del cliente: ";
        cin >> idCliente;
		setIdCliente(idCliente);

        int idEmpleado;
        cout << "Ingrese el id del Empleado: ";
        cin >> idEmpleado;
		setIdEmpleado(idEmpleado);

        float total;
        cout << "Ingrese el total a pagar: $";
        cin >> total;
		setTotalAmount(total);

		venta.date = getDateTime();

        ofstream SaveFile("Ventas.csv", fstream::app);
        if (SaveFile.is_open()) {
            SaveFile << venta.id << "," << venta.id_Cliente << "," << venta.id_Empleado << ","
                << venta.total << "," << venta.date << "\n";
            SaveFile.close();
            cout << "Venta registrada con exito.\n";
        }
        else {
            cerr << "Error al abrir el archivo para escritura.\n";
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
        SaveFile << "Id,Id_cliente,Id_empleado,Total,Fecha" << endl;
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
        venta.total = VectorVentas[i].total;
        venta.date = VectorVentas[i].date;

    }
    //Para probar si está leyendo el archivo correctamente, implemento este ciclo for.
    for (int i = 0; i < VectorVentas.size(); i++)
    {
        cout << "ID: " << VectorVentas[i].id
            << ", ID Cliente: " << VectorVentas[i].id_Cliente
            << ", ID Empleado: " << VectorVentas[i].id_Empleado
            << ", Total: " << VectorVentas[i].total
            << ", Fecha: " << VectorVentas[i].date << endl;
        
    }
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
            temporal.id_Cliente =stoi(value);
            break;
        case 3:
            temporal.id_Empleado = stoi(value);
            break;
        case 4:
            temporal.total = stof(value);
            break;
        case 5:
            temporal.date = value;
            break;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error al convertir el valor '" << value << "' en el campo " << elemento << ": " << e.what() << endl;
    }
    return cadena;
}
