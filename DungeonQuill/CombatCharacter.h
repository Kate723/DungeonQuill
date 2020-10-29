﻿/*创建日期：2020/9/25
* 类名称：战斗角色
* 类用途：存储参与战斗的角色数据
* 作者：吴彤
*/

#pragma once
#include <string>
#include <vector>
#include <qstring.h>
#include "EnumType.h"
#include "AbilityScore.h"
#include "CombatAction.h"
#include "Buff.h"

class CombatPiece;

class CombatCharacter
{
protected:
	int id;							//角色编号
	std::string name;				//角色名称
	CharacterType type;				//角色类型

	AbilityScore abilityScore;		//角色属性值
	bool skillPro[20];								//技能熟练列表
	std::vector<std::string> equipmentProList;		//装备熟练列表

	Size size;						//体型
	int speed;						//速度，以尺为单位
	int maxHitPoint;				//最大生命值
	int curHitPoint;				//当前生命值
	int tempHitPoint;				//临时生命值

	/// <summary>
	/// 以下战斗临时数据，不计入数据库
	/// </summary>
	std::vector<Buff> buffList;		//增/减益列表

	bool isConsentrating;			//是否处于专注
	bool isInCondition[15];			//状态标签

	CharacterCondition conditon;	//人物状态

	int attackTime;                 //攻击次数
	int maxAttackTime;              //最大攻击次数
	int deathSTtime;				//已进行死亡豁免次数 
	int deathSTSuccess;				//已成功死亡豁免次数 
	int deathSTFailure;				//已失败死亡豁免次数 

public:
	static std::string conditionName[15];					//状态名称

	//CombatCharacter* findCharacter(int id);
	CombatCharacter(int tid, std::string tname, CharacterType ttype, AbilityScore tabilityScore,
		int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9, int s10,
		int s11, int s12, int s13, int  s14, int s15, int s16, int s17, int s18, int s19,
		std::vector<std::string> tequipmentProList,Size tsize,int tspeed, int tmaxHitPoint,
		int tcurHitPoint, int ttempHitPoint):
		id(tid), name(tname), type(ttype), abilityScore(tabilityScore), skillPro{s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,
	s15,s16,s17,s18,s19}, equipmentProList(tequipmentProList), size(tsize),speed(tspeed), maxHitPoint(tmaxHitPoint),
		curHitPoint(tcurHitPoint),
		tempHitPoint(ttempHitPoint){}

	QString getName();
	virtual QString getRaceName();
	QString getSizeString();
	QString getSpeedString();
	QString getHPString();

	AbilityScore* Ability();
	const bool* getSkillProList();
	int getSkillProBonus(int x);
	const std::vector<std::string> getEquipmentProList();
	int getSpeed();
	int* getHPdata();

	friend CombatPiece;
};

