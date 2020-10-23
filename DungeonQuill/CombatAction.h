/*创建日期：2020/9/25
* 类名称：战斗动作
* 类用途：存储参与战斗的角色的战斗动作
* 作者：吴彤
*/

#pragma once
#include <vector>
#include "EnumType.h"
#include "BasicInfo.h"
#include "DiceRollType.h"

class CombatAction
{
	BasicInfo actionInfo;					//动作信息				
	int diceAddition;						//命中加值
	int range;								//触及范围
	std::vector<DiceRollType> damageDice;	//伤害骰
};

