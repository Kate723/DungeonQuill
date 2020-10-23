/*创建日期：2020/10/15
* 类名称：装备
* 类用途：存储装备信息
* 作者：吴彤
*/

#pragma once
#include <string>
#include "EnumType.h"
#include "BasicInfo.h"

class Equipment
{
	BasicInfo equipmentInfo;		//装备信息
	EquipemntType equipmentType;	//装备类型

public:
	Equipment(int ID, std::string name, std::string remark, EquipemntType type);
	int getID();
	std::string getName();
	std::string getRemarks();
};

