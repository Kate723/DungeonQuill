/*创建日期：2020/10/14
* 类名称：职业
* 类用途：存储职业信息
* 作者：吴彤
*/

#pragma once
#include <string>
#include <vector>
#include "EnumType.h"
#include "BasicInfo.h"
#include "AbilityScore.h"
#include "ChoosableClassTrait.h"

class Class
{
	BasicInfo classInfo;									//基本职业信息
	int healthDice;											//职业生命骰

	std::vector<std::string> equipmentProList;				//装备熟练列表
	std::vector<AbilityType> abilityProList;				//属性熟练列表
	int skillProNum;										//技能熟练数
	std::vector<Skill> skillProList;						//技能熟练列表

	std::vector<int> abilityIncreaseLV;						//属性值提升等级

	std::string specialAbilityName;							//特殊能力名称
	std::vector<int> specialPointLV;						//特殊能力各等级点数

	std::vector<BasicInfo> classTraitLV[21];				//各等级职业特性

	std::vector<ChoosableClassTrait> chooseTraitList;		//可选职业特性列表

	AbilityType castingAbility;								//施法关键属性
	int spellSlotNum[21][10];								//各等级法术位
	std::vector<int> spellList;								//法术列表

	std::string subClassName;					//职业分支名称
	int subClassNum;							//副职业
	std::vector<Class*> subClassList;			//副职业列表

public:
	static int classNum;						//职业总数
	static std::vector<Class*> classList;		//职业列表
	Class(int tid, std::string tname,std::string tremarks, int thealthDice, int tskillProNum, std::string tsubClassName,int tsubClassNum):
		classInfo(tid, tname, tremarks), healthDice(thealthDice), skillProNum(tskillProNum), subClassName(tsubClassName), subClassNum(tsubClassNum){}
};

