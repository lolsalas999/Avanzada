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
    vectorpresentacionl.clear();
    leerarchivopresentacion();
    char seguir = 's';
    do {
        LimpiarPantalla();
        cout << "\n==================== Registro de Producto ====================\n";
        Producto.id = Producto.id += 1;

        string upc;
        cout << "Ingrese el UPC del producto: ";
        cin.ignore();
        getline(cin, upc);
        setupc(upc);

        string name;
        cout << "Ingrese el nombre del producto: ";
        getline(cin, name);
        setname(name);

        // Mostrar presentaciones disponibles
        cout << "\nPresentaciones disponibles:\n";
        for (const auto& presentacion : vectorpresentacionl) {
            cout << "ID: " << presentacion.id << ", Nombre: " << presentacion.name << endl;
        }

        int id_presentacion = 0;
        bool id_presentacion_valido = false;
        while (!id_presentacion_valido)
        {
            cout << "Ingrese el ID de la presentacion asociada: ";
            cin >> id_presentacion;
            if (cin.fail()) {
                cout << "Por favor ingrese un número válido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            for (const auto& presentacion : vectorpresentacionl)
            {
                if (presentacion.id == id_presentacion)
                {
                    id_presentacion_valido = true;
                    break;
                }
            }
            if (!id_presentacion_valido)
            {
                cout << "Por favor ingrese un id existente de presentacion" << endl;
            }
        }
        setid_presentacion(id_presentacion);

        float price;
        cout << "Ingrese el precio del producto: $";
        cin >> price;
        while (cin.fail() || price < 0) {
            cout << "Por favor ingrese un precio válido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> price;
        }
        setprice(price);

        float cost;
        cout << "Ingrese el costo de produccion del producto: $";
        cin >> cost;
        while (cin.fail() || cost < 0) {
            cout << "Por favor ingrese un costo válido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> cost;
        }
        setcost(cost);

        bool has_iva;
        cout << "El producto incluye IVA? (1 para si, 0 para no): ";
        cin >> has_iva;
        while (cin.fail() || (has_iva != 0 && has_iva != 1)) {
            cout << "Por favor ingrese 1 para sí o 0 para no." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> has_iva;
        }
        sethas_iva(has_iva);

        int stock;
        cout << "Ingrese el stock del producto: ";
        cin >> stock;
        while (cin.fail() || stock < 0) {
            cout << "Por favor ingrese un stock válido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> stock;
        }
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
}

vector<string> Productos::buscarproducto()
{
    vector<string> resultado;
    string file_name = "Productos.csv";
    ifstream SaveFile;
    SaveFile.open(file_name);
    bool found = false;
    string field1, field2, field3, field4, field5, field6, field7, field8;
    string search;
    cout << "Ingrese el UPC del producto a buscar: ";
    cin >> search;
    while (getline(SaveFile, field1, ',') && !found)
    {
        getline(SaveFile, field2, ',');
        getline(SaveFile, field3, ',');
        getline(SaveFile, field4, ',');
        getline(SaveFile, field5, ',');
        getline(SaveFile, field6, ',');
        getline(SaveFile, field7, ',');
        getline(SaveFile, field8, '\n');
        if (field2 == search)
        {
            found = true;
            resultado.push_back(field1);
            resultado.push_back(field2);
            resultado.push_back(field3);
            resultado.push_back(field4);
            resultado.push_back(field5);
            resultado.push_back(field6);
            resultado.push_back(field7);
            resultado.push_back(field8);
        }
    }
    return resultado;
}

void Productos::modificarproducto()
{
    string file_name = "Productos.csv";
    int line_number = 0;
    fstream read_file;
    read_file.open(file_name);
    string search;
    cout << "Ingrese el UPC del producto a modificar: ";
    cin.ignore();
    getline(cin, search);
    if (read_file.fail()) {
        cout << "Error abrir el archivo" << endl;
    }
    else {
        vector<string> lines;
        string line;
        while (getline(read_file, line)) {
            lines.push_back(line);
        }
        read_file.close();
        vector<string> resultado;
        ifstream SaveFile;
        SaveFile.open(file_name);
        bool found = false;
        string field1, field2, field3, field4, field5, field6, field7, field8;
        while (getline(SaveFile, field1, ',') && !found)
        {
            line_number++;
            getline(SaveFile, field2, ',');
            getline(SaveFile, field3, ',');
            getline(SaveFile, field4, ',');
            getline(SaveFile, field5, ',');
            getline(SaveFile, field6, ',');
            getline(SaveFile, field7, ',');
            getline(SaveFile, field8, '\n');
            if (field2 == search)
            {
                found = true;
                resultado.push_back(field1);
                resultado.push_back(field2);
                resultado.push_back(field3);
                resultado.push_back(field4);
                resultado.push_back(field5);
                resultado.push_back(field6);
                resultado.push_back(field7);
                resultado.push_back(field8);
            }
        }
        int choice;
        if (found)
        {
            do {
                LimpiarPantalla();
                cout << endl;
                cout << "==================== Modificar Producto ====================\n";
                cout << "1. ID" << endl;
                cout << "2. Nombre" << endl;
                cout << "3. Id Presentacion" << endl;
                cout << "4. Precio" << endl;
                cout << "5. Costo" << endl;
                cout << "6. IVA" << endl;
                cout << "7. Stock" << endl;
                cout << "0. Quit" << endl;
                cin >> choice;
                cin.ignore();
                switch (choice)
                {
                case 1:
                    cout << "Nuevo ID: ";
                    getline(cin, resultado[0]);
                    break;
                case 2:
                    cout << "Nuevo nombre: ";
                    getline(cin, resultado[2]);
                    break;
                case 3:
                    cout << "Nuevo ID Presentacion: ";
                    getline(cin, resultado[3]);
                    break;
                case 4:
                    cout << "Nuevo precio: ";
                    getline(cin, resultado[4]);
                    break;
                case 5:
                    cout << "Nuevo costo: ";
                    getline(cin, resultado[5]);
                    break;
                case 6:
                    cout << "IVA (1 para si, 0 para no): ";
                    getline(cin, resultado[6]);
                    break;
                case 7:
                    cout << "Nuevo stock: ";
                    getline(cin, resultado[7]);
                    break;
                default:
                    cout << "bye bye" << endl;
                    break;
                }

            } while (choice != 0);
            lines[line_number - 1] = resultado[0] + "," + resultado[1] + "," + resultado[2] + "," + resultado[3] + "," + resultado[4] + "," + resultado[5] + "," + resultado[6] + "," + resultado[7];
        }
        else
        {
            cout << "Producto no encontrado" << endl;
        }
        ofstream write_file;
        write_file.open(file_name);
        if (write_file.fail())
        {
            cout << "Error al abrir el archivo para escribir" << endl;
        }
        else
        {
            for (int i = 0; i < lines.size(); i++)
            {
                write_file << lines[i] << endl;
            }
        }

    }
}

void Productos::ClearProductos()
{
    VectorProductos.clear();
}

void Productos::LimpiarPantalla()
{
    system("cls");
}

bool Productos::checkvectorproductos()
{
    ClearProductos();
    leerproductos();
    if (VectorProductos.size() == 0)
    {
        return false;
    }
    else
    {
        return true;
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