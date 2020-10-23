#pragma once

#include <QWidget>
#include <qcombobox.h>
#include <qstring.h>
#include "ui_CharacterDisplay.h"

class CharacterDisplay : public QWidget
{
	Q_OBJECT

public:
	CharacterDisplay(QWidget *parent = Q_NULLPTR);
	~CharacterDisplay();

private:
	Ui::CharacterDisplay ui;
	QTableWidgetItem* tableItem(const char* str);
	QComboBox* newProBox();
	void initFormat();
	void initBasicInfo();
	void initBgTab();
	void initMainTab();
	void initSkillTable();
	void initTableFormat(const QTableWidget* table, const int HeaderWidth = 50);
};
