#pragma once

#include <QWidget>
#include <qcheckbox.h>
#include <qlayout.h>
#include "Adventurer.h"
#include "CombatManager.h"
#include "ui_CharacterChoose.h"

class CharacterChoose : public QWidget
{
	Q_OBJECT

public slots:
	void characterSelected();

public:
	CharacterChoose();
	~CharacterChoose();

private:
	Ui::CharacterChoose ui;
	std::vector<QCheckBox*> checkBoxList;
};
