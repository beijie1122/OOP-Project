#include "Maps.h"
#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

Maps::Maps()
{

}

void Maps::InitCombat(unique_ptr <CharacterPlayer>& Character, unique_ptr <Enemy>& PP, unique_ptr<TurnBasedCombat>& TBC)
{
	EncounterRoll = rand() % 10 + 1;
	cout << "Encounter Roll: " << EncounterRoll << endl;
	if (EncounterRoll > 7)
	{
		printf("No enemies found!\n");
	}
	else
	{
		TBC->CheckSpeed(Character, PP);
	}
	
}

void Maps::GenerateNewMap(vector<vector<string>>& NewMap, int VectorColumn, int VectorRow, string GrassNode)
{
	for (size_t i = 0; i < VectorColumn; i++)
	{
		for (size_t j = 0; j < VectorRow; j++)
		{
			NewMap[i][j] = GrassNode;
		}
	}
}

void Maps::DisplayNewMap(vector<vector<string>> NewMap, int VectorColumn, int VectorRow)
{
	printf("******************************\n");
	for (size_t i = 0; i < VectorColumn; i++)
	{
		cout << "\n||";
		for (size_t j = 0; j < VectorRow; j++)
		{
			cout << NewMap[i][j] << "||";
		}
	}
}

void Maps::NewMapInit(unique_ptr <CharacterPlayer>& Character, unique_ptr <Enemy>& PP, unique_ptr<TurnBasedCombat>& TBC, unique_ptr<Maps>& Map1, int & PlayerXValue, int & PlayerYValue)
{
	GenerateNewMap(NewMap, VectorColumn, VectorRow, GrassNode);

	GenerateHomeTownBBBBMap(NewMap, HomeTown, HomeTownXValue, HomeTownYValue, BillysBigBobbaBungalow, BBBBXValue, BBBBYValue);

	NewMap[PlayerXValue][PlayerYValue] = PlayerNode;

	do
	{
		DidPlayerArriveAtLocation(PlayerXValue, PlayerYValue, HomeTownXValue, HomeTownYValue, BBBBXValue, BBBBYValue, Map1, Character, PP, TBC);
		DisplayNewMap(NewMap, VectorColumn, VectorRow);
		cout << endl;
		Character->CheckIfLvlUp(Character->PlayerEXP, Character->PlayerLevel, Character->LevelIdentifier);
		Character->HUD();
		printf("\n=================================\n");
		printf("Press D to move right\n");
		printf("Press S to move down\n");
		printf("Press A to move left\n");
		printf("Press W to move up\n");
		printf("=================================\n");
		printf("Press E to see Enemy Table\n");
		printf("Press Z to exit the map");
		printf("\n=================================\n");

		cin >> DirectionSelectionInput;

		MapsCharInputValidation(DirectionSelectionInput);

		//system("CLS");
		//ADD DATA VALIDATION FUNCTION!!!

		if (DirectionSelectionInput == 'D' || DirectionSelectionInput == 'd')
		{
			if (PlayerYValue == (VectorRow - 1))
			{
				DisplayOutofBoundsMessage();
			}
			else
			{
				printf("You have moved right!\n");
				NewMap[PlayerXValue][PlayerYValue] = GrassNode;
				PlayerYValue = PlayerYValue++;
				NewMap[PlayerXValue][PlayerYValue] = PlayerNode;
				InitCombat(Character, PP, TBC);
			}

		}
		else if (DirectionSelectionInput == 'S' || DirectionSelectionInput == 's')
		{
			if (PlayerXValue == (VectorColumn - 1))
			{
				DisplayOutofBoundsMessage();
			}
			else
			{
				printf("You have moved down!\n");
				NewMap[PlayerXValue][PlayerYValue] = GrassNode;
				PlayerXValue = PlayerXValue++;
				NewMap[PlayerXValue][PlayerYValue] = PlayerNode;
				InitCombat(Character, PP, TBC);
			}

		}
		else if (DirectionSelectionInput == 'A' || DirectionSelectionInput == 'a')
		{
			if (PlayerYValue == 0)
			{
				DisplayOutofBoundsMessage();
			}
			else
			{
				printf("You have moved left!\n");
				NewMap[PlayerXValue][PlayerYValue] = GrassNode;
				PlayerYValue = PlayerYValue--;
				NewMap[PlayerXValue][PlayerYValue] = PlayerNode;
				InitCombat(Character, PP, TBC);
			}
		}
		else if (DirectionSelectionInput == 'W' || DirectionSelectionInput == 'w')
		{
			if (PlayerXValue == 0)
			{
				DisplayOutofBoundsMessage();
			}
			else
			{
				printf("You have moved up!\n");
				NewMap[PlayerXValue][PlayerYValue] = GrassNode;
				PlayerXValue = PlayerXValue--;
				NewMap[PlayerXValue][PlayerYValue] = PlayerNode;
				InitCombat(Character, PP, TBC);
			}

		}
		else if (DirectionSelectionInput == 'E' || DirectionSelectionInput == 'e')
		{
			PP->DisplaySpawnTable();
		}
		else
		{
			printf("Invalid selection, please try again\n");
		}

	} while (DirectionSelectionInput != 'Z');
}


