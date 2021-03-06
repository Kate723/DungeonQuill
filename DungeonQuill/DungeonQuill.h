﻿#pragma once
#include <string>
#include <QtWidgets/QMainWindow>
#include <qtoolbutton.h>
#include <qscrollarea.h>
#include "CharacterButton.h"
#include "SpellBotton.h"
#include "MapButton.h"
#include "NewMapButton.h"
#include "qtablewidget.h"
#include "CombatManager.h"
#include "DiceMaid.h"
#include "CharacterChoose.h"
#include "DataManager.h"
#include "ui_DungeonQuill.h"

class DiceMaid;

class DungeonQuill : public QMainWindow
{
    Q_OBJECT

public slots:
    void spellInquiry(int x);
    void diceRollButtonClicked();

public:
    DungeonQuill();
    static void renewMapList();
    static void combatStart(CombatMap* _map);

private:
    Ui::DungeonQuillClass ui;
    static DungeonQuill* instance;
    DiceMaid* dice;
    static void deleteLayout(QLayout* layout);

    void initCharacterTab();
    
    void initCombatTab();
    QTableWidget* showMap(CombatMap* map);
    QTableWidgetItem* tableItem(QColor gridColor, QString& str);

    void initSpellTab();
    Spell* findNextSpell(bool resetFlag);

    void initDiceTab();
    void sleep(int msec);

    friend DiceMaid;
};
