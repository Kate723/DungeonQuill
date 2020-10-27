#pragma once
#include <string>
#include <QtWidgets/QMainWindow>
#include <qtoolbutton.h>
#include "SpellBotton.h"
#include "MapButton.h"
#include "NewMapButton.h"
#include "qtablewidget.h"
#include "DataManager.h"
#include "ui_DungeonQuill.h"

class DungeonQuill : public QMainWindow
{
    Q_OBJECT

public slots:
    void spellInquiry(int x);

public:
    DungeonQuill();

private:
    Ui::DungeonQuillClass ui;

    void initCombatTab();

    void initSpellTab();
    Spell* findNextSpell(bool resetFlag);
};
