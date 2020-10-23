/*创建日期：2020/10/20
* 类名称：基本信息
* 类用途：存储对象基本信息
* 作者：吴彤
*/

#pragma once
#include <string>

class BasicInfo
{
public:
	int id;								//编号
	std::string name;					//名称
	std::string remarks;				//备注

	BasicInfo(int tid, std::string tname = "我觉得这里应该有名字。", std::string tremarks = "不说点什么吗？"):
	id(tid),name(tname),remarks(tremarks){}		//构造函数
};

