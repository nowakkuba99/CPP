/*
 * Game.cpp
 *
 *  Created on: 12 lut 2022
 *      Author: nowak
 */

#include "Game.h"
#include <string>
using namespace std;
Game::Game() {
	// TODO Auto-generated constructor stub

}
void Game::star_new_game()
{
	this->fill_the_board_init();
}
void Game::show_id()
{
	int i=0,j=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			std::cout<<(this->id_board)[i][j];
		}
		std::cout<<"\n";
	}
}
Game::~Game()
{
	unsigned int i=0;
	for(i=0;i<this->count_pionki;i++)
	{
		delete this->pionki[i];
		cout<<"Usuniêto pionek"<<endl;
		this->pionki[i] = nullptr;
	}
}
char Game::get_type(unsigned int id)
{
	for(unsigned int i=0;i<this->count_pionki;i++)
	{
		if(pionki[i]->get_id() == id)
		{
			return pionki[i]->get_type();
		}
	}
	return ' ';
}
void Game::add_to_board(Interface * figura)
{
	int x = figura->get_poz_x();
	int y = figura->get_poz_y();
	if((x>=0 && x<8) && (y>=0 && y<8))
	{
		this->id_board[x][y]=figura->get_id();
		this->board[x][y]=figura->get_type();
	}
}
void Game::refresh_board()
{
	unsigned int i=0,j=0;
	// Reset board
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			this->board[i][j]=' ';
		}
	}
	// Fill with elements
	for(i=0;i<this->count_pionki;i++)
	{
		this->add_to_board(this->pionki[i]);
	}
	for(i=0;i<this->count_damki;i++)
	{
		this->add_to_board(this->damki[i]);
	}
}
void Game::fill_the_board_init()
{
	unsigned int i=0,j=0,k=0;
	//Pionki 'X'
	for(i=0;i<3;i++)
	{
		if(i == 0 || i == 2)
		{
			k=1;
		}
		else
			k=0;
		for(j=k;j<8;j+=2)
		{
			this->pionki.push_back(new Pionek(i,j,'x',this->id_count));
			this->id_count++;
			this->count_pionki++;
		}
	}
	//Pionki 'O'
	for(i=5;i<8;i++)
	{
		if(i == 6)
		{
			k=1;
		}
		else
			k=0;
		for(j=k;j<8;j+=2)
		{
			this->pionki.push_back(new Pionek(i,j,'o',this->id_count));
			this->id_count++;
			this->count_pionki++;
		}
	}
}
unsigned int Game::get_pos_in_vec_pion(unsigned int id)
{
	unsigned int i=0;
	for(i=0;i<this->count_pionki;i++)
	{
		if(id == this->pionki[i]->get_id())
		{
			return i;
		}
	}
	return 99;
}
unsigned int Game::get_pos_in_vec_dam(unsigned int id)
{
	unsigned int i=0;
	for(i=0;i<this->count_damki;i++)
	{
		if(id == this->damki[i]->get_id())
		{
			return i;
		}
	}
	return 99;
}
void Game::choose_pos(Player * player)
{
	string input;
	unsigned int len,flag=0,x,y,pos,type;
	while(flag == 0)
	{
		cout<<"Podaj pozycje [x] [y]:";
		getline(cin,input);
		len=input.length();
		if(len!=3)
		{
			cout<<"Dlugosc wpisanych danych jest zla: "<<len<<endl;
		}
		else if ((input[0] > 47 && input [0] < 57) && (input[1] == ' ') && (input[2] > 47 && input [2] < 57))
		{
			x = input[0]-48;
			y = input[2]-48;
			pos = this->get_pos_in_vec_pion(this->get_id_from_pos(x, y));
			if(pos != 99)
			{
				/*W wektorze pionki jest takie ID - to jest pionek*/
				type = 0;
				if(player->get_type() == 'B')
				{
					/*Gracz z czarnymi pionkami: x/X*/
					if(this->pionki[pos]->get_type() == 'x')
					{
						/*Prawidolowy pionek wybrany */
						cout<<"Wybor prawidlowy"<<endl;
						flag = 1;
					}
					else
					{
						/*Zly pionek wybrany*/
						cout<<"Wybrany pionek nie nalezy do gracza, ktory wykonuje ruch"<<endl;
					}
				}
				else if (player->get_type() == 'W')
				{
					/*Gracz z bialymi pionkami: o/O*/
					if(this->pionki[pos]->get_type() == 'o')
					{
						/*Prawidolowy pionek wybrany */
						cout<<"Wybor prawidlowy"<<endl;
						flag = 1;
					}
					else
					{
						/*Zly pionek wybrany*/
						cout<<"Wybrany pionek nie nalezy do gracza, ktory wykonuje ruch"<<endl;
					}
				}
			}
			else
			{
				pos = this->get_pos_in_vec_dam(this->get_id_from_pos(x, y));
				if(pos != 99)
				{
					/*W wektorze damki jest takie ID - to jest damka*/
					type = 1;
					if(player->get_type() == 'B')
					{
						/*Gracz z czarnymi pionkami: x/X*/
						if(this->pionki[pos]->get_type() == 'X')
						{
							/*Prawidolowy pionek wybrany */
							cout<<"Wybor prawidlowy"<<endl;
							flag = 1;
						}
						else
						{
							/*Zly pionek wybrany*/
							cout<<"Wybrany pionek nie nalezy do gracza, ktory wykonuje ruch"<<endl;
						}
					}
					else if (player->get_type() == 'W')
					{
						/*Gracz z bialymi pionkami: o/O*/
						if(this->pionki[pos]->get_type() == 'O')
						{
							/*Prawidolowy pionek wybrany */
							cout<<"Wybor prawidlowy"<<endl;
							flag = 1;
						}
						else
						{
							/*Zly pionek wybrany*/
							cout<<"Wybrany pionek nie nalezy do gracza, ktory wykonuje ruch"<<endl;
						}
					}
				}
				else
				{
					/*Nie ma takiego id w zadnym wektorze*/
					if(this->get_id_from_pos(x, y) == 0)
					{
						/*Na tym polu nic nie ma*/
						cout<<"Wybrane pole jest puste"<<endl;
					}
				}
			}
		}
		else
		{
			if(input[1] ==' ')
			{
				/*Dwie liczby oddzielone spacja ale nie z zakresu 0 -8*/
				cout<<"Wybrano pole z poza zakresu planszy!"<<endl;
			}
			else
			{
				/*Srodkowym znakiem nie jest spacja*/
				cout<<"Srodkowym znakiem nie jest spacja"<<endl;
			}

		}
	}
	/*Zapisz do zmiennych co zostalo wybrane - type 0 - pion, 1 -damka + miejsce w wektorze*/
	this->choosen_type = type;
	this->choosen_pos_in_vec = pos;
	//system("CLS");
}
void Game::debug_show_info_choosen()
{
	if(this->choosen_type == 0)
	{
		/*Pionek*/
		this->pionki[this->choosen_pos_in_vec]->get_info();
	}
	else
	{
		/*Damka*/
		this->damki[this->choosen_pos_in_vec]->get_info();
	}
}
bool Game::check_if_move_possible()
{
	return true;
}
void Game::calculate_all_possible_moves()
{
	bool flag_ready = false;
	unsigned int x,y;
	unsigned int buff[2]={0};
	/*Clear possible moves vector*/
	this->possible_moves.clear();
	/*Check type*/
	if(this->choosen_type == 0)
	{
		/*Pionek*/
		/*Possible moves/
		 * #1 x+1, y-1/y+1 if there is no opponent
		 * #2 x+2, y-2/y+2 if there is opponent on x+1 y-1/y+1
		 */
		x = this->pionki[this->choosen_pos_in_vec]->get_poz_x();
		y = this->pionki[this->choosen_pos_in_vec]->get_poz_y();
		/* #1 - x+1, y-1*/
		if((x+1 < 8) && (y-1 > 0))
		{
			/*Field exist*/
			if(this->id_board[x+1][y-1] == 0)
			{
				/*Field is empty -> Move is possible*/
				buff[0] = x+1;
				buff[1] = y-1;
				this->possible_moves.push_back(buff);
			}
			else
			{
				/*Field is taken*/
				if((this->pionki[this->choosen_pos_in_vec]->get_id() != this->get_type(this->id_board[x+1][y-1])) && (this->pionki[this->choosen_pos_in_vec]->get_id() != (this->get_type(this->id_board[x+1][y-1]))-32))
				{
					/*Field is NOT the same type as chosen one*/
					if((x+2 < 8) && (y-2 > 0))
					{
						/*Field exist*/
						if(this->id_board[x+2][y-2] == 0)
						{
							/*Field is empty -> Move is possible*/
							buff[0] = x+1;
							buff[1] = y-1;
							this->possible_moves.push_back(buff);
						}
					}
				}
			}
		}
	}
	else if (this->choosen_type == 1)
	{
		/*Damka*/
	}
}











