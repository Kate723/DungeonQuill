#pragma once

#include <QWidget>
#include <qcombobox.h>
#include <qstring.h>
#include <qfontmetrics.h>
#include "ui_CharacterDisplay.h"
#include "Adventurer.h"

class CharacterDisplay : public QWidget
{
	Q_OBJECT

public:
	static QTableWidgetItem* tableItem(const char* str);
	static QTableWidgetItem* tableItem(QString str);
	static QTableWidgetItem* tableItem(std::string str);
	static QTableWidgetItem* tableItem(int num);
	static void initTableFormat(const QTableWidget* table, const int HeaderWidth = 50);

	CharacterDisplay(Adventurer* _character);
	~CharacterDisplay();

private:
	Ui::CharacterDisplay ui;
	Adventurer* character;
	std::vector<QComboBox*> proBoxList;

	QComboBox* newProBox();
	void initFormat();
	void initBasicInfo();
	void initBgTab();
	void initMainTab();
	void initSkillTable();
	void initTextEditFormat(QTextEdit* edit);

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
	void initSpellSlots();
};
