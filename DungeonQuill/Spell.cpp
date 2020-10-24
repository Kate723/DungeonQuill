#include "Spell.h"

std::string Spell::schoolName[] = { "", "防护", "咒法", "预言", "附魔" ,"塑能" ,"幻术" ,"死灵" ,"变化" };

std::string Spell::getNameCH() {
	return this->nameCh;
}

std::string Spell::getNameEN() {
	return this->nameEn;
}

std::string Spell::getSchoolName() {
	return this->schoolName[schoolID];
}

int Spell::getLevel() {
	return level;
}

bool Spell::spellIsRitual() {
	return isRitual;
}

std::string Spell::getRemarks() {
	return remarks;
}