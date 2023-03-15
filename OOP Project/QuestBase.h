#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class QuestBase
{

public:

	//Individual Values
	int QuestProgressTracker{};
	bool QuestStartedTracker{};
	bool QuestCompleteTracker{};
	string QuestName{};
	int QuestEXPGained{};
	string QuestDescription{};

	//Value Vecctors
	vector<string> QuestNameVec{};
	vector<int> QuestEXPGainedVec{};
	vector<string> QuestDescriptionVec{};
	vector<QuestBase> QuestList{};


	QuestBase();

	void InitializeQuests();

	void DisplayQuestDetails();

	~QuestBase();



};

