#ifndef BOARD_H
#define BOARD_H

class Board {
private:
	int _rows, _columns;
	char _boardArray[9][9];
public:
	Board();

	void setRows(int r);
	int getRows();
	void setColumns(int c);
	int getColumns();
	char getBoardArray(int r, int c);
	void initBoard();
	void updateBoard(int row, int column, char symbol);
	void displayBoard();
	bool checkWin();
	bool checkEmpty();
};

#endif //BOARD_H