#include "Maps.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

void Maps::display(list<string> const& Map2)
{
	cout << "[||";
	for (auto const& i : Map2)
	{
		cout << i << "||";
	}
	cout << "]" << " ";
}

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


void Maps::InitMap2(unique_ptr <CharacterPlayer>& Character, unique_ptr <Enemy>& PP, unique_ptr<TurnBasedCombat>& TBC)
{
	P1 = { "You" };
	P2 = { "Grass" };
	Map2 = { P1, P2, P2, P2, P2 };
	EventPoint1 = { "Hometown" };
	EventPoint2 = { "Billy's Big Boba Bungalow" };

	//list<string>::iterator pr;
	//for (pr = Map2.begin(); pr != Map2.end(); pr++)
	//{
	//	cout << *pr;
	//}

	do
	{
		cout << EventPoint1 << " ";
		display(Map2);
		cout << EventPoint2 << endl;
		printf("=====================\n");
		printf("Press 1 to move LEFT\n");
		printf("Press 2 to move Right\n");
		printf("=====================\n");
		cin >> selection;

		if (selection == 1)
		{
			auto it = find(Map2.begin(), Map2.end(), P1);
			if(it == Map2.begin())
			{
				printf("Arrived at HomeTown!\n");
			}
			else
			{
				auto it = find(Map2.begin(), Map2.end(), P1);
				if (it != Map2.end())
				{
					Map2.insert(it--, P2);
					Map2.erase(it++);
					Map2.insert(it++, P1);
					Map2.erase(it);
					InitCombat(Character, PP, TBC);
					
				}
			}
		}
		else if (selection == 2)
		{
			if (Map2.back() == P1)
			{
				printf("You have reached Billy's Big Boba Bungalow!\n");
			}
			else
			{
				auto ot = find(Map2.begin(), Map2.end(), P1);
				if (ot != Map2.end())
				{
					Map2.insert(ot++, P1);
					Map2.erase(ot--);
					Map2.insert(ot--, P2);
					Map2.erase(ot);
					InitCombat(Character, PP, TBC);
				}
			}
		}
		else
		{
			printf("Press enter a correct entry!\n");
		}

	} while (selection != 9);
		

}

Maps::~Maps()
{

}
