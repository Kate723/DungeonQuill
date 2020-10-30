/*创建日期：2020/10/16
* 类名称：战斗管理系统
* 类用途：管理战斗流程
* 作者：吴彤
*/
#pragma once

#include <QObject>
#include <queue>
#include "EnumType.h"
#include "InitiativeRoll.h"
#include "CombatMap.h"
#include "MapEditor.h"

class CombatManager : public QObject
{
	Q_OBJECT

	static CombatManager* instance;

	CombatCondition conditionFlag;
	CombatMap* map;							//战斗地图
	MapEditor* combatWin;					//战斗窗口
	QScrollArea* combatQueueArea;			//战斗队列显示
	std::queue<CombatPiece*> actionQueue;	//先攻队列

	void characterSort(std::vector<Adventurer*> characterList);
	void initQuickSort(std::vector<Adventurer*> &characterList, int begin, int end);
	void initQueue(std::vector<Adventurer*> characterList);

public slots:
	static void combatStart(CombatMap* _map, MapEditor* _combatWin);
	static void combatEnd();

public:
	CombatManager();
	~CombatManager();
	static CombatCondition getCombatCondition();
	static void setCombatCondition(CombatCondition condition);
	static void characterSelected(std::vector<Adventurer*> characterList);
};
