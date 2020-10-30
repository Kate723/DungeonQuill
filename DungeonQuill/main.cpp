#include "DungeonQuill.h"
#include "CharacterDisplay.h"
#include "AbilityScore.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qdebug.h>
#include <iostream>
#include "DataManager.h"
#include "DiceMaid.h"

//设置格式
void setQss() {
    QFile qssFile(":/qss/Source/Ubuntu.qss");
    qssFile.open(QFile::ReadOnly);
    if (qssFile.isOpen())
    {
        qApp->setStyleSheet(qssFile.readAll());
        qssFile.close();
    }
}

int main(int argc, char *argv[])
{
    DataManager dataManager;
    dataManager.createDb();
    dataManager.download();
    
    QApplication a(argc, argv);
    setQss();

    //定义主窗口并打开
    DungeonQuill w;
    auto dicemaid = new DiceMaid();
    auto combatManager = new CombatManager();
    w.show();

    return a.exec();
}
