/*创建日期：2020/9/25
* 类名称：怪物
* 类用途：存储怪物相关数据
* 作者：吴彤
*/

#pragma once
#include "CombatCharacter.h"

class Monster :
    public CombatCharacter
{
    BasicInfo raceInfo;                         //种族信息
    std::vector<CombatAction> actionList;		//动作列表
public:
    static int monsterNum;                      //怪物数目
    static std::vector<Monster*> monsterList;   //怪物列表
    Monster(int ttid, std::string ttname, int tspeed, int tmaxHitPoint, int tcurHitPoint, int ttempHitPoint,int tid, std::string tname, 
        std::string tremarks):
    CombatCharacter(ttid,ttname,tspeed, tmaxHitPoint, tcurHitPoint, ttempHitPoint),raceInfo(tid, tname, tremarks),actionList(){}

    virtual QString getRaceName();
};

