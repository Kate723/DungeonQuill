/*创建日期：2020/10/15
* 类名称：护甲
* 类用途：存储护甲信息
* 作者：吴彤
*/

#pragma once
#include "EnumType.h"
#include "Equipment.h"

class Amour :
    public Equipment
{
    int basicAC;        //基础AC
    AmourType type;     //护甲类型
    int strengthLimit;  //力量要求

public:
    Amour(int ID, std::string name, std::string remark, AmourType type, int tbasicAC, int strength);
};

