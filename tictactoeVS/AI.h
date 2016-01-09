#ifndef AI_H
#define AI_H

#include "Board.h"
#include "PlayerDetails.h"

struct AIMove
{
	AIMove() {}
	AIMove(int Score) : score(Score) {}
	int x;
	int y;
	int score;
};

class AI
{
private:
	AIMove getBestMove(Board &, int, PlayerDetails);
public:
	void setAISymbol(char symbol);
	char getAISymbol();

	void performMove(Board &, int, PlayerDetails);
};

#endif // AI_H