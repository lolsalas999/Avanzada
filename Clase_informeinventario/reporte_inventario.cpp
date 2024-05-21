#include "reporte_inventario.h"

ReporteInventario::ReporteInventario() {
    // Usamos los métodos de lecturas de las clases heredadas.
    leerproductos();//Leemos los productos actuales
    leerVentas();//Leemos los movimientos en ventas
}

ReporteInventario::~ReporteInventario() {

}

//En los siguientes, simplemente hacemos el display de cada vector con su información útil para generar los reportes debidos

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
    int stockminimo = 5; // Límite que hay (Antes del enviar el mensaje de "reposición necesaria")
    for (size_t i = 0; i < VectorProductos.size(); ++i) {
        if (VectorProductos[i].stock <= stockminimo) {
            cout << "ID: " << VectorProductos[i].id << ", Nombre: " << VectorProductos[i].name << ", Stock: " << VectorProductos[i].stock << " (Necesita Reposición)\n";
        }
    }
}