/*创建日期：2020/9/25
* 类名称：属性值
* 类用途：存储角色基础六属性值
* 作者：吴彤
*/

#pragma once
#define ABILITY_NUM  6
#include <string>

class AbilityScore
{
	int abilityScore[ABILITY_NUM];														//属性值
	bool abilityProficiency[ABILITY_NUM];												//属性豁免
public:
	static std::string abilityNameEn[ABILITY_NUM], abilityNameCh[ABILITY_NUM];		//属性名称
	
	AbilityScore(int defaultNum = 8);				//构造函数
	const int getAbilityScore(int id);					//由id得到属性值
	const int getAbilityScore(std::string name);			//由名称得到属性值
	const int getAbilityModifier(int id);					//由id得到调整值
	const int getAbilityModifier(std::string name);		//由名称得到调整值
	const bool* getProList();
};