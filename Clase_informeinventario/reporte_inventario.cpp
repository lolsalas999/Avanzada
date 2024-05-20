#include "reporte_inventario.h"

ReporteInventario::ReporteInventario() {
    LeerProductos();
    LeerVentas();
}

ReporteInventario::~ReporteInventario() {

}

void ReporteInventario::LeerProductos() {
    VectorProductos.clear();
    try {
        ifstream SaveFile("Productos.csv");
        if (!SaveFile) {
            throw std::runtime_error("No se pudo abrir Productos.csv");
        }
        string line;
        getline(SaveFile, line); // Omitir la primera l�nea (encabezado)
        while (getline(SaveFile, line)) {
            if (line.empty()) continue; // Evitar l�neas vac�as
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
    catch (const std::exception& e) {
        cerr << "Ocurri� un error al leer el archivo: " << e.what() << endl;
    }
}

void ReporteInventario::LeerVentas() {
    VectorVentas.clear();
    try {
        ifstream SaveFile("Ventas.csv");
        if (!SaveFile) {
            throw std::runtime_error("No se pudo abrir Ventas.csv");
        }
        string line;
        getline(SaveFile, line); // Omitir la primera l�nea (encabezado)
        while (getline(SaveFile, line)) {
            if (line.empty()) continue; // Evitar l�neas vac�as
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
    catch (const std::exception& e) {
        cerr << "Ocurri� un error al leer el archivo: " << e.what() << endl;
    }
}

void ReporteInventario::GenerarReporteInventario() {
    LeerProductos();
    cout << "\n=== Reporte de Inventario ===\n";
    for (int i = 0; i < VectorProductos.size(); ++i) {
        cout << "ID: " << VectorProductos[i].id << ", Nombre: " << VectorProductos[i].name << ", Stock: " << VectorProductos[i].stock << endl;
    }
}

void ReporteInventario::GenerarReporteMovimiento() {
    LeerVentas();
    cout << "\n=== Reporte de Movimiento de Productos ===\n";
    for (int i = 0; i < VectorVentas.size(); ++i) {
        cout << "ID Producto: " << VectorVentas[i].idproducto << ", Cantidad Vendida: " << VectorVentas[i].cant << ", Fecha: " << VectorVentas[i].date << endl;
    }
}

void ReporteInventario::GenerarReporteReposicion() {
    LeerProductos();
    cout << "\n=== Reporte de Necesidades de Reposici�n ===\n";
    int stockminimo = 1; //El l�mite para que se necesite un reporte de reposici�n
    for (int i = 0; i < VectorProductos.size(); ++i) {
        if (VectorProductos[i].stock < stockminimo) {
            cout << "ID: " << VectorProductos[i].id << ", Nombre: " << VectorProductos[i].name << ", Stock: " << VectorProductos[i].stock << " (Necesita Reposici�n)\n";
        }
    }
}