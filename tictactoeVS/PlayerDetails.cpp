#include "PlayerDetails.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//CONSTRUCTOR
PlayerDetails::PlayerDetails()
{
	srand(time(0));
	int random = rand() % 2 + 1;
	_playerNumber = random;
}

//GETTERS AND SETTERS
void PlayerDetails::setPlayerName(std::string pName)
{
	_playerName = pName;
}

std::string PlayerDetails::getPlayerName()
{
	return _playerName;
}

void PlayerDetails::setPlayerSymbol(char pSymbol)
{
	_playerSymbol = pSymbol;
}

char PlayerDetails::getPlayerSymbol()
{
	return _playerSymbol;
}

void PlayerDetails::setPlayerNumber(int pNumber)
{
	_playerNumber = pNumber;
}

int PlayerDetails::getPlayerNumber()
{
	return _playerNumber;
	return 0;
}