/*
 * Interface.h
 *
 *  Created on: 11 lut 2022
 *      Author: nowak
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>

class Interface {
private:
	unsigned int id;
public:
	Interface() {}
	//Zbiór publicznych metod do obs³ugi pionków i dam
	virtual void move() {};
	virtual void get_info() = 0;
	virtual unsigned int get_id()= 0;
	virtual unsigned int get_poz_x()= 0;
	virtual unsigned int get_poz_y()= 0;
	virtual char get_type()= 0;
	virtual ~Interface() {}
};

#endif /* INTERFACE_H_ */
