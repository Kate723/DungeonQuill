/*创建日期：2020/10/15
* 类名称：武器
* 类用途：存储武器信息
* 作者：吴彤
*/

#pragma once
#include <string>
#include "Equipment.h"
#include "DiceRollType.h"

class Weapon :
    public Equipment
{
    DamageType damageType;      //伤害类型
    DiceRollType damageDice;    //伤害骰
    
    bool needAmmunition;        //是否需要弹药
    bool isFinesse;             //是否具有灵巧属性
    WeaponType type;            //军用，简易
    WeaponRange range;          //近战，远程
    int regularRange;           //常规射程
    int maxRange;                //最大射程

public:
    static std::string damageTypeName[5];
    Weapon(int ID, std::string name, std::string remark, EquipemntType type, int dN, int dND, int dSN, bool tneedAmmunition,bool tisFinesse,
        int tregularRange,int tmaxRange):
        Equipment(ID, name,  remark,type), damageDice(dN, dND, dSN), needAmmunition(tneedAmmunition), isFinesse(tisFinesse), 
        regularRange(tregularRange), maxRange(tmaxRange){}
};

