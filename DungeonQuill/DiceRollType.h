/*创建日期：2020/9/18
* 类名称：掷骰类型
* 类用途：存储所需投掷的骰子类型
* 作者：吴彤
*/

#pragma once

class DiceMaid;

class DiceRollType
{
public:
	int diceNum;				//骰子数量
	int diceNumDependence;		//骰子数量决定值
	int diceSideNum;			//骰子面数

	DiceRollType(int _diceNum,int _diceNumDependence,int _diceSideNum):
		diceNum(_diceNum),diceNumDependence(_diceNumDependence),diceSideNum(_diceSideNum){}

	friend DiceMaid;
};

