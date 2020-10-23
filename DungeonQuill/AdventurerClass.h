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
		std::string tspecialAbilityName,int tcurSpecialPoint,int tmaxSpecialPoint):
	_class(tid,tname,tremarks),subClass(ttid, ttname, ttremarks),level(tlevel), specialAbilityName(tspecialAbilityName), 
		curSpecialPoint(tcurSpecialPoint), maxSpecialPoint(tmaxSpecialPoint){}
};

