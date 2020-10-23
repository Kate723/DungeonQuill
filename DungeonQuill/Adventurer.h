/*创建日期：2020/9/25
* 类名称：冒险者
* 类用途：存储冒险者相关数据
* 作者：吴彤
*/

#pragma once
#include "CombatCharacter.h"
#include "CharacterDetails.h"
#include "AdventurerClass.h"
#include "AdventurerRace.h"
#include "Equipment.h"
#include "Weapon.h"
#include "Amour.h"
#include "Wealth.h"
#include <qstring.h>
#include <vector>

class Adventurer :
    public CombatCharacter
{
    int exp;                    //角色经验
    CharacterDetails details;   //角色细节
    AdventurerRace race;         //角色种族
    AdventurerClass _class;       //角色职业

    int curHitDice;				//当前生命骰
    int maxHitDice;				//最大生命骰

    QString iconPath;           //头像路径
    std::vector<Equipment> equipmentList;       //装备列表
    std::vector<Weapon> weaponList;             //武器列表
    std::vector<Amour> amourList;               //护甲列表
    Wealth characterWealth;                     //角色财富
public:
    static int adventurerNum;                           //冒险者数目
    static std::vector<Adventurer*> adventurerList;     //冒险者列表
    Adventurer(int ttid, std::string ttname, int tspeed, int tmaxHitPoint, int tcurHitPoint, int ttempHitPoint, int texp, bool tsex, int tage, 
        int feet, int inch, int tweight, std::string tideal, std::string tbond, std::string tflaw,std::string tapperance, std::string tbgStory,
        std::string ttttname, int ttttid, std::string tsubName, int tsubID,int tid, std::string tname, std::string tremarks, int tttid, 
        std::string tttname, std::string ttremarks, int tlevel,std::string tspecialAbilityName, int tcurSpecialPoint, int tmaxSpecialPoint,
        int tcurHitDice,int tmaxHitDice,QString ticonPath, int cp, int sp, int ep, int gp, int pp):
    CombatCharacter(ttid, ttname, tspeed, tmaxHitPoint, tcurHitPoint, ttempHitPoint), exp(texp),details(tsex, tage,feet,inch,tweight, tideal, tbond,
        tflaw, tapperance, tbgStory), race(ttttname,ttttid,  tsubName, tsubID),_class(tid, tname, tremarks, tttid,  tttname, ttremarks, tlevel,
            tspecialAbilityName,tcurSpecialPoint,tmaxSpecialPoint), curHitDice(tcurHitDice), maxHitDice(tmaxHitDice), iconPath(ticonPath),
        characterWealth (cp, sp, ep, gp, pp){}
};

