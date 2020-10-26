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
	SpellDisplay(Spell* displaySpell = NULL);
	~SpellDisplay();

private:
	Ui::SpellDisplay ui;
	Spell* spell;

	void initFormat();
	QTableWidgetItem* tableItem(QString str, QFont font,QColor color = QColor(0,0,0),int codeType = 0);
	void initTableFormat(const QTableWidget* table);
};
