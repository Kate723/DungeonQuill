/*创建日期：2020/10/14
* 类名称：可选职业特性
* 类用途：存储特殊可选职业特性信息
* 作者：吴彤
*/

#pragma once
#include <string>
#include <vector>
#include "BasicInfo.h"

class ChoosableClassTrait
{
	BasicInfo traitInfo;									//基本信息
	std::vector<BasicInfo> traitChooseList;					//职业可选特性列表
	std::vector<int> chooseLV;								//选择等级
};

