#pragma once

#include <QWidget>
#include <qstring.h>
#include <qmessagebox.h>
#include <string.h>
#include "ui_SpellDisplay.h"
#include "Spell.h"

class SpellDisplay : public QWidget
{
	Q_OBJECT

public:
	SpellDisplay(Spell* displaySpell = NULL, QWidget *parent = Q_NULLPTR);
	~SpellDisplay();

private:
	Ui::SpellDisplay ui;
	Spell* spell;

	void initFormat();
	QTableWidgetItem* tableItem(const char* str,QFont font,QColor color = QColor(255,255,255));
	void initTableFormat(const QTableWidget* table);
};
