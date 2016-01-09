#include <iostream>
#include "Board.h"
#include "PlayerDetails.h"
#include "AI.h"
#include "GameLoop.h"

//CONSTRUCTOR
GameLoop::GameLoop()
{
	_quitValue = 'p';
	_checkWin = false;
	_pSym1 = _pSym2 = ' ';
}

//MODE SELECTION (SP / MP)
void GameLoop::runLoop()
{
	char input;	
	do
	{
		std::cout << "Enter S for single player or M for multiplayer or Q to quit the game" << std::endl;
		std::cin >> input;

		switch (input)
		{
		case 'm':
		case 'M':
			multiPlayer();
			break;
		case 's':
		case 'S':
			singlePlayer();
			break;
		case 'q':
		case 'Q':
			break;
		default:
			std::cout << "Please enter a valid choice" << std::endl;
			break;
		}
	} while (input != 'q' && input != 'Q');
}

//SINGLE PLAYER MODE
void GameLoop::singlePlayer()
{
	do
	{
		_quitValue = 'p';

		//GET PLAYER DETAILS FROM USER AND SET IT

		PlayerDetails player, player1, player2;
		AI ai;

		_pSym1 = ' ';
		_pSym2 = ' ';

		_rows = _columns = 0;

		std::cout << "\nNew Game Starting\n";

		while (_rows < 3 || _rows > 9) {

			std::cout << "\nEnter the number of grids (Between 3 and 9) : ";
			std::cin >> _rows;
		}

		_columns = _rows;

		std::cout << "\nEnter player 1 name: ";
		std::cin >> _pN;
		player1.setPlayerName(_pN);

		while (_pSym1 == ' ') {

			std::cout << "\nEnter player 1 symbol : ";
			std::cin >> _pSym1;
			player1.setPlayerSymbol(_pSym1);
		}

		player2.setPlayerName("AI");
		while (_pSym2 == ' ') {

			std::cout << "\nEnter AI symbol : ";
			std::cin >> _pSym2;
			player2.setPlayerSymbol(_pSym2);
		}

		//INITIALIZE AND DISPLAY THE BOARD

		Board board;

		board.setRows(_rows);
		board.setColumns(_columns);
		std::cout << "\nYou have chosen a board with " << board.getRows() << " rows and " << board.getColumns() << " columns\n";
		board.initBoard();
		board.displayBoard();

		// ACTUAL SINGLE PLAYER GAME LOOP

		while (_quitValue != 'q') {
			//PLAYER 1
			if (player.getPlayerNumber() == 1) {
				
				std::cout << player1.getPlayerName() << "'s turn\n";
				std::cout << "\nChoose an x and y position:\n\n";
				std::cin >> _x >> _y;

				if (board.getBoardArray(_x, _y) == ' ')
					board.updateBoard(_x, _y, player1.getPlayerSymbol());
				else {
					std::cout << "\nThis position has already been selected or does not exist\n";
					continue;
				}

				board.displayBoard();

				if (board.checkWin()) {

					std::cout << "Congratulations! " << player1.getPlayerName() << " is the winner!\n\n";
					std::cout << "Press q to quit or any other key to start a new game: ";
					std::cin >> _quitValue;
					break;
				}
				player.setPlayerNumber(2);
			}
			//PLAYER 2
			else {

				std::cout << "COMPUTER's turn\n";
				
				ai.performMove(board, player.getPlayerNumber(), player);

				board.displayBoard();

				if (board.checkWin()) {

					std::cout << "YOU LOSE! COMPUTER is the winner!\n\n";
					std::cout << "Press q to quit or any other key to start a new game: ";
					std::cin >> _quitValue;
					break;
				}
				player.setPlayerNumber(1);
			}

			if (!board.checkEmpty()) {
				std::cout << "Match Draw!\n\n";
				std::cout << "Press q to quit or any other key to start a new game: ";
				std::cin >> _quitValue;
				break;
			}
		}
	} while (_quitValue != 'q');
}

//MULTI PLAYER MODE
void GameLoop::multiPlayer()
{
	do
	{
		_quitValue = 'p';

		//GET PLAYER DETAILS FROM USER AND SET IT

		PlayerDetails player, player1, player2;

		_pSym1 = _pSym2 = ' ';

		_rows = _columns = 0;

		std::cout << "\nNew Game Starting\n";

		while (_rows < 3 || _rows > 9) {

			std::cout << "\nEnter the number of grids (Between 3 and 9) : ";
			std::cin >> _rows;
		}

		_columns = _rows;

		std::cout << "\nEnter player 1 name: ";
		std::cin >> _pN;
		player1.setPlayerName(_pN);

		while (_pSym1 == ' ') {

			std::cout << "\nEnter player 1 symbol : ";
			std::cin >> _pSym1;
			player1.setPlayerSymbol(_pSym1);
		}

		std::cout << "\nEnter player 2 name: ";
		std::cin >> _pN;
		player2.setPlayerName(_pN);

		while (_pSym2 == ' ') {

			std::cout << "\nEnter player 2 symbol : ";
			std::cin >> _pSym2;
			player2.setPlayerSymbol(_pSym2);
		}


		//INITIALIZE AND DISPLAY THE BOARD

		Board board;

		board.setRows(_rows);
		board.setColumns(_columns);
		std::cout << "\nYou have chosen a board with " << board.getRows() << " rows and " << board.getColumns() << " columns\n";
		board.initBoard();
		board.displayBoard();

		// ACTUAL MULTIPLAYER GAME LOOP

		while (_quitValue != 'q') {
			//PLAYER 1
			if (player.getPlayerNumber() == 1) {

				std::cout << player1.getPlayerName() << "'s turn\n";
				std::cout << "\nChoose an x and y position:\n\n";
				std::cin >> _x >> _y;

				if (board.getBoardArray(_x, _y) == ' ')
					board.updateBoard(_x, _y, player1.getPlayerSymbol());
				else {
					std::cout << "\nThis position has already been selected or does not exist\n";
					continue;
				}

				board.displayBoard();

				if (board.checkWin()) {

					std::cout << "Congratulations! " << player1.getPlayerName() << " is the winner!\n\n";
					std::cout << "Press q to quit or any other key to start a new game: ";
					std::cin >> _quitValue;
					break;
				}
				player.setPlayerNumber(2);

			}
			//PLAYER 2
			else {

				std::cout << player2.getPlayerName() << "'s turn\n";
				std::cout << "\nChoose an x and y position:\n\n";
				std::cin >> _x >> _y;

				if (board.getBoardArray(_x, _y) == ' ')
					board.updateBoard(_x, _y, player2.getPlayerSymbol());
				else {
					std::cout << "\nThis position has already been selected or does not exist\n";
					continue;
				}

				board.displayBoard();

				if (board.checkWin()) {

					std::cout << "Congratulations! " << player2.getPlayerName() << " is the winner!\n\n";
					std::cout << "Press q to quit or any other key to start a new game: ";
					std::cin >> _quitValue;
					break;
				}
				player.setPlayerNumber(1);
			}

			if (!board.checkEmpty()) {
				std::cout << "Match Draw!\n\n";
				std::cout << "Press q to quit or any other key to start a new game: ";
				std::cin >> _quitValue;
				break;
			}
		}
	} while (_quitValue != 'q');
}