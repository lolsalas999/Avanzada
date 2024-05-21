#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Producto.h"
#include "Venta.h"

using namespace std;

class ReporteInventario : public Venta {
public:
    ReporteInventario();
    ~ReporteInventario();
    void GenerarReporteInventario();
    void GenerarReporteMovimiento();
    void GenerarReporteReposicion();
};