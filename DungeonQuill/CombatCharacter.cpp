#include "CombatCharacter.h"

std::string CombatCharacter::conditionName[] = {"目盲", "魅惑" , "耳聋", "恐慌", 
"擒抱", "失能", "隐形", "麻痹", "石化", "中毒", "倒地", "束缚", "震慑", "昏迷"};

int CombatCharacter::getID() {
	return id;
}

QString CombatCharacter::getName() {
	return QString::fromUtf8(name.c_str());
}

QString CombatCharacter::getRaceName() {
	return NULL;
}

QString CombatCharacter::getSizeString() {
	switch (size)
	{
	case Size::TINY :
		return QString::fromLocal8Bit("微型");
		break;
	case Size::SMALL:
		return QString::fromLocal8Bit("小型");
		break; 
	case Size::MEDIUM:
		return QString::fromLocal8Bit("中型");
		break; 
	case Size::LARGE:
		return QString::fromLocal8Bit("大型");
		break; 
	case Size::HUGE_S:
		return QString::fromLocal8Bit("巨型");
		break; 
	case Size::GARGANTUAN:
		return QString::fromLocal8Bit("超巨型");
		break;
	default:
		break;
	}

	return nullptr;
}

QString CombatCharacter::getSpeedString() {
	return QString::number(speed) + QString::fromLocal8Bit("尺");
}

QString CombatCharacter::getHPString() {
	return QString::number(curHitPoint) + '/' + QString::number(maxHitPoint);
}

AbilityScore* CombatCharacter::Ability() {
	return &abilityScore;
}

const bool* CombatCharacter::getSkillProList() {
	return skillPro;
}

const std::vector<std::string> CombatCharacter::getEquipmentProList() {
	return equipmentProList;
}

int CombatCharacter::getSpeed() {
	return speed;
}

int* CombatCharacter::getHPdata() {
	int hpData[] = { maxHitPoint,curHitPoint,tempHitPoint };

	return hpData;
}

int CombatCharacter::getInitiativePlus() {
	return 0;
}

void CombatCharacter::setInitiativeData(int* data) {
	for (int i = 0; i < 3; i++) {
		*(initiative + i) = *(data + i);
	}
}

int* CombatCharacter::getInitiativeData() {
	return initiative;
}

QString CombatCharacter::getInitiativeString() {
	if (!initiative) return nullptr;
	return QString::number(initiative[1]) + '+' + QString::number(initiative[2]) + '=' + QString::number(initiative[0]);
}

bool CombatCharacter::compareInitiative(CombatCharacter* last) {
	if (this->initiative[0] == last->initiative[0])
		return this->initiative[2] > last->initiative[2];
	return this->initiative[0] > last->initiative[0];
}
