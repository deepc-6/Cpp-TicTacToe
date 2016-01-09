#include "Board.h"
#include "PlayerDetails.h"
#include <iostream>

//CONSTRUCTOR
Board::Board() {
	_rows = _columns = 0;
}

//GETTERS AND SETTERS
void Board::setRows(int r) {
	_rows = r;
}

int Board::getRows() {
	return _rows;
}

void Board::setColumns(int c) {
	_columns = c;
}

int Board::getColumns() {
	return _columns;
}

char Board::getBoardArray(int r, int c) {
	return _boardArray[c - 1][r - 1];
}

//INITIALIZE THE BOARD
void Board::initBoard() {

	for (int i = 0; i<_rows; i++) {
		for (int j = 0; j<_columns; j++) {

			_boardArray[i][j] = ' ';
		}
	}
}

//UPDATE THE BOARD
void Board::updateBoard(int row, int column, char symbol) {

	_boardArray[column - 1][row - 1] = symbol;
}

//DISPLAY THE BOARD
void Board::displayBoard() {

	std::cout << std::endl;

	for (int i = 0; i<_rows + 1; i++)
		std::cout << i << " | ";
	std::cout << std::endl;

	std::cout << "---";

	for (int i = 0; i<_rows; i++) {

		for (int j = 0; j<4; j++) {

			std::cout << "-";
		}
	}
	std::cout << std::endl;

	for (int i = 0; i<_rows; i++) {

		std::cout << i + 1 << " |";

		for (int j = 0; j<_columns; j++) {

			std::cout << " " << _boardArray[i][j] << " |";
		}

		std::cout << std::endl;
		std::cout << "---";

		for (int i = 0; i<_rows; i++) {
			for (int j = 0; j<4; j++) {

				std::cout << "-";
			}
		}
		std::cout << std::endl;
	}
}

//CHECK FOR VICTORY
bool Board::checkWin() {

	//Counters to keep track of how many grids are same (horizontally, vertically or diagonallyUp or diagonallyDown)
	int _counterX, _counterY, _counterUp = 0, _counterDown = 0;

	//Check Horizontal
	for (int i = 0; i<_rows; i++) {

		_counterX = 0;

		for (int j = 0; j<_columns - 1; j++) {

			if (_boardArray[j][i] == _boardArray[j + 1][i] && _boardArray[j][i] != ' ') {

				_counterX++;

				if (_counterX == _columns - 1)
					return true;
			}
		}
	}

	//Check Vertical
	for (int i = 0; i<_columns; i++) {

		_counterY = 0;

		for (int j = 0; j<_rows - 1; j++) {

			if (_boardArray[i][j] == _boardArray[i][j + 1] && _boardArray[i][j] != ' ') {

				_counterY++;

				if (_counterY == _rows - 1)
					return true;
			}
		}
	}

	//Check Diagonal Left Top to Right Bottom 
	for (int i = 0, j = 0; i<_columns - 1, j<_rows - 1; i++, j++) {

		if (_boardArray[i][j] == _boardArray[i + 1][j + 1] && _boardArray[i][j] != ' ') {

			_counterDown++;

			if (_counterDown == _columns - 1)
				return true;
		}
	}

	//Check Diagonal Left Bottom to Right Top
	for (int i = 0, j = _rows - 1; i<_columns - 1, j>0; i++, j--) {

		if (_boardArray[i][j] == _boardArray[i + 1][j - 1] && _boardArray[i][j] != ' ') {

			_counterUp++;

			if (_counterUp == _columns - 1)
				return true;
		}
	}

	return false;
}

//CHECK IF ANY GRID IS STILL EMPTY (TO CHECK THE TIE/DRAW CONDITION)
bool Board::checkEmpty() {

	for (int i = 0; i<_rows; i++) {
		for (int j = 0; j<_columns; j++) {

			if (_boardArray[i][j] == ' ')
				return true;
		}
	}
	return false;
}