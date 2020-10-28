/*创建日期：2020/10/14
* 类名称：冒险者种族
* 类用途：存储冒险者种族信息
* 作者：吴彤
*/

#pragma once
#include <string>
#include <vector>
#include "BasicInfo.h"

class AdventurerRace
{
	std::string name;		//种族名称
	int id;					//种族编号

	std::string subName;	//种族分支名称
	int subID;				//种族分支编号

	std::vector<BasicInfo> traitList;	//种族特性列表
public:
	AdventurerRace(std::string tname,int tid, std::string tsubName,int tsubID, std::vector<BasicInfo> ttraitList):
		name(tname), id(tid), subName(tsubName),subID(tsubID), traitList(ttraitList){}

	QString getRaceName();
	QString getSubRaceName();
};