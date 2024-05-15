#include "ProductoVendido.h"

ProductoVendido::ProductoVendido()
{
	productoVendido.id = 0;
	productoVendido.id_venta = 0;
	productoVendido.id_producto = 0;
	productoVendido.cantidad = 0;
	productoVendido.ppu = 0.0;
}

ProductoVendido::~ProductoVendido()
{
}

int ProductoVendido::getId()
{
	return productoVendido.id;
}

void ProductoVendido::setIdSale(int id)
{
    productoVendido.id_venta = id;
}

int ProductoVendido::getIdSale()
{
	return productoVendido.id_venta;
}

void ProductoVendido::setIdProduct(int id)
{
    productoVendido.id_producto = id;
}

int ProductoVendido::getIdProduct()
{
	return productoVendido.id_producto;
}

void ProductoVendido::setQuantity(int q)
{
    productoVendido.cantidad = q;
}

int ProductoVendido::getQuantity()
{
	return productoVendido.cantidad;
}

void ProductoVendido::setSalePricePerUnit(float price)
{
    productoVendido.ppu = price;

}

float ProductoVendido::getSalePricePerUnit()
{
	return productoVendido.ppu;
}

void ProductoVendido::registrarProductoVendido(Venta venta, Productos p)
{
    leerProductosVendios();
    char seguir = 's';
    do {
        cout << "\n==================== Registro de productos Vendidos ====================\n";
        productoVendido.id = unique_id++;

        
		setIdSale(venta.getIdVenta());

		setIdProduct(p.getid());

        int cantidad;
        cout << "Ingrese cuantos productos se vendieron: ";
        cin >> cantidad;
		setQuantity(cantidad);

        float ppu;
        cout << "Ingrese el precio de cada unidad: $";
        cin >> ppu;
		setSalePricePerUnit(ppu);

        

        ofstream SaveFile("productoVendido.csv", fstream::app);
        if (SaveFile.is_open()) {
            SaveFile << productoVendido.id << "," << productoVendido.id_venta << "," << productoVendido.id_producto << ","
                << productoVendido.cantidad << "," << productoVendido.ppu << "\n";
            SaveFile.close();
            cout << "Producto Vendido registrado con exito.\n";
        }
        else {
            cerr << "Error al abrir el archivo para escritura.\n";
        }
        cout << "\nDesea registrar otro producto? (s/n): ";
        cin >> seguir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (seguir == 's' || seguir == 'S');
}

void ProductoVendido::archivoProductosVendios()
{
    ofstream SaveFile;
    try
    {
        SaveFile.open("productoVendido.csv", fstream::out);
        if (!SaveFile)
        {
            throw std::runtime_error("No se pudo abrir el productoVendido.csv para escritura");
        }
        SaveFile << "Id,Id_Venta,Id_producto,Cantidad,Price_per_unit" << endl;
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrio un error al escribir en productoVendido.csv" << e.what() << endl;
    }
}

void ProductoVendido::leerProductosVendios()
{
    try
    {
        ifstream SaveFile;
        SaveFile.open("productoVendido.csv");
        if (!SaveFile)
        {
            throw std::runtime_error("No se pudo abrir productoVendido.csv");
        }
        string line;
        getline(SaveFile, line); // Omito la primera línea que es el encabezado

        while (getline(SaveFile, line))
        {
            if (line.empty()) continue;// Para evadir las líneas blancas que se crean

            infoProductoVendido temporal;
            string templine = line;
            templine = ModificaLinea(templine, 1, temporal);
            templine = ModificaLinea(templine, 2, temporal);
            templine = ModificaLinea(templine, 3, temporal);
            templine = ModificaLinea(templine, 4, temporal);
            templine = ModificaLinea(templine, 5, temporal);
            VectorVendidos.push_back(temporal);
        }
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrió un error al leer el archivo o no hay un archivo creado todavía: " << e.what() << endl;
    }
    for (int i = 0; i < VectorVendidos.size(); i++)
    {
        productoVendido.id = VectorVendidos[i].id;
        productoVendido.id_venta = VectorVendidos[i].id_venta;
        productoVendido.id_producto = VectorVendidos[i].id_producto;
        productoVendido.cantidad = VectorVendidos[i].cantidad;
        productoVendido.ppu = VectorVendidos[i].ppu;

    }
    //Para probar si está leyendo el archivo correctamente, implemento este ciclo for.
    for (int i = 0; i < VectorVendidos.size(); i++)
    {
        cout << "ID: " << VectorVendidos[i].id
            << ", ID Venta: " << VectorVendidos[i].id_venta
            << ", ID Producto: " << VectorVendidos[i].id_producto
            << ", cantidad vendida: " << VectorVendidos[i].cantidad
            << ", precio por unidad: " << VectorVendidos[i].ppu << endl;

    }
}

string ProductoVendido::ModificaLinea(string cadena, int elemento, infoProductoVendido& temporal)
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
            temporal.id_venta = stoi(value);
            break;
        case 3:
            temporal.id_producto = stoi(value);
            break;
        case 4:
            temporal.cantidad = stoi(value);
            break;
        case 5:
            temporal.ppu = stof(value);
            break;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error al convertir el valor '" << value << "' en el campo " << elemento << ": " << e.what() << endl;
    }
    return cadena;
}