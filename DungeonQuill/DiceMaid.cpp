#include "DiceMaid.h"

DiceMaid* DiceMaid::instance = nullptr;

DiceMaid::DiceMaid()
{
	if (instance) {
		delete this;
		return;
	}

	instance = this;
}

DiceMaid::~DiceMaid()
{
}

int DiceMaid::Random(int x) {
	std::random_device rd;			//真随机数生成器生成种子
	std::mt19937 eng(rd());			// 使用梅森旋转法作为伪随机数生成器
	std::uniform_int_distribution<int> dis(1, x); //整数均匀分布

	return dis(eng);
}

int* DiceMaid::diceRoll(DiceRollType* dice) {
	if (dice->diceNum <= 0 || dice->diceSideNum <= 0) return nullptr;

	auto diceList = (int *)malloc(sizeof(int) * ((size_t)dice->diceNum + (size_t)1));
	if(!diceList) return nullptr;

	int res = 0;
	for (auto i = diceList; i < diceList + dice->diceNum; i++) {
		*i = instance->Random(dice->diceSideNum);
		res += *i;
	}
	diceList[dice->diceNum] = res;

	return diceList;
}

void DiceMaid::initiativeRoll(Adventurer* character) {
	static int rollRes[] = { 0,0,0 };
	rollRes[1] = instance->Random(20);
	rollRes[2] = character->getInitiativePlus();
	*rollRes = rollRes[1] + rollRes[2];
	
	character->setInitiativeData(rollRes);
}
