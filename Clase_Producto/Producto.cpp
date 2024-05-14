#include "Producto.h"

Productos::Productos()
{
    Producto.id = 0;
    Producto.UPC = "";
    Producto.name = "";
    Producto.id_presentacion = 0;
    Producto.price = 0;
    Producto.cost = 0;
    Producto.has_iva = false;
    Producto.stock = 0;
}

Productos::~Productos()
{

}

void Productos::setid(int a)
{
    Producto.id = a;
}

int Productos::getid()
{
    return Producto.id;
}

void Productos::setupc(string b)
{
    Producto.UPC = b;
}

string Productos::getupc()
{
    return Producto.UPC;
}

void Productos::setname(string c)
{
    Producto.name = c;
}

string Productos::getname()
{
    return Producto.name;
}

void Productos::setid_presentacion(int d)
{
    Producto.id_presentacion = d;
}

int Productos::getid_presentacion()
{
    return Producto.id_presentacion;
}

void Productos::setprice(float e)
{
    Producto.price = e;
}

float Productos::getprice()
{
    return Producto.price;
}

void Productos::setcost(float f)
{
    Producto.cost = f;
}

float Productos::getcost()
{
    return Producto.cost;
}

void Productos::sethas_iva(bool g)
{
    Producto.has_iva = g;
}

bool Productos::gethas_iva()
{
    return Producto.has_iva;
}


void Productos::setstock(int h)
{
    Producto.stock = h;
}

int Productos::getstock()
{
    return Producto.stock;
}

void Productos::registrarproducto()
{
    leerproductos();
    char seguir = 's';
    do {
        cout << "\n==================== Registro de Producto ====================\n";
        Producto.id = Producto.id += 1;

        string upc;
        cout << "Ingrese el UPC del producto: ";
        getline(cin, upc);
        setupc(upc);

        string name;
        cout << "Ingrese el nombre del producto: ";
        getline(cin, name);
        setname(name);

        int id_presentacion;
        cout << "Ingrese el ID de la presentacion asociada: ";
        cin >> id_presentacion;
        setid_presentacion(id_presentacion);

        float price;
        cout << "Ingrese el precio del producto: $";
        cin >> price;
        setprice(price);

        float cost;
        cout << "Ingrese el costo de produccion del producto: $";
        cin >> cost;
        setcost(cost);

        bool has_iva;
        cout << "El producto incluye IVA? (1 para si, 0 para no): ";
        cin >> has_iva;
        sethas_iva(has_iva);

        int stock;
        cout << "Ingrese el stock del producto: ";
        cin >> stock;
        setstock(stock);

        ofstream SaveFile("Productos.csv", fstream::app);
        if (SaveFile.is_open()) {
            SaveFile << Producto.id << "," << Producto.UPC << "," << Producto.name << ","
                << Producto.id_presentacion << "," << Producto.price << ","
                << Producto.cost << "," << Producto.has_iva << "," << Producto.stock << "\n";
            SaveFile.close();
            cout << "Producto registrado con exito.\n";
        }
        else {
            cerr << "Error al abrir el archivo para escritura.\n";
        }
        cout << "\nDesea registrar otro producto? (s/n): ";
        cin >> seguir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (seguir == 's' || seguir == 'S');
}

void Productos::archivoproductos()
{
    ofstream SaveFile;
    try
    {
        SaveFile.open("Productos.csv", fstream::out);
        if (!SaveFile)
        {
            throw std::runtime_error("No se pudo abrir el Productos.csv para escritura");
        }
        SaveFile << "Id,UPC,Nombre,Id_presentacion,Precio,Costo,IVA,Stock" << endl;
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrio un error al escribir en Productos.csv" << e.what() << endl;
    }
}

void Productos::leerproductos()
{
    try
    {
        ifstream SaveFile;
        SaveFile.open("Productos.csv");
        if (!SaveFile)
        {
            throw std::runtime_error("No se pudo abrir el Productos.csv");
        }
        string line;
        getline(SaveFile, line); // Omito la primera línea que es el encabezado

        while (getline(SaveFile, line))
        {
            if (line.empty()) continue;// Para evadir las líneas blancas que se crean

            infoProducto temporal;
            string templine = line;
            templine = ModificaLinea(templine, 1, temporal);
            templine = ModificaLinea(templine, 2, temporal);
            templine = ModificaLinea(templine, 3, temporal);
            templine = ModificaLinea(templine, 4, temporal);
            templine = ModificaLinea(templine, 5, temporal);
            templine = ModificaLinea(templine, 6, temporal);
            templine = ModificaLinea(templine, 7, temporal);
            templine = ModificaLinea(templine, 8, temporal);
            VectorProductos.push_back(temporal);
        }
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrió un error al leer el archivo o no hay un archivo creado todavía: " << e.what() << endl;
    }
    for (int i = 0; i < VectorProductos.size(); i++)
    {
        Producto.id = VectorProductos[i].id;
        Producto.UPC = VectorProductos[i].UPC;
        Producto.name = VectorProductos[i].name;
        Producto.id_presentacion = VectorProductos[i].id_presentacion;
        Producto.price = VectorProductos[i].price;
        Producto.cost = VectorProductos[i].cost;
        Producto.has_iva = VectorProductos[i].has_iva;
        Producto.stock = VectorProductos[i].stock;

    }
    //Para probar si está leyendo el archivo correctamente, implemento este ciclo for.
    for (int i = 0; i < VectorProductos.size(); i++)
    {
        cout << "ID: " << VectorProductos[i].id
            << ", UPC: " << VectorProductos[i].UPC
            << ", Nombre: " << VectorProductos[i].name
            << ", ID Presentacion: " << VectorProductos[i].id_presentacion
            << ", Precio: " << VectorProductos[i].price
            << ", Costo: " << VectorProductos[i].cost
            << ", IVA: " << (VectorProductos[i].has_iva ? "Si" : "No")
            << ", Stock: " << VectorProductos[i].stock << endl;
    }
}

string Productos::ModificaLinea(string cadena, int elemento, infoProducto& temporal)
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
            temporal.UPC = value;
            break;
        case 3:
            temporal.name = value;
            break;
        case 4:
            temporal.id_presentacion = stoi(value);
            break;
        case 5:
            temporal.price = stof(value);
            break;
        case 6:
            temporal.cost = stof(value);
            break;
        case 7:
            temporal.has_iva = (value == "1");
            break;
        case 8:
            temporal.stock = stoi(value);
            break;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error al convertir el valor '" << value << "' en el campo " << elemento << ": " << e.what() << endl;
    }
    return cadena;
}

