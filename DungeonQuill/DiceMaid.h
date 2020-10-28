#pragma once

#include <QObject>
#include <qtimer.h>
#include <qdebug.h>
#include "DungeonQuill.h"
#include "DiceRollType.h"

class DiceMaid : public QObject
{
	static DiceMaid* instance;
	Ui::DungeonQuillClass* ui;
	Q_OBJECT

	void initDiceTab();
	int* diceRoll(DiceRollType* dice);
	void sleep(int msec);

public slots:
	void diceRollButtonClicked();

public:
	DiceMaid();
	~DiceMaid();
};
