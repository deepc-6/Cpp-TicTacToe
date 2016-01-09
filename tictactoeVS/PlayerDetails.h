#ifndef PLAYERDETAILS_H
#define PLAYERDETAILS_H

#include <string>

class PlayerDetails {

private:
	std::string _playerName;
	char _playerSymbol;
	int _playerNumber;
public:
	PlayerDetails();

	void setPlayerName(std::string pName);
	std::string getPlayerName();
	void setPlayerSymbol(char pSymbol);
	char getPlayerSymbol();
	void setPlayerNumber(int pNumber);
	int getPlayerNumber();
};

#endif // PLAYERDETAILS_H
