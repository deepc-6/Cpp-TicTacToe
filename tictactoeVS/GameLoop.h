#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string>

class GameLoop
{
private:
	int _rows, _columns, _x, _y;
	char _symbol, _quitValue, _pSym1, _pSym2;
	bool _checkWin;
	std::string _pN;

	void singlePlayer();
	void multiPlayer();
public:
	GameLoop();
	void runLoop();
};

#endif // GAMELOOP_H