/*创建日期：2020/9/18
* 类名称：法术成分
* 类用途：存储法术成分数据，供法术类使用
* 作者：吴彤
*/
#pragma once
#include <string>

class SpellComponments
{
public:
	bool verbalNeed;		//是否需要言语
	bool somaticNeed;		//是否需要姿势
	bool materialNeed;		//是否需要材料
	std::string remark;		//备注，多描述具体材料
	SpellComponments(bool _verbalNeed,bool _somaticNeed,bool _materialNeed,std::string& _remark):
		verbalNeed(_verbalNeed), somaticNeed(_somaticNeed), materialNeed(_materialNeed), remark(_remark){}
};

