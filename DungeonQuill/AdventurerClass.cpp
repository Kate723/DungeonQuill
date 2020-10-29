#include "AdventurerClass.h"

int AdventurerClass::getProBonus() {
	return (level - 1) / 4;
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