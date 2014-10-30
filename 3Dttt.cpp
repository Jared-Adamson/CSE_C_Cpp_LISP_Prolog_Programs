
// Jared Adamson
// 3Dttt.cpp
//  3d Tic Tac Toe - Scoring is unfinished.

#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

#pragma warning(disable: 4996)

using namespace std;



class ticGame{
public:


	char cSpace[3][3][3];
	int i, j, h, c1, c2, c3, oScore, xScore;
	int pTurn = 0;
	int iSpace[3][3][3];


	ticGame() {

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				for (h = 0; h < 3; h++){
					cSpace[i][j][h] = ' ';
				}
			}
		}

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				for (h = 0; h < 3; h++){
					iSpace[i][j][h] = 0;
				}
			}
		}

	}

	void scoreCheck(void);
	void drawBoard(void);
	void playGame(void);
	void setSpecial(void);

	//Destructor



};//end of class

void ticGame::drawBoard()
{

	// build board 1
	cout << "\n";
	cout << "Board #1\n";
	cout << cSpace[0][0][0] << " | " << cSpace[0][1][0] << " | " << cSpace[0][02][0] << endl;
	cout << "--|---|--\n";
	cout << cSpace[1][0][0] << " | " << cSpace[1][1][0] << " | " << cSpace[1][2][0] << endl;
	cout << "--|---|--\n";
	cout << cSpace[2][0][0] << " | " << cSpace[2][1][0] << " | " << cSpace[2][2][0] << endl;
	// build board 2
	cout << "\n";
	cout << "Board #2\n";
	cout << cSpace[0][0][1] << " | " << cSpace[0][1][1] << " | " << cSpace[0][2][1] << endl;
	cout << "--|---|--\n";
	cout << cSpace[1][0][1] << " | " << cSpace[1][1][1] << " | " << cSpace[1][2][1] << endl;
	cout << "--|---|--\n";
	cout << cSpace[2][0][1] << " | " << cSpace[2][1][1] << " | " << cSpace[2][2][1] << endl;
	// build board 3
	cout << "\n";
	cout << "Board #3\n";
	cout << cSpace[0][0][2] << " | " << cSpace[0][1][2] << " | " << cSpace[0][2][2] << endl;
	cout << "--|---|--\n";
	cout << cSpace[1][0][2] << " | " << cSpace[1][1][2] << " | " << cSpace[1][2][2] << endl;
	cout << "--|---|--\n";
	cout << cSpace[2][0][2] << " | " << cSpace[2][1][2] << " | " << cSpace[2][2][2] << endl;



}//end

void ticGame::playGame()
{
	int input1, input2, input3;
	bool quit = false;

	setSpecial();

	while (quit == false) {

		pTurn++;

		drawBoard();

		scoreCheck();

		if (pTurn % 2 == 0){

			cout << "Player 2, it's your turn!\n";

		}
		else{

			cout << "Player 1, it's your turn!\n";

		}

		cout << "Enter the BOARD number to play on(press 4 to quit):";

		cin >> input1;
		if (input1 == 4){
			quit = true;

			break;
		}
		if ((input1 > 4 || input1 < 1)){

			cout << "\nInvalid Input.\n";
			pTurn--;

		}
		else{

			cout << "Enter the ROW number to play on:";

			cin >> input2;
			if ((input2 > 3 || input2 < 1)){

				cout << "\nInvalid Input.\n";
				pTurn--;

			}
			else{

				cout << "Enter the COLUMN number to play on:";

				cin >> input3;
				if (input3 > 3 || input3 < 1){

					cout << "\nInvalid Input.\n";
					pTurn--;

				}

				if (iSpace[input2 - 1][input3 - 1][input1 - 1] != 0){
					cout << "Please choose an OPEN square.";
					pTurn--;
				}
				else if (pTurn % 2 == 0){

					iSpace[input2 - 1][input3 - 1][input1 - 1] = 2;
					cSpace[input2 - 1][input3 - 1][input1 - 1] = 'O';
				}
				else{

					iSpace[input2 - 1][input3 - 1][input1 - 1] = 1;
					cSpace[input2 - 1][input3 - 1][input1 - 1] = 'X';
				}
			}
		}



	}// End of loop



	}//end


