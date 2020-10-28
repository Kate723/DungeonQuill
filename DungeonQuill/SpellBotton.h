#pragma once

#include "DisplayButton.h"
#include "Spell.h"
#include "SpellDisplay.h"

class SpellBotton : public DisplayButton
{
	Spell* spell;
	Q_OBJECT

	virtual void setDisplayText();
		
public slots:
	void displaySpell();

public:
	SpellBotton(Spell* _spell);
	~SpellBotton();
};
