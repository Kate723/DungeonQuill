/*创建日期：2020/9/25
* 类名称：角色细节
* 类用途：存储冒险者背景细节
* 作者：吴彤
*/
#pragma once
#include <string>
#include <vector>
#include <qstring.h>
#include "EnumType.h"

struct Height{
	int feet, inch;
	Height(int tfeet, int tinch):
	feet(tfeet),inch(tinch){}
};

struct Characteristics {
	std::string trait[2];	//特点
	std::string ideal;		//理想
	std::string bond;		//羁绊
	std::string flaw;		//缺点
	Characteristics(std::string trait1, std::string trait2, std::string tideal, std::string tbond,std::string tflaw):
		trait{trait1,trait2}, ideal(tideal), bond(tbond), flaw(tflaw){}
};

class CharacterDetails
{
	bool sex;					//1为男性，0为女性
	int age;					//年龄
	Height height;				//身高

	int weight;					//体重，磅为单位

	Aligment alignment;			//角色阵营

	std::vector<std::string> languageList;		//语言列表20

	Characteristics characteristics;			//角色性格

	std::string apperance;		//外貌描写
	std::string bgStory;		//背景故事
public:
	CharacterDetails(bool tsex, int tage, int feet, int inch, int tweight, int talignment, 
		std::vector<std::string> tlanguageList,
		std::string trait1, std::string trait2, 
		std::string tideal, std::string tbond, std::string tflaw,
		std::string tapperance,std::string tbgStory):

		sex(tsex), age(tage), height(feet, inch), weight(tweight),alignment((Aligment)talignment), 
		languageList(tlanguageList),
		characteristics(trait1, trait2, tideal,tbond,tflaw),
		apperance(tapperance),bgStory(tbgStory) {}

	QString getGender();
	QString getAge();
	QString getAlignment();
	QString getHeight();
	QString getWeight();
	QString* getCharacteristics();
	QString getAppearance();
	QString getBGStory();
	std::vector<std::string> getLanguageList();

	bool isMale();
	int getAlignmentID();
};