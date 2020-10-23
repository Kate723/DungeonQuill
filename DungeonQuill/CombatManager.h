/*创建日期：2020/10/16
* 类名称：战斗管理系统
* 类用途：管理战斗流程
* 作者：吴彤
*/

#pragma once
#include <queue>
#include "CombatMap.h"
#include "CombatCharacter.h"

class CombatManager
{
	static CombatManager* instance;
	CombatMap* map;								//战斗地图
	std::queue<CombatCharacter*> actionQueue;	//先攻队列
public:
	CombatManager();
};