void Maps::HomeTownMenu(unique_ptr<Maps>& Map1, unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP, unique_ptr<TurnBasedCombat>& TBC)
{
	do
	{
		printf("*====================*\n");
		printf("*******HomeTown*******\n");
		printf("*====================*\n");
		printf("Press 1 to hit the road\n");
		printf("Press 2 to see your stats\n");
		printf("Press 3 to see your quest log\n");
		printf("*====================*\n");
		cin >> selection;
		MapsInputValidation(selection);

		if (selection == 1)
		{
			PlayerXValue = 0;
			PlayerYValue = 1;
			Map1->NewMapInit(Character, PP, TBC, Map1, PlayerXValue, PlayerYValue);
		}
		else if (selection == 2)
		{
			Character->HUD();
		}
		else if (selection == 3)
		{

		}
		else
		{
			printf("Please enter a valid entry!\n");
		}

	} while (selection != 9);

}

void Maps::GenerateHomeTownBBBBMap(vector<vector<string>> &NewMap, string& HomeTown, int &HomeTownXValue, int &HomeTownYValue, string &BillysBigBobbaBungalow, int &BBBBXValue, int &BBBBYValue)
{
	HomeTown = "**HT**";
	HomeTownXValue = 0;
	HomeTownYValue = 0;
	NewMap[HomeTownXValue][HomeTownYValue] = HomeTown;

	BillysBigBobbaBungalow = "*BBBB*";
	BBBBXValue = 4;
	BBBBYValue = 4;
	NewMap[BBBBXValue][BBBBYValue] = BillysBigBobbaBungalow;
}

void Maps::DidPlayerArriveAtLocation(int PlayerXValue, int PlayerYValue, int HomeTownXValue, int HomeTownYValue, int BBBBXValue, int BBBBYValue, unique_ptr<Maps>& Map1, unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP, unique_ptr<TurnBasedCombat>& TBC)
{
	if (PlayerXValue == HomeTownXValue && PlayerYValue == HomeTownYValue)
	{
		HomeTownMenu(Map1, Character, PP, TBC);
	}
	else if (PlayerXValue == BBBBXValue && PlayerYValue == BBBBYValue)
	{
		BillysBigBobaBungalowMenu(Map1, Character, PP, TBC);
	}
	else
	{
	}
}

void Maps::BillysBigBobaBungalowMenu(unique_ptr<Maps>& Map1, unique_ptr<CharacterPlayer>& Character, unique_ptr<Enemy>& PP, unique_ptr<TurnBasedCombat>& TBC)
{
	do
	{
		printf("==============================\n");
		printf("**Billy's Big Boba Bungalow **\n");
		printf("==============================\n");
		printf("Press 1 to hit the road\n");
		printf("Press 2 to see your stats\n");
		cin >> selection;
		MapsInputValidation(selection);

		if (selection == 1)
		{
			PlayerXValue = 4;
			PlayerYValue = 3;
			Map1->NewMapInit(Character, PP, TBC, Map1, PlayerXValue, PlayerYValue);
		}
		else if (selection == 2)
		{
			Character->HUD();
		}
		else
		{
			printf("Please enter a valid entry!\n");
		}

	} while (selection != 9);


}

int Maps::MapsInputValidation(int &selection)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("Please enter a valid input!\n");
			cin >> selection;
		}
		else
		{
			break;
		}
	}
	return selection;
}

char Maps::MapsCharInputValidation(char& DirectionSelectionInput)
{
	{
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				printf("Please enter a valid input!\n");
				cin >> DirectionSelectionInput;
			}
			else
			{
				break;
			}
		}
		return DirectionSelectionInput;
	}
}

void Maps::DisplayOutofBoundsMessage()
{
	printf("You are at the edge and cannot move further!\n");
}


Maps::~Maps()
{

}
