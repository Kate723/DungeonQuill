#include "CombatCharacter.h"

std::string CombatCharacter::conditionName[] = {"目盲", "魅惑" , "耳聋", "恐慌", 
"擒抱", "失能", "隐形", "麻痹", "石化", "中毒", "倒地", "束缚", "震慑", "昏迷"};

QString CombatCharacter::getName() {
	return QString::fromUtf8(name.c_str());
}

QString CombatCharacter::getRaceName() {
	return NULL;
}