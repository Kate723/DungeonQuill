/*创建日期：2020/9/25
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
	int initiative[3];				//先攻数据
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
	CombatCharacter(int tid, std::string tname, CharacterType ttype, int as0, int as1, int as2, int as3, int as4, int as5,
		bool ap0, bool ap1, bool ap2, bool ap3, bool ap4,bool ap5,
		bool s0, bool s1, bool s2, bool s3, bool  s4, bool  s5, bool  s6, bool  s7, bool  s8, bool s9, bool  s10,
		bool  s11, bool  s12, bool s13, bool  s14, bool  s15, bool s16, bool s17, bool s18, bool  s19,
		std::vector<std::string> tequipmentProList,Size tsize,int tspeed, int tmaxHitPoint,
		int tcurHitPoint, int ttempHitPoint):
		id(tid), name(tname), type(ttype), abilityScore(as0, as1, as2, as3, as4, as5, ap0, ap1, ap2, ap3, ap4, ap5), skillPro{s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,
	s15,s16,s17,s18,s19}, equipmentProList(tequipmentProList), size(tsize),speed(tspeed), maxHitPoint(tmaxHitPoint),
		curHitPoint(tcurHitPoint),
		tempHitPoint(ttempHitPoint){}

	int getID();
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

	virtual int getInitiativePlus();
	void setInitiativeData(int* data);
	int* getInitiativeData();
	QString getInitiativeString();
	bool compareInitiative(CombatCharacter* last);

	friend CombatPiece;
};

