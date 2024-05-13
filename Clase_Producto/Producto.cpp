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
    char seguir = 's';
    do {
        cout << "\n==================== Registro de Producto ====================\n";
        int id;
        cout << "Ingrese el ID del producto (solo números): ";
        while (!(cin >> id) || id < 0) {
            cout << "ID no válido. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        setid(id);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string upc;
        cout << "Ingrese el UPC del producto: ";
        getline(cin, upc);
        setupc(upc);

        string name;
        cout << "Ingrese el nombre del producto: ";
        getline(cin, name);
        setname(name);

        int id_presentacion;
        cout << "Ingrese el ID de la presentación asociada: ";
        cin >> id_presentacion;
        setid_presentacion(id_presentacion);

        float price;
        cout << "Ingrese el precio del producto: $";
        cin >> price;
        setprice(price);

        float cost;
        cout << "Ingrese el costo de producción del producto: $";
        cin >> cost;
        setcost(cost);

        bool has_iva;
        cout << "¿El producto incluye IVA? (1 para sí, 0 para no): ";
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
        }
        else {
            cerr << "Error al abrir el archivo para escritura.\n";
        }

        cout << "Producto registrado con éxito.\n";
        cout << "\n¿Desea registrar otro producto? (s/n): ";
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
            throw std::runtime_error("No se pudo abrir el usuarios.csv para escritura");
        }
        SaveFile << "Id,UPC,Nombre,Id_presentacion,Precio,Costo,IVA,Stock" << endl;
        SaveFile.close();
    }
    catch (const std::exception& e)
    {
        cerr << "Ocurrio un error al escribir en usuarios.csv" << e.what() << endl;
    }
}