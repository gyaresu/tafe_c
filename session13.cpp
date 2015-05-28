
// session 13
// TAFE Programming Online
// Teacher Henry Bush
// Program by Gareth
// version 1.0 2003-03-22
// For this exercise you will create a game yourself.
// The game is a modified version of battleships.
// If you are not familiar with the game then a quick overview will help you to create the program for this exercise.
// The game starts with you placing a number of ships onto a grid and your opponent does the same.
// Then taking turns each player calls out a grid coordinate.
// If that matches where the opponent has placed one of his ships then it is sunk.
// Either way you place a marker on a grid to indicate where you have sent a missile.
// The game continues until one player has had his whole fleet sunk.
// For this program the board will be a ten by ten grid and you will place six ships in this grid.

#include <iostream>
using namespace std;
#include <string>


// Adjustments to size of the game
const int cNumShips=6;
const int cNumRows=10;
const int cNumCols=10;

const bool Debug = true;
//

struct player
{
	int numberOfShips;
	char board1[cNumRows][cNumCols];
	char board2[cNumRows][cNumCols];
	string name;
};


void title();
bool checkPosition(char board[][cNumCols], int,int);
void initialiseBoard(char board[][cNumCols]);
void displayBoard(char board[][cNumCols]);
void setShips(player);
void doTurn(player);
void debug(string);
int main()
{
	bool gameOver=false;

	title();
	player p1, p2;
	setShips (p1);
	setShips (p2);

	if (Debug)
	{
		displayBoard(p1.board1);
		displayBoard(p2.board1);
	}

	while (!gameOver)
	{
		doTurn(p1);
		doTurn(p2);
	}
	return 0;
} // close main function

void title()
// displays the introduction title
{
	debug("start title()");
	cout << "A Game of Battleships for two Players" << endl;
}

void setShips (player current)
// array initialisation to place ships on the board
{
 debug("start setShips()");
	current.numberOfShips = cNumShips;
	current.name = "noname";
	char ship = 'S';
	bool validMove;
	int xpos, ypos;

	initialiseBoard(current.board1);

	cout << "Please enter your name: ";
	cin >> current.name;
	cout << endl << current.name << " this is your board. You have " << current.numberOfShips << " Ships to place apon it.\n";
	cout << "Enter a row number followed by a column number to place your ships.\n";

	for (int i = 0; i < cNumShips; i++)
	{

		cout << "\nRow# ";
		cin >> ypos;
		cout << "\nColumn# ";
		cin >> xpos;
		xpos -= 1;
		ypos -= 1;
		validMove = checkPosition(current.board1, ypos, xpos);
		while(validMove)
		{
			cout << "That is an invalid move\n";
			cout << current.name << "\nRow# ";
			cin >> ypos;
			cout << "\nColumn# ";
			cin >> xpos;
			ypos -=1;
			xpos -=1;
			validMove = checkPosition(current.board1, ypos, xpos);
		}// close while loop
		current.board1[ypos][xpos] = ship;
	displayBoard(current.board1);
	cout << i;
	} //
	cout << "\n\n";
	debug("end setShips()");
}

void initialiseBoard(char board[][cNumCols])
{
	debug("start initialiseBoard()");
	for(int row= 0; row < cNumRows; row++)
	{
		for(int col= 0; col < cNumCols; col++)
		{
			board[row][col] = '*';
		}// close col loop
	}// close row loop
	debug("end initialiseBoard()");
}// close initialiseBoard function


void displayBoard(char board[][cNumCols])
{
	debug("start displayBoard()");
	cout << "\n 1 2 3 4 5 6 7 8 9 10" << endl;
	for(int i= 0; i < cNumRows; i++)
	{
		cout << (i + 1);
		for(int j= 0; j < cNumCols; j++)
		{
			cout << board[i][j] <<" ";
		}// close inner for loop
			cout << endl << endl;
	}// close outer for loop
	cout << "\n\n";
	debug("end displayBoard()");
}// close displayBoard function

bool checkPosition(char board[][cNumCols], int y, int x)
{
	debug("start checkPosition()");
	if(board[y][x] != '*')
	{
	debug("end checkPosition() true");
	return true;
	}// close if block
	debug("end checkPosition() false");
	return false;

}// close checkPosition function

void doTurn(player current)
// Player picks a position on the board.
{
debug("start doTurn()");
}

void debug(string text)
{
	if (Debug)
	{
		cout << "DBG: " << text << endl;
	}
}
