#pragma once

#include <qtoolbutton.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include "Spell.h"
#include "SpellDisplay.h"

class SpellBotton : public QToolButton
{
	Spell* spell;
	QTextBrowser* spellText;

	Q_OBJECT

	void setSpellText();
		
public slots:
	void displaySpell();

public:
	SpellBotton(Spell* _spell);
	~SpellBotton();
};
