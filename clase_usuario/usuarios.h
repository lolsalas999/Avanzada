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
    bool LeerArchivoUsuario();
    void ActualizarArchivoUsuario();
    bool AdministradorExiste();
    string getDateTime();
    void LimpiarPantalla();
    void OrdenarUsuariosPorID();
    void UsuarioClear();
    bool CallLogin(string& useractual, int& role);
    void RegistrarUsuario(int& rol, string& useractual);
    void EditarUsuario(int& rol, string& useractual);
    void EliminarUsuarios(int& rol, string& useractual);
    bool IniciarSesion(string& useractual, int& rol);
    bool checkvectoruser();

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
};