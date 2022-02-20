/*
 * Pionek.cpp
 *
 *  Created on: 11 lut 2022
 *      Author: nowak
 */

#include "Pionek.h"
using namespace std;

Pionek::Pionek(unsigned int poz_x, unsigned int poz_y, char type,unsigned int id) : poz_x {poz_x}, poz_y {poz_y}, type {type}, id {id}
{
	cout<<"Pionek utworzony poprawnie!"<<endl;
	this->get_info();
}

void Pionek::move()
{
	std::cout<<"ID: "<<this->id<<"\n";
}
void Pionek::get_info()
{
	cout<<"Pozycja: "<<this->poz_x<<","<<this->poz_y<<endl;
	cout<<"Typ: "<<this->type<<endl;
	cout<<"ID: "<<this->id<<endl;
}
