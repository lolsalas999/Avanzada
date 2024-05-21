#include "reporte_inventario.h"

ReporteInventario::ReporteInventario() {
    // Usamos los métodos de lectura heredados.
    leerproductos();
    leerVentas();
}

ReporteInventario::~ReporteInventario() {}

void ReporteInventario::GenerarReporteInventario() {
    leerproductos();
    cout << "\n=== Reporte de Inventario ===\n";
    for (size_t i = 0; i < VectorProductos.size(); ++i) {
        cout << "ID: " << VectorProductos[i].id << ", Nombre: " << VectorProductos[i].name << ", Stock: " << VectorProductos[i].stock << endl;
    }
}

void ReporteInventario::GenerarReporteMovimiento() {
    leerVentas();
    cout << "\n=== Reporte de Movimiento de Productos ===\n";
    for (size_t i = 0; i < VectorVentas.size(); ++i) {
        cout << "ID Producto: " << VectorVentas[i].idproducto << ", Cantidad Vendida: " << VectorVentas[i].cant << ", Fecha: " << VectorVentas[i].date << endl;
    }
}

void ReporteInventario::GenerarReporteReposicion() {
    leerproductos();
    cout << "\n=== Reporte de Necesidades de Reposición ===\n";
    const int umbral = 10; // Umbral de reposición
    for (size_t i = 0; i < VectorProductos.size(); ++i) {
        if (VectorProductos[i].stock < umbral) {
            cout << "ID: " << VectorProductos[i].id << ", Nombre: " << VectorProductos[i].name << ", Stock: " << VectorProductos[i].stock << " (Necesita Reposición)\n";
        }
    }
}