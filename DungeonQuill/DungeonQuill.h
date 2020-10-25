#pragma once
#include <string>
#include <QtWidgets/QMainWindow>
#include <qtoolbutton.h>
#include "qtablewidget.h"
#include "SpellBotton.h"
#include "DamageSpell.h"
#include "HealSpell.h"
#include "DataManager.h"
#include "ui_DungeonQuill.h"

class DungeonQuill : public QMainWindow
{
    Q_OBJECT

public:
    DungeonQuill();

private:
    Ui::DungeonQuillClass ui;

    void initSpellTab();
    Spell* findNextSpell(bool resetFlag);
};
