#include "Spell.h"

std::string Spell::schoolName[] = {"防护", "咒法", "预言", "附魔" ,"塑能" ,"幻术" ,"死灵" ,"变化" };

int Spell::getID() {
	return ID;
}

int Spell::getSchoolID() {
	return schoolID;
}

QString Spell::getNameCH() {
	return QString::fromUtf8(nameCh.c_str());
}

QString Spell::getNameEN() {
	return QString::fromUtf8(nameEn.c_str());
}

QString Spell::getSchoolName() {
	return QString::fromLocal8Bit(schoolName[schoolID].c_str());
}

int Spell::getLevel() {
	return level;
}

QString Spell::getLevelString() {
	std::string levelString[] = { "戏法", "一环", "二环", "三环", "四环", "五环",
		"六环", "七环", "八环", "九环", };
	return QString::fromLocal8Bit(levelString[level].c_str());
}

bool Spell::spellIsRitual() {
	return isRitual;
}

QString Spell::getRemarks() {
	return QString::fromUtf8(remarks.c_str());
}

QString Spell::getCastingTimeRemarks() {
	return QString::fromUtf8(castingTime.remarks.c_str());
}

QString Spell::getRangeString() {
	if (range)
	{
		return QString::number(range) + QString::fromLocal8Bit("尺");
	}
	if (isSelfOnly)
	{
		return QString::fromLocal8Bit("自身");
	}
	else
		return QString::fromLocal8Bit("触及");
}

QString Spell::getComponentString() {
	QString compomentString;
	if (componments.verbalNeed) {
		compomentString += QString::fromLocal8Bit("V");
	}
	if (componments.somaticNeed) {
		if(!compomentString.isEmpty())
			compomentString += QString::fromLocal8Bit("、");
		compomentString += QString::fromLocal8Bit("S");
	}
	if (componments.materialNeed) {
		if (!compomentString.isEmpty())
			compomentString += QString::fromLocal8Bit("、");
		compomentString += QString::fromLocal8Bit("M（") + QString::fromUtf8(componments.remark.c_str()) + QString::fromLocal8Bit("）");
	}
	return compomentString;
}

QString Spell::getDurationString() {
	QString durationString;
	if (duration.concentrationNeed) {
		durationString += QString::fromLocal8Bit("专注，");
	}
	durationString += QString::fromUtf8(duration.remarks.c_str());
	return durationString;
}