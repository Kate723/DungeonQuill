/*创建日期：2020/10/25
* 类名称：战斗地图编辑器
* 类用途：编辑战斗所需地形图
* 作者：吴彤
*/

#pragma once

#include <QWidget>
#include <qtablewidget.h>
#include <qmessagebox.h>
#include <qstring.h>
#include "ui_MapEditor.h"
#include "DungeonQuill.h"
#include "CombatMap.h"
#include "Adventurer.h"
#include "Monster.h"

class MapEditor : public QWidget
{
	CombatMap* map;
	Q_OBJECT

public slots:
	void selectedItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous);
	void setBarrier();
	void onSaveButtonClicked();

public:
	MapEditor(CombatMap* _map = NULL);
	~MapEditor();

private:
	Ui::MapEditor ui;
	void showMap();
	void setText();
	QTableWidgetItem* tableItem(QColor gridColor, QString& str);

	friend DungeonQuill;
};