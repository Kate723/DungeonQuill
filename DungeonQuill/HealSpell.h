/*创建日期：2020/10/7
* 类名称：治疗法术
* 类用途：存储治疗法术数据，在建立角色与战斗流程中提供数据查询
* 作者：吴彤
*/

#pragma once
#include "Spell.h"
#include "DiceRollType.h"

class HealSpell :
    public Spell
{
    DiceRollType healDice;
};

