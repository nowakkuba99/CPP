/*
 * Display.cpp
 *
 *  Created on: 12 lut 2022
 *      Author: nowak
 */

#include "Display.h"
using namespace std;

Display::Display()
{

}
void Display::board_dispaly(char (*board)[8][8])
{
	int i=0,j=0;
	cout<<"  01234567"<<endl;
	for(i = 0;i < Y_LEN; i++)
	{
		cout<<i<<" ";
		for(j = 0;j < X_LEN; j++)
		{
			cout<<(*board)[i][j];

		}
		cout<<"\n";
	}
}
