﻿#include "Adventurer.h"

QString Adventurer::getHDString() {
	return QString::number(curHitDice) + '/' + QString::number(maxHitDice);
}

QString Adventurer::getRaceName() {
	return race.getRaceName();
}

QString Adventurer::getSubRaceName() {
	if (!race.getSubRaceName().isEmpty())
		return race.getSubRaceName();
	else
		return QString::fromLocal8Bit("-");
}

QString Adventurer::getClassName() {
	return _class._classInfo.getName();
}

QString Adventurer::getPlayerName() {
	return playerName;
}

int Adventurer::getEXP() {
	return exp;
}

int Adventurer::getSkillProBonus(int x) {
	int proBonus = 0;
	switch (x)
	{
	case 0 :
		proBonus += abilityScore.getAbilityModifier(0);
		break;
	case 1: case 2: case 3:
		proBonus += abilityScore.getAbilityModifier(1);
		break;
	case 4: case 5: case 6: case 7: case 8:
		proBonus += abilityScore.getAbilityModifier(3);
		break;
	case 9: case 10: case 11: case 12: case 13:
		proBonus += abilityScore.getAbilityModifier(4);
		break;
	case 14: case 15: case 16: case 17:
		proBonus += abilityScore.getAbilityModifier(5);
		break;
	default:
		break;
	}

	if (skillPro[x])
		proBonus += _class.getProBonus();
	return proBonus;
}

int Adventurer::getInitiativePlus() {
	return abilityScore.getAbilityModifier(1);
}