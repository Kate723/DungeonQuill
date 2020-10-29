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
    Monster(int ttid, std::string ttname, CharacterType ttype, int as0, int as1, int as2, int as3, int as4, int as5,
        bool ap0, bool ap1, bool ap2, bool ap3, bool ap4, bool ap5,
        bool s0, bool s1, bool s2, bool s3, bool  s4, bool  s5, bool  s6, bool  s7, bool  s8, bool s9, bool  s10,
        bool  s11, bool  s12, bool s13, bool  s14, bool  s15, bool s16, bool s17, bool s18, bool  s19, std::vector<std::string> tequipmentProList,
        Size tsize, int tspeed,
        int tmaxHitPoint, int tcurHitPoint, int ttempHitPointint ,int tid, std::string tname,
        std::string tremarks):
    CombatCharacter(ttid, ttname, ttype, as0, as1, as2, as3, as4, as5, ap0, ap1, ap2, ap3, ap4, ap5, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14,
        s15, s16, s17, s18, s19, tequipmentProList, tsize, tspeed, tmaxHitPoint, tcurHitPoint, ttempHitPointint),raceInfo(tid, tname, tremarks),actionList(){}

    virtual QString getRaceName();
};

