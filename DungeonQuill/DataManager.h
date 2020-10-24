#pragma once
#include "DungeonQuill.h"
#include "qtablewidget.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QtSql>
#include<Qlist>
#include<QVariant>
#include "DamageSpell.h"
#define vnum 30
class DataManager
{
public:
	void createDb();
	void download();
};

