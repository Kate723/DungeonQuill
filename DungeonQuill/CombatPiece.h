/*创建日期：2020/9/18
* 类名称：战斗棋子
* 类用途：存储战斗地图上角色位置/法术影响区域
* 作者：吴彤
*/

#include "Area.h"
#include "CombatCharacter.h"

#pragma once
class CombatPiece
{
	int x, y;						//xy坐标，角色被视为位于中央

	int type;						//棋子类型，1怪物/冒险者，2召唤物/灵能武器等，3法术影响区域
	Area occupiedArea;				//占据区域（画图用）
	int id;							//战斗角色id
	CombatCharacter *character;		//代表战斗角色

	CombatPiece(const CombatCharacter character,int _x,int _y);
};

