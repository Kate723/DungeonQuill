/*创建日期：2020/10/24
* 类名称：角色按钮
* 类用途：显示冒险者基本信息，提供呼出冒险者窗口功能
* 作者：吴彤
*/
#pragma once

#include "DisplayButton.h"
#include "Adventurer.h"
#include "CharacterDisplay.h"

class CharacterButton : public DisplayButton
{
	Adventurer* adventurer;
	Q_OBJECT

	virtual void setDisplayText();

public slots:
	void displayCharacter();

public:
	CharacterButton(Adventurer* _character);
	~CharacterButton();
};
