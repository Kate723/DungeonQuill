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
	AttackRollType rollType;		//攻击检定类型
	STSuccess decrease;				//豁免成功减免伤害数
	AbilityType STType;				//豁免属性
	DamageType damageType;			//伤害类型
	DiceRollType damageDice;	//伤害骰

public:
	static int damageSpellNum;
	static std::vector<DamageSpell*> DamageSpellList;
	
	DamageSpell(int i, std::string& nC, std::string& nE, int sI, int l, bool iR, int cl, std::string& cr, int r, bool iSO, bool vN, bool sN, bool mN,
		std::string& cre, bool c, int t, std::string& dr, bool tN, int tNum, int asI, int s, std::string& re,bool aRN, bool sTN, int sTTID, int dT,
		int dN, int dND, int dS):
		Spell(i,nC,nE,sI,l,iR,cl,cr,r, iSO, vN, sN, mN, cre, c, t, dr,tN,tNum, asI, s,re), rollType((AttackRollType)aRN), 
		decrease((STSuccess)sTN),STType((AbilityType)sTTID),damageType((DamageType)dT),  damageDice(dN,dND,dS){}
		
};

