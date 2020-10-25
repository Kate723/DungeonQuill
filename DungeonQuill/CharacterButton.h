/*创建日期：2020/10/24
* 类名称：角色按钮
* 类用途：显示角色基本信息，提供呼出角色窗口功能
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
	CombatCharacter* character;
	QTextBrowser* characterText;
	Q_OBJECT

	void setCharacterText();

public slots:
	void displayCharacter();

public:
	CharacterButton(CombatCharacter* _chatacter);
	~CharacterButton();
};
