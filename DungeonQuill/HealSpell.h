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
public:
	static int healSpellNum;
    static std::vector<HealSpell*> HealSpellList;
	HealSpell(int i, std::string& nC, std::string& nE, int sI, int l, bool iR, int cl, std::string& cr, int r, bool iSO, bool vN, bool sN, bool mN,
		std::string& cre, bool c, int t, std::string& dr, bool tN, int tNum, int asI, int s, std::string& re, int dN, int dND, int dS) :
		Spell(i, nC, nE, sI, l, iR, cl, cr, r, iSO, vN, sN, mN, cre, c, t, dr, tN, tNum, asI, s, re), healDice(dN, dND, dS) {}
};

