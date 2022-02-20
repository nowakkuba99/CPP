/*
 * main.cpp
 *
 *  Created on: 11 lut 2022
 *      Author: nowak
 */
#include <iostream>
#include "Interface.h"
#include "Pionek.h"
#include "Damka.h"
#include "Display.h"
#include "Game.h"
#include "Player.h"
#include <string>
using namespace std;

/* List of functions*/
string fun_hello(string input);

int main()
{
	/*Create game object*/
	Game* new_game = new Game();

	/*Create two players*/
	Player* Black = new Player('B', 12, 0, 0, 0);
	Player* White = new Player('W', 12, 0, 0, 0);
	/*Start new game - create Mens*/
	new_game->star_new_game();
	new_game->refresh_board();

	//new_game->show_id();
	cout<<endl<<endl;

	Display::board_dispaly(&(new_game->board));

	new_game->choose_pos(Black);

	//new_game->debug_show_info_choosen();

	/*Delete all dynamic objects*/
	delete new_game;
	delete Black;
	delete White;

	cin.ignore();
	return 0;
}


/*
 * Przemyslec kwestie dodawania i usuwania pionkow
 * Mo¿e zrobic tak, ze na poczatku petli gry robic zczytanie wszystkich pozycji i jak usuwac obiekty -?
 * Przy zbiciu najpierw poprzez delate kasowac obiekt lub np funkcja destroy a potem skracac wektor?
 * vector::erase
 * Upewnic sie ze sie beda kasowac obiekty - teraz jest to w destrukotrze obiektu gry
 * Co zrobic z odczytem - odczytac pozycje czy zapisywac np.
 * #[Pionek/Damka] [x] [y] [id] [typ] - Pionek 0 5 10 X
 * i na podstawie tego tworzyc obiekty po odczycie stanu gry?
 *
 */

/*MAIN Loop Idea*/
 int main_2()
 {
	 /* Variables */
	 	string input="";

	 	/*Start the game*/
	 	//input = fun_hello(input);

	 	if(input == "START")
	 	{
	 		/*Create game object*/
	 		Game* new_game = new Game();

	 		/*Start new game - create Mens*/
	 		new_game->star_new_game();
	 		new_game->refresh_board();

	 		//new_game->show_id();
	 		cout<<endl<<endl;

	 		Display::board_dispaly(&(new_game->board));

	 		cout<<"Rozpoczynamy gre!"<<endl;
	 		while(1)
	 		{
	 			cout<<"ABY WYJSC WPISZ 'QUIT'"<<endl;
	 			cout<<"W PRZECIWNYM RAZIE DOWOLNY PRZYCISK"<<endl;
	 			getline(cin,input);
	 			if(input == "QUIT")
	 				break;
	 			/*
	 			cout<<"ABY ZAPISAC WPISZ 'SAVE'"<<endl;
	 			if(input == "SAVE")
	 			{

	 			}*/

	 		}
	 		delete new_game;
	 	}


	 	cin.ignore();
	 	return 0;
 }
 string fun_hello(string input)
 {
 	cout<<"WITAJ W WARCABACH"<<endl;
 	cout<<"ABY ROZPOCZAC WPISZ 'START'"<<endl;
 	//cout<<"ABY WCZYTAC GRE WPISZ 'LOAD GAME'"<<endl;
 	getline(cin,input);
 	system("CLS");
 	return input;
 }
