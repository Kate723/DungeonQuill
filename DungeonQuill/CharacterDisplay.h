#pragma once

#include <QWidget>
#include <qcombobox.h>
#include <qstring.h>
#include "ui_CharacterDisplay.h"
#include "Adventurer.h"

class CharacterDisplay : public QWidget
{
	Q_OBJECT

public:
	CharacterDisplay(Adventurer* dispalyCharacter);
	~CharacterDisplay();

private:
	Ui::CharacterDisplay ui;
	Adventurer* character;

	QTableWidgetItem* tableItem(const char* str);
	QComboBox* newProBox();
	void initFormat();
	void initBasicInfo();
	void initBgTab();
	void initMainTab();
	void initSkillTable();
	void initTableFormat(const QTableWidget* table, const int HeaderWidth = 50);
};
