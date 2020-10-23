#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DungeonQuill.h"

class DungeonQuill : public QMainWindow
{
    Q_OBJECT

public:
    DungeonQuill(QWidget *parent = Q_NULLPTR);

private:
    Ui::DungeonQuillClass ui;
};
