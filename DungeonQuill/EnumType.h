/*创建日期：2020/9/25
* 名称：枚举类型
* 用途：存储所有枚举类型
* 作者：吴彤
*/

#pragma once
enum AreaShape {				//形状
	CONE,		//锥状
	CUBE,		//立方
	CYLINDER,	//柱状
	LINE,		//线状
	SPHERE		//球状
};

enum EquipemntType {			//装备类型
	OTHER_E,
	WEAPON,
	AMOUR,
	TOOL
};

enum WeaponType {				//武器类型
	Simple,
	Martial
};

enum AmourType {				//护甲类型
	Light,
	Medium,
	Heavy,
	Sheild
};

enum ToolType {					//工具类型
	OrtiansTool,
	DisguiseTool,
	ForgeryKit,
	GamingSet,
	HerbalismKit,
	MusicalInstrument,
	NavigatorsTool,
	PoisonersKit,
	ThievesTool
};

enum WeaponRange {				//武器范围
	Melee,
	Ranged
};

enum Size {						//体型
	TINY,
	SMALL,
	MEDIUM,
	LARGE,
	HUGE_S,
	GARGANTUAN
};

enum CharacterType {			//角色类型
	PC,
	NPC,
	MONSTER
};

enum CharacterCondition {			//人物状态
	NORM,
	DEAD,
	NEED_DEATH_ST,
	STABLE
};

enum Aligment {					//阵营
	LG,
	NG,
	CG,
	LN,
	TN,
	CN,
	LE,
	NE,
	CE
};

enum AbilityType {				//属性类型
	OTHER,
	ALL,
	NONE,
	STRENGTH,
	DEXTERITY,
	CONSTITUTION,
	INTELLIGENCE,
	WISDOM,
	CHARISMA
};

enum Skill {					//技能
	Athletics,
	Acrobatics,
	SleightOfHand,
	Stealth,
	Arcana,
	History,
	Investigation,
	Nature,
	Religion,
	AnimalHandling,
	Insight,
	Medicine,
	Perception,
	Survival
};

enum DamageType {				//伤害类型
	Other_D,
	Blunt,
	Slash,
	Puncture,
	Acid,
	Cold,
	Fire,
	Force,
	Lightning,
	Necrotic,
	Poison,
	Psychic,
	Radiant,
	Thunder
};

enum AttackRollType {			//攻击检定类型
	ATTACKROLL,
	SAVINGTHROW
};

enum STSuccess {				//豁免成功
	FullDamageDecrease,
	HalfDamageDecrease,
	BuffRemove,
};

enum CombatCondition {			//战斗状态
	IDIE,
	CHARACTER_CHOOSE,
	ACTION_ROUND
};