void ticGame::scoreCheck(){




		int i = 0;
		oScore = 0;
		xScore = 0;
		iSpace[c1][c2][c3] = 1;

		//-----------------------------
		// Check the X's
	// checking the rows

	for (i = 0; i<3; i++)
	if (iSpace[0][i][0] == iSpace[0][i][1] && iSpace[0][i][0] == iSpace[0][i][2]){
		if (iSpace[0][i][0] == 1)
			xScore++;
			}


	for (i = 0; i<3; i++)
	if (iSpace[1][i][0] == iSpace[1][i][1] && iSpace[1][i][0] == iSpace[1][i][2]){
		if (iSpace[1][i][0] == 1)
			xScore++;

	}

	for (i = 0; i<3; i++)
	if (iSpace[2][i][0] == iSpace[2][i][1] && iSpace[2][i][0] == iSpace[2][i][2])
	{
		if (iSpace[2][i][0] == 1)
			xScore++;

	}

	//----------------------------------------
	// checking more rows

	for (i = 0; i<3; i++)
	if (iSpace[i][0][0] == iSpace[i][1][0] && iSpace[i][0][0] == iSpace[i][2][0])
	{
		if (iSpace[i][0][0] == 1)
			xScore++;

	}

	for (i = 0; i<3; i++)
	if (iSpace[i][0][1] == iSpace[i][1][1] && iSpace[i][0][1] == iSpace[i][2][1])
	{
		if (iSpace[i][0][1] == 1)
			xScore++;

	}

	for (i = 0; i<3; i++)
	if (iSpace[i][0][2] == iSpace[i][1][2] && iSpace[i][0][2] == iSpace[i][2][2])
	{
		if (iSpace[i][0][2] == 1)
			xScore++;

	}



	//--------------------------------------------

	// checking the columns

	for (i = 0; i<3; i++)
	if (iSpace[0][i][0] == iSpace[1][i][0] && iSpace[0][i][0] == iSpace[2][i][0])
	{
		if (iSpace[0][i][0] == 1)
			xScore++;

	}

	for (i = 0; i<3; i++)
	if (iSpace[0][i][1] == iSpace[1][i][1] && iSpace[0][i][1] == iSpace[2][i][1])
	{
		if (iSpace[0][i][1] == 1)
			xScore++;

	}

	for (i = 0; i<3; i++)
	if (iSpace[0][i][2] == iSpace[1][i][2] && iSpace[0][i][2] == iSpace[2][i][2])
	{
		if (iSpace[0][i][2] == 1)
			xScore++;

	}
	//------------------------------------


	//----------------------------------


	// Check diagonals

	if (iSpace[0][0][0] == iSpace[1][1][0] && iSpace[1][1][0] == iSpace[2][2][0])
	{
		if (iSpace[0][0][0] == 1)
			xScore++;

	}

	if (iSpace[0][2][0] == iSpace[1][1][0] && iSpace[1][1][0] == iSpace[2][0][0])
	{
		if (iSpace[0][2][0] == 1)
			xScore++;

	}

	//---------------------------------------------
	// Check the O's

	iSpace[c1][c2][c3] = 2;
	// checking the rows

	for (i = 0; i<3; i++)
	if (iSpace[0][i][0] == iSpace[0][i][1] && iSpace[0][i][0] == iSpace[0][i][2]){

		if (iSpace[0][i][0] == 2)
			oScore++;
	}


	for (i = 0; i<3; i++)
	if (iSpace[1][i][0] == iSpace[1][i][1] && iSpace[1][i][0] == iSpace[1][i][2]){

		if (iSpace[1][i][0] == 2)
			oScore++;
	}

	for (i = 0; i<3; i++)
	if (iSpace[2][i][0] == iSpace[2][i][1] && iSpace[2][i][0] == iSpace[2][i][2])
	{

		if (iSpace[2][i][0] == 2)
			oScore++;
	}

	//----------------------------------------
	// checking more rows

	for (i = 0; i<3; i++)
	if (iSpace[i][0][0] == iSpace[i][1][0] && iSpace[i][0][0] == iSpace[i][2][0])
	{

		if (iSpace[i][0][0] == 2)
			oScore++;
	}

	for (i = 0; i<3; i++)
	if (iSpace[i][0][1] == iSpace[i][1][1] && iSpace[i][0][1] == iSpace[i][2][1])
	{

		if (iSpace[i][0][1] == 2)
			oScore++;
	}

	for (i = 0; i<3; i++)
	if (iSpace[i][0][2] == iSpace[i][1][2] && iSpace[i][0][2] == iSpace[i][2][2])
	{

		if (iSpace[i][0][2] == 2)
			oScore++;
	}



	//--------------------------------------------

	// checking the columns

	for (i = 0; i<3; i++)
	if (iSpace[0][i][0] == iSpace[1][i][0] && iSpace[0][i][0] == iSpace[2][i][0])
	{

		if (iSpace[1][i][0] == 2)
			oScore++;
	}

	for (i = 0; i<3; i++)
	if (iSpace[0][i][1] == iSpace[1][i][1] && iSpace[0][i][1] == iSpace[2][i][1])
	{

		if (iSpace[0][i][1] == 2)
			oScore++;
	}

	for (i = 0; i<3; i++)
	if (iSpace[0][i][2] == iSpace[1][i][2] && iSpace[0][i][2] == iSpace[2][i][2])
	{

		if (iSpace[0][i][2] == 2)
			oScore++;
	}
	//------------------------------------


	//----------------------------------


	// Check diagonals

	if (iSpace[0][0][0] == iSpace[1][1][0] && iSpace[1][1][0] == iSpace[2][2][0])
	{

		if (iSpace[0][0][0] == 2)
			oScore++;
	}

	if (iSpace[0][2][0] == iSpace[1][1][0] && iSpace[1][1][0] == iSpace[2][0][0])
	{

		if (iSpace[0][2][0] == 2)
			oScore++;
	}

	cout << "Player1 Score: " << xScore << "\tPlayer2 Score: " << oScore << endl;

}

