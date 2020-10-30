/*创建日期：2020/9/18
* 类名称：战斗棋子
* 类用途：存储战斗地图上角色位置/法术影响区域
* 作者：吴彤
*/
#pragma once
#include "Area.h"
#include "Adventurer.h"

class MapEditor;
class CombatManager;

class CombatPiece
{
	int x, y;						//xy坐标，角色被视为位于中央

	int type;						//棋子类型，1怪物/冒险者，2召唤物/灵能武器/文字标签等，3法术影响区域
	BasicInfo pieceInfo;			//棋子信息
	Area occupiedArea;				//占据区域（画图用）
	
	Adventurer *character;		//代表战斗角色
	CombatPiece(Adventurer* character = NULL);

	friend MapEditor;
	friend CombatManager;
};

