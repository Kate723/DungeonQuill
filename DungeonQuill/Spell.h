/*创建日期：2020/9/18
* 类名称：法术
* 类用途：存储法术数据，在建立角色与战斗流程中提供数据查询
* 作者：吴彤
*/

#include <string>
#include <vector>
#include "SpellComponments.h"
#include "Area.h"
#include "DiceRollType.h"
#include "Adventurer.h"

#pragma once
struct CastingTime			//施法时间
{
	int length;				//长度标记，0：1反应，1：1附赠，2：1动作，3：更长
	std::string remarks;	//备注，长于1动作将被标记在这里
	CastingTime(int l, std::string& r) :
		length(l), remarks(r) {}

};

struct Duration				//法术持续时间
{
	bool concentrationNeed;	//是否需要专注
	int time;				//持续时间，0：即时，1：1轮，2：更长
	std::string remarks;	//备注，标记更长时间
	Duration(bool c, int t, std::string& r) :
		concentrationNeed(c), time(t), remarks(r) {}
};

class Spell
{
	int ID;						//法术编号
	std::string nameCh, nameEn;	//法术中英文名称
	int schoolID;				//所属学派编号
	int level;					//法术环阶
	bool isRitual;				//是否为仪式法术

	CastingTime cT;				//施法时间

	int range;					//施法距离，单位为尺，0即为触及或自身
	bool isSelfOnly;			//是否只能对自身使用

	SpellComponments componments;	//法术成分

	Duration d;					//法术持续时间

	bool targetNeed;			//是否需要目标
	int targetNum;				//目标数量
	
	Area effectArea;			//法术影响区域

	std::string remarks;		//备注，法术文字描述
public:
	Spell(int i, std::string& nC, std::string& nE, int sI, int l, bool iR, int cl, std::string& cr,int r, bool iSO, bool vN, bool sN, bool mN, 
		std::string& cre, bool c, int t, std::string& dr,bool tN,int tNum,int asI, int s,std::string& re):
	ID(i), nameCh(nC), nameEn(nE), schoolID(sI), level(l), isRitual(iR), cT(cl,cr), range(r), isSelfOnly(iSO), componments(vN,sN,mN,cre), d(c,t,dr),
		targetNeed(tN), targetNum(tNum), effectArea(asI,s), remarks(re){}
};

