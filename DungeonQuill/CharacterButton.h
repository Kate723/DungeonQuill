/*创建日期：2020/10/24
* 类名称：角色按钮
* 类用途：存储角色基础六属性值
* 作者：吴彤
*/
#pragma once

#include <QObject>
#include <qtoolbutton.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include "CombatCharacter.h"

class CharacterButton : public QToolButton
{
	CombatCharacter* chatacter;
	QTextBrowser* characterText;
	Q_OBJECT

	void setCharacterText();

public slots:
	void displayCharacter();

public:
	CharacterButton(CombatCharacter* _chatacter);
	~CharacterButton();
};
