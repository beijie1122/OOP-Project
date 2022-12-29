#include "Player.h"
#include <ctime>

//No-args Constructor

ostream& operator<<(ostream& os, const Player& e)
{
	os <<"NAME: " << e.PlayerName << " LEVEL: " << e.PlayerLevel << " HP: " << e.PlayerHP << " ATT: " << e.PlayerAtt << " SPD: " << e.PlayerSpeed << endl;
	return os;
}


Player::Player()
{

}


Player::Player(string iPlayerName)
	:PlayerName(iPlayerName)
{
}


void Player::SetPlayerLevel(int PlayerEXP, int PlayerLevel)
{
	if (PlayerEXP >= 10)
	{
		if (PlayerEXP >= 20)
		{
			PlayerLevel = 3;
			printf("Level: %d\n", PlayerLevel);
		}
		else
		{
			PlayerLevel = 2;
			printf("Level: %d\n", PlayerLevel);
		}
	}
	else 
	{
		printf("Level: %d\n", PlayerLevel);
	}
}

void Player::HUD()
{
	printf("==========\n");
	cout << "=Name: " << PlayerName << endl;
	printf("=Level: %d\n", PlayerLevel);
	printf("=Att: %d\n", PlayerAtt);
	printf("=Spd: %d\n", PlayerSpeed);
	printf("=EXP: %d\n", PlayerEXP);
	printf("==========\n");
}

Player::~Player()
{

}
