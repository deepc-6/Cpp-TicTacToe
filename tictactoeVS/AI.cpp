#include "AI.h"
#include "PlayerDetails.h"
#include <vector>
#include <iostream>

//AI makes its move
void AI::performMove(Board &board, int playerNumber, PlayerDetails player)
{
	AIMove bestMove = getBestMove(board, playerNumber, player);
	board.updateBoard(bestMove.x, bestMove.y, player.getPlayerSymbol());
}

//Check for best move
AIMove AI::getBestMove(Board &board, int playerNumber, PlayerDetails player)
{
	//Base Case
	if (playerNumber == 2) {
		if (board.checkWin())
			return AIMove(10);
	}
	else if (playerNumber == 1) {
		if (board.checkWin())
			return AIMove(-10);
	}
	else
		return AIMove(0);

	std::vector<AIMove> moves;

	//Recursive function calls and construct moves vector
	for (int y = 0; y < board.getRows() + 1; y++) {
		for (int x = 0; x < board.getColumns() + 1; x++) {

			if (board.getBoardArray(x, y) == ' ') {

				AIMove move;
				move.x = x;
				move.y = y;

				board.updateBoard(x, y, player.getPlayerSymbol());
				if (playerNumber == 1) {
					playerNumber = 2;
					move.score = getBestMove(board, playerNumber, player).score;
				} else {
					playerNumber = 1;
					move.score = getBestMove(board, playerNumber, player).score;
				}

				moves.push_back(move);

				board.updateBoard(x, y, ' ');
			}
		}
	}

	//Pick the best move for the current player
	int bestMove = 0;

	if (playerNumber == 2) {

		int bestScore = -1000000;

		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score > bestScore) {
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else {

		int bestScore = 1000000;

		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score < bestScore) {
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}

	//Return the best move
	return moves[bestMove];
}