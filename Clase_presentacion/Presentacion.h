#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <stdexcept>

using namespace std;

class Presentacion
{
public:
	Presentacion();
	~Presentacion();
	void setid(int);
	int getid();
	void setname(string);
	string getname();
	void registrarpresentacion();


private:
protected:
	struct PresentacionProduct {
		int id;
		string name;
	};
	PresentacionProduct PresentacionP;
};