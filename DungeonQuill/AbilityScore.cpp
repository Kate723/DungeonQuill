#include "AbilityScore.h"

std::string AbilityScore::abilityNameEn[] = { "strength","dexterity","constitution",
												"intelligence", "wisdom", "charisma" };
std::string AbilityScore::abilityNameCh[] = { "力量","敏捷","体质",
												"智力", "感知", "魅力" };

AbilityScore::AbilityScore(int defaultnum) {
	for (int i = 0; i < ABILITY_NUM; i++) {
		abilityScore[i] = defaultnum;
		abilityProficiency[i] = false;
	}
}

const int AbilityScore::getAbilityScore(int id) {
	return abilityScore[id];
}

const int AbilityScore::getAbilityScore(std::string name) {
	int id;
	for (id = 0; id < ABILITY_NUM; id++) {
		if (abilityNameEn[id] == name || abilityNameCh[id] == name) break;
	}
	return abilityScore[id];
}

const int AbilityScore::getAbilityModifier(int id) {
	return (abilityScore[id] - 10) / 2;
}

const int AbilityScore::getAbilityModifier(std::string name) {
	int id;
	for (id = 0; id < ABILITY_NUM; id++) {
		if (abilityNameEn[id] == name || abilityNameCh[id] == name) break;
	}
	return (abilityScore[id] - 10) / 2;
}

const bool* AbilityScore::getProList() {
	return abilityProficiency;
}