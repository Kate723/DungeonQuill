#include "AdventurerClass.h"

int AdventurerClass::getLV() {
	return level;
}

int AdventurerClass::getProBonus() {
	return (level - 1) / 4 + 2;
}

QString AdventurerClass::getspecialAbilityName() {
	return QString::fromStdString(specialAbilityName);
}

QString AdventurerClass::getspecialAbilityString() {
	return QString::number(curSpecialPoint) + '/' + QString::number(maxSpecialPoint);
}

const int* AdventurerClass::getMaxSpellSlots() {
	return maxSpellSlots;
}

const int* AdventurerClass::getCurSpellSlots() {
	return curSpellSlots;
}

QString* AdventurerClass::getSpellSlotStrings() {
	static QString spellSlot[10];
	for (int i = 0; i < 9; i++) {
		spellSlot[i] = QString::number(curSpellSlots[i + 1]) + '/' + QString::number(maxSpellSlots[i + 1]);
	}

	return spellSlot;
}