/*创建日期：2020/10/2
* 类名称：攻击法术
* 类用途：存储攻击法术数据，在建立角色与战斗流程中提供数据查询
* 作者：吴彤
*/

#pragma once
#include "Spell.h"
class DamageSpell :
    public Spell
{
	bool attackRollNeed;		//需要攻击检定
	bool savingThrowNeed;		//需要豁免
	int savingThrowTypeID;		//豁免属性编号

	int damageType;				//伤害类型
	DiceRollType damageDice;	//伤害骰

public:
	static int DamageSpellNum;
	static std::vector<DamageSpell*> DamageSpellList;
	
	DamageSpell(int i, std::string& nC, std::string& nE, int sI, int l, bool iR, int cl, std::string& cr, int r, bool iSO, bool vN, bool sN, bool mN,
		std::string& cre, bool c, int t, std::string& dr, bool tN, int tNum, int asI, int s, std::string& re,bool aRN, bool sTN, int sTTID, int dT,
		int dN, int dND, int dS):
		Spell(i,nC,nE,sI,l,iR,cl,cr,r, iSO, vN, sN, mN, cre, c, t, dr,tN,tNum, asI, s,re), attackRollNeed(aRN), savingThrowNeed(sTN), 
		savingThrowTypeID(sTTID),damageType(dT),  damageDice(dN,dND,dS){}
		
};

