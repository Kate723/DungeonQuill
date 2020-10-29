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
	CharacterDisplay(Adventurer* _character);
	~CharacterDisplay();

private:
	Ui::CharacterDisplay ui;
	Adventurer* character;
	std::vector<QComboBox*> proBoxList;

	QTableWidgetItem* tableItem(const char* str);
	QTableWidgetItem* tableItem(QString str);
	QTableWidgetItem* tableItem(std::string str);
	QTableWidgetItem* tableItem(int num);
	QComboBox* newProBox();
	void initFormat();
	void initBasicInfo();
	void initBgTab();
	void initMainTab();
	void initSkillTable();
	void initTableFormat(const QTableWidget* table, const int HeaderWidth = 50);

	void initContent();
	void initBasicContent();
	void initGenderBox(int index = 0);
	void initRaceBox(int index = 0);
	void initAligBox(int index = 0);
	void setProBox();
	void initHPContent();
	void initAbilityContent();
	void initBGContent();
	void initWealthTable();
};