void ticGame::setSpecial()
{
	int input1, input2, input3;


	drawBoard();



	cout << "Player 1, place your CEMENT BLOCK!\n";
	cout << "Enter the BOARD number to place your CEMENT BLOCK:";
	cin >> input1;

	if ((input1 > 4 || input1 < 1)){

		cout << "\nInvalid Input.\n";


	}
	else{

		cout << "Enter the ROW number to place your CEMENT BLOCK:";

		cin >> input2;
		if ((input2 > 3 || input2 < 1)){

			cout << "\nInvalid Input.\n";


		}
		else{

			cout << "Enter the COLUMN number to place your CEMENT BLOCK:";

			cin >> input3;
			if (input3 > 3 || input3 < 1){

				cout << "\nInvalid Input.\n";


			}

			if (iSpace[input2 - 1][input3 - 1][input1 - 1] != 0){
				cout << "Please choose an OPEN square.";

			}
			else {

				iSpace[input2 - 1][input3 - 1][input1 - 1] = 5;
				cSpace[input2 - 1][input3 - 1][input1 - 1] = 'B';
			}

		}

		//---------------------------------------------------

		drawBoard();



		cout << "Player 2, place your WILD CHERRY!\n";
		cout << "Enter the BOARD number to place your WILD CHERRY:";
		cin >> input1;

		if ((input1 > 4 || input1 < 1)){

			cout << "\nInvalid Input.\n";


		}
		else{

			cout << "Enter the ROW number to place your WILD CHERRY:";

			cin >> input2;
			if ((input2 > 3 || input2 < 1)){

				cout << "\nInvalid Input.\n";


			}
			else{

				cout << "Enter the COLUMN number to place your WILD CHERRY:";

				cin >> input3;
				if (input3 > 3 || input3 < 1){

					cout << "\nInvalid Input.\n";


				}

				if (iSpace[input2 - 1][input3 - 1][input1 - 1] != 0){
					cout << "Please choose an OPEN square.";

				}
				else {
					c1 = input2 - 1;
					c2 = input3 - 1;
					c3 = input1 - 1;

					iSpace[c1][c2][c3] = 1;
					cSpace[c1][c2][c3] = 'C';
				}

			}

		}
	}




}//end


int main()
{
	cout << "Welcome to Tic Tac Toe in 3D!" << endl;

	ticGame newGame;

	newGame.playGame();

	return 0;
}
