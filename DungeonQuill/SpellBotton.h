#pragma once

#include <qtoolbutton.h>
#include "Spell.h"
#include "SpellDisplay.h"

class SpellBotton : public QToolButton
{
	Spell* spell;

	Q_OBJECT
		
public slots:
	void displaySpell();

public:
	SpellBotton(Spell* _spell);
	~SpellBotton();
};
