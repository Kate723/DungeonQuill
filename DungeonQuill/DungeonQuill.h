#pragma once
#include <string>
#include <QtWidgets/QMainWindow>
#include <qtoolbutton.h>
#include "qtablewidget.h"
#include "SpellBotton.h"
#include "DataManager.h"
#include "ui_DungeonQuill.h"

class DungeonQuill : public QMainWindow
{
    Q_OBJECT

public:
    DungeonQuill(QWidget *parent = Q_NULLPTR);

private:
    Ui::DungeonQuillClass ui;

    void initSpellTab();
};
