#include "Monster.h"

int Monster::monsterNum = 0;
std::vector<Monster*> Monster::monsterList = std::vector<Monster*>();

QString Monster::getRaceName() {
	return raceInfo.getName();
}