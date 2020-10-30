#pragma once

#include <QWidget>
#include <qtablewidget.h>
#include "CharacterDisplay.h"
#include "DiceMaid.h"
#include "ui_InitiativeRoll.h"

class InitiativeRoll : public QWidget
{
	Q_OBJECT

public:
	InitiativeRoll(std::vector<Adventurer*> characterList);
	~InitiativeRoll();

private:
	Ui::InitiativeRoll ui;
};
