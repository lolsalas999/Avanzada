#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include <ctime>   // For time()
#pragma warning(disable : 4996)

using namespace std;

class usuario
{
public:
    usuario();
    ~usuario();
    void setid();
    int getid();
    void setnombre(string);
    string getnombre();
    void setapellido(string);
    string getapellido();
    void setusuario(string);
    string getusuario();
    void setpassword(string);
    string getpassword();
    void setrol(int);
    int getrol();
    void VerUsuarios();
    void gestionarUsuarios();
    bool LeerArchivoUsuario();
    void ActualizarArchivoUsuario();
    bool AdministradorExiste();
    string getDateTime();
    void LimpiarPantalla();
    void OrdenarUsuariosPorID();

private:
protected:

    struct UsuariosRegistrados
    {
        int id;
        string nombre;
        string apellido;
        string usuario;
        string password;
        int rol;
        string date;
    };

    UsuariosRegistrados ObjetoUsuarios;
    vector<UsuariosRegistrados> VectorUsuarios;

    string ModificaLinea(string, int, UsuariosRegistrados&);
    void RegistrarUsuario(UsuariosRegistrados&);
    void EditarUsuario(UsuariosRegistrados&);
    void EliminarUsuarios(UsuariosRegistrados&);
    bool IniciarSesion(UsuariosRegistrados&);
};
