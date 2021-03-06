﻿/*创建日期：2020/9/25
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
    
    int curHitDice;				//当前生命骰
    int maxHitDice;				//最大生命骰

    QString playerName;           //玩家名称
    
public:
    CharacterDetails details;   //角色细节
    AdventurerRace race;         //角色种族
    AdventurerClass _class;       //角色职业
    std::vector<Equipment> equipmentList;       //装备列表
    std::vector<Weapon> weaponList;             //武器列表
    std::vector<Amour> amourList;               //护甲列表
    Wealth characterWealth;                     //角色财富

    static int adventurerNum;                           //冒险者数目
    static std::vector<Adventurer*> adventurerList;     //冒险者列表

    Adventurer(int ttid, std::string ttname, CharacterType ttype, int as0, int as1, int as2, int as3, int as4, int as5,
        bool ap0, bool ap1, bool ap2, bool ap3, bool ap4, bool ap5,
        bool s0, bool s1, bool s2, bool s3, bool s4, bool s5, bool s6, bool s7, bool s8, bool s9, bool s10,
        bool s11, bool s12, bool s13, bool s14, bool s15, bool s16, bool s17, bool s18, bool s19, 
        std::vector<std::string> tequipmentProList, 
        Size tsize, int tspeed,
        int tmaxHitPoint, int tcurHitPoint, int ttempHitPoint, 

        int texp, 

        bool tsex, int tage, int feet, int inch, int tweight, int talignment,
        std::vector<std::string> tlanguageList,std::string trait1, std::string trait2,
        std::string tideal, std::string tbond, std::string tflaw,std::string tapperance, std::string tbgStory,

        std::string ttttname, int ttttid, std::string tsubName, int tsubID, std::vector<BasicInfo> ttraitList,
        int tid, std::string tname, std::string tremarks, int tttid, 
        std::string tttname, std::string ttremarks, int tlevel,
        std::string tspecialAbilityName, int tcurSpecialPoint, int tmaxSpecialPoint,
        int m0, int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int m9, 
        int c0, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9,
        std::vector<BasicInfo> tspellList,
        std::vector<BasicInfo> traitList,

        int tcurHitDice,int tmaxHitDice,
        QString tplayername,
        std::vector<Equipment> tequipmentList,std::vector<Weapon> tweaponList,std::vector<Amour> tamourList,

        int cp, int sp, int ep, int gp, int pp):

        CombatCharacter(ttid, ttname, ttype, as0, as1, as2, as3, as4, as5, ap0, ap1, ap2, ap3, ap4, ap5, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14,
            s15, s16, s17, s18, s19,tequipmentProList, tsize, tspeed, tmaxHitPoint, tcurHitPoint, ttempHitPoint),
        exp(texp),
        details(tsex, tage,feet,inch,tweight,talignment, tlanguageList,
            trait1, trait2, tideal, tbond, tflaw, tapperance, tbgStory),
        race(ttttname,ttttid,  tsubName, tsubID, ttraitList),
        _class(tid, tname, tremarks, tttid,  tttname, ttremarks, tlevel,
            tspecialAbilityName,tcurSpecialPoint,tmaxSpecialPoint, m0, m1, m2, m3, m4, m5, m6, m7, m8, m9,
            c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, tspellList, traitList),
        curHitDice(tcurHitDice), maxHitDice(tmaxHitDice), 
        playerName(tplayername),
        equipmentList(tequipmentList), weaponList(tweaponList), amourList(tamourList),
        characterWealth (cp, sp, ep, gp, pp){}

    QString getHDString();
    virtual QString getRaceName();
    QString getSubRaceName();
    QString getClassName();
    QString getPlayerName();
    int getEXP();
    int getSkillProBonus(int x);
    virtual int getInitiativePlus();
};

