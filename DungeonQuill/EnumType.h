/*创建日期：2020/9/25
* 名称：枚举类型
* 用途：存储所有枚举类型
* 作者：吴彤
*/

#pragma once
enum Shape {					//形状
	Cone,
	Cube,
	Cylinder,
	Line,
	Sphere
};

enum EquipemntType {			//装备类型
	OTHER,
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
	Tiny,
	Small,
	Medium,
	Large,
	Huge,
	Gargantuan
};

enum CharacterType {			//角色类型
	PC,
	NPC,
	MONSTER
};

enum CombatCondition {			//人物状态
	Norm,
	Dead,
	NeedDeathST,
	Stable
};

enum Aligment {					//阵营
	LawfulGood,
	NeutralGood,
	ChaoticGood,
	LawfulNeutral,
	TrueNeutral,
	ChaoticNeutral,
	LawfulEvil,
	NeutralEvil,
	ChaoticEvil
};

enum AbilityType {				//属性类型
	Other,
	All,
	None,
	Strength,
	Dexterity,
	Constitution,
	Intelligence,
	Wisdom,
	Charisma
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
	AttackRoll,
	SavingThrow
};

enum STSuccess {				//豁免成功
	FullDamageDecrease,
	HalfDamageDecrease,
	BuffRemove,
};