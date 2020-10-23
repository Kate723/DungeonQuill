/*�������ڣ�2020/9/18
* �����ƣ�����
* ����;���洢�������ݣ��ڽ�����ɫ��ս���������ṩ���ݲ�ѯ
* ���ߣ���ͮ
*/

#include <string>
#include <vector>
#include "SpellComponments.h"
#include "Area.h"
#include "DiceRollType.h"
#include "Adventurer.h"

#pragma once
struct CastingTime			//ʩ��ʱ��
{
	int length;				//���ȱ�ǣ�0��1��Ӧ��1��1������2��1������3������
	std::string remarks;	//��ע������1�����������������
	CastingTime(int l, std::string& r) :
		length(l), remarks(r) {}

};

struct Duration				//��������ʱ��
{
	bool concentrationNeed;	//�Ƿ���Ҫרע
	int time;				//����ʱ�䣬0����ʱ��1��1�֣�2������
	std::string remarks;	//��ע����Ǹ���ʱ��
	Duration(bool c, int t, std::string& r) :
		concentrationNeed(c), time(t), remarks(r) {}
};

class Spell
{
	int ID;						//�������
	std::string nameCh, nameEn;	//������Ӣ������
	int schoolID;				//����ѧ�ɱ��
	int level;					//��������
	bool isRitual;				//�Ƿ�Ϊ��ʽ����

	CastingTime cT;				//ʩ��ʱ��

	int range;					//ʩ�����룬��λΪ�ߣ�0��Ϊ����������
	bool isSelfOnly;			//�Ƿ�ֻ�ܶ�����ʹ��

	SpellComponments componments;	//�����ɷ�

	Duration d;					//��������ʱ��

	bool targetNeed;			//�Ƿ���ҪĿ��
	int targetNum;				//Ŀ������
	
	Area effectArea;			//����Ӱ������

	std::string remarks;		//��ע��������������
public:
	Spell(int i, std::string& nC, std::string& nE, int sI, int l, bool iR, int cl, std::string& cr,int r, bool iSO, bool vN, bool sN, bool mN, 
		std::string& cre, bool c, int t, std::string& dr,bool tN,int tNum,int asI, int s,std::string& re):
	ID(i), nameCh(nC), nameEn(nE), schoolID(sI), level(l), isRitual(iR), cT(cl,cr), range(r), isSelfOnly(iSO), componments(vN,sN,mN,cre), d(c,t,dr),
		targetNeed(tN), targetNum(tNum), effectArea(asI,s), remarks(re){}
};

