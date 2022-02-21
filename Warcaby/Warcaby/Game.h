/*
 * Game.h
 *
 *  Created on: 12 lut 2022
 *      Author: nowak
 */

#ifndef GAME_H_
#define GAME_H_
#include "Pionek.h"
#include "Damka.h"
#include "Player.h"

#include <vector>

class Game {
private:
	std::vector<Pionek *> pionki;
	std::vector<Damka *> damki;

	unsigned int id_count = 1;
	unsigned int count_pionki = 0;
	unsigned int count_damki = 0;
	unsigned int choosen_type = 0;	//0 - pionek, 1 - damka
	unsigned int choosen_pos_in_vec = 0;

	std::vector<std::vector<unsigned int>> possible_moves;

public:
	Game();
	unsigned int id_board[8][8]={0};
	char board[8][8]={' '};

	void star_new_game();
	void show_id();
	void add_to_board(Interface * figura);
	void delete_item(Interface * figura);
	char get_type(unsigned int id);
	void refresh_board();
	void choose_pos(Player * player);
	/*Fucntions for debug*/
	void debug_show_info_choosen();

private:
	void fill_the_board_init();
	unsigned int get_id_from_pos(unsigned int x, unsigned int y) {return this->id_board[x][y];}
	unsigned int get_pos_in_vec_pion(unsigned int id);
	unsigned int get_pos_in_vec_dam(unsigned int id);
	void delete_pionek(unsigned int pos_in_vec_pion);
	void delete_damka(unsigned int pos_in_vec_dam);
	bool check_if_move_possible();
	void calculate_all_possible_moves();
public:
	~Game();

};

#endif /* GAME_H_ */
