/*
 * Pionek.h
 *
 *  Created on: 11 lut 2022
 *      Author: nowak
 */

#ifndef PIONEK_H_
#define PIONEK_H_

#include "Interface.h"
#include <iostream>

class Pionek: public Interface
{
private:
	unsigned int id;
	unsigned int poz_x;
	unsigned int poz_y;
	char type;
public:
	// Constructor
	Pionek(unsigned int poz_x, unsigned int poz_y, char type,unsigned int id);

	// Functions
	void move();
	void get_info();
	unsigned int get_id()
	{
		return this->id;
	}
	char get_type()
	{
		return this->type;
	}
	unsigned int get_poz_x()
	{
		return this->poz_x;
	}
	unsigned int get_poz_y()
	{
		return this->poz_y;
	}

	// Destructor
	~Pionek()
	{}
};

#endif /* PIONEK_H_ */
