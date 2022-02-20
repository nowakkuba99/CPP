/*
 * Display.h
 *
 *  Created on: 12 lut 2022
 *      Author: nowak
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_


#include <iostream>
#define X_LEN 8
#define Y_LEN 8

#include "Game.h"
class Display {
public:
	Display();
	static void board_dispaly (char (*board)[8][8]);
private:

};

#endif /* DISPLAY_H_ */
