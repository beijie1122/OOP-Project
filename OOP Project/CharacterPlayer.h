#pragma once
#include "Player.h"
#include <vector>
#include <string>


using namespace std;


class CharacterPlayer :
    public Player
{
public:

    vector <string> CharacterPlayerName{};
    vector <int> CharacterPlayerHP{};
    vector <int> CharacterPlayerAtt{};
    vector <int> CharacterPlayerSpd{};
    vector <int> CharacterPlayerLvl{};
    int CharacterPlayerExp{};

    int LevelIdentifier{};
    


    CharacterPlayer();

    CharacterPlayer(string PlayerName, int PlayerLevel, int PlayerHP, int PlayerAtt, int PlayerSpeed, int PlayerEXP);

    void InitCharacterPlayerStats();

    void CheckIfLvlUp(int PlayerExp, int &PlayerLevel, int LevelIdentifier);

    void LevelUpFunction(int LevelIdentifier);

    ~CharacterPlayer();



};

