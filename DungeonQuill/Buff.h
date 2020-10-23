/*创建日期：2020/10/7
* 类名称：法术增益
* 类用途：在战斗中存储法术增/减益对角色的影响。
* 作者：吴彤
*/

#pragma once
#include "BasicInfo.h"
#include "CombatCharacter.h"

class Buff
{
	BasicInfo* buffInfo;					//基本信息
	CombatCharacter* sourceCharacter;		//源角色
	int startRound;							//开始轮次
	int lastTime;							//持续时间
	AbilityType dependAbility;				//依赖检定属性

public:
	Buff(BasicInfo* _buffInfo = NULL, CombatCharacter* _sourceCharacter = NULL);//构造函数
};

