#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include <ctime>


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
	void RegistrarUsuario();
	void creararchivousuarios();
	void LeerArchivoUsuario();


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
		time_t datejoined;
	};
	
	 UsuariosRegistrados ObjetoUsuarios;
	 vector<UsuariosRegistrados> VectorUsuarios;

	 string ModificaLinea(string, int, UsuariosRegistrados&);
};
