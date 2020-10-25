#include "Spell.h"

std::string Spell::schoolName[] = {"防护", "咒法", "预言", "附魔" ,"塑能" ,"幻术" ,"死灵" ,"变化" };

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

std::string Spell::getLevelString() {
	std::string levelString[] = { "戏法", "一环", "二环", "三环", "四环", "五环",
		"六环", "七环", "八环", "九环", };
	return levelString[level];
}

bool Spell::spellIsRitual() {
	return isRitual;
}

std::string Spell::getRemarks() {
	return remarks;
}

std::string Spell::getCastingTimeRemarks() {
	return castingTime.remarks;
}

std::string Spell::getRangeString() {
	if (range)
	{
		return std::to_string(range) + "尺";
	}
	if (isSelfOnly)
	{
		return std::string("自身");
	}
	else
		return std::string("触及");
}

std::string Spell::getComponentString() {
	std::string compomentString;
	if (componments.verbalNeed) {
		compomentString += 'V';
	}
	if (componments.somaticNeed) {
		if(!compomentString.empty())
			compomentString += '、';
		compomentString += 'S';
	}
	if (componments.materialNeed) {
		if (!compomentString.empty())
			compomentString += '、';
		compomentString += "M（" + componments.remark + "）";
	}
	return compomentString;
}

std::string Spell::getDurationString() {
	std::string durationString;
	if (duration.concentrationNeed) {
		durationString += "专注，";
	}
	durationString += duration.remarks;
	return durationString;
}