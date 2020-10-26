/*创建日期：2020/10/14
* 类名称：冒险者职业
* 类用途：存储冒险者职业信息
* 作者：吴彤
*/

#pragma once
#include <vector>
#include "BasicInfo.h"

class AdventurerClass
{
	BasicInfo _class;		//职业信息
	BasicInfo subClass;		//职业分支信息

	int level;				//职业等级

	std::string specialAbilityName;		//特殊能力名称
	int curSpecialPoint;				//当前值
	int maxSpecialPoint;				//最大值

	int maxSpellSlots[10];				//最大法术位数量
	int curSpellSlots[10];					//当前法术位数量
	std::vector<BasicInfo> spellList;		//法术列表

	std::vector<BasicInfo> traitList;	//职业特性列表
public:
	AdventurerClass(int tid, std::string tname, std::string tremarks, int ttid, std::string ttname, std::string ttremarks, int tlevel,
		std::string tspecialAbilityName,int tcurSpecialPoint,int tmaxSpecialPoint, int m0,int m1,int m2,int m3, int m4, int m5, 
		int m6,int m7, int m8, int m9, int c0, int c1, int c2, int c3, int c4, int c5,int c6, int c7, int c8, int c9,
		std::vector<BasicInfo> tspellList, 
		std::vector<BasicInfo> ttraitList):
	_class(tid,tname,tremarks),subClass(ttid, ttname, ttremarks),level(tlevel), specialAbilityName(tspecialAbilityName), 
		curSpecialPoint(tcurSpecialPoint), maxSpecialPoint(tmaxSpecialPoint), maxSpellSlots{m0,m1,m2,m3,m4,m5,m6,m7,m8,m9}, 
		curSpellSlots{ c0,c1,c2,c3,c4,c5,c6,c7,c8,c9 },
		spellList(tspellList), traitList(ttraitList) {}
};

