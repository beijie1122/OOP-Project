#include "QuestBase.h"

QuestBase::QuestBase()
{

}

void QuestBase::InitializeQuests()
{
	QuestNameVec = { "Journey to The Bungalow", "Culling the Field", "Why is this one back again?" };
	QuestEXPGainedVec = { 10, 15, 15 };
	QuestDescriptionVec = { "Travel to Billy's Big Bobba Bungalow. See your map for details.", "Slay 5 enemies of any type in the overworld.", 
		"Report back to ranger Roger about your encounter. Ranger Roger can be found in your HomeTown." };

	unique_ptr <QuestBase> Quest1 = make_unique <QuestBase>();
	unique_ptr <QuestBase> Quest2 = make_unique <QuestBase>();
	unique_ptr <QuestBase> Quest3 = make_unique <QuestBase>();

	QuestList.emplace_back(*Quest1);
	QuestList.emplace_back(*Quest2);
	QuestList.emplace_back(*Quest3);

	vector<QuestBase>::iterator VecSetupIterator;

	for (VecSetupIterator = QuestList.begin(); VecSetupIterator != QuestList.end(); VecSetupIterator++)
	{
		VecSetupIterator->QuestName = QuestNameVec.at(0);
		VecSetupIterator->QuestEXPGained = QuestEXPGainedVec.at(0);
		VecSetupIterator->QuestDescription = QuestDescriptionVec.at(0);
		VecSetupIterator->QuestStartedTracker = false;
		VecSetupIterator->QuestCompleteTracker = false;
		VecSetupIterator->QuestProgressTracker = 0;
		QuestNameVec.erase(QuestNameVec.begin());
		QuestEXPGainedVec.erase(QuestEXPGainedVec.begin());
		QuestDescriptionVec.erase(QuestDescriptionVec.begin());
	}
}

void QuestBase::DisplayQuestDetails()
{
	vector<QuestBase>::iterator DisplayIterator;
	
	for (DisplayIterator = QuestList.begin(); DisplayIterator != QuestList.end(); DisplayIterator++)
	{
		cout << DisplayIterator->QuestName << endl;
		cout << DisplayIterator->QuestDescription << endl;
	}
}

QuestBase::~QuestBase()
{

}