#pragma once
#include <iostream>
#include <string>

using namespace std;


class Player
{
public:

	friend ostream& operator<<(ostream& os, const Player& e);
	

	string PlayerName{};
	int PlayerHP{};
	int PlayerSpeed{};
	int PlayerEXP{};
	int PlayerAtt{};
	int PlayerLevel{};


	//No-args Constructor
	Player();

	//Constructor
	Player(string iPlayerName);

	virtual void SetPlayerLevel(int PlayerEXP, int PlayerLevel);

	virtual void HUD();

	//bool operator==(const Player& rhs) const
	//{
	//	return (this->PlayerLevel == rhs.PlayerLevel);
	//}

	//Destructor
	~Player();



};

