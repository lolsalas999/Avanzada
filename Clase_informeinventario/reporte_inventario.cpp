#include "reporte_inventario.h"

ReporteInventario::ReporteInventario() {
    LeerProductos();
    LeerVentas();
}

ReporteInventario::~ReporteInventario() {

}

void ReporteInventario::LeerProductos() {
    LeerProductos();
}

void ReporteInventario::LeerVentas() {
    LeerVentas();
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
    cout << "\n=== Reporte de Necesidades de Reposición ===\n";
    int stockminimo = 1; //El límite para que se necesite un reporte de reposición
    for (int i = 0; i < VectorProductos.size(); ++i) {
        if (VectorProductos[i].stock < stockminimo) {
            cout << "ID: " << VectorProductos[i].id << ", Nombre: " << VectorProductos[i].name << ", Stock: " << VectorProductos[i].stock << " (Necesita Reposición)\n";
        }
    }
}