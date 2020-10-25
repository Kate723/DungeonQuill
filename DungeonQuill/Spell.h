/*创建日期：2020/9/18
* 类名称：法术
* 类用途：存储法术数据，在建立角色与战斗流程中提供数据查询
* 作者：吴彤
*/

#include <string>
#include <vector>
#include "EnumType.h"
#include "SpellComponments.h"
#include "Area.h"
#include "DiceRollType.h"
#include "Adventurer.h"

#pragma once
struct CastingTime			//施法时间
{
	int length;				//长度标记，0：瞬发，1：1反应，2：1附赠，3：1动作，4：更长
	std::string remarks;	//备注，时间具体标记
	CastingTime(int length, std::string& remark) :
		length(length), remarks(remark) {}

};

struct Duration				//法术持续时间
{
	bool concentrationNeed;	//是否需要专注
	int time;				//持续时间，0：即时，1：1轮，2：更长
	std::string remarks;	//标记具体时间
	Duration(bool concentarte, int time, std::string& remark) :
		concentrationNeed(concentarte), time(time), remarks(remark) {}
};

class Spell
{
	int ID;						//法术编号
	std::string nameCh, nameEn;	//法术中英文名称
	int schoolID;				//所属学派编号
	int level;					//法术环阶
	bool isRitual;				//是否为仪式法术

	CastingTime castingTime;				//施法时间

	int range;					//施法距离，单位为尺，0即为触及或自身
	bool isSelfOnly;			//是否只能对自身使用

	SpellComponments componments;	//法术成分

	Duration duration;					//法术持续时间

	bool targetNeed;			//是否需要目标
	int targetNum;				//目标数量

	Area effectArea;			//法术影响区域

	std::string remarks;		//备注，法术文字描述

	static std::string schoolName[10];
public:
	Spell(int id, std::string& nameC, std::string& nameE, int schoolID, int lv, bool ritual,
		int castingLength, std::string& castingRemarks,
		int range, bool selfOnly,
		bool verbal, bool somatic, bool material,std::string& compRemark,
		bool concentration, int time, std::string& durationRemark,
		bool target, int tNum,
		int areaShape, int areaSize,
		std::string& remark) :

		ID(id), nameCh(nameC), nameEn(nameE), schoolID(schoolID), level(lv), isRitual(ritual),
		castingTime(castingLength, castingRemarks),
		range(range), isSelfOnly(selfOnly),
		componments(verbal, somatic, material, compRemark),
		duration(concentration, time, durationRemark),
		targetNeed(target), targetNum(tNum), effectArea(areaShape, areaSize), remarks(remark) {}

	std::string getNameCH();
	std::string getNameEN();
	std::string getSchoolName();
	int getLevel();
	std::string getLevelString();
	bool spellIsRitual();
	std::string getRemarks();

	std::string getCastingTimeRemarks();
	std::string getRangeString();
	std::string getComponentString();
	std::string getDurationString();
	
};
