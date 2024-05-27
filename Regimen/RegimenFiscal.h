#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ostream>
#include<stdexcept>

using namespace std;

class Regimen
{
public:
	Regimen();
	~Regimen();
	void LeerArchivoRegimen();

private:
protected:
	struct RegimenFiscal
	{
		int id;
		int code;
		string descripcion;
	};
	string ModificaLinea(string, int, RegimenFiscal&);
	RegimenFiscal ObjetoRegimen;
	vector<RegimenFiscal>VectorRegimen;
};


