/*
 * Damka.cpp
 *
 *  Created on: 11 lut 2022
 *      Author: nowak
 */

#include "Damka.h"
using namespace std;
Damka::Damka(unsigned int poz_x, unsigned int poz_y, char type,unsigned int id) : poz_x {poz_x}, poz_y {poz_x}, type {type}, id {id}
{
	cout<<"Damka utworzona poprawnie!"<<endl;
	this->get_info();

}
void Damka::move()
{
	cout<<"a";
}
void Damka::get_info()
{
	cout<<"Pozycja: "<<this->poz_x<<","<<this->poz_y<<endl;
	cout<<"Typ: "<<this->type<<endl;
	cout<<"ID: "<<this->id<<endl;
}
