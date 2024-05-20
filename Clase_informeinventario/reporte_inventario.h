#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Producto.h"
#include "Venta.h"

using namespace std;

class ReporteInventario : public Productos, public Venta {
public:
    ReporteInventario();
    ~ReporteInventario();
    void GenerarReporteInventario();
    void GenerarReporteMovimiento();
    void GenerarReporteReposicion();

private:
    void LeerProductos();
    void LeerVentas();
};