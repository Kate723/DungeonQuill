/*�������ڣ�2020/10/2
* �����ƣ���������
* ����;���洢�����������ݣ��ڽ�����ɫ��ս���������ṩ���ݲ�ѯ
* ���ߣ���ͮ
*/

#pragma once
#include "Spell.h"
class DamageSpell :
    public Spell
{
	AttackRollType rollType;		//�����춨����
	STSuccess decrease;				//����ɹ������˺���
	AbilityType STType;				//��������
	DamageType damageType;			//�˺�����
	DiceRollType damageDice;	//�˺���

public:
	static int DamageSpellNum;
	static std::vector<DamageSpell*> DamageSpellList;
	
	DamageSpell(int i, std::string& nC, std::string& nE, int sI, int l, bool iR, int cl, std::string& cr, int r, bool iSO, bool vN, bool sN, bool mN,
		std::string& cre, bool c, int t, std::string& dr, bool tN, int tNum, int asI, int s, std::string& re,bool aRN, bool sTN, int sTTID, int dT,
		int dN, int dND, int dS):
		Spell(i,nC,nE,sI,l,iR,cl,cr,r, iSO, vN, sN, mN, cre, c, t, dr,tN,tNum, asI, s,re), rollType((AttackRollType)aRN), 
		decrease((STSuccess)sTN),STType((AbilityType)sTTID),damageType((DamageType)dT),  damageDice(dN,dND,dS){}
		
};

