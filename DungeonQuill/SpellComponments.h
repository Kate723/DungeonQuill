/*�������ڣ�2020/9/18
* �����ƣ������ɷ�
* ����;���洢�����ɷ����ݣ���������ʹ��
* ���ߣ���ͮ
*/

#include <string>

#pragma once
class SpellComponments
{
	bool verbalNeed;		//�Ƿ���Ҫ����
	bool somaticNeed;		//�Ƿ���Ҫ����
	bool materialNeed;		//�Ƿ���Ҫ����
	std::string remark;		//��ע���������������
public:
	SpellComponments(bool vN,bool sN,bool mN,std::string& r):
		verbalNeed(vN), somaticNeed(sN), materialNeed(mN), remark(r){}
};

