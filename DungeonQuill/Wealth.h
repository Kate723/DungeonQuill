/*创建日期：2020/10/20
* 类名称：财富
* 类用途：存储角色财富数据，提供记录与修改功能
* 作者：吴彤
*/

#pragma once
#include <string>

class Wealth
{
	int copperCoin;			//铜币
	int silverCoin;			//银币
	int electrumCoin;		//银金币
	int goldCoin;			//金币
	int platinumCoin;		//铂金币

public:
	static std::string coinNameCH[6], coinNameEN[6];						//币种名称
	static int coinWeight[6];												//币种权值（换算使用）

	Wealth(int cp = 0, int sp = 0, int ep = 0, int gp = 0, int pp = 0);		//构造函数
};

