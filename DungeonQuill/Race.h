/*创建日期：2020/10/14
* 类名称：种族
* 类用途：存储种族信息
* 作者：吴彤
*/

#pragma once
#include <string>
#include <vector>
#include "BasicInfo.h"
#include "AbilityScore.h"
#include "CombatCharacter.h"

struct AbilityIncrease
{
	AbilityScore::AbilityType increaseType;
	int increase;
};

class Race
{
	BasicInfo raceBasicInfo;

	std::vector<AbilityIncrease> increaseList;		//属性值增加列表
	Size size;										//种族体型
	int speed;										//种族速度
	std::vector<BasicInfo> RaceTraitsList;			//种族特性列表（仅文字）
	std::vector<Race*> subRace;						//亚种
public:
	static int raceNum;						//种族个数
	static std::vector<Race*> raceList;		//种族列表
	Race(int tid, std::string tname, std::string tremarks, int tspeed):
		raceBasicInfo(tid, tname, tremarks), speed(tspeed){}
};

