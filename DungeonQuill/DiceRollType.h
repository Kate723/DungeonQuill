/*�������ڣ�2020/9/18
* �����ƣ���������
* ����;���洢����Ͷ������������
* ���ߣ���ͮ
*/

#pragma once
class DiceRollType
{
	int diceNum;				//��������
	int diceNumDependence;		//������������ֵ
	int diceSideNum;			//��������
public:
	DiceRollType(int dN,int dND,int dSN):
		diceNum(dN),diceNumDependence(dND),diceSideNum(dSN){}
};

