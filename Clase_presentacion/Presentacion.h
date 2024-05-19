#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include "cliente.h"

using namespace std;

class Presentacion :public Cliente
{
public:
	Presentacion();
	~Presentacion();
	void setid(int);
	int getid();
	void setname(string);
	string getname();
	void registrarpresentacion();
	void archivopresentacion();
	void leerarchivopresentacion();
	void clearpresentacion();


private:
protected:
	struct PresentacionProduct {
		int id;
		string name;
	};
	string ModificaLinea(string, int, PresentacionProduct&);
	PresentacionProduct PresentacionP;
	vector<PresentacionProduct> vectorpresentacionl;
};