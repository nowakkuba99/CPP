/*
 * Player.h
 *
 *  Created on: 15 lut 2022
 *      Author: nowak
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
private:
	char type;	//Jakie pionki ma gracz - Black (B): x - pionek, X -damka || Whilte:(W) o - pionek, O - damka
	unsigned int beaten_counter_pion;	//Ilsoc zbitych pionkow
	unsigned int beaten_counter_dam;	//Ilsoc damek
	unsigned int fig_counter_pion; 	//Ilsoc pionkow
	unsigned int fig_counter_dam;	//Ilosc damek
public:
	Player(char type, unsigned int fig_counter_pion, unsigned int fig_counter_dam,unsigned int beaten_counter_pion, unsigned int beaten_counter_dam);
	char get_type()	{return this->type;}
};

#endif /* PLAYER_H_ */
