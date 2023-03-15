#include "Player.h"
#include <ctime>
#include <iomanip>

//No-args Constructor

ostream& operator<<(ostream& os, const Player& e)
{
	os <<"NAME: " << e.PlayerName << " LEVEL: " << e.PlayerLevel << " HP: " << e.PlayerHP << " ATT: " << e.PlayerAtt << " SPD: " << e.PlayerSpeed <<  endl;
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
	cout << '*' << setfill('=');
	cout << setw(65)<< '*' << endl;
	cout << " Name: " << PlayerName;
	printf("||Level: %d ", PlayerLevel);
	printf("||HP: %d ", PlayerHP);
	printf("||Att: %d ", PlayerAtt);
	printf("||Spd: %d ", PlayerSpeed);
	printf("||EXP: %d \n", PlayerEXP);
	cout << '*' << setfill('=');
	cout << setw(65) << '*' << endl;
}

void Player::EnemyCombatHUD()
{
	cout << '*' << setfill('=');
	cout << setw(40) << '*' << endl;
	cout << " Enemy Name: " << PlayerName;
	printf(" || Enemy HP: %d \n", PlayerHP);
	cout << '*' << setfill('=');
	cout << setw(40) << '*' << endl;
}

Player::~Player()
{

}
