#pragma once

#include <QObject>
#include <qtimer.h>
#include <random>
#include "DiceRollType.h"
#include "Adventurer.h"

class Adventurer;

class DiceMaid : public QObject
{
	static DiceMaid* instance;
	Q_OBJECT

	int Random(int x);	

public:
	DiceMaid();
	~DiceMaid();

	static int* diceRoll(DiceRollType* dice);
	static void initiativeRoll(Adventurer* character);
};
