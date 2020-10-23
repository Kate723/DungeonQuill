#include "AbilityScore.h"

std::string AbilityScore::abilityNameEn[] = { "","strength","dexterity","constitution",
												"intelligence", "wisdom", "charisma" };
std::string AbilityScore::abilityNameCh[] = { "","力量","敏捷","体质",
												"智力", "感知", "魅力" };

AbilityScore::AbilityScore(int defaultnum) {
	for (int i = 1; i <= ABILITY_NUM; i++) {
		abilityScore[i] = defaultnum;
		abilityProficiency[i] = false;
	}
}

int AbilityScore::getAbilityScore(int id) {
	return abilityScore[id];
}

int AbilityScore::getAbilityScore(std::string name) {
	int id;
	for (id = 1; id <= ABILITY_NUM; id++) {
		if (abilityNameEn[id] == name || abilityNameCh[id] == name) break;
	}
	return abilityScore[id];
}

int AbilityScore::getAbilityModifier(int id) {
	return (abilityScore[id] - 10) / 2;
}

int AbilityScore::getAbilityModifier(std::string name) {
	int id;
	for (id = 1; id <= ABILITY_NUM; id++) {
		if (abilityNameEn[id] == name || abilityNameCh[id] == name) break;
	}
	return (abilityScore[id] - 10) / 2;
}