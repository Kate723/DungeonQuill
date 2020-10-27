/*创建日期：2020/10/26
* 类名称：地图按钮
* 类用途：显示地图基本信息，提供选择地图开始战斗功能
* 作者：吴彤
*/

#pragma once

#include <qtoolbutton.h>
#include <qtextbrowser.h>
#include <qlayout.h>
#include <qmessagebox.h>
#include "CombatMap.h"
#include "MapEditor.h"

class MapButton : public QToolButton
{
	CombatMap* map;
	QTextBrowser* mapText;
	Q_OBJECT

	void setMaptext();

public slots:
	void selectMap();

public:
	MapButton(CombatMap* _map);
	~MapButton();
};
