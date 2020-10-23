/*创建日期：2020/9/18
* 类名称：掷骰类型
* 类用途：存储所需投掷的骰子类型
* 作者：吴彤
*/

#pragma once
class DiceRollType
{
	int diceNum;				//骰子数量
	int diceNumDependence;		//骰子数量决定值
	int diceSideNum;			//骰子面数
public:
	DiceRollType(int dN,int dND,int dSN):
		diceNum(dN),diceNumDependence(dND),diceSideNum(dSN){}
};